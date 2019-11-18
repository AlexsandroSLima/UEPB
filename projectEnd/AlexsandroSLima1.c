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
    int i = 0,j = 0, aux = 1, aux1 = 1, aux2 = 1, aux3 = 1,op ;
    int quant = 0,quant1, opcaoDigitada = 0,opcaoDigitada2 = 0,usuario = 0;
    //arquivos
    FILE *palestrantes;
    FILE *congressistas;
    FILE *organizadores;
    FILE *palestras;
    FILE *grupoDiscussao;
    FILE *curso;
    FILE *oficinas;

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
        puts("-----------------------------------------------------------------------------------------------------");
        printf("----------| SENHA: ");
        gets(senha1);
        system("cls");


        //login do administrador
        if(strcmp(loginPadrao, login1) == 0 || strcmp(login, login1) == 0)
           if(strcmp(senhaPadrao, senha1) == 0 || strcmp(senha, senha1) == 0){
                puts("-----------------------------------------------------------------------------------------------------");
            printf(" Seja bem vindo administrador!\n");

              aux1 = 0;
              while(opcaoDigitada != 4){
                puts("-----------------------------------------------------------------------------------------------------");
                printf("| Novo cadastro ------> (1) |\n| Listar  ------------> (2) |\n| Alterar cadastro ---> (3) |\n| Sair  --------------> (4) |\n| Remover cadastros --> (5) |\n");
                printf("-----------------------------------------------------------------------------------------------------\n");
                printf("==> ");
                setbuf(stdin,NULL);
                scanf("%d", &opcaoDigitada);

                switch(opcaoDigitada){

                    //cadastro de usuarios
                    case 1:
                            system("cls");
                            puts("-----------------------------------------------------------------------------------------------------");
                            printf("| Novo Cadastro de Pessoas -- (1) |\n| Cadastrar Eventos ------- (2)|\n| Voltar --------- (3) |\n");
                            puts("--------------------------------------------------------");
                            printf("Digite: ");
                            setbuf(stdin,NULL);
                            scanf("%d", &op);
                            if(op == 1){
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
                            }if(op == 2){




                            }else{
                               system("cls");
                               break;
                               }

                    case 2:
                            system("cls");
                            puts("-----------------------------------------------------------------------------------------------------");
                            printf("| Listar -- (1) |\n| Voltar ----------- (2) |\n");
                            puts("--------------------------------------------------------");
                            printf("Digite ==>  ");
                            setbuf(stdin,NULL);
                            scanf("%d", &op);
                            if(op == 1){
                               system("cls");
                               puts("--------------------------------------------------------");
                               printf("| Congressistas ---- (1) |\n| Palestrantes ---- (2) |\n| Organizadores --- (3) |\n");
                               puts("--------------------------------------------------------");
                               printf("Digite ==> ");
                               setbuf(stdin,NULL);
                               scanf("%d", &op);

                               if(op ==1){
                                   congressistas=fopen("congressistas.txt","rt");
                                   if(congressistas==NULL){
                                        printf("Erro ao abrir o arquivo para leitura!");
                                        exit(1);
                                    }

                                   while(fgets(name[i],sizeof(name[i]),congressistas)!=NULL && fgets(cpf[i],sizeof(cpf[i]),congressistas)!=NULL){
                                        name[i][strlen(name[i])-1]='\0';
                                        cpf[i][strlen(cpf[i])-1]='\0';
                                        i++;
                                    }
                                    fclose(congressistas);
                                    puts("--------------------------------------------------------");
                                    printf("Digite a quantidade de nomes que deseja listar\n");
                                    printf("Digite ==> ");

                                    setbuf(stdin,NULL);
                                    scanf("%d", &quant1);

                                    for(i=0;i<quant1;i++){
                                        printf("Nome ------> %s\n",name[i]);
                                        printf("cpf -------> %s\n\n",cpf[i]);
                                    }
                                   system("pause");
                                   system("cls");
                                   break;
                                   }
                               if(op == 2){
                                   system("cls");
                                   palestrantes=fopen("palestrantes.txt","rt");
                                   if(palestrantes==NULL){
                                        printf("Erro ao abrir o arquivo para leitura!");
                                        exit(1);
                                   }
                                   while(fgets(name[i],sizeof(name[i]),palestrantes)!=NULL && fgets(cpf[i],sizeof(cpf[i]),palestrantes)!=NULL){
                                        name[i][strlen(name[i])-1]='\0';
                                        cpf[i][strlen(cpf[i])-1]='\0';
                                        i++;
                                    }
                                    fclose(palestrantes);
                                    puts("--------------------------------------------------------");
                                    printf(" Digite a quantidade de nomes que deseja listar\n");
                                    printf(" Digite ==> ");

                                    setbuf(stdin,NULL);
                                    scanf("%d", &quant1);

                                    for(i=0;i<quant1;i++){
                                        printf("Nome ------> %s\n",name[i]);
                                        printf("cpf -------> %s\n\n",cpf[i]);
                                    }
                                   system("pause");
                                   system("cls");
                                   break;
                               }
                               if(op == 3){
                                   system("cls");
                                   organizadores=fopen("organizadores.txt","rt");
                                   if(organizadores==NULL){
                                        printf("Erro ao abrir o arquivo para leitura!");
                                        exit(1);
                                   }

                                   while(fgets(name[i],sizeof(name[i]),organizadores)!=NULL && fgets(cpf[i],sizeof(cpf[i]),organizadores)!=NULL){
                                        name[i][strlen(name[i])-1]='\0';
                                        cpf[i][strlen(cpf[i])-1]='\0';
                                        i++;
                                    }
                                    fclose(organizadores);
                                    puts("--------------------------------------------------------");
                                    printf(" Digite a quantidade de nomes que deseja listar\n");
                                    printf(" Digite ==> ");

                                    setbuf(stdin,NULL);
                                    scanf("%d", &quant1);

                                    for(i=0;i<quant1;i++){
                                        printf("Nome ------> %s\n",name[i]);
                                        printf("cpf -------> %s\n\n",cpf[i]);
                                    }
                                    system("pause");
                                    system("cls");
                                    break;

                               }

                               }else{
                                  system("cls");
                                  break;
                                       }
                    //SE FOR DIGITADO UM VALOR DIFERENTE SERA IMPRESSO A MENSAGEM
                    case 3:

                       system("cls");
                       puts("-----------------------------------------------------------------------------------------------------");
                            printf("| Alterar Cadastro -- (1) |\n| Voltar ------------ (2) |\n");
                            puts("--------------------------------------------------------");
                            printf("Digite ==>  ");
                            setbuf(stdin,NULL);
                            scanf("%d", &op);
                            if(op == 1){




                                system("pause");
                                system("cls");
                                break;
                            }else{
                                  system("cls");
                                  break;
                                       }
                    case 4:
                        printf("Saindo...\n");
                        aux3 = 0;
                        break;
                    case 5:
                        system("cls");
                        puts("-----------------------------------------------------------------------------------------------------");
                        printf("| Remover -- (1) |\n| Voltar ----------- (2) |\n");
                        puts("--------------------------------------------------------");
                        printf("Digite ==>  ");
                        setbuf(stdin,NULL);
                        scanf("%d", &op);
                        if(op == 1){




                                system("pause");
                                system("cls");
                                break;
                            }else{
                                  system("cls");
                                  break;
                                       }



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
