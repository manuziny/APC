#include <stdio.h>
#include <stdlib.h>

int main(){
    int X, Y, Z, i, opcoes, fatorial;
    int resultado;

    resultado = 0;
    
    void introducao();
    void menu();
    int invalida_X(int X);
    int invalida_Y(int Y);
    int invalida_Z(int Z);
    int invalida_primo(int xyz, int primo);
    int fatorial_X(int X, int i, int fatorial);
    int fatorial_Y(int Y, int i, int fatorial);
    int fatorial_Z(int Z, int i, int fatorial);
    int soma_caso_2( int X, int Y, int Z);
    int soma_sub(int X, int Y, int Z);
    int fat_soma(int X, int Y, int Z);
    void triangulo_equilatero(int X, int Y, int Z);
    void triangulo_isosceles(int X, int Y, int Z);
    void sair();
    void opcao_invalida();

    
    introducao(); //Void para dar introdução ao usuario.

    //Recebendo o valor de X.
    printf("Insira X: ");
    scanf("%d", &X);
    X = invalida_X(X);
    printf("\n");

    //Recebendo o valor de Y.
    printf("Insira Y: ");
    scanf("%d", &Y);
    Y = invalida_Y(Y);
    printf("\n");

    //Recebendo o valor de Z.
    printf("Insira Z: ");
    scanf("%d", &Z);
    Z = invalida_Z(Z);
    printf("\n");
    
    do{
        menu(); //Void para imprimir o menu.
        scanf("%d", &opcoes);
        printf("\n");

        switch (opcoes){
            case 1: //Caso em que se soma os fatoriais de X, Y e Z.
            resultado = fatorial_X(X,i ,fatorial) + fatorial_Y(Y, i, fatorial) + fatorial_Z(Z, i,fatorial);

            printf("Esse eh o resultado da formula escolhida: %d", resultado);
            printf("\n");
            break;

            case 2: //Caso em que se soma X, Y, Z e faz o fatorial da soma.
            resultado = soma_caso_2(X, Y, Z);

            printf("Esse eh o resultado da formula escolhida: %d", resultado);
            printf("\n");
            break;

            case 3: //Caso em que se soma X e Y, subtrai X e Z e soma seus fatoriais.
            resultado = soma_sub(X, Y, Z);

            printf("Esse eh o resultado da formula escolhida: %d", resultado);
            printf("\n");
            break;

            case 4: //Caso em que se subtrai o fatorial de X pelo fatorial da soma entre Z e Y.
            resultado = fat_soma(X, Y, Z);

            printf("Esse eh o resultado da formula escolhida: %d", resultado);
            printf("\n");
            break;
            
            case 5: //Caso em que se verifica se X, Y e Z podem ser um triangulo equilátero.
            triangulo_equilatero(X, Y, Z);
            break;

            case 6: //Caso em que se verifica se X, Y e Z podem ser um triangulo isosceles.
            triangulo_isosceles(X, Y, Z);
            break;

            case 7: //Se despir do usuário.
            sair();
            break;

            default: //Invalidar opcoes diferentes de 1 a 7.
            opcao_invalida();
        }
        
    }while(opcoes != 7);

        
       return 0;
}

void introducao(){
    printf("Ola! Seja muito bem vindo. :)\n\n");
    printf("Nesse programa voce podera executar algumas formulas a partir de tres numeros ecolhidos por voce!\n");
    printf("Lembrando que os numeros nao podem ser negativos, meiores que sete ou primos. ;)\n");
    printf("Os numeros serao julgados como X, Y e Z.\n\n");
    printf("Vamos dar continuidade a isso? :)\n\n");
    system("pause");
    system("cls");
}

void menu(){
    printf("\n");
    printf("1 - X! + Y! + Z!\n");
    printf("2 - (X + Y + Z)!\n");
    printf("3 - (X + Y)! + (X - Z)!\n");
    printf("4 - X! - (Z + Y)!\n");
    printf("5 - Se fossem lados, os 3 numeros formariam um triangulo equilatero?\n");
    printf("6 - Se fossem lados, os 3 numeros formariam um triangulo isosceles?\n");
    printf("7 - Sair\n");
    printf("\n");
}

//As funções da linha 127 a 197 são de condições que invalidam os numeros que sejam primos, negativos ou maiores que sete caso o usuario os digite.
int invalida_X(int X){ 
    int i;
    int primo;
    primo = 0;

    for(i = 1; i <= X; i++){  
        if(X % i == 0)
            primo++;
    }

    while((primo <= 2 && X != 1)|| X < 0 || X > 7){ 
        primo = 0;
        printf("\n");
        printf("Numero invalido, insira novamente: ");
        scanf("%d", &X);
        for(i = 1; i <= X; i++){  
            if(X % i == 0)
            primo++;
        }
    }

    return X;
}

int invalida_Y(int Y){
    int i;
    int primo;
    primo = 0;

    for(i = 1; i <= Y; i++){  
        if(Y % i == 0)
            primo++;
    }

    while((primo <= 2 && Y != 1)|| Y < 0 || Y > 7){ 
        primo = 0;
        printf("\n");
        printf("Numero invalido, insira novamente: ");
        scanf("%d", &Y);
        for(i = 1; i <= Y; i++){  
            if(Y % i == 0)
            primo++;
        }
    }
    return Y;

}

int invalida_Z(int Z){
    int i;
    int primo;
    primo = 0;

    for(i = 1; i <= Z; i++){  
        if(Z % i == 0)
            primo++;
    }

    while((primo <= 2 && Z != 1)|| Z < 0 || Z > 7){ 
        primo = 0;
        printf("\n");
        printf("Numero invalido, insira novamente: ");
        scanf("%d", &Z);
        for(i = 1; i <= Z; i++){  
            if(Z % i == 0)
            primo++;
        }
    }

    return Z;
}

//Funções da linha 200 a 225 são de cálculo do fatorial de X, Y e Z.
int fatorial_X(int X, int i, int fatorial){
    i = X;
    for(fatorial = 1; i > 1; i--){
    fatorial = fatorial * X;
    X--;
}
    return fatorial;
}

int fatorial_Y(int Y, int i, int fatorial){
    i = Y;
    for(fatorial = 1; i > 1; i--){
    fatorial = fatorial * Y;
    Y--;
}
    return fatorial;
}

int fatorial_Z(int Z, int i, int fatorial){
    i = Z;
    for(fatorial = 1; i > 1; i--){
    fatorial = fatorial * Z;
    Z--;
}
    return fatorial;
}

//Função de soma relacionada ao caso 2.
int soma_caso_2( int X, int Y, int Z){
    int soma;
    int fatorial_soma;
    fatorial_soma = 1;

    soma = X + Y + Z;

    for(fatorial_soma = 1; soma > 1; soma--){
        fatorial_soma = fatorial_soma * soma;
        }
        return fatorial_soma;
}

//Funcão de soma e subtração de fatoriais relacionas ao caso 3;
int soma_sub(int X, int Y, int Z){
    int soma_e_sub;
    int soma_XY;
    int fatorial_XY;
    int sub_XZ;
    int fatorial_XZ;

    fatorial_XY = 1;
    fatorial_XZ = 1;

    soma_XY = X + Y;

    for(fatorial_XY = 1; soma_XY >= 1; soma_XY--){
        fatorial_XY = fatorial_XY * soma_XY;
    }

    sub_XZ = X - Z;

    for(fatorial_XZ = 1; sub_XZ >= 1; sub_XZ--){
        fatorial_XZ = fatorial_XZ * sub_XZ;
    }

        soma_e_sub = fatorial_XY + fatorial_XZ;

    return soma_e_sub;
}

//Função para subtração do fatorial de X e soma entre o fatorial da soma de Z e Y.
int fat_soma(int X, int Y, int Z){
    int fatorial_X;
    int soma_ZY;
    int fatorial_ZY;
    int fat_e_soma;
    
    fatorial_ZY = 1;


    for(fatorial_X = 1; X > 1; X = X - 1){
        fatorial_X = fatorial_X * X;
    }

    soma_ZY = Z + Y;
    for(fatorial_ZY = 1; soma_ZY >= 1; soma_ZY--){
        fatorial_ZY = fatorial_ZY * soma_ZY;
    }

    fat_e_soma = fatorial_X - fatorial_ZY;
    return fat_e_soma;
}

//Void para verificação se é um triângulo equilátero ou não.
void triangulo_equilatero(int X, int Y, int Z){
    if(X == Y && X == Z)
        printf("Sim! Eh um triangulo equilatero. :)\n");
    else 
        printf("Nao eh um triangulo equilatero. :(\n");
}

//Void para verificação se é um triângulo isósceles ou não.
void triangulo_isosceles(int X, int Y, int Z){
    if((X == Y && X != Z)||(Y == X && Y != Z)||(Z == X && Z != Y))
        printf("Sim! Eh um traingulo isosceles. :)\n");
    else
        printf("Nao eh um triangulo isosceles. :(\n");
}

void sair(){
    printf("\n");
    printf("Tchauzinho! :)\n");
}

void opcao_invalida(){
    printf("\n");
    printf("Por favor, digite um numero de 1 a 7!\n");
}