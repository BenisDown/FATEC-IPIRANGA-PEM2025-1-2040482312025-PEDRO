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
#include <string.h>

void ListarDiretorio(const char *caminhos, int nivel);


int main() {
    const char *diretorioEscolhido = ".";
    printf("Escolha o diretório a ser mostrado: %s", diretorioEscolhido);
    return 0;
}

void MostrarCaminho(const char *caminhos, int nivel) {
    const char *caminhoEscolhido = abrirdir(caminhoEscolhido);
    struct direct *entrada;

    if (caminhoEscolhido= NULL){
        printf("Erro: o diretório escolhido não existe.");
        return;
    }

    while ((entrada = lerdir(caminhoEscolhido)) != NULL) {
        if (strcmp(entrada() ))
    }
}