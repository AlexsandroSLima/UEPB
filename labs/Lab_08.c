#include <stdio.h>
#include <stdlib.h>
#ifndef FILA_HEADER
#define FILA_HEADER
#endif

typedef struct pessoa PESSOA;
typedef struct elemento ELEM;
typedef struct controlador FILA;

struct pessoa{
    char senha[31];
    int pos;
};
struct elemento{
    PESSOA dado;
    ELEM *prox;
};

struct controlador{
    ELEM *inicio;
    ELEM *fim;
};

FILA* criarFila(){
    FILA *f = (FILA*)malloc(sizeof(FILA));
    if(f!=NULL){
        f->inicio=NULL;
        f->fim=NULL;
    }
    return f;
}
void pessoaFila(ELEM *e){
    static int aux = 1;
    printf("Digite o senha: ");
    setbuf(stdin,NULL);
    gets(e->dado.senha);
    e->dado.pos=aux++;
}
void inserirElemento(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *novoElemento = (ELEM*)malloc(sizeof(ELEM));
        if(novoElemento!=NULL){
            pessoaFila(novoElemento);
            novoElemento->prox=NULL;
            if(fila->inicio==NULL){
                fila->inicio=novoElemento;
            }else{
                fila->fim->prox=novoElemento;
            }
            fila->fim=novoElemento;
        }else{
            printf("\nELEMENTO NAO INSERIDO\n");
        }
    }
}
void removerElemento(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
            fila->inicio=fila->inicio->prox;
            free(aux);
            if(fila->inicio==NULL){
                fila->fim=NULL;
            }
        }
    }
}
void limpaTela(){
 system("cls");
}

void mostrarFila(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
           while(aux!=NULL){
                puts(aux->dado.senha);
                printf("Posicao: %d\n",aux->dado.pos);

                aux=aux->prox;
           }
        }else{
            printf("FILA VAZIA\n");
        }
    }
}

void liberarFila(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
           while(aux!=NULL){
                fila->inicio=aux->prox;
                free(aux);
                aux=fila->inicio;
           }
           free(fila);
        }
    }
}
int menu(){
    int op;
    puts("==========================================================================================");
    printf("\t\tFila de Banco\n");
    puts("==========================================================================================");
    printf("\n1 - INSERIR SENHA\n");
    printf("2 - MOSTRAR SENHAS\n");
    printf("3 - REMOVER SENHAS\n");
    printf("4 - SAIR\n");
    printf("\nOPCAO: ");
    scanf("%d",&op);
    return op;
}
int main(void){
    FILA *fi = criarFila();
    int aux;
    while((aux=menu())!=4){
        switch(aux){
        case 1:
            limpaTela();
            puts("==========================================================================================");
            inserirElemento(fi);
            mostrarFila(fi);
            break;
        case 2:
            limpaTela();
            puts("==========================================================================================");
            mostrarFila(fi);
            break;
        case 3:
            limpaTela();
            puts("==========================================================================================");
            removerElemento(fi);
            mostrarFila(fi);
            break;

        default:
            printf("OPCAO INVALIDA\n\n");
        }
        printf("\n\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n\n");
        setbuf(stdin,NULL);
        getchar();
        limpaTela();
    }
    liberarFila(fi);
    return 0;
}
