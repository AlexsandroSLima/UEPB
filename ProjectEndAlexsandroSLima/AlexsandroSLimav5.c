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

void abertura(){
        system("COLOR 0A");
        gotoxy(40,11);printf("*******  ***     ***  *******  *******  *******");
        gotoxy(40,12);printf("*******  ****    ***  *******  *******  *******");
        gotoxy(40,13);printf("***      *****   ***  ***      ***      ***    ");
        gotoxy(40,14);printf("*******  *** **  ***  ***      *******  ***    ");
        gotoxy(40,15);printf("*******  ***  ** ***  ***      *******  ***    ");
        gotoxy(40,16);printf("***      ***   *****  ***      ***      ***    ");
        gotoxy(40,17);printf("*******  ***    ****  *******  *******  *******");
        gotoxy(40,18);printf("*******  ***     ***  *******  *******  *******  2019");
        gotoxy(40,23);printf("Carregando ");
        for(int x = 0; x <26; x++){
           printf("%c",254);Sleep(80);
        }

        Sleep(500);
        limpaTela();

}

//funcoes para cadastro
void cadastraCongressista(char nome[], char cpf[]){
	FILE *congressistas;
	congressistas = fopen("congressistas.txt", "at");
	fprintf(congressistas, " %s %s ", nome, cpf);
	fclose(congressistas);
}
void cadastraPalestrante(char nome[], char cpf[]){
	FILE *palestrantes;
	palestrantes = fopen("palestrantes.txt", "at");
	fprintf(palestrantes, " %s %s ", nome, cpf);
	fclose(palestrantes);
}
void cadastraOrganizador(char nome[], char cpf[]){
	FILE *organizadores;
	organizadores = fopen("organizadores.txt", "at");
	fprintf(organizadores, " %s %s ", nome, cpf);
	fclose(organizadores);
}
//funcoes para listar cadastrados
void listaCongressista(){
	FILE *congressistas;
	char nome[100];
	int cpf[50];

	congressistas = fopen("congressistas.txt", "rt");

	if(congressistas != NULL){
		while(!feof(congressistas)){
			fscanf(congressistas, "\n%s  %s", nome, cpf);
			printf("\nNome: %s\ncpf: %s\n\n", nome, cpf);
		}
	}
	else{
		printf("\nErro: não foi possivel abrir o arquivo\n");
	}

	fclose(congressistas);
}
void listaPalestrante(){
	FILE *palestrantes;
	char nome[100];
	int cpf[50];

	palestrantes = fopen("palestrantes.txt", "rt");

	if(palestrantes != NULL){
		while(!feof(palestrantes)){
			fscanf(palestrantes, "\n%s  %s", nome, cpf);
			printf("\nNome: %s\ncpf: %s\n\n", nome, cpf);
		}
	}
	else{
		printf("\nErro: não foi possivel abrir o arquivo\n");
	}

	fclose(palestrantes);
}
void listaOrganizador(){
	FILE *organizadores;
	char nome[100];
	int cpf[50];

	organizadores = fopen("organizadores.txt", "rt");

	if(organizadores != NULL){
	    while (!feof(organizadores)){
			fscanf(organizadores, "\n %s  %s", nome, cpf);
			printf("\n Nome: %s\n Cpf: %s\n\n", nome, cpf);
		}
	}
	else{
		printf("\nErro: não foi possivel abrir o arquivo\n");
	}
	fclose(organizadores);
}



int main(void){

    while(1){
    char name[100], cpf[50], congressista[50], palestrante[50], organizador[50], ch;
    char loginPadrao[] = "admin" , senhaPadrao[] = "admin";
    char login1[15], senha1[15], letra;
    int i = 0,j = 0, aux = 1, aux1 = 1, aux2 = 1, aux3 = 1, op;
    int quant = 0,quant1, opcaoDigitada = 0,opcaoDigitada2 = 0,usuario = 0, opcao;


    //eventos
    FILE *palestras;
    FILE *gruposDiscussao;
    FILE *curso;
    FILE *oficinas;




    //login administrador
    while(aux2 != 0){

             abertura();
             system("COLOR 0F");

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
                   if(strcmp(loginPadrao, login1) == 0 && strcmp(senhaPadrao,senha1)== 0){


                      gotoxy(45,22);printf("ACESSO PERMITIDO!");
                      Sleep(200);
                      aux2 = 0;
                      limpaTela();

                  }else{

                      gotoxy(45,22);printf("ACESSO NEGADO!");
                      Sleep(200);
                  }
                    limpaTela();

                    }//chave do while

       while(aux1 != 0){
           limpaTela();

           if(strcmp(loginPadrao, login1)  == 0 && strcmp(senhaPadrao,senha1) == 0){
               puts(" \t\t\t\t|-------------------------------|");
               printf("\t\t\t\t| Seja bem vindo administrador! |\n");
               puts(" \t\t\t\t|-------------------------------|");

              aux1 = 0;
              while(opcaoDigitada != 4){
                printf("\t\t\tMENU");


                puts("\n-----------------------------------------------------------------------------------------------------");
                printf("| Novo cadastro ------> (1) |\n| Listar  ------------> (2) |\n| Alterar cadastro ---> (3) |\n| Sair  --------------> (4) |\n| Remover cadastros --> (5) |\n");
                printf("-----------------------------------------------------------------------------------------------------\n");
                printf("==> ");
                limpaBuffer();
                scanf("%d", &opcaoDigitada);

                switch(opcaoDigitada){

                    //cadastro de usuarios
                    case 1:
                            limpaTela();
                            printf("\t\t\tNovo cadastro\n");
                            puts("-----------------------------------------------------------------------------------------------------");
                            printf("| Novo Cadastro de Pessoas -- (1) |\n| Cadastrar Eventos ------- (2)|\n| Voltar --------- (3) |\n");
                            puts("--------------------------------------------------------");
                            printf("Digite: ");
                            limpaBuffer();
                            scanf("%d", &op);
                            if(op == 1){

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


                                printf("\n-------------------------------------------------------------------------------\n");

                                if(usuario == 1){

                                        limpaTela();
                                        printf("\nInforme o nome: ");
                                        limpaBuffer();
                                        gets(name);
                                        strtok(name, "\n");
                                        if(strlen(name) ==100-1){
                                            while ((ch = getchar()) != '\n' && ch != EOF);
                                        }

                                        printf("Informe o cpf: ");
                                        limpaBuffer();
                                        scanf("%s", cpf);


                                        cadastraCongressista(name, cpf);

                                        limpaTela();
                                        break;

                                        printf(" CADASTRO REALIZADO COM SUCESSO\n");
                                        system("pause");
                                        limpaTela();
                                }
                                if(usuario == 2){
                                        limpaTela();
                                        printf("\nInforme o nome: ");
                                        limpaBuffer();
                                        fgets(name, 100, stdin);
                                        strtok(name, "\n");
                                        if(strlen(name) ==100-1){
                                            while ((ch = getchar()) != '\n' && ch != EOF);
                                        }

                                        printf("Informe o cpf: ");
                                        limpaBuffer();
                                        scanf("%s", cpf);


                                        cadastraPalestrante(name, cpf);
                                        printf(" CADASTRO REALIZADO COM SUCESSO!\n");
                                        system("pause");
                                        limpaTela();
                                }
                                if(usuario == 3){
                                        limpaTela();
                                        printf("\nInforme o nome: ");
                                        limpaBuffer();
                                        fgets(name, 100, stdin);
                                        strtok(name, "\n");
                                        if(strlen(name) ==100-1){
                                            while ((ch = getchar()) != '\n' && ch != EOF);
                                        }

                                        printf("Informe o cpf: ");
                                        limpaBuffer();
                                        scanf("%s", cpf);


                                        cadastraOrganizador(name, cpf);
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
                            printf("\t\t\tListar\n");
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
                                   limpaTela();
                                   listaCongressista();
                                   system("pause");
                                   limpaTela();
                                   break;
                               }
                               if(op == 2){
                                   limpaTela();
                                   listaPalestrante();
                                   system("pause");
                                   limpaTela();
                                   break;
                               }
                               if(op == 3){
                                    limpaTela();
                                    listaOrganizador();
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
                       printf("\t\t\tAlterar cadastro\n");
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
                        printf("S");Sleep(150);
                        printf("a");Sleep(150);
                        printf("i");Sleep(150);
                        printf("n");Sleep(150);
                        printf("d");Sleep(150);
                        printf("o...");Sleep(100);
                        return 0;
                        aux3 = 0;
                        break;
                    case 5:
                        limpaTela();
                        printf("\t\t\tRemover cadastros\n");
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
