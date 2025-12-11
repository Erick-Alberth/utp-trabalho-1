#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PRODUTOS 8
#define MAX_NOME_PROD 20
#define BUF 128

/*le uma linha do stdin e retorna um buffer alocado sem o '\n'*/
char *ler_linha(void) {
    char temp[BUF];
    if (!fgets(temp, BUF, stdin)) return NULL;
    temp[strcspn(temp, "\n")] = '\0';
    size_t L = strlen(temp);
    char *s = malloc(L + 1);
    if (!s) return NULL;
    strcpy(s, temp);
    return s;
}

voidespera_enter(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/*limpa o resto da linha lida por scanf*/
voidlimpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/*mostra o menu principal*/
void mostrar_menu(void) {
    printf("==============================\n");
    printf("SUPERMERCADO SS\n");
    printf("==============================\n");
    printf("1- Listar produtos\n");
    printf("2- Adicionar ao carrinho\n");
    printf("3- Ver carrinho\n");
    printf("4- Finalizar compra\n");
    printf("5- Relatorio de estoque\n");
    printf("6- Sair\n");
}

void carregar_estoque(int estoque[NUM_PRODUTOS][2]) {
    int inic[NUM_PRODUTOS] = {10, 8, 15, 12, 20, 25, 7, 14};
    int mini[NUM_PRODUTOS] = {2, 2, 5, 2, 5, 5, 2, 3};
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        estoque[i][0] = inic[i];
        estoque[i][1] = mini[i];
    }
}

/*lista produtos com preco e qtd*/
void listar_produtos(char produtos[][MAX_NOME_PROD], float precos[], int estoque[NUM_PRODUTOS][2]) {
    printf("\n--- Produtos ---\n");
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("%d. %s - R$ %.2f - Qtd:%d\n", i + 1, produtos[i], precos[i], estoque[i][0]);
    }
}

/*busca por nome (substring simples)*/
int buscar_por_nome(char produtos[][MAX_NOME_PROD], const char *busca) {
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        if (strstr(produtos[i], busca) != NULL) return i;
    }
    return -1;
}

/*adiciona produto ao carrinho*/
void adicionar_ao_carrinho(int *carrinho, char produtos[][MAX_NOME_PROD], float precos[], int estoque[NUM_PRODUTOS][2]) {
    int modo = -1;
    char buf[BUF];
    for (;;) {
        printf("\n0- voltar 1- por numero 2- por nome: ");
        if (scanf("%d", &modo) != 1) {
            printf("entrada invalida\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();
        if (modo == 0) return;
        if (modo == 1) {
            int id = 0;
            printf("numero do produto (1-%d): ", NUM_PRODUTOS);
            if (scanf("%d", &id) != 1) { limpar_buffer(); printf("entrada invalida\n"); continue; }
            limpar_buffer();
            if (id < 1 || id > NUM_PRODUTOS) { printf("produto invalido\n"); continue; }
            int qtd = 0;
            printf("quantidade: ");
            if (scanf("%d", &qtd) != 1) { limpar_buffer(); printf("entrada invalida\n"); continue; }
            limpar_buffer();
            if (qtd <= 0) { printf("quantidade invalida\n"); continue; }
            int idx = id - 1;
            if (estoque[idx][0] < qtd) { printf("estoque insuficiente (disponivel %d)\n", estoque[idx][0]); continue; }
            carrinho[idx] += qtd;
            estoque[idx][0] -= qtd;
            printf("%d x %s adicionado(s)\n", qtd, produtos[idx]);
            return;
        } else if (modo == 2) {
            printf("digite parte do nome: ");
            if (!fgets(buf, BUF, stdin)) { printf("erro leitura\n"); return; }
            buf[strcspn(buf, "\n")] = '\0';
            if (strlen(buf) == 0) { printf("busca vazia\n"); continue; }
            int idx = buscar_por_nome(produtos, buf);
            if (idx == -1) { printf("produto nao encontrado\n"); continue; }
            printf("produto: %s R$ %.2f disponivel %d\n", produtos[idx], precos[idx], estoque[idx][0]);
            int qtd = 0;
            printf("quantidade: ");
            if (scanf("%d", &qtd) != 1) { limpar_buffer(); printf("entrada invalida\n"); continue; }
            limpar_buffer();
            if (qtd <= 0) { printf("quantidade invalida\n"); continue; }
            if (estoque[idx][0] < qtd) { printf("estoque insuficiente\n"); continue; }
            carrinho[idx] += qtd;
            estoque[idx][0] -= qtd;
            printf("%d x %s adicionado(s)\n", qtd, produtos[idx]);
            return;
        } else {
            printf("opcao invalida\n");
        }
    }
}

/*mostra carrinho e total*/
void ver_carrinho(int *carrinho, char produtos[][MAX_NOME_PROD], float precos[]) {
    printf("\n--- Carrinho ---\n");
    float total = 0.0f;
    int vazio = 1;
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        if (carrinho[i] > 0) {
            float subtotal = carrinho[i] * precos[i];
            printf("%s - %d unidade(s) - R$ %.2f\n", produtos[i], carrinho[i], subtotal);
            total += subtotal;
            vazio = 0;
        }
    }
    if (vazio) { printf("carrinho vazio\n"); }
    else { printf("total: R$ %.2f\n", total); }
    printf("aperte ENTER para voltar\n");
    espera_enter();
}

void finalizar_compra(int *carrinho, char produtos[][MAX_NOME_PROD], float precos[]) {
    printf("\n--- Finalizar Compra ---\n");
    float total = 0.0f;
    int vazio = 1;
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        if (carrinho[i] > 0) {
            float subtotal = carrinho[i] * precos[i];
            printf("%s - %d - R$ %.2f\n", produtos[i], carrinho[i], subtotal);
            total += subtotal;
            vazio = 0;
        }
    }
    if (vazio) {
        printf("carrinho vazio. nada feito\n");
    } else {
        printf("total: R$ %.2f\n", total);
        printf("compra concluida. obrigado\n");
        for (int i = 0; i < NUM_PRODUTOS; i++) carrinho[i] = 0;
    }
    printf("aperte ENTER para voltar\n");
    espera_enter();
}

int main(void) {
    char produtos[NUM_PRODUTOS][MAX_NOME_PROD] = {
        "Arroz","Feijao Preto","Acucar","Leite",
        "Macarrao","Molho do Tomate","Feijao Carioca","Oleo de Soja"
    };
    float precos[NUM_PRODUTOS] = {5.99f,8.99f,4.99f,8.99f,3.49f,2.29f,7.69f,7.99f};
    int estoque[NUM_PRODUTOS][2];
    carregar_estoque(estoque);

    int *carrinho = calloc(NUM_PRODUTOS, sizeof(int));
    if (!carrinho) {
        fprintf(stderr, "erro: sem memoria para carrinho\n");
        return 1;
    }

    printf("digite seu nome: ");
    char *cliente = ler_linha();
    if (!cliente) {
        fprintf(stderr, "erro leitura nome\n");
        free(carrinho);
        return 1;
    }

    int opc = 0;
    do {
        mostrar_menu();
        printf("cliente: %s\n", cliente);
        printf("opcao: ");
        if (scanf("%d", &opc) != 1) { printf("entrada invalida\n"); limpar_buffer(); continue; }
        limpar_buffer();
        switch (opc) {
            case 1: listar_produtos(produtos, precos, estoque); break;
            case 2: adicionar_ao_carrinho(carrinho, produtos, precos, estoque); break;
            case 3: ver_carrinho(carrinho, produtos, precos); break;
            case 4: finalizar_compra(carrinho, produtos, precos); break;
            case 5:
                printf("\n--- Estoque ---\n");
                printf("ID Nome                 Preco    Qtd  MinRep\n");
                for (int i = 0; i < NUM_PRODUTOS; i++) {
                    printf("%2d %-20s R$%6.2f %4d %6d\n", i+1, produtos[i], precos[i], estoque[i][0], estoque[i][1]);
                }
                printf("aperte ENTER\n");
                espera_enter();
                break;
            case 6: printf("saindo. bye\n"); break;
            default: printf("opcao invalida\n");
        }
    } while (opc != 6);

    free(carrinho);
    free(cliente);
    return 0;
}