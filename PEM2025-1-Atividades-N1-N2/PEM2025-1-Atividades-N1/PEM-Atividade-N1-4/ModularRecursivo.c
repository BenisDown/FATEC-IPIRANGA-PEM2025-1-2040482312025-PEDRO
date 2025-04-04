/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Fazer uso de recursividade       *
* Data - 02/04/2025                                      * 
* Autor: Pedro Lucas Rocha Ferraz                        *
*--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void ListarDiretorio(const char *caminhos, int nivel);


int main() {
    const char *diretorioEscolhido = ".";
    printf("Escolha o diretório a ser mostrado: %s", diretorioEscolhido);
    return 0;
}

void listar_diretorios(const char *caminho, int nivel) {
    DIR *dir = opendir(caminho);
    struct dirent *entrada;

    if (dir == NULL) {
        printf("Erro ao abrir o diretorio: %s\n", caminho);
        return;
    }

    while ((entrada = readdir(dir)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }

        char caminho_completo[1024];
        snprintf(caminho_completo, sizeof(caminho_completo), "%s/%s", caminho, entrada->d_name);

        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }
        printf("%s\n", entrada->d_name);{

            listar_diretorios(caminho_completo, nivel + 1);
        }
    }

    closedir(dir);
}