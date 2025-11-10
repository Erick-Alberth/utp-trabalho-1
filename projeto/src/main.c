#include <stdio.h>

int main() {
    int opcao; //escolha do usuario
    int carrinho[8] = {0}; //quantidade de cada produto

    //vetores produtos e preços
    char produtos[8][20] = {"Arroz", "Feijao Preto", "Acucar", "Leite", "Macarrao", "Molho do Tomate", "Feijao Carioca", "Oleo de Soja"};

    float precos[8] = {5.99, 8.99, 4.99, 8.99, 3.49, 2.29, 7.69, 7.99};

    do { //repete o menu até o usuario escolher sair
        printf("==============================\n");
        printf("     SUPERMERCADO SS   \n");
        printf("==============================\n");

        printf("\n1- Ver Produtos Disponiveis\n");
        printf("2- Ver Meu Carrinho\n");
        printf("3- Finalizar Compra\n");
        printf("4- Sair\n");

        printf("\nEscolha Uma Opcao: ");
        scanf("%d", &opcao); // lê dados do teclado






        if(opcao == 1) {
            int escolha;

            printf("\n--- Produtos a Venda ---\n");

            for(int i = 0; i < 8; i++) {
                printf("%d. %s - R$ %.2f\n", i + 1, produtos[i], precos[i]);//numero. nome do produto. preço com 2 casas decimais
            }

            do {

                printf("\nDigite o numero do produto que deseja adicionar (0 para voltar): ");
                scanf("%d", &escolha); //numero do produto que quero comprar

                if (escolha >= 1 && escolha <=8) { //se o numero é valido

                    carrinho[escolha - 1]++;
                    printf("%s adicionado ao carrinho!\n", produtos[escolha - 1]);

                } else if (escolha == 0) {
                    printf("Voltando ao menu...\n");
                } else {
                    printf("Opcao Invalida!");
                }
            } while (escolha != 0);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else if(opcao == 2) {
            printf("\n--- Seu Carrinho de Compras ---\n");

            float totalGeral = 0.0; //valor total da compra
            int vazio = 1; //1=vazio;0=algum produto(flag sinalizador)

            for(int i = 0; i < 8; i++) {
                if(carrinho[i] > 0) {
                    float totalProduto = carrinho[i] * precos[i];
                    
                    printf("%s - %d unidade(s) - R$ %.2f\n", produtos[i], carrinho[i], totalProduto);
                    
                    totalGeral += totalProduto;
                    vazio = 0;
                }
            }

            if(vazio) {
                printf("Seu carrinho está vazio.\n");
            } else {
                printf("\nTotal da compra: R$ %.2f\n", totalGeral);
            }

            printf("\nPressione ENTER para voltar ao menu...");
            getchar(); getchar();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        } else if(opcao == 3) {
            printf("Sua Compra:\n");
        } else if (opcao == 4) {
            printf("Saindo do programa...\n");
        } else {
            printf("Opcao Invalida! Tente novamente.\n");
        }

    } while(opcao != 4);

    

    return 0;
}