#include <stdio.h>
#include <string.h>
#include <windows.h>
#define TAMANHO 30
#define TAMANHO2 60

int main(void) {

system("color F0");
//declarando variaveis
char nome[TAMANHO];
char significado[TAMANHO];
char frase[TAMANHO2];
int percString = 0, percSignificado = 0, auxiliar = 0, aux = 1,aux1 = 1;
char fraseFinal[TAMANHO2];
int primeiroloop = 0,segundoloop = 0, terceiroloop = 0, posicao = 0;

printf("------------------------------------------------------------------------------\n\n");
printf("******************************************************************************\n");
printf("********************** Dicionario Criptografado ******************************\n");
printf("******************************************************************************\n");
printf("********************************* V 1.0 **************************************\n");
printf("******************************************************************************\n");
printf("------------------------------------------------------------------------------\n");
printf("i");Sleep(100);printf("n");Sleep(100);printf("i");Sleep(100);printf("c");Sleep(100);
printf("i");Sleep(100);printf("a");Sleep(100);printf("n");Sleep(100);printf("d");Sleep(100);
printf("o...\n");Sleep(100);
printf("------------------------------------------------------------------------------\n");
       system("cls");
printf("------------------------------------------------------------------------------\n");
printf("S");Sleep(100);printf("e");Sleep(100);printf("j");Sleep(100);printf("a");Sleep(100);
printf(" ");Sleep(100);printf("b");Sleep(100);printf("e");Sleep(100);printf("m");Sleep(100);
printf(" ");Sleep(100);printf("v");Sleep(100);printf("i");Sleep(100);printf("n");Sleep(100);
printf("d");Sleep(100);printf("o");Sleep(100);printf("!");Sleep(100);
      system("cls");
printf("------------------------------------------------------------------------------\n");
printf("Quantas vezes voce deseja repetir?\n==> ");
//limpando buff do teclado
setbuf(stdin,NULL);
//lendo valor para primeiro loop
scanf("%d",&primeiroloop);
system("cls");
//primeiro loop
for(int i=0;i<primeiroloop;i++){
   printf("------------------------------------------------------------------------------\n");
   printf("Digite a quantidade de palavras e significados:\n==> ");
   //tratamento para que segundoloop seja >0 e <=100
   while(aux != 0){
     system("color F0");
     //limpando buff do teclado
     setbuf(stdin,NULL);
     //lendo valor para segundo loop
     scanf("%d",&segundoloop);

     if(segundoloop > 0 && segundoloop <= 100){
        aux = 0;
     }else{
      system("color F4");
      Sleep(500);
      system("cls");
      printf("\nValor digitado invalido!\npor favor digite novamente...\n\n");
      printf("Digite a quantidade de palavras e significados:\n==> ");

      aux = 1;
       }
   }
   //segundo loop
   for(int j=0;j<segundoloop;j++){
       printf("------------------------------------------------------------------------------\n");
       printf("Digite o nome e significado:\n");
       //limpando buff do teclado
       setbuf(stdin,NULL);
       //lendo a string nome
       gets(nome);

       //limpando buff do teclado
       setbuf(stdin,NULL);
       //lendo a string significado
       gets(significado);
       //percorrendo a string significado para ler seu tamanho
       percSignificado = strlen(significado);
   }
       printf("------------------------------------------------------------------------------\n");
       printf("Quantas frases voce deseja digitar?\n==> ");
   //tratamento para que terceiroloop seja >0 e <=100
   while(aux1 != 0){
       system("color F0");
       //limpando buff do teclado
       setbuf(stdin,NULL);
       //lendo valor para terceiro loop
       scanf("%d",&terceiroloop);

       if(terceiroloop > 0 && terceiroloop <= 100){
          aux1 = 0;
       }else{
           system("color F4");
           Sleep(500);
           system("cls");
           printf("\nValor digitado invalido!\npor favor digite novamente...\n\n");
           printf("Quantas frases voce deseja digitar?\n==> ");
           aux1 = 1;
       }
   }
   //terceiro loop
   for(int k=0;k<terceiroloop; k++){
       printf("------------------------------------------------------------------------------\n");
       printf("Digite a frase:\n==> ");
       //limpando buff do teclado
       setbuf(stdin,NULL);
       //lendo frase
       fgets(frase, sizeof(frase), stdin);
       //percorrendo a string frase para ler seu tamanho
       percString = strlen(frase);

   }
   //tratamento auxiliar
   if(percSignificado > percString){
        auxiliar = percSignificado;
    } else{
        auxiliar = percString;
    }

   for(int l = 0; l <= auxiliar ; l++){
        posicao = l;
        if(frase[l] != nome[posicao]){
           printf("iguais na posicao => %d\n", l);
           fraseFinal[l] = frase[posicao];
        }

        if(frase[l] == nome[posicao]|| frase[l] != '\0'){
           fraseFinal[l] = significado[posicao];
           printf("iguais l = %d ,posicao = %d\n", l,posicao);

        }
   }
    }
printf("------------------------------------------------------------------------------\n");

printf("%s\n",fraseFinal);

printf("------------------------------------------------------------------------------");
return 0;
}
