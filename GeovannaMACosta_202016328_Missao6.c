#include <stdio.h> 

int main() {
    int opcoes, par_ou_impar;
    float peso, altura, resultado, num1, num2;

    printf("> 1 Informacoes\n"); //informações do criador do programa.
    printf("> 2 Calcular IMC\n");
    printf("> 3 Par ou Impar\n");
    printf("> 4 Multiplicacao\n");
    printf("> 5 Divisao\n");
    printf("> 6 Sair\n");
    printf("\n");
    scanf("%d", &opcoes);
    printf("\n");


    switch (opcoes)
    {
    case 1:
        printf("> Informacoes!\n\n");
        printf("> Me chamo Geovanna Maciel Avelino da Costa.\n");
        printf("> Tenho matricula 202016328.\n");
        printf("> Estou cursando o semestre 2/2020\n."); 
        break;

    case 2:
        printf("> Calculando seu IMC!\n\n");
        printf("> Digite seu peso: ");
        scanf("%f", &peso);
        printf("\n");
        printf("> Digite sua altura: ");
        scanf("%f", &altura);
        printf("\n");
        resultado = peso / (altura * altura);
        printf("\n");
        printf("> Seu IMC eh de: %f", resultado);
        break;

    case 3:
        printf("> Verificando se o numero eh par ou impar!\n\n");
        printf("> Digite um numero: ");
        scanf("%d", &par_ou_impar);
        printf("\n");
         if(par_ou_impar % 2 == 0){
            printf("> Eh par!\n");
         }
         else{
             printf("> Eh impar!\n");
         }
        break;
    
    case 4:
        printf("> Multiplicacao!\n\n");
        printf("> Digite o primeiro numero: ");
        scanf("%f", &num1);
        printf("\n");
        printf("> Digite o segundo numero: ");
        scanf("%f", &num2);
        printf("\n");
        resultado = num1 * num2;
        printf("\n");
        printf("> O resultado eh = %f", resultado);
        break;

    case 5: 
        printf("> Divisao!\n\n");
        printf("> Digite o primeiro numero: ");
        scanf("%f", &num1);
        printf("\n");
        if(num1 == 0){
            printf("\n");
            printf("> Numero invalido :/");
        }
        else if(num1 > 0){
            printf("> Digite o segundo numero: ");
            scanf("%f", &num2);
                if(num2 == 0){
                printf("\n");
                printf("> Numero invalido :/");
                }
                else if(num2 > 0){
                    printf("\n");
                    resultado = num1 / num2;
                    printf("> O resultado eh = %f", resultado);
                }
        }
        break;

    case 6:
        printf("Tchauzinho! :D");
        break;

    default:
        printf("Escolha entre 1 e 6, poxa :( ");
        break;
    }
    return 0;
}
