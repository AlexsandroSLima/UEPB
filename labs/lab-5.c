#include <stdio.h>
#include <ctype.h>

//Declaracao do registro
 struct {
 char nome[200];
 int numero;
 char grupo[50]
}agenda[50];


//Funcao Principal
int main(void){
 struct agenda;

 int valorDigitado,aux, i = 0, quantContatos = 0, op =0, op1 = 0;
 //estrutura de repeticao
 do{
    system("color f8");
    system("cls");
    puts("--------------------------------------------------------");
    printf("\t\t  Agenda Telefonica \n");
    puts("--------------------------------------------------------");
    printf("\n| Criar um contato ------------ (1)");
    printf("\n| Alterar um dado do contato -- (2)\n| *Remover um contato ---------- (3)\n| Listar contatos por nome ---- (4)");
    printf("\n| *Listar contatos de um grupo - (5)\n| Listar todos os contatos ---- (6)\n| Quantidade de contatos ------ (7)");
    printf("\n| Sair ------------------------ (8)");
    puts("\n\n--------------------------------------------------------");

    printf("Digite a opcao desejada: ");
    //limpando buffer do teclado
    setbuf(stdin,NULL);
    scanf("%d",&valorDigitado);
    switch(valorDigitado){
        case 1:

              system("cls");
              puts("--------------------------------------------------------");
              printf("| Criar um contato - (1)\n| Voltar - (2)\n");
              puts("--------------------------------------------------------");
              printf("Digite: ");
              //limpando buffer do teclado
              setbuf(stdin,NULL);
              scanf("%d", &op);
              //esstrutura de condicao para continuar ou voltar
              if(op == 1){
                      system("cls");
                      printf("\nInforme nome: ");
                      //limpando buffer do teclado
                      setbuf(stdin,NULL);
                      scanf("%[^\n]",agenda[i].nome);
                      printf("Informe telefone: ");
                      //limpando buffer do teclado
                      setbuf(stdin,NULL);
                      scanf("%d",&agenda[i].numero);
                      puts("--------------------------------------------------------\n");
                      printf("| Grupos: \n");
                      puts("-------------");
                      printf("\n| Familia \n| Amigos \n| Trabalho \n| Estudos \n| Colegas \n| Outros \n");
                      puts("--------------------------------------------------------");
                      printf("Informe o grupo: ");
                      //limpando buffer do teclado
                      setbuf(stdin,NULL);
                      scanf("%[^\n]",strlwr(agenda[i].grupo));

                      quantContatos++;
                      i++;
                      printf("Contato salvo...\n");
                      system("pause");
                      break;
              }else
                 break;
        case 2:
            system("cls");
            puts("--------------------------------------------------------");
            printf("| Alterar um dado do contato - (1) \n| Voltar - (2)\n");
            puts("--------------------------------------------------------");
            printf("Digite: ");
            //limpando buffer do teclado
            setbuf(stdin,NULL);
            scanf("%d", &op);
            if(op == 1){
                puts("--------------------------------------------------------");
                printf("\nInforme o id do contato que deseja alterar:");
                //limpando buffer do teclado
                setbuf(stdin,NULL);
                scanf("%d",&aux);

                printf("\nNome: %s",agenda[aux].nome);
                printf("\nInforme NOVO nome: ");
                //limpando buffer do teclado
                setbuf(stdin,NULL);
                scanf("%[^\n]",agenda[aux].nome);

                printf("\nTelefone: %d",agenda[aux].numero);
                printf("\nInforme NOVO telefone: ");
                //limpando buffer do teclado
                setbuf(stdin,NULL);
                scanf("%d",agenda[aux].numero);

                printf("\nGrupo: %s",agenda[aux].grupo);
                printf("\nInforme NOVO grupo: ");
                //limpando buffer do teclado
                setbuf(stdin,NULL);
                scanf("%[^\n]",agenda[aux].grupo);

                break;
            }else
              break;
        case 3:
            system("cls");
            puts("--------------------------------------------------------");
            printf("| Remover um contato -- (1)\n| Voltar -- (2)\n");
            puts("--------------------------------------------------------");
            printf("Digite: ");
            //limpando buffer do teclado
            setbuf(stdin,NULL);
            scanf("%d", &op);
            if(op == 1){
                printf("\nInforme o id do contato que deseja remover: ");
                //limpando buffer do teclado
                setbuf(stdin,NULL);
                scanf("%d",&aux);
                printf("\nNome: %s",agenda[aux].nome);
                printf("\nTelefone: %d\n",agenda[aux].numero);
                printf("\nGrupo: %s\n",agenda[aux].grupo);
                puts("--------------------------------------------------------");
                printf("| Confirmar -- (1)\n| Voltar -- (2)\n");
                printf("Digite: ");
                //limpando buffer do teclado
                setbuf(stdin,NULL);
                scanf("%d", &op1);
                if(op1 == 1){

                       agenda[aux].numero = 0;
                       printf("Contato removido\n");
                       system("pause");
                       system("cls");
                       break;
                }
                system("pause");
                system("cls");
                break;

            }else
              break;

        case 4:
            system("cls");
            puts("--------------------------------------------------------");
            printf("| Listar contatos por nome\n");
            for(i=0;i<50;i++){
                if(agenda[0].numero == 0 ){
                   puts("--------------------------------------------------------");
                   printf(" Lista Vazia!\n\n");
                   break;
                }if(agenda[i].numero == 0)
                   break;

                printf("\nID: %d",i);
                printf("\nNome: %s",agenda[i].nome);
                printf("\nTelefone: %d",agenda[i].numero);
                printf("\nGrupo: %s",agenda[i].grupo);
                printf("\n------------------------------------------------------\n");
            }
            getchar();
            system("pause");
            system("cls");
            break;
        case 5:
            printf("| Lista contatos de um grupo\n");
            printf("\nInforme grupo: \n| Familia \n| Amigos \n| Trabalho\n| Estudos\n| Colegas| \n| Outros\n");

            printf("\nTelefone: %s",agenda[i].grupo);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            puts("--------------------------------------------------------");

            printf("| Listar todos os contatos\n");

            for(i=0;i<50;i++){
                if(agenda[0].numero == 0){
                   puts("--------------------------------------------------------");
                   printf(" Lista Vazia!\n\n");
                   break;
                }if(agenda[i].numero == 0)
                   break;
                printf("\nID: %d",i);
                printf("\nNome: %s",agenda[i].nome);
                printf("\nTelefone: %d",agenda[i].numero);
                printf("\nGrupo: %s",agenda[i].grupo);
                printf("\n---------------------------------\n");
            }
            getchar();
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            puts("--------------------------------------------------------");
            printf("|Quantidade de contatos\n");
            puts("--------------------------------------------------------");
            printf(" Quantidade de contatos %d\n\n", quantContatos);
            system("pause");
            system("cls");
            break;
        case 8:
            printf("Saindo...");
            break;
        default:

            printf("\n Opcao invalida\n");
            system("pause");
            system("cls");
            break;
    }
    }while(valorDigitado != 8);
return 0 ;
 }
