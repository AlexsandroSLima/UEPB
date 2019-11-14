#include <stdio.h>
#include <windows.h>
int main(void) {
  system("color F8");
  while(1){
  system("color F8");
  //DECLARANDO AS VARIAVEIS PARA ARMAZENAR A OPCAO ESCOLHIDA
  int opcaoDigitada, numSeqTermos, numOpAritmetica1,numOpAritmetica2;
  int numeroDobras, dobradura = 4, potencia = 0;
  int contador, numFibonacci,seqFibonacci1=0, seqFibonacci2=1, numFiboAtual=1;
  float soma, subtracao, multiplicao, divisao;
  char carOperacao;
  printf("-----------------------------------------------------------------\n");
  printf("----------------------------- V.1.2 -----------------------------\n");
  printf("-----------------------------------------------------------------\n");
  //IMPRIMINDO NA TELA AS OPCOES DE ESCOLHA P/ O USUARIO
  printf("---     Sequencia de Fibonacci   (1)   --------------------------\n");
  printf("---     Sequencia de termos      (2)   --------------------------\n");
  printf("---     Operacoes aritmeticas    (3)   --------------------------\n");
  printf("---     Dobras                   (4)   --------------------------\n");
  printf("---     Sair do programa         (5)   --------------------------\n");
  printf("-----------------------------------------------------------------\n");
  printf("DIGITE A OPCAO DESEJADA:\n");
  printf("===> ");
  //LENDO A OPCAO DESEJADA COM O scanf
  scanf("%d", &opcaoDigitada);
  //UTILIZANDO O switch case PARA ENTRAR NA OPCAO ESCOLHIDA
  switch (opcaoDigitada)
  {

    ////CASO PARA A Sequência de Fibonacci
    case 1 :

      printf("Voce escolheu a Sequencia de Fibonacci!\n");
      printf("Digite um numero para continuar:\n");
      printf("===> ");

      //LENDO NUMERO PARA A SEQUENCIA
      scanf("%d", &numFibonacci);
      if(numFibonacci < 0){
        printf("NUMERO NEGATIVO!\n");
        break;
        } else{
            printf("A sequencia e:\n");
            printf("%d\n",seqFibonacci1);
            //LACO PARA SOMAR OS NUMEROS E ATUALIZAR
            for(contador=0;contador<numFibonacci;contador++){
              //IMPRIMINDO NA TELA O VALOR ATUALIZADO
              printf("%d\n", numFiboAtual );
              numFiboAtual = seqFibonacci1 + seqFibonacci2;
              seqFibonacci1 = seqFibonacci2;
              seqFibonacci2 = numFiboAtual;
              //QUANDO NUMERO DIGITADO < QUE O NUMERO DA SEQUENCIA
              //ENCERRA A EXECUCAO DO CODIGO
              if(numFibonacci < seqFibonacci1)
               break;
    }
        }
    system("pause");
    system("cls");
    break;


    ////CASO PARA A Sequência de termos
    case 2 :

      printf("Voce escolheu a Sequencia de termos!\n");
      printf("Digite um numero:\n");
      printf("===> ");
      //LENDO O NUMERO DIGITADO PELO USUARIO
      scanf("%d", &numSeqTermos);
      if(numSeqTermos < 0){
        printf("NUMERO NEGATIVO!\n");
        break;
        } else{
            //LACO PARA CALCULAR A SEQUENCIA DE TERMOS,ENQUANTO O NUMERO FOR MAIOR QUE 1
            while(numSeqTermos>1){
              //ESTRUTURA DE DECISAO PARA REALIZAR A OPERACAO
              if(numSeqTermos%2 == 0){
                numSeqTermos = numSeqTermos / 2;
              }else
              numSeqTermos = numSeqTermos * 3 + 1;
            //IMPRIMINDO VALOR FINAL DA SEQUENCIA DE TERMOS
            printf("-> %d\n",numSeqTermos);
          }
          }
          system("pause");
          system("cls");
          break;


    ////CASO PARA AS Operações aritméticas
    case 3 :

      printf("Voce escolheu as Operacoes aritmeticas!\n");
      printf("Digite o 1 numero:\n");
      printf("O operador: Soma (+) Subtracao (-) Multiplicao (*) Divisao (/)\n");
      printf("Digite o 2 numero:\n");
      printf("===> ");
      //LENDO O PRIMEIRO NUMERO, OPERADOR E SEGUND/O NUMERO
      scanf("%d %c %d",&numOpAritmetica1, &carOperacao,&numOpAritmetica2);

      //COMPARANDO A VARIAVEL DA OPERACAO AO NUMERO CORRESPONDENTE DA TABELA ASCII
      if(carOperacao == 43){
        //SOMANDO
        soma = numOpAritmetica1+numOpAritmetica2;
        //IMPRIMINDO NA TELA O RESULTADO
        printf("A soma e = %1.f\n",soma);
      }
      if(carOperacao == 45){
        //SUBTRAINDO
        subtracao = numOpAritmetica1 - numOpAritmetica2;
        //IMPRIMINDO NA TELA O RESULTADO
        printf("A subtracao e = %1.f\n",subtracao);
      }
      if(carOperacao == 42){
        //MULTIPLICANDO
        multiplicao = numOpAritmetica1 * numOpAritmetica2;
        //IMPRIMINDO NA TELA O RESULTADO
        printf("A multiplicao e = %1.f\n",multiplicao);
      }
      if(carOperacao == 47){
        //DIVIDINDO
        divisao = numOpAritmetica1 / numOpAritmetica2;
        //IMPRIMINDO NA TELA O RESULTADO
        printf("A divisao e = %1.f\n",divisao);
      }
      system("pause");
      system("cls");
      break;


    ////CASO PARA AS Dobras
    case 4 :

      printf("Voce escolheu as Dobras!\n");
      printf("Digite um numero para continuar: \n");
      printf("===> ");
      //LENDO VALOR PARA A OPERACAO
      scanf("%d",&numeroDobras);
      //ESTRUTURA DE SELECAO P/ NUMERO NEGATIVO
      if (numeroDobras < 0 ){
        printf("NUMERO NEGATIVO!\n");
        break;
        return 0;
      }
      //ESTRUTURA DE SELECAO P/ 1 CONDICAO
      //SENDO O ZERO COM UM VALOR FIXO
      if (numeroDobras == 0){
        printf("%d dobraduras\n",dobradura);
        system("pause");
        system("cls");
        break;
      }
      //ESTRUTURA DE SELECAO P/ 2 CONDICAO
      if (numeroDobras == 1){
        potencia = 3 * 3;
        printf ("%d dobraduras\n", potencia);
        system("pause");
        system("cls");
        break;
      }
      //ESTRUTURA DE SELECAO P/ 3 CONDICAO
      if (numeroDobras == 2){
        potencia = 5 * 5;
        printf ("%d dobraduras\n", potencia);
        system("pause");
        system("cls");
        break;
      }
      //ESTRUTURA DE SELECAO P/ 4 CONDICAO
      if (numeroDobras == 3) {
        potencia = 7 * 7;
        printf ("%d dobraduras\n", potencia);
        system("pause");
        system("cls");
        break;
      }
      //ESTRUTURA DE SELECAO P/ 5 CONDICAO
      if (numeroDobras == 4 ){
        potencia = 9 * 9;
        printf ("%d dobraduras\n", potencia);
        system("pause");
        system("cls");
        break;
      }
      //ESTRUTURA DE SELECAO P/ 6 CONDICAO
      if (numeroDobras == 5){
        potencia =  11 * 11;
        printf ("%d dobraduras\n", potencia);
        system("pause");
        system("cls");
        break;
      }
      //ESTRUTURA DE SELECAO P/ 7 CONDICAO
      if (numeroDobras == 6){
        potencia =  13 * 13;
        printf ("%d dobraduras\n", potencia);
        system("pause");
        system("cls");
        break;
      }
      //ESTRUTURA DE SELECAO P/ 8 CONDICAO
      if (numeroDobras == 7 ){
        potencia =  15 * 15;
        printf ("%d dobraduras\n", potencia);
        system("pause");
        system("cls");
        break;
      }

      system("pause");
      system("cls");
      break;

    //CASO PARA PARA sair do programa
    case 5 :
      printf("S");Sleep(150);
      printf("a");Sleep(150);
      printf("i");Sleep(150);
      printf("n");Sleep(150);
      printf("d");Sleep(150);
      printf("o...");Sleep(100);
      return 0;
      break;

    //SE FOR DIGITADO UM VALOR DIFERENTE SERA IMPRESSO A MENSAGEM
    default :
        system("color F4");
        printf("OPCAO INVALIDA! POR FAVOR, DIGITE O VALOR CORRESPONDENTE!\n");
        system("pause");
        system("cls");
        break;

  }
  }

  return 0;
}
