#include <stdio.h>
#include <string.h>
#include <windows.h>
//funcao para calcular a media e retornar a situacao do aluno
char *alunosSituacao(const char nome[16]){
    //declarando variaveis de controle
    int i = 0, j = 0;
    for(i = 0; i < 20; i++){
    //declarando variaveis para a media e nota
    float media = 0, nota = 0;
    //laco para ler as notas
    for(j = 0; j < 4; j++){
        printf("NOTA %d DE %s ", j + 1, nome);
        //limpando o buffer do teclado
        setbuf(stdin,NULL);
        //lendo a nota
        scanf ("%f", &nota);
        //somando a media com a nota
        media += nota;
       }
    //calculando a media
    media = media / 4.0;
    printf ("\n>> MEDIA DE %s: %.2f\n\n ", nome, media);
    //retornana situacao "APROVADO" ou "REPROVADO"
    if(media >= 7.0)
        return "APROVADO";
    if(media < 7.0)
        return "REPROVADO";
    }
}
//funcao para ler os nomes dos alunos
void nomesAlunos(char nomes[][2][16]){
    //declarando variaveis de controle
    int i = 0, j = 0;
    for(i = 0; i < 20; i++){
        printf("Nome ");
        //limpando o buffer do teclado
        setbuf(stdin, NULL);
        //lendo nomes dos alunos
        fgets(&nomes[i][0][0], 16, stdin);
        strtok(&nomes[i][0][0], "\n");
        for(j=0;j <nomes[i][0][j];j++){
             //convertendo nomes para maiusculo
             nomes[i][0][j] = toupper(nomes[i][0][j]);
        }
        strcpy(&nomes[i][1][0], alunosSituacao(&nomes[i][0][0]));
    }
}
//funcao para mostrar os nomes dos alunos e suas siituacoes finais
void mostrar(char nomes[][2][16]){
    //declarando variaveis de controle
    int i = 0;
    printf(">>>> SITUACAO FINAL\n\n");
    for(i = 0; i < 20; i++){
        printf("%s %s\n", &nomes[i][0][0], &nomes[i][1][0]);
    }
}
int main(void){
    system("color F0");
    //declarando o array
    char nomes[20][2][16];
    printf(">>>> INSIRA OS DADOS DOS ALUNOS\n\n");
    //chamando a funcao nomesAlunos
    nomesAlunos(nomes);
    //chamando a funcao mostrar
    mostrar(nomes);
return 0;
}
