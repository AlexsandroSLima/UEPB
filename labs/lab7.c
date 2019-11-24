//laboratorio 7 pilhas encadeadas
//Alexsandro da Silva Lima

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void gotoxy(int cordX, int cordY){

   COORD c;
   c.X = cordX;
   c.Y = cordY;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//struct da pilha
typedef struct pilha{
 int top;
 int discos[3];
} Pilha;
//criando pilha
Pilha hannoi[3];
//limpa tela
void limpaTela(){
    system("cls");
}
//pausa tela
void pausa(){
    system("pause");
}
//limpa buffer
void limpaBuffer(){
    setbuf(stdin,NULL);
}
//Inicializa
void inicializa(Pilha *pilha){
   (*pilha).top=-1;
}
//Empilha
void push(Pilha *pilha, int disco){
   (*pilha).discos[++(*pilha).top]=disco;
}
//Desempilha
int pop(Pilha *pilha){
  return (*pilha).discos[((*pilha).top)--];
}
//Verifica topo
int pilhaSuperior(Pilha pilha){
   return pilha.discos[pilha.top];
}
//Retorna se cheia
int underflow(Pilha pilha){
   return pilha.top == 3-1;
}
int empilha(Pilha pilha){
   return pilha.top == -1;
}
//Funcoes do Jogo
inicio(Pilha hannoi[3]){
  int i= 0,j = 0;
  //Empilha
  push(hannoi,3);
  push(hannoi,2);
  push(hannoi,1);

  for(j=1;j<3;j++)
    for(i=0;i<3;i++){
       hannoi[j].discos[i]=0;
       }
}

fim(Pilha hannoi[3]){
   if((hannoi[2].discos[0]==3) && (hannoi[2].discos[1]==2) && (hannoi[2].discos[2]==1) ){
       return 1;
   }else
       return 0;
   }


imprime(Pilha hannoi[3]){

    char caracter = 254;
    int i = 0,j = 0, cord = 4;
    gotoxy(30,0);printf(" \t\tTorre de HANOI ");
    gotoxy(30,0.5);printf("\n*****************************************************************************************************");
    gotoxy(30,2.5);printf("\n-----------------------------------------------------------------------------------------------------");
    gotoxy(0,2);printf("  Pilha 1");
    gotoxy(0,cord++);
    for(j=hannoi[0].top; j>=0; j--){
        if(hannoi[0].discos[j] == 1){
           printf("   %c%c%c%c ",caracter, caracter, caracter, caracter);
           gotoxy(0,cord++);
        }
        if(hannoi[0].discos[j] == 2){
           printf("  %c%c%c%c%c%c",caracter, caracter, caracter, caracter, caracter, caracter);
           gotoxy(0,cord++);
        }
        if(hannoi[0].discos[j] == 3){
           printf(" %c%c%c%c%c%c%c%c",caracter, caracter, caracter, caracter, caracter, caracter, caracter, caracter);
           gotoxy(0,++cord);
        }
    }

    gotoxy(25,2);printf("  Pilha 2");
    cord=4;
    gotoxy(25,cord++);
    for(j=hannoi[1].top; j>=0; j--){
        if(hannoi[1].discos[j]== 1){
           printf("   %c%c%c%c    ",caracter, caracter, caracter,caracter);
           gotoxy(25,cord++);
        }
        if(hannoi[1].discos[j]== 2){
            printf("  %c%c%c%c%c%c",caracter, caracter, caracter, caracter, caracter, caracter);
            gotoxy(25,cord++);
        }
        if(hannoi[1].discos[j]== 3){
            printf(" %c%c%c%c%c%c%c%c ",caracter, caracter, caracter, caracter, caracter, caracter, caracter, caracter);
            gotoxy(25,++cord);
        }
      }

      gotoxy(50,2);printf("  Pilha 3");
      cord=4;
      gotoxy(50,cord++);
      for (j=hannoi[2].top; j>=0; j--){
        if(hannoi[2].discos[j]== 1){
            printf("   %c%c%c%c ",caracter, caracter, caracter,caracter);
            gotoxy(50,cord++);
        }
        if(hannoi[2].discos[j]== 2){
            printf("  %c%c%c%c%c%c  ",caracter, caracter, caracter, caracter, caracter, caracter);
            gotoxy(50,cord++);
        }
        if(hannoi[2].discos[j]== 3){
            printf(" %c%c%c%c%c%c%c%c ",caracter, caracter, caracter, caracter, caracter, caracter, caracter, caracter);
            gotoxy(50,++cord);
        }

     }
     gotoxy(0,8.5);printf("*****************************************************************************************************");
     gotoxy(50,9.8);printf(" Quantidade Minima de Jogadas = 7");

  }

int main(void){
        system("color 0A");
        int i = 0,jogadas = 0, pilhaRetira = 0,pilhaInsere = 0;
              //Iniciando as pilhas
              for(i=0;i<3;i++)
                 inicializa(hannoi+i);
              //Colocando os discos na 1° pilha
              inicio(hannoi);
        while(fim(hannoi)!=1){
          imprime(hannoi);
          gotoxy(0,9.8);printf("| Quantidade de Jogadas Realizadas = %d ", jogadas);
          gotoxy(30,10);printf("\n*****************************************************************************************************");
          gotoxy(20,12);printf("Mover o Disco da Pilha: ");
          limpaBuffer();
          scanf("%d",&pilhaRetira);
          gotoxy(0,13);

          if((pilhaRetira!=1)&&(pilhaRetira!=2)&&(pilhaRetira!=3)){
             printf("Jogada Invalida: Esta pilha nao existe!");
             pausa();
             limpaTela();
             continue;
           }
          gotoxy(20,13);printf("Mover Para a Pilha: ");
          limpaBuffer();
          scanf("%d",&pilhaInsere);

          if((pilhaInsere!=1)&&(pilhaInsere!=2)&&(pilhaInsere!=3) ){
             printf("jogada Invalida: Esta pilha nao existe! \n");
             pausa();
             limpaTela();
             continue;
           }

          jogadas++;

          if(empilha(hannoi[pilhaRetira-1])){
              printf("Jogada Invalida: Pilha Vazia\n");
              pausa();

          }else if(underflow(hannoi[pilhaInsere-1])){
             printf("Jogada Invalida: Pilha cheia!!! \n");
             pausa();

          }else if(hannoi[pilhaInsere-1].top == -1){
             push(hannoi+(pilhaInsere-1),pop( hannoi+(pilhaRetira-1)));

          }else if(hannoi[pilhaRetira-1].discos[hannoi[pilhaRetira-1].top]  > hannoi[pilhaInsere-1].discos[ hannoi[pilhaInsere-1].top]){
             printf("Jogada Invalida: Disco maior que o topo \n");
             pausa();

          }else
              push(hannoi+(pilhaInsere-1),pop( hannoi+(pilhaRetira-1)));

        limpaTela();
        }
        gotoxy(20,10);printf("FIM DE JOGO \n");

        if(jogadas == 7){
          gotoxy(20,11);printf("Parabens! Muito Bom!");
        }
        if((jogadas > 7) && (jogadas <= 10) ){
          gotoxy(20,11);printf("Bom!");
        }
        if(jogadas > 10){
          gotoxy(20,11);printf("Razoavel!");
        }
        gotoxy(20,12);printf("Voce realizou %d jogadas\n",jogadas);
        return 0;
        pausa();
   }
