#include <stdio.h>
#include <stdlib.h>

int main(){

    int recebidos, opcoes, quantidade_numeros, quantidade_negativos, quantidade_pares, quantidade_primos, resultado;
    float soma, media;

    quantidade_numeros = 0;
    quantidade_negativos = 0;
    quantidade_pares = 0;
    quantidade_primos = 0;
    resultado = 0;
    media = 0;
    soma = 0;

    printf("Por favor, digite uma sequencia de numeros inteiros. Quando quiser sair, digite um multiplo de 150.\n");

    do{   

        scanf("%d", &recebidos);
            if(recebidos % 150 == 0){
                break;
            }

        quantidade_numeros++; // Variavel para quantificar os numeros que o usuario inseriu.

        if(recebidos < 0){ // Condicional para quantificar os numeros negativos CASO o usuario os inserir.
            quantidade_negativos++;
        }

        if(recebidos % 2 == 0){ // Condicional para quantificar os numeros pares CASO o usuario os inserir.
            quantidade_pares++;
        }

        for (int i = 1; i <= recebidos; i++){ // Laço para contabilizar os números primos positivos. 
            if (recebidos % i == 0){
            resultado++;
            }
        }
        for (int i = -1; i >= recebidos; i--){ // Laço para contabilizar os números primos negativos. 
            if (recebidos % i == 0){
            resultado++;
            }
        }
        if(resultado <= 2){ // Condicional para quantificar os numeros primos CASO o usuario os insira.
            quantidade_primos++;
        }
        resultado = 0;

        soma = soma + recebidos; // Linhas 44 e 45 de cálculo para a média dos numeros inseridos.
        media = soma / quantidade_numeros;

    } while(recebidos % 150 != 0);

    do{
        printf("1 - Quantidade de numeros inseridos\n");
        printf("2 - Quantidade de numeros negativos\n");
        printf("3 - Quantidade de numeros pares\n");
        printf("4 - Quantidade de numeros primos\n");
        printf("5 - Media dos numeros\n");
        printf("6 - Sair\n");
        scanf("%d", &opcoes);

        switch (opcoes){

        case 1: //
            printf("\n");
            printf("Essa eh a quantidade de numeros que voce inseriu: %d\n", quantidade_numeros);
            printf("\n");
            break;
        
        case 2:
            printf("\n");
            printf("Essa eh a quantidade de numeros negativos: %d\n", quantidade_negativos);
            printf("\n");
            break;

        case 3:
            printf("\n");
            printf("Essa eh a quantidade de numeros pares: %d\n", quantidade_pares);
            printf("\n");
            break;

        case 4:
            printf("\n");
            printf("Essa eh a quantidade de numeros primos: %d\n", quantidade_primos);
            printf("\n");
            break;

        case 5:
            printf("\n");
            printf("Essa eh a media dos numeros que voce inseriu: %2.f\n", media);
            printf("\n");
            break;
        
        case 6:
            printf("\n");
            printf("Tchauzinho :)");
            printf("\n");
            break;
        
        default:
            printf("\n");
            printf("Por favor, digite um numero entre 1 e 6!");
            printf("\n");
        }

        } while (opcoes != 6);

    
    return 0;
    
}