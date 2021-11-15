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
list alocar(){
    return (malloc(sizeof(struct listNo)));
}

int vazia(list inicio){
    if(inicio == NULL)
        return 1;

    return 0;
}

void inserirPalavra(list *inicio, list *fim){

    list aux;
    aux = alocar();

    printf("\n\t--- Cadastro de Palavras ---\n\n");
    printf("\n\tPalavra:\n\t>");
    fflush(stdin);
    gets(aux->dicionario.palavra);
    printf("\n\tSignificado:\n\t>");
    fflush(stdin);
    gets(aux->dicionario.significado);

    if (vazia(*inicio)){
        *inicio = aux;
        *fim = aux;
        (*fim)->prox = NULL;
    }
    else{
        (*fim)->prox = aux;
        *fim = aux;
        (*fim)->prox = NULL;

    }
}

void listarPalavras(list auxiliar){
    if(vazia(auxiliar)){
        printf("\n\tDicionario Vazio!");
    }
    else{
        printf("\n\t-- Palavras e seus significados --\n");

        while (auxiliar != NULL){
            printf("\n\t%s: %s\n\n", auxiliar->dicionario.palavra, auxiliar->dicionario.significado);
            auxiliar = auxiliar->prox;
        }
    }
}

main(){
    int opcao;
    list inicio, fim;

    inicializar(&inicio, &fim);

    
    do{
        opcao = menu();

        switch (opcao){
        case 1:
            system("cls");
            inserirPalavra(&inicio, &fim);
            break;
        case 2:
            system("cls");
            listarPalavras(inicio);
            break;
        case 3:
            //pesquisar
        case 0:
            printf("\n\tSaindo..");
        default:
            printf("\n\tOpcao Invalida.");
        }
    }while(opcao!= 0);
}
