#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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

FILA* criaFila(){
    FILA *f = (FILA*)malloc(sizeof(FILA));
    if(f!=NULL){
        f->inicio=NULL;
        f->fim=NULL;
    }
    return f;
}
void pessoaFila(ELEM *e){
    static int aux = 1;
    int opc = 0;

    gotoxy(10,2);puts("====================================");
    gotoxy(10,3);printf(" Opcional -----> (1)");
    gotoxy(10,4);printf(" Prioritaria --> (2)");
    gotoxy(10,5);puts("====================================");
    printf("Digite:");
    scanf("%d", &opc);
    if(opc == 1){
        printf("\nDigite a senha Opcional: ");
        setbuf(stdin,NULL);
        gets(e->dado.senha);
        e->dado.pos=aux++;

    }else{
        printf("\nDigite a senha Prioritaria: ");
        setbuf(stdin,NULL);
        gets(e->dado.senha);
        e->dado.pos=aux++;
    }

}
void inseriElemento(FILA *fila){
    if(fila==NULL){
        printf("\nFila nao Alocada\n");
    }else{
        ELEM *novoElemento = (ELEM*)malloc(sizeof(ELEM));
        if(novoElemento!=NULL){
            pessoaFila(novoElemento);
            novoElemento->prox=NULL;
            if(fila->inicio==NULL){
                fila->inicio=novoElemento;
            }else
                fila->fim->prox=novoElemento;

            fila->fim=novoElemento;
        }else{
            printf("\nElemento nao Inserido\n");
        }
    }
}
void removeElemento(FILA *fila){
    if(fila==NULL){
        printf("\nFila nao Alocada\n");
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

void mostraFila(FILA *fila){
    if(fila==NULL){
        printf("\nFila nao Alocada\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
           while(aux!=NULL){
                puts(aux->dado.senha);
                printf("Posicao %d\n",aux->dado.pos);
                aux=aux->prox;
           }
        }else{
            printf("Fila Vazia\n");
        }
    }
}

void liberaFila(FILA *fila){
    if(fila==NULL){
        printf("\nFila nao Alocada\n");
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
void gotoxy(int x, int y) {
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
int menu(){
    int op;
    gotoxy(10,2);puts("====================================");
    gotoxy(26,3);printf("Fila \n");
    gotoxy(10,4);puts("====================================");
    gotoxy(10,5);printf("|     INSERIR PESSOA --> (1)       |\n");
    gotoxy(10,6);printf("|     MOSTRAR SENHAS --> (2)       |\n");
    gotoxy(10,7);printf("|     REMOVER SENHAS --> (3)       |\n");
    gotoxy(10,8);printf("|     SAIR ------------> (4)       |\n");
    gotoxy(10,9);puts("====================================");
    gotoxy(1,11);printf(" Digite a opcao desejada\n ==> ");
    scanf("%d",&op);
    return op;
}
int main(void){
    system("color 70");
    FILA *fila = criaFila();
    int aux;
    while((aux=menu())!=4){
      switch(aux){
        case 1:
            limpaTela();
            inseriElemento(fila);
            mostraFila(fila);
            break;
        case 2:
            limpaTela();
            mostraFila(fila);
            break;
        case 3:
            limpaTela();
            removeElemento(fila);
            mostraFila(fila);
            break;
        default:
            printf("Opcao Invalida\n\n");
        }
    system("pause");
    limpaTela();
    }
    liberaFila(fila);
    return 0;
}
