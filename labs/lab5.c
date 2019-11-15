#include <stdio.h>

//Declaracao do registro
struct {
 char nome[200];
 int numero;
 char grupo[10]
}agenda[15];





//Funcao Principal
int main(void){
 struct agenda;

 int valorDigitado,aux, i = 0, quantContatos = 0, op =0;
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
    setbuf(stdin,NULL);
    scanf("%d",&valorDigitado);
    switch(valorDigitado){
        case 1:

              system("cls");
              puts("--------------------------------------------------------");
              printf("Criar um contato - (1)\nVoltar - (2)\n");
              puts("--------------------------------------------------------");
              printf("Digite: ");
              setbuf(stdin,NULL);
              scanf("%d", &op);
              if(op == 1){
                      printf("\nInforme nome: ");
                      setbuf(stdin,NULL);
                      scanf("%[^\n]",agenda[i].nome);
                      printf("\nInforme telefone: ");
                      setbuf(stdin,NULL);
                      scanf("%d",&agenda[i].numero);
                      printf("\nInforme grupo: \n Familia \n Amigos \n Trabalho\n Estudos\n Colegas \n Outros\n");
                      setbuf(stdin,NULL);
                      scanf("%d",&agenda[i].grupo);
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
            printf("Alterar um dado do contato - (1) \nVoltar - (2)\n");
            puts("--------------------------------------------------------");
            printf("Digite: ");
            setbuf(stdin,NULL);
            scanf("%d", &op);
            if(op == 1){
                puts("--------------------------------------------------------");
                printf("\nInforme o id do contato que deseja alterar:");
                scanf("%d",&aux);
                printf("\nNome: %s",agenda[aux].nome);
                printf("\nInforme NOVO nome: ");
                scanf("%s",agenda[aux].nome);
                printf("\nTelefone: %d",agenda[aux].numero);
                printf("\nInforme NOVO telefone: ");
                scanf("%d",&agenda[aux].numero);
                break;
            }else
              break;
        case 3:
            system("cls");
            printf("Remover um contato\n");

        case 4:
            system("cls");
            puts("--------------------------------------------------------");
            printf("Listar contatos por nome\n");
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
                printf("\n------------------------------------------------------\n");
            }
            getchar();
            system("pause");
            system("cls");
            break;
        case 5:
            printf("Lista contatos de um grupo\n");
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            puts("--------------------------------------------------------");

            printf("Listar todos os contatos\n");

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
                printf("\n---------------------------------\n");
            }
            getchar();
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            puts("--------------------------------------------------------");
            printf("Quantidade de contatos\n");
            puts("--------------------------------------------------------");
            printf(" Quantidade de contatos %d\n\n", quantContatos);
            system("pause");
            system("cls");
            break;
        case 8:
            printf("saindo");
            break;
        default:

            printf("\nOpcao invalida\n");
            system("pause");
            system("cls");
            break;
    }
    }while(valorDigitado != 8);
return 0 ;
 }
