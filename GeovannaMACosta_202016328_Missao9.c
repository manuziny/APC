#include <stdio.h>
#include <stdlib.h>

void introducao();
void menu();
void listar_idades(int vet[], int quantidade);
void invalida_idades(int vet[], int i);
float media_idades(int vet[], int quantidade);
int maior_idade(int vet[], int maior);
void maiores_menores(int vet[], int quantidade, int media);
void editar_idade(int vet[], int quantidade);
void exclui_idade(int vet[], int quantidade);
void pesquisar_idade(int vet[], int quantidade);
void sair();
void opcao_invalida();

int main()
{
    //Declaração de variáveis.
    int idades[100], i, opcoes, soma, quantidade, maior, menor;
    float media;
    i = 0;
    quantidade = 0;
    soma = 0;
    media = 0;
    maior = 0;
    menor = 99999;

    introducao();

    printf("Insira as idades de seus alunos:\n");

    for (i = 0; i < 100; i++){
        scanf("%d", &idades[i]);

        if(idades[i] == (150)){ //Parar a leitura e ir ao menu quando se insere o numero 150.
            break;
        }

        invalida_idades(idades, i);
        quantidade++;

        media = media_idades(idades, quantidade);

        //soma = soma + idades[i];
        //media = soma / quantidade;
        
        //if(idades[i] > maior) //Condição para idade maior que a media.
            //maior = idades[i];
        
        //if(idades[i] < menor) //Condição para menor que a media.
            //menor = idades[i];
    }


do{
    menu(opcoes);
    scanf("%d", &opcoes);

    switch(opcoes){

        case 1: //Quantifica as notas, mostra a media assim como a maior e menor idade da turma.
        printf("\n");
        printf("Essa eh a quantidade de idades que voce inseriu: %d\n", quantidade);
        printf("Essa eh a media das idades: %2.f\n", media);
        maior = maior_idade(idades, maior);
        printf("Essa eh a maior idade: %d\n", maior);
        menor = menor_idade(idades, menor);
        printf("Essa eh a menor idade: %d\n", menor);
        break;

        case 2: //Lista as idades.
        listar_idades(idades, quantidade);
        break;

        case 3: //Lista as maiores e menores idades que a média da turma.
        maiores_menores(idades, quantidade, media);
        break;

        case 4: //Edita as idades em determinada posição, caso exista.
        editar_idade(idades, quantidade);
        break;

        case 5: //Exclui a idade inserida, caso exista.
        exclui_idade(idades, quantidade);
        break;

        case 6: //Pesquisa uma idade em determinada posição, caso exista.
        pesquisar_idade(idades, quantidade);
        break;
        
        case 7: // Sair do programa.
        sair();
        break;

        default: //Invalida opções diferentes de 1 e 7.
        opcao_invalida();
        
    }

}while(opcoes != 7);


    return 0;
}


void introducao()
{
    printf("Ola! Seja muito bem vindo. :)\n\n");
    printf("Nesse programa voce podera registrar as idades de seus alunos.\n");
    printf("Quando quiser parar o cadastro e ir ao menu, digite o numero 150. ;)\n\n");
    printf("Vamos dar continuidade a isso? :)\n\n");
    system("pause");
    system("cls");
}

void invalida_idades(int vet[], int i) //Invalidação das idades q não seguem o padrão de 1 a 149.
{

    while(vet[i] <= 0 || vet[i] >= 150)
    {
        printf("\n");
        printf("\aIdade invalida! Insira novamente: ");
        scanf("%d", &vet[i]);
    }

}

float media_idades(int vet[], int quantidade){
    int i;
    int soma;
    float media;
    soma = 0;
    media = 0;
    i = 0;
    
    soma = soma + vet[i];
    media = soma / quantidade;
    return media;
}

int maior_idade(int vet[], int maior){
    int i;
    i = 0;
    maior = 0;

    if(vet[i] > maior) //Condição para idade maior que a media.
        maior = vet[i];
        return maior;
}

int menor_idade( int vet[], int menor){
    int i;
    i = 0;
    menor = 99999;

    if(vet[i] < menor) //Condição para menor que a media.
        menor = vet[i];
        return menor;

}


void menu(){ //Funcao para o menu.
    printf("\n");
    printf("1 - Informacoes Gerais\n");
    printf("2 - Listar idades\n");
    printf("3 - Listar Maiores/Menores que a media\n");
    printf("4 - Editar idade\n");
    printf("5 - Excluir idade\n");
    printf("6 - Pesquisar posicao\n");
    printf("7 - Sair\n");
    printf("\n");

}

void listar_idades(int vet[], int quantidade) //Listagem das idades inseridas.
{
    int i;
    i = 0;

    printf("\n");
    printf("Listando as idades:\n");

    for (i = 0; i < quantidade; i++)
    {
        printf("%d\n", vet[i]);
    }
}

void maiores_menores(int vet[], int quantidade, int media) //Definição de idades maiores e menores que a média.
{
    int i;
    i = 0;

    printf("\n");
    printf("Essas sao as idades maiores que a media: \n");
    for (i = 0; i < quantidade; i++){
      if (vet[i] > media){
        printf("%d\n", vet[i]);
        
    }
    }

    printf("\n");
    printf("Essas sao as idades menores que a media: \n");
    for (i = 0; i < quantidade; i++){
      if (vet[i] < media){
        printf("%d\n", vet[i]);
      }
    }
}

void editar_idade(int vet[], int quantidade){ //Edição das idades.
    int i;
    int idade;
    int substituta;
    int perdido;

            printf("\n");
            printf("Digite a idade que deseja alterar: ");
            scanf("%d", &idade);
            printf("\n");
            printf("Agora digite a nova idade: ");
            scanf("%d", &substituta);
        

        while((idade < 1 || idade > 150 || substituta < 1 || substituta > 150)){ //Laço de repetição pro caso de idades fora do padrão solicitado.
            printf("\n");
            printf("\a Voce inseriu uma idade invalida! Por favor, insira uma idade entre 1 a 149.\n");
            printf("\n");
            printf("Digite a idade que deseja alterar: ");
            scanf("%d", &idade);
            printf("\n");
            printf("Digite a nova idade: ");
            scanf("%d", &substituta);
        }

    for(i = 0; i <= quantidade; i++){
        if(vet[i] == idade){
            vet[i] = substituta;
            perdido = 0;
            break;
        }else{
        perdido++;
        }
    }

    if(perdido != 0){ //Condicional pro caso de não achar a idade solicitada.
        perdido = 0;
        printf("\n");
        printf("\aNao achei essa idade! :(\n");
    }
}

void exclui_idade(int vet[], int quantidade){ //Exclui as idades solicitadas
    int i;
    int idade;
    int perdido;

    printf("\n");
    printf("Digite a nota que deseja excluir: ");
    scanf("%d", &idade);

    for( i = 0; i <= quantidade; i++){
        if(vet[i] == idade)
            for(int count = 0; count <= i; count++){
                vet[i] = vet[i+1];
                quantidade--;
                perdido = 0;
                break;
            }else{
            perdido++;
            }
    }

if(perdido != 0){ //Condicional caso a idade solicitada não exista.
    perdido = 0;
    printf("\n");
    printf("\aNao achei essa idade! :(\n");
}


}

void pesquisar_idade(int vet[], int quantidade){ //Pesquisa a posição de uma idade.
    int i;
    int idade;
    int perdido;
    perdido = 0;

    printf("\n");
    printf("Digite a idade que deseja pesquisar: ");
    scanf("%d", &idade);

    for( i = 0; i <= quantidade; i++){
        if(vet[i] == idade){
            printf("\n");
            printf("Essa eh a idade que voce pesquisou: %d\n", idade);
            perdido = 0;
            break;
        }else{
         perdido++;
        }
    }
    while(perdido != 0){ //Condicional pra caso a idade solicitada não exista.
        perdido = 0;
        printf("\n");
        printf("\aNao achei essa idade! :(\n");
    }
}

void sair(){
    printf("\n");
    printf("Tchauzinho! :)\n");
}

void opcao_invalida(){
    printf("\n");
    printf("\aPor favor, digite um numero de 1 a 7!\n");
}