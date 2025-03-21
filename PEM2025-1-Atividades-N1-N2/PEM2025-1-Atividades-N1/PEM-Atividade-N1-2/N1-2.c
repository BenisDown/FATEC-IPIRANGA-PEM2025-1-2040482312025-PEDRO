#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    Atividade 2: Vetor multidimensional
    Criador: Pedro Lucas Rocha Ferraz
    Data: 06/03/2025
*/

#define NUM_RUAS 3
#define NUM_POSICOES 10
#define MAX_COD 20

int ruaIndice (char rua) {
    switch (toupper(rua))
    {
        case 'A': return 0;
        break;
        
        case 'B': return 1;
        break;
        
        case 'C': return 2;
        break;

        default: return -1;
        break;
    }
}

char indiceRua(int i) {
    if (i == 0) return 'A';
    if (i == 1) return 'B';
    if (i == 2) return 'C';
    return '?';
}

int buscarProduto(char estoque[NUM_RUAS][NUM_POSICOES][MAX_COD],
    const char *codigoProduto,
    int *indiceRuaEncontrada,
    int *indicePosicaoEncontrada) 
{
    for (int indiceRua = 0; indiceRua < NUM_RUAS; indiceRua++) {
        for (int indicePosicao = 0; indicePosicao < NUM_POSICOES; indicePosicao++) {
            if (strcmp(estoque[indiceRua][indicePosicao], codigoProduto) == 0) {
                *indiceRuaEncontrada = indiceRua;
                *indicePosicaoEncontrada = indicePosicao;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char estoque[NUM_RUAS][NUM_POSICOES][MAX_COD];
    for (int r = 0; r < NUM_RUAS; r++) {
        for (int p = 0; p < NUM_POSICOES; p++) {
            estoque[r][p][0] = '\0';
        }
    }

    int opcao;
    do {
        printf("\n========================================\n");
        printf("         GESTAO DE ESTOQUE (3D)         \n");
        printf("========================================\n");
        printf("1 - Estocar Produto\n");
        printf("2 - Retirar Produto\n");
        printf("3 - Mostrar Estoque\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        if (opcao == 1) {
            // Estocar produto
            char codigo[MAX_COD];
            printf("\nDigite o codigo do produto (ex: S123): ");
            fgets(codigo, sizeof(codigo), stdin);
            // Remover eventual '\n' do final
            codigo[strcspn(codigo, "\n")] = '\0';

            // Verificar se o produto já existe no estoque
            int ruaE, posE;
            if (buscarProduto(estoque, codigo, &ruaE, &posE)) {
                // Produto já armazenado em alguma posição
                printf("O produto %s ja esta armazenado na Rua %c, Posicao %d.\n",
                    codigo, indiceRua(ruaE), posE + 1);
            } else {
                // Produto ainda nao existe, precisamos estocar
                printf("Produto %s nao encontrado. Informe onde deseja estocar.\n", codigo);
                
                char ruaChar;
                int posicao;
                printf("Digite a Rua (A, B ou C): ");
                scanf(" %c", &ruaChar);
                printf("Digite a Posicao (1..10): ");
                scanf("%d", &posicao);

                int indiceRua = ruaIndice(ruaChar);
                int indicePos = posicao - 1; // pois internamente usamos 0..9

                if (indiceRua < 0 || indiceRua > 2 || indicePos < 0 || indicePos > 9) {
                    printf("Entrada de rua/posicao invalida.\n");
                } else {
                    if (estoque[indiceRua][indicePos][0] == '\0') {
                        // Está vazio, podemos estocar
                        strcpy(estoque[indiceRua][indicePos], codigo);
                        printf("Produto %s estocado em Rua %c, Posicao %d.\n",
                            codigo, toupper(ruaChar), posicao);
                    } else {
                        printf("A posicao Rua %c, Posicao %d ja esta ocupada pelo produto %s.\n",
                            toupper(ruaChar), posicao, estoque[indiceRua][indicePos]);
                    }
                }
            }

        } else if (opcao == 2) {
            // Retirar produto
            char codigo[MAX_COD];
            printf("\nDigite o codigo do produto a retirar: ");
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = '\0';

            int ruaE, posE;
            if (buscarProduto(estoque, codigo, &ruaE, &posE)) {
                // Se encontrado, "remove" (limpa)
                estoque[ruaE][posE][0] = '\0';
                printf("Produto %s foi retirado do estoque (Rua %c, Posicao %d).\n",
                    codigo, indiceRua(ruaE), posE + 1);
            } else {
                printf("Produto %s nao encontrado no estoque.\n", codigo);
            }

        } else if (opcao == 3) {
            // Mostrar estoque
            printf("\n--- ESTOQUE ATUAL ---\n");
            for (int r = 0; r < NUM_RUAS; r++) {
                for (int p = 0; p < NUM_POSICOES; p++) {
                    if (estoque[r][p][0] != '\0') {
                        printf("Rua %c, Posicao %d -> %s\n",
                            indiceRua(r), p + 1, estoque[r][p]);
                    }
                }
            }
            printf("----------------------\n");

        } else if (opcao == 4) {
            printf("\nSaindo do programa...\n");
        } else {
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}