#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

typedef struct Dicionario{
    char palavra[SIZE];
    char significado[SIZE];
}Dicionario;

typedef struct listNo{
    Dicionario dicionario;
    struct listNo *prox;

}*list;


int menu(){
    int opcao;

    printf("\n\t--- Dicionario Pai dos Burros ---\n");
    printf("\n\t1. Adicionar uma palavra");
    printf("\n\t2. Listar palavras");
    printf("\n\t3. Pesquisar palavra");
    printf("\n\t0. Sair");
    printf("\n\n\tEscolha uma opcao:\n\t>");
    scanf("%d", &opcao);
    
    return opcao;
}

void inicializar(list *inicio, list *fim){
    *inicio = NULL;
    *fim = NULL;
}

main(){
    int opcao;
    list inicio, fim;

    inicializar(&inicio, &fim);

    opcao = menu();

    switch (opcao){
    case 1:
        //cadastro
        break;
    case 2:
        // listar
        break;
    case 3:
        //pesquisar
    case 0:
        printf("\n\tSaindo..");
    default:
        printf("\n\tOpcao Invalida.");
    }
}