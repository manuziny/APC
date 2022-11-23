#include <stdio.h>
#include <string.h>
#include <ctype.h>

void introducao();
int validar_email(char email[]);
int valida_username(char username[]);
int valida_senha(char senha[]);
int frase_sinistra(char sinistra[]);

int main(){

    //Declaração de variáveis.
    char email[100], username[15], senha[45], sinistra[150];

    introducao(); //void de recepção ao usuario.

    printf("Informe seu email: "); //Recebe o email.
    scanf("%[^\n]%*c", email);
    validar_email(email);

    printf("Informe seu username: "); //Recebe o username.
    scanf("%[^\n]%*c", username);
    valida_username(username);

    printf("Infome sua senha: "); //Recebe a senha.
    scanf("%[^\n]%*c", senha);
    valida_senha(senha);

    printf("_________________________________________________\n"); //Recebe a frase sinistra.
    printf("O login foi um sucesso! \nAgora para valida-lo, digite a frase sinsitra: \n\n");
    scanf("%[^\n]%*c", sinistra);
    frase_sinistra(sinistra);


    return 0;
}

void introducao(){
    printf("_________________________________________________\n");
    printf("            Ola! Seja bem vindo ^^\n");
    printf("_________________________________________________\n");
}

int validar_email(char email[]){
    int contArroba = 0;
    int contPonto = 0;
    int contCaracterEspecial = 0;
    int contMaiusculo = 0;
    int i;

    do{ //Laço de repetição para verificar o email e reclamar caso o email seja inválido.
        contArroba = 0;
        contPonto = 0;
        contCaracterEspecial = 0;
        contMaiusculo = 0;

        for(i = 0; i < strlen(email); i++){
            if(email[i] == '@'){ //Contador de @s.
                contArroba++;
            }
            if(email[i] == '.'){ //Contador de pontos.
                contPonto++;
            }
            if(ispunct(email[i]) && email[i] != '@' && email[i] != '.'){ //Contador de caracteres especiais menos @ e ponto.
                contCaracterEspecial++;
            }
            if(isupper(email[i])){ //Contador de letras maiusculas.
                contMaiusculo++;
            }
        }
        //Condicional para invalidação.
        if(contArroba == 1 && contPonto != 0 && contCaracterEspecial == 0 && contMaiusculo == 0){
            printf("Esse foi o email inserido: %s\n", email);
            printf("\n");
        }else{
            if(contArroba != 1){ //Invalida mais de um @.
                printf("\n");
                printf("\aTem que ter pelo menos um @ e nao pode mais de um!\n");
            }
            if(contPonto == 0){ //Invalida se nao houver ponto.
                printf("\n");
                printf("\aTem que ter pelo menos um '.'\n");
            }
            if(contMaiusculo != 0){ //Invalida se houver letras maiusculas.
                printf("\n");
                printf("\aNao se pode colocar letras maiusculas!\n");
                }
            if(contCaracterEspecial != 0){ //Invalida se houver caracteres especiais alem de @ e ponto.
                printf("\n");
                printf("\aNao se pode colocar carcateres especiais alem de arroba (@) e ponto (.)\n");
            }
            printf("\n"); //Releitura do email.
            printf("Email invalido! Digite novamente: ");
            scanf("%[^\n]%*c", email);
        }

    }while(contArroba != 1 || contPonto == 0 || contCaracterEspecial != 0 || contMaiusculo != 0);
        
    return  0;
}

int valida_username(char username[]){
    int i = 0;
    int contMaiusculo = 0;
    int contCaracterEspecial = 0;
    int tamanhoUser;

    do{
        tamanhoUser = strlen(username); 
        contMaiusculo = 0;
        contCaracterEspecial = 0;

        for(i = 0; i < strlen(username); i++){ //Contagem e maisuculos.
            if(isupper(username[i])){
                contMaiusculo++;
            }
            if(ispunct(username[i])){ //Contagem de caracteres especiais.
                contCaracterEspecial++;
            }
        }

        if(tamanhoUser >= 5 && tamanhoUser <= 10 && contCaracterEspecial == 0 && contMaiusculo == 0){ //Apresentar o username se estiver válido.
            printf("Esse eh o username inserido: %s\n", username);
            printf("\n");

        }else{
            if(tamanhoUser < 5 || tamanhoUser > 10){ //Reclamar se houver menos ou a mais caracteres;
                printf("\aDigite um username que tenha entre 5 a 10 caracteres!\n");
            }
            if(contMaiusculo != 0){ //Recalmar se houver letras maiusculas.
                printf("\n");
                printf("\aNao se pode colocar letras maiusculas!\n"); 
            }
            if(contCaracterEspecial != 0){ //Reclamar de caracter especial.
                printf("\n");
                printf("\aNao se pode colocar carcateres especiais!\n");
            }
            printf("\n"); //Releitura do username.
            printf("Username invalido! Digite novamente: ");
            scanf("%[^\n]%*c", username);
        }

    }while(tamanhoUser < 5 || tamanhoUser > 10 || (contMaiusculo != 0) || contCaracterEspecial != 0);

    return 0;

}

int valida_senha(char senha[]){
    int tamanhoSenha;

    do{
        tamanhoSenha = strlen(senha);

        if(tamanhoSenha >= 8 && tamanhoSenha <= 40){ //Valida a senha e imprime na tela.
            printf("Essa eh a senha inserida: %s\n", senha);
            printf("\n");
        }
        else{
            printf("\n"); //Invalida e pede releitura.
            printf("\aSenha invalida! Digite uma senha que tenha entre 8 a 40 caracteres: ");
            scanf("%[^\n]%*c", senha);
        }

    }while(tamanhoSenha < 8 || tamanhoSenha > 40);

    return 0;

}

int frase_sinistra(char sinistra[]){
    int i;
    int tamanhoSinistra =0;
    int contEspaco = 0;
    int contInicialMaiuscula = 0;
    int contPonto = 0;
    int contTamanho = 0;

    tamanhoSinistra = strlen(sinistra);

    if(isupper(sinistra[0])){ //Contator para a primeira letra maiúscula.
        contInicialMaiuscula++;
    }

    if((sinistra[tamanhoSinistra-1]) == '.'){ //Contador para se a frase termina com ponto.
        contPonto++;
    }

    for(i = 0; i < tamanhoSinistra; i++ ){ //Contador de espaços da frase sinistra.
        if(sinistra[i] == ' '){
            contEspaco++;
        }
    }


    if(contEspaco >= 4 && contInicialMaiuscula == 1 && contPonto == 1 && tamanhoSinistra >= 70){ //Validação do login.
        printf("_________________________________________________\n");
        printf("\n");
        printf("Parabens, cara. Voce conseguiu!\n");
    }else{
        if(contEspaco != 4 || contInicialMaiuscula != 1 || contPonto != 1 || tamanhoSinistra < 70){ //Invalidação do login.
            printf("_________________________________________________\n");
            printf("\n");
            printf("Nao foi dessa vez...\n");
        }
    }

    return 0;
}
