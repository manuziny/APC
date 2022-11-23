#include <stdio.h>
#include <stdlib.h>

void introducao();
void menu();
int cadastroID(int posicaoID[3][3], int linha, int coluna, int id);
int imprimeAlunos(int posicao[3][3]);
void sair();
void opcao_invalida();

int main(){

    //Declaração de variáveis.
    int opcoes, linha, coluna, id;
    int posicaoID [3] [3];

    //Fazer todas as posições do vetor serem iguais a -1.
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            posicaoID[i][j] = -1;
        }
    }

    introducao();

    do{
        menu(opcoes);
        scanf("%d", &opcoes);

        switch(opcoes){
        case 1:
            //Cadastrar os alunos.
            cadastroID(posicaoID, linha, coluna, id); 
            break;

        case 2: 
            //Imprimir o ID da turma.
            imprimeAlunos(posicaoID);
            break;

        case 3:
            //Sair do programa.
            sair();
            break;

        default:
            //Invalidar opcoes diferentes de 1 e 3.
            opcao_invalida();
        }

    }while(opcoes != 3);

    return 0;
}

void introducao(){
    printf("_________________________________________________\n");
    printf("            Ola! Seja bem vindo ^^\n");
    printf("_________________________________________________\n");
}

void menu(){
    printf("\n");
    printf("1 - Cadastrar aluno.\n");
    printf("2 - Ver turma\n");
    printf("3 - Sair\n\n");
}

int cadastroID(int posicaoID[3][3], int linha, int coluna, int id){
    //Leitura da linha.
    printf("_________________________________________________\n\n");
    printf("Informe em que linha: ");
    scanf("%d", &linha);
    printf("\n");
    while(linha < 0 || linha > 2){
        printf("\aLinha invalida! Insira uma linha entre 0 e 2: ");
        scanf("%d", &linha);
        printf("\n");
    }
    //Leitura da coluna.
    printf("Informe em que coluna: ");
    scanf("%d", &coluna);
    printf("\n");
    while(coluna < 0 || coluna > 2){
        printf("\aColuna invalida! Insira uma coluna entre 0 e 2: ");
        scanf("%d", &coluna);
        printf("\n");
    }
    //Leitura do ID do aluno.
    printf("Informe o ID de seu aluno: ");
    scanf("%d", &id);
    printf("\n");
    while(id < 1 || id > 99){
        printf("\aID invalido! Insira um ID entre 1 e 99: ");
        scanf("%d", &id);
        printf("\n");
    }
    printf("_________________________________________________\n");

    posicaoID[linha][coluna] = id; //Atribui a linha e coluna ao ID o posicionando na matriz.

    return 0;

}

int imprimeAlunos(int posicao [3][3]){
    //Impressão dos ID's da turma.
    printf("_________________________________________________\n\n");
    printf("Esses sao os IDs de sua turma:\n\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", posicao[i][j]);
        }   
        printf("\n");
    }
    printf("_________________________________________________\n");
    return 0;
}

void sair(){
    printf("_________________________________________________\n");
    printf("\n");
    printf("Tchauzinho! :)\n\n");
    printf("_________________________________________________\n");
}

void opcao_invalida(){
    printf("_________________________________________________\n");
    printf("\aPor favor, digite um numero de 1 a 3!\n");
    printf("_________________________________________________\n");
}

