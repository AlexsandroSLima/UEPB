//Projeto Final Alexsandro da Silva Lima
//Graduando em Ciencia da Computacao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
int main(void){
    system("color F8");
    while(1){
    system("color F8");
    char name[50][50], cpf[50][50];
    char congressista[50][50],palestrante[50][50],organizador[50][50];
    //usuario administrador padrao   //senha padrao
    char loginPadrao[15] = "admin" , senhaPadrao[15] = "admin";
    char login1[15], senha1[15], login[15], senha[15];
    int i = 0,j = 0, aux = 1, aux1 = 1, aux2 = 1, aux3 = 1;
    int quant = 0, opcaoDigitada = 0,opcaoDigitada2 = 0,usuario = 0;
    //arquivos
    FILE *palestrantes;
    FILE *congressistas;
    FILE *organizadores;
    FILE *arquivo;

    while(aux2 != 0){
        puts("-----------------------------------------------------------------------------------------------------");
        puts("                                      ENCEC 2019 ");
        puts("-----------------------------------------------------------------------------------------------------");
        puts("            Digite o usuario seguido de [ENTER] para continuar...");
        puts("-----------------------------------------------------------------------------------------------------");
        printf("----------| LOGIN: ");
        gets(login1);
        system("cls");
        if(strlen(login1) > 0 ){
            aux2 = 0;
        }//chave do if

        }//chave do while

    while(aux1 != 0){
        //puts("-----------------------------------------------------------------------------------------------------");
        printf("----------| SENHA: ");
        gets(senha1);


        //login do administrador
        if(strcmp(loginPadrao, login1) == 0 || strcmp(login, login1) == 0)
           if(strcmp(senhaPadrao, senha1) == 0 || strcmp(senha, senha1) == 0){
            puts("-----------------------------------------------------------------------------------------------------");
            printf(" Seja bem vindo administrador!\n");
            puts("-----------------------------------------------------------------------------------------------------");
            aux1 = 0;
                while(opcaoDigitada != 4){
                puts("-----------------------------------------------------------------------------------------------------");
                printf(" Novo cadastro ------> (1)\n Buscar cadastro ----> (2)\n Alterar cadastro ---> (3)\n Sair  --------------> (4)\n==> ");
                setbuf(stdin,NULL);
                scanf("%d", &opcaoDigitada);

                switch(opcaoDigitada){

                    //cadastro de usuarios
                    case 1:
                            system("cls");
                            puts("-----------------------------------------------------------------------------------------------------");
                            printf("Novo Cadastro:\n");
                            printf(" Quantos pessoas deseja cadastrar? \n==> ");
                            scanf("%d", &quant);
                            //tratamento para dado incorreto digitado pelo usuario
                            while(aux != 0){
                              puts("-----------------------------------------------------------------------------------------------------");
                              printf(" Voce deseja cadastrar: \n Congressista ---> (1)\n Palestrante ----> (2)\n Organizador ----> (3) \n==> ");
                              //lendo tipo de usuario
                              setbuf(stdin,NULL);
                              scanf("%d", &usuario);
                              switch(usuario){
                                case 1:
                                    aux = 0;
                                    system("cls");
                                    break;
                                case 2:
                                    aux = 0;
                                    system("cls");
                                    break;
                                case 3:
                                    aux = 0;
                                    system("cls");
                                    break;
                                default :
                                    aux = 1;
                                    puts("-----------------------------------------------------------------------------------------------------");
                                    printf("OPCAO INVALIDA! POR FAVOR, DIGITE O VALOR CORRESPONDENTE!\n");
                                    system("pause");
                                    system("cls");
                                    break;
                            }
                            }






                            for(i=0;i<quant;i++){
                                puts("-----------------------------------------------------------------------------------------------------");
                                printf(" Digite nome: ");
                                fflush(stdin);
                                gets(name[i]);


                                printf(" Digite CPF: ");
                                fflush(stdin);
                                gets(cpf[i]);



                            }


                            printf("\n-------------------------------------------------------------------------------\n");

                            if(usuario == 1){
                                congressistas=fopen("congressistas.txt","a");
                                for(i=0;i<quant;i++){
                                    fprintf(congressistas,"%s\n",name[i]);
                                    fprintf(congressistas,"%s\n",cpf[i]);
                                }
                                fclose(congressistas);
                                printf(" CADASTRO REALIZADO COM SUCESSO\n");
                                system("pause");
                                system("cls");
                            }
                            if(usuario == 2){
                                palestrantes=fopen("palestrantes.txt","a");
                                for(i=0;i<quant;i++){
                                    fprintf(palestrantes,"%s\n",name[i]);
                                    fprintf(palestrantes,"%s\n",cpf[i]);
                                }
                                fclose(palestrantes);
                                printf(" CADASTRO REALIZADO COM SUCESSO!\n");
                                system("pause");
                                system("cls");
                            }
                            if(usuario == 3){
                                organizadores=fopen("organizadores.txt","a");
                                for(i=0;i<quant;i++){
                                    fprintf(organizadores,"%s\n",name[i]);
                                    fprintf(organizadores,"%s\n",cpf[i]);
                                }
                                fclose(organizadores);
                                printf(" CADASTRO REALIZADO COM SUCESSO!\n");
                                puts("-----------------------------------------------------------------------------------------------------");
                                system("pause");
                                system("cls");
                            }

                            break;


                    case 2:
                       system("cls");
                       puts("-----------------------------------------------------------------------------------------------------");
                       printf("Buscar Cadastro:\n");
                       congressistas=fopen("congressistas.txt","r");
                       if(congressistas==NULL){
                            printf("Erro No Arquivo");
                            exit(1);
                            }
                       i=0;
                       while( fgets(name[i],sizeof(name[i]),congressistas)!=NULL && fgets(cpf[i],sizeof(cpf[i]),congressistas)!=NULL )
                       {
                            name[i][strlen(name[i])-1]='\0';


                            cpf[i][strlen(cpf[i])-1]='\0';

                            i++;
                        }
                        fclose(congressistas);
                        printf("\n\n");
                        for(i=0;i<quant;i++)
                        {
                            printf("Nome ------> %s\n",name[i]);
                            printf("cpf -------> %s\n\n",cpf[i]);
                        }
                       system("pause");
                       system("cls");
                       break;
                    //SE FOR DIGITADO UM VALOR DIFERENTE SERA IMPRESSO A MENSAGEM
                    case 3:
                       system("cls");
                       puts("-----------------------------------------------------------------------------------------------------");
                       printf("Alterar Cadastro:\n");
                       system("pause");
                       system("cls");

                       break;
                    case 4:
                        printf("Saindo...\n");
                        aux3 = 0;
                        break;

                    default:

                        puts("-----------------------------------------------------------------------------------------------------");
                        printf("OPCAO INVALIDA! POR FAVOR, DIGITE O VALOR CORRESPONDENTE!\n");
                        system("pause");
                        system("cls");
                }}




        }else{
            puts("-----------------------------------------------------------------------------------------------------");
            printf("SENHA INCORRETA!\nPOR FAVOR DIGITE NOVAMENTE!\n");
            system("pause");
            system("cls");



            }

    	}

 return 0;
    }
}
