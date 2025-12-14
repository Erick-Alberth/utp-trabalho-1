#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUTOS 5 // qtd produtos
#define TAM_NOME 30 // qtd caracteres

// FUNÇÕES AUXILIARES

void limpar_buffer() { // limpa lixo do scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void pausa() { // pausar tela ate o enter
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// FUNÇÕES DO SISTEMA

void mostrar_menu() {
    printf("\n=============================\n");
    printf(" SUPERMERCADO SS\n");
    printf("=============================\n");
    printf("1 - Listar produtos\n");
    printf("2 - Adicionar ao carrinho\n");
    printf("3 - Ver carrinho\n");
    printf("4 - Finalizar compra\n");
    printf("5 - Sair\n");
}



void listar_produtos(char nomes[][TAM_NOME], float precos[], int estoque[][2]) {
    printf("\n--- Produtos Disponiveis ---\n");
    
    for (int i = 0; i < PRODUTOS; i++) {
        printf("%d - %s | R$ %.2f | Estoque: %d\n",
               i + 1, nomes[i], precos[i], estoque[i][0]);
    }
}



void adicionar_carrinho(int *carrinho,
                        char nomes[][TAM_NOME],
                        float precos[],
                        int estoque[][2]) { // ponteiro para alterar fora da função
    int op, qtd;

    listar_produtos(nomes, precos, estoque); // listar reutilizado

    printf("\nEscolha o produto: ");
    scanf("%d", &op);// ler o numero, endereço da variavel
    limpar_buffer(); //evita erro de leitura
//////////////////////////////////////////////////////////////////
    if (op < 1 || op > PRODUTOS) {
        printf("Produto invalido\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &qtd);
    limpar_buffer();
//////////////////////////////////////////////////////////////////
    if (qtd <= 0 || qtd > estoque[op - 1][0]) {
        printf("Quantidade invalida\n");
        return;
    }

    carrinho[op - 1] += qtd;
    estoque[op - 1][0] -= qtd;

    printf("%d unidade(s) de %s adicionada(s)\n",
           qtd, nomes[op - 1]);
}



void ver_carrinho(int *carrinho,
                  char nomes[][TAM_NOME],
                  float precos[]) {
    float total = 0;
    int vazio = 1;

    printf("\n--- Seu Carrinho ---\n");

    for (int i = 0; i < PRODUTOS; i++) {
        if (carrinho[i] > 0) {
            float subtotal = carrinho[i] * precos[i];
            printf("%s - %d un - R$ %.2f\n",
                   nomes[i], carrinho[i], subtotal);
            total += subtotal;
            vazio = 0;
        }
    }

    if (vazio) {
        printf("Carrinho vazio\n");
    } else {
        printf("Total: R$ %.2f\n", total);
    }
}



void finalizar_compra(int *carrinho,
                      char nomes[][TAM_NOME],
                      float precos[]) {
    float total = 0;

    printf("\n--- Finalizando Compra ---\n");

    for (int i = 0; i < PRODUTOS; i++) {
        if (carrinho[i] > 0) {
            total += carrinho[i] * precos[i];
            carrinho[i] = 0;
        }
    }

    printf("Compra finalizada\n");
    printf("Total pago: R$ %.2f\n", total);
}

/* ---------- MAIN ---------- */

int main() {
    char produtos[PRODUTOS][TAM_NOME] = {
        "Arroz", "Feijao", "Leite", "Macarrao", "Oleo"
    };

    float precos[PRODUTOS] = {5.99, 7.49, 4.89, 3.29, 7.99};

    /* matriz:estoque e minimo */
    int estoque[PRODUTOS][2] = {
        {10, 2}, {8, 2}, {12, 3}, {15, 4}, {6, 2}
    };

    int *carrinho = malloc(PRODUTOS * sizeof(int));
    if (carrinho == NULL) {
        printf("Erro de memoria\n");
        return 1;
    }

    for (int i = 0; i < PRODUTOS; i++) {
        carrinho[i] = 0;
    }

    int opcao;

    do {
        mostrar_menu();
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                listar_produtos(produtos, precos, estoque);
                pausa();
                break;
            case 2:
                adicionar_carrinho(carrinho, produtos, precos, estoque);
                pausa();
                break;
            case 3:
                ver_carrinho(carrinho, produtos, precos);
                pausa();
                break;
            case 4:
                finalizar_compra(carrinho, produtos, precos);
                pausa();
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 5);

    free(carrinho);
    return 0;
}
