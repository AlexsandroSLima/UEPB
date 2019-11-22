//Projeto Final Alexsandro da Silva Lima
//Graduando em Ciencia da Computacao

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>


struct palestras{
	char capacidade[150];
    char local[20];
    int cargaHoraria;
    int horario[10];
    char tema[20];
    char palestrante[50];
};

struct gruposDiscu{
	char capacidade[50];
	int cargaHoraria;
	int horario[10];
    char local[20];
    char tema[20];
    char menbrosMesa[100];
};

struct curso{
	char capacidade[40];
    char local[20];
    int cargaHoraria;
    int horario[10];
    char tema[20];
    char palestrante[50];
};

struct oficinas{
	char capacidade[20];
    char local[20];
    int cargaHoraria;
    int horario[10];
    char tema[20];
    char palestrante[50];
};


//funcoes
void gotoxy(int x, int y) {
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
void limpaTela(){
    system("cls");
}
void limpaBuffer(){
    setbuf(stdin,NULL);
}
void verde()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void abertura(){
        system("COLOR 0A");
        gotoxy(40,11);printf("*******  ***      **  *******  *******  *******");
        gotoxy(40,12);printf("*******  ****     **  *******  *******  *******");
        gotoxy(40,13);printf("**       ** **    **  **       **       **     ");
        gotoxy(40,14);printf("*******  **  **   **  **       *******  **     ");
        gotoxy(40,15);printf("*******  **   **  **  **       *******  **     ");
        gotoxy(40,16);printf("**       **    ** **  **       **       **     ");
        gotoxy(40,17);printf("*******  **     ****  *******  *******  *******");
        gotoxy(40,18);printf("*******  **      ***  *******  *******  *******  2019");
        gotoxy(14,23);
        for(int i = 0; i > 15; i++){
            gotoxy(40,18);printf("");
        }
        Sleep(500);
        limpaTela();
}


int main(void){

    while(1){
    char name[50][50], cpf[50][50];
    char congressista[50][50],palestrante[50][50],organizador[50][50];
    char loginPadrao[] = "admin" , senhaPadrao[] = "admin";
    char login1[15], senha1[15], letra;
    int i = 0,j = 0, aux = 1, aux1 = 1, aux2 = 1, aux3 = 1, op;
    int quant = 0,quant1, opcaoDigitada = 0,opcaoDigitada2 = 0,usuario = 0;

    //arquivos
    FILE *palestrantes;
    FILE *congressistas;
    FILE *organizadores;
    //eventos
    FILE *palestras;
    FILE *gruposDiscussao;
    FILE *curso;
    FILE *oficinas;




    //login administrador
    while(aux2 != 0){

             abertura();
             gotoxy(34,12);printf("============================================");
             gotoxy(34,13);printf("|                                          |");
             gotoxy(34,14);printf("| USUARIO:                                 |");
             gotoxy(34,15);printf("|                                          |");
             gotoxy(34,16);printf("|   SENHA:                                 |");
             gotoxy(34,17);printf("|                                          |");
             gotoxy(34,18);printf("============================================");
             gotoxy(46,14);scanf("%s",login1);
             gotoxy(46,16);


              while(aux2 != 0){
                    letra = getch();

                    if(letra == 13 || letra== 9){
                        senha1[i] = '\0';
                        break;
                    }else if(letra == 8){
                        if(i > 0){
                            i--;
                            printf("\b \b");
                        }
                    }else{
                        senha1[i++] = letra;
                        printf("* \b");
                    }
                    }
                   if(strcmp(loginPadrao, login1)  == 0 && strcmp(senhaPadrao,senha1) == 0){


                      gotoxy(45,22);printf("ACESSO PERMITIDO");
                      Sleep(200);
                      aux2 = 0;
                      limpaTela();

                  }else{
                      gotoxy(45,22);printf("ACESSO NEGADO");
                      Sleep(200);
                  }
                    limpaTela();

                    }//chave do while

       while(aux1 != 0){
           limpaTela();

           if(strcmp(loginPadrao, login1)  == 0 && strcmp(senhaPadrao,senha1) == 0){
               puts("-----------------------------------------------------------------------------------------------------");
               printf(" \t\t\t\tSeja bem vindo administrador!\n");

              aux1 = 0;
              while(opcaoDigitada != 4){
                puts("-----------------------------------------------------------------------------------------------------");
                printf("| Novo cadastro ------> (1) |\n| Listar  ------------> (2) |\n| Alterar cadastro ---> (3) |\n| Sair  --------------> (4) |\n| Remover cadastros --> (5) |\n");
                printf("-----------------------------------------------------------------------------------------------------\n");
                printf("==> ");
                limpaBuffer();
                scanf("%d", &opcaoDigitada);

                switch(opcaoDigitada){

                    //cadastro de usuarios
                    case 1:
                            limpaTela();
                            puts("-----------------------------------------------------------------------------------------------------");
                            printf("| Novo Cadastro de Pessoas -- (1) |\n| Cadastrar Eventos ------- (2)|\n| Voltar --------- (3) |\n");
                            puts("--------------------------------------------------------");
                            printf("Digite: ");
                            limpaBuffer();
                            scanf("%d", &op);
                            if(op == 1){
                                printf(" Quantos pessoas deseja cadastrar? \n==> ");
                                scanf("%d", &quant);
                                //tratamento para dado incorreto digitado pelo usuario
                                while(aux != 0){
                                  puts("-----------------------------------------------------------------------------------------------------");
                                  printf(" Voce deseja cadastrar: \n Congressista ---> (1)\n Palestrante ----> (2)\n Organizador ----> (3) \n==> ");
                                  //lendo tipo de usuario
                                  limpaBuffer();
                                  scanf("%d", &usuario);
                                  switch(usuario){
                                    case 1:
                                        aux = 0;
                                        limpaTela();
                                        break;
                                    case 2:
                                        aux = 0;
                                        limpaTela();
                                        break;
                                    case 3:
                                        aux = 0;
                                        limpaTela();
                                        break;
                                    default :
                                        aux = 1;
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        printf("OPCAO INVALIDA! POR FAVOR, DIGITE O VALOR CORRESPONDENTE!\n");
                                        system("pause");
                                        limpaTela();
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
                                    congressistas=fopen("congressistas.txt","at");
                                    for(i=0;i<quant;i++){
                                        fprintf(congressistas,"%s\n",name[i]);
                                        fprintf(congressistas,"%s\n",cpf[i]);
                                    }
                                    fclose(congressistas);
                                    printf(" CADASTRO REALIZADO COM SUCESSO\n");
                                    system("pause");
                                    limpaTela();
                                }
                                if(usuario == 2){
                                    palestrantes=fopen("palestrantes.txt","at");
                                    for(i=0;i<quant;i++){
                                        fprintf(palestrantes,"%s\n",name[i]);
                                        fprintf(palestrantes,"%s\n",cpf[i]);
                                    }
                                    fclose(palestrantes);
                                    printf(" CADASTRO REALIZADO COM SUCESSO!\n");
                                    system("pause");
                                    limpaTela();
                                }
                                if(usuario == 3){
                                    organizadores=fopen("organizadores.txt","at");
                                    for(i=0;i<quant;i++){
                                        fprintf(organizadores,"%s\n",name[i]);
                                        fprintf(organizadores,"%s\n",cpf[i]);
                                    }
                                    fclose(organizadores);
                                    printf(" CADASTRO REALIZADO COM SUCESSO!\n");
                                    puts("-----------------------------------------------------------------------------------------------------");
                                    system("pause");
                                    limpaTela();
                                }

                                break;
                            }
                            if(op == 2){
                                limpaTela();
                                puts("-----------------------------------------------------------------------------------------------------");
                                printf("Cadastrar eventos\n");
                                puts("-----------------------------------------------------------------------------------------------------");
                                printf("| Palestras --- (1) |\n| Grupos de Discussao ---- (2) |\n| Curso ---- (3) |\n| Oficinas --- (4) |\n| Voltar -- (5) \n");
                                puts("-----------------------------------------------------------------------------------------------------");
                                printf("Digite: ");
                                limpaBuffer();
                                scanf("%d", &op);
                                if(op == 1){
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        printf("| Palestras |\n");
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        system("pause");
                                        limpaTela();
                                        break;

                                }if(op == 2){
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        printf("| Grupos de Discussao |\n");
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        system("pause");
                                        limpaTela();
                                        break;

                                }if(op == 3){
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        printf("| Curso |\n");
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        system("pause");
                                        limpaTela();
                                        break;

                                }if(op == 4){
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        printf("| Oficinas |\n");
                                        puts("-----------------------------------------------------------------------------------------------------");
                                        system("pause");
                                        limpaTela();
                                        break;

                                }else{
                                   limpaTela();
                                   break;
                                   }




                                system("pause");
                                limpaTela();
                                break;
                            }
                            else{
                               limpaTela();
                               break;
                               }

                    case 2:
                            limpaTela();
                            puts("-----------------------------------------------------------------------------------------------------");
                            printf("| Listar -- (1) |\n| Voltar ----------- (2) |\n");
                            puts("--------------------------------------------------------");
                            printf("Digite ==>  ");
                            limpaBuffer();
                            scanf("%d", &op);
                            if(op == 1){
                               limpaTela();
                               puts("--------------------------------------------------------");
                               printf("| Congressistas ---- (1) |\n| Palestrantes ---- (2) |\n| Organizadores --- (3) |\n");
                               puts("--------------------------------------------------------");
                               printf("Digite ==> ");
                               limpaBuffer();
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

                                    limpaBuffer();
                                    scanf("%d", &quant1);

                                    for(i=0;i<quant1;i++){
                                        printf("Nome ------> %s\n",name[i]);
                                        printf("cpf -------> %s\n\n",cpf[i]);
                                    }
                                   system("pause");
                                   limpaTela();
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

                                    limpaBuffer();
                                    scanf("%d", &quant1);

                                    for(i=0;i<quant1;i++){
                                        printf("Nome ------> %s\n",name[i]);
                                        printf("cpf -------> %s\n\n",cpf[i]);
                                    }
                                   system("pause");
                                   limpaTela();
                                   break;
                               }
                               if(op == 3){
                                   limpaTela();
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

                                    limpaBuffer();
                                    scanf("%d", &quant1);

                                    for(i=0;i<quant1;i++){
                                        printf("Nome ------> %s\n",name[i]);
                                        printf("cpf -------> %s\n\n",cpf[i]);
                                    }
                                    system("pause");
                                    limpaTela();
                                    break;

                               }

                               }else{
                                  limpaTela();
                                  break;
                                       }
                    //SE FOR DIGITADO UM VALOR DIFERENTE SERA IMPRESSO A MENSAGEM
                    case 3:

                       limpaTela();
                       puts("-----------------------------------------------------------------------------------------------------");
                            printf("| Alterar Cadastro -- (1) |\n| Voltar ------------ (2) |\n");
                            puts("--------------------------------------------------------");
                            printf("Digite ==>  ");
                            limpaBuffer();
                            scanf("%d", &op);
                            if(op == 1){




                                system("pause");
                                limpaTela();
                                break;
                            }else{
                                  limpaTela();
                                  break;
                                       }
                    case 4:
                        printf("Saindo...\n");
                        aux3 = 0;
                        break;
                    case 5:
                        limpaTela();
                        puts("-----------------------------------------------------------------------------------------------------");
                        printf("| Remover -- (1) |\n| Voltar ----------- (2) |\n");
                        puts("--------------------------------------------------------");
                        printf("Digite ==>  ");
                        limpaBuffer();
                        scanf("%d", &op);
                        if(op == 1){




                                system("pause");
                                limpaTela();
                                break;
                            }else{
                                  limpaTela();
                                  break;
                                       }



                    default:

                        puts("-----------------------------------------------------------------------------------------------------");
                        printf("OPCAO INVALIDA! POR FAVOR, DIGITE O VALOR CORRESPONDENTE!\n");
                        system("pause");
                        limpaTela();
                }}




        }else{
            puts("-----------------------------------------------------------------------------------------------------");
            printf("SENHA INCORRETA!\nPOR FAVOR DIGITE NOVAMENTE!\n");
            system("pause");
            limpaTela();



            }

    	}

 return 0;
    }
}
