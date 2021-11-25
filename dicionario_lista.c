#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

typedef struct Dicionario{
    char palavra[30];
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
    printf("\n\t4. Remover palavra");
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
            printf("\n\t%s:\n\t%s\n\n", auxiliar->dicionario.palavra, auxiliar->dicionario.significado);
            auxiliar = auxiliar->prox;
        }
    }
}

void pesquisarPalavra(list auxiliar, char palavra[30]){
    int found = 0;

    while (auxiliar!=NULL){
        if(strcmp(auxiliar->dicionario.palavra , palavra) == 0){
            printf("\n\t%s:\n\t%s.", auxiliar->dicionario.palavra, auxiliar->dicionario.significado);
            found= 1;
        }
        auxiliar = auxiliar->prox;
    }
    if(found == 0){
        printf("\n\tPalavra nao encontrada!\n");
    }
    return menu();
}

void removerPalavra(list *inicial, list *final, char palavra[30]) {
    list auxiliar, anterior;
    int found = 0;

    anterior = NULL;
    auxiliar = *inicial;

    while(auxiliar != NULL) {
        if (strcmp(auxiliar->dicionario.palavra, palavra) == 0) {
            found = 1;
            auxiliar = auxiliar->prox;
            if (anterior == NULL) {
                free(*inicial);
                *inicial = auxiliar;
            } else {
                free(anterior->prox);
                anterior->prox = auxiliar;
            }
        } else {
            anterior = auxiliar;
            auxiliar = auxiliar->prox;
        }
    }
    return menu;
}

main(){

    int opcao;
    list inicio, fim;
    char pesquisa[30], palavraRemovida[30];
    
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
            system("cls");
            printf("\n\tInforme a palavra: ");
            fflush(stdin);
            gets(pesquisa);
            pesquisarPalavra(inicio, pesquisa);
        break;
        case 4:
            system("cls");
            printf("\n\tPalavra que sera removida: ");
            fflush(stdin);
            gets(palavraRemovida);

            if(vazia(inicio)) {
                printf("\n\tDicionario vazio\n\n");
            } else {
                removerPalavra(&inicio, &fim, palavraRemovida);
                printf("\n\tPalavra removida com sucesso!\n");
            }   
        break;
        case 0:
            printf("\n\tSaindo..");
        default:
            printf("\n\tOpcao Invalida.");
        }
    }while(opcao != 0);
}
