#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//Struct para armazenar os dados dos jogadores.
typedef struct cadastro_jogador{
    int id;
    char nome[50];
    char posicao[3];
    int idade;
    int pontuacao;
}jogador;

//Struct para armazenar os dados do time, como nome e tecnico.
typedef struct time_tecnico{
    jogador jogadores[5];
    char nome_time[50];
    char tecnico[50];
}time;

//Struct para armazenar os dados da partida relacionados aos jogadores e seu desempenho.
typedef struct jogadores_partida{
    int id_jogador;
    int num_assistencias;
    int num_kills;
    int num_mortes;
}jogadorPartida;

//Struct para armazenar os dados da partida em si fora os jogadores, atribuindo aos adversários também.
typedef struct partida{
    int total_kills_time;
    int total_kills_adversario;
    bool vitoria;
    int total_torres_destruidas_time;
    int total_torres_destruidas_adversario;
    int total_mortes;
    int pontuacao_jogadores[5]; 
    jogadorPartida jogadores_partida[5];
}partida;

void recebe_cadastro(time *cadastroTime);
void introducao();
void menu();
void imprime_times(time cadastroTime);
void editar_time(time *cadastroTime);
int cadastrar_partida(partida cadastroPartida[], time *cadastroTime, int *quantidade_partidas, int resultado);
void imprime_partidas(time cadastroTime, partida cadastroPartida[], int quantidade_partidas);
int melhor_jogador(partida cadastroPartida);
void pesquisar_jogador(time cadastroTime);
int total_kills(partida cadastroPartida[], int quantidade_partidas);
int total_assistencias(partida cadastroPartida[], int quantidade_partidas);
void imprime_total_kills(partida cadastroPartida[], int quantidade_partidas);
int menor_pontuado(time cadastroTime);
void imprime_menor_pontuado(time cadastroTime, int quantidade_partidas);
int maior_pontuado(time cadastroTime);
void imprime_maior_pontuado(time cadastroTime, int quantidade_partida);
void sair();
void opcao_invalida();

int main(){
    
    //Declaração de variáveis.
    int quantidade_times, opcoes, pontuacao, quantidade_partidas, resultado;
    time cadastroTime;
    partida cadastroPartida[20];
    pontuacao = 0;
    quantidade_partidas = 0;
    
    introducao();

    //Menu com as possíveis opções para o usuário.
    do{
        menu();
        scanf("%d", &opcoes);
        setbuf(stdin, NULL);

        switch (opcoes){
        case 1:
            recebe_cadastro(&cadastroTime);
            break;
        
        case 2:
            imprime_times(cadastroTime);
            break;

        case 3:
            editar_time(&cadastroTime);
            break;

        case 4:
            cadastrar_partida(cadastroPartida, &cadastroTime, &quantidade_partidas, resultado);
            break;

        case 5:
            imprime_partidas(cadastroTime, cadastroPartida, quantidade_partidas);
            break;

        case 6:
            pesquisar_jogador(cadastroTime);
            break;

        case 7:
            imprime_total_kills(cadastroPartida, quantidade_partidas);
            break;

        case 8:
            imprime_menor_pontuado(cadastroTime, quantidade_partidas);
            break;
        
        case 9:
            imprime_maior_pontuado(cadastroTime, quantidade_partidas);
            break;

        case 10:
            sair();
            break;

        default:
            opcao_invalida();
        }

    }while(opcoes != 10);
    
}

//Da linha 129 a 168 void para receber o cadastro do time e os dados dos jogadores.
void recebe_cadastro(time (*cadastroTime)){

    printf("_________________________________________________\n");
    printf("\nNome do time: ");
    scanf("%[^\n]%*c", (*cadastroTime).nome_time);

    printf("\nNome do tecnico: ");
    scanf("%[^\n]%*c", (*cadastroTime).tecnico);
    printf("_________________________________________________\n");

    for(int i = 0; i < 5; i++){
        (*cadastroTime).jogadores[i].pontuacao = 0; //Igualando a pontuação de cada jogador a 0 ao inicio do cadastro.

        printf("\nNome do jogador: ");
        scanf("%[^\n]%*c", (*cadastroTime).jogadores[i].nome);

        printf("\nPosicao do jogador: ");
        scanf("%[^\n]%*c", (*cadastroTime).jogadores[i].posicao); //Linha 145 restringe as posições dos jogadores para apenas ADC, SUP, MID, TOP e JG.
            while(strcmp((*cadastroTime).jogadores[i].posicao, "ADC") != 0 && strcmp((*cadastroTime).jogadores[i].posicao, "SUP") != 0 && strcmp((*cadastroTime).jogadores[i].posicao, "TOP") != 0 && strcmp((*cadastroTime).jogadores[i].posicao, "JG") != 0 && strcmp((*cadastroTime).jogadores[i].posicao, "MID") != 0){
                printf("_________________________________________________\n");
                printf("\a\nSolicite uma posicao valida: ");
                scanf("%[^\n]%*c", (*cadastroTime).jogadores[i].posicao);
            }

        printf("\nIdade do jogador: ");
        scanf("%d", &(*cadastroTime).jogadores[i].idade);
        setbuf(stdin, NULL);
            while((*cadastroTime).jogadores[i].idade < 0 || (*cadastroTime).jogadores[i].idade > 150){
                printf("_________________________________________________\n");
                printf("\a\nSolicite uma idade valida: ");
                scanf("%d", &(*cadastroTime).jogadores[i].idade);
                setbuf(stdin, NULL);
            }
        
        (*cadastroTime).jogadores[i].id = i+1; //Definindo o número do ID dos jogadores.
        printf("_________________________________________________\n"); 

    }
    
}
 
//Void da linha 171 a 183 de impressão dos jogadores cadastrados.
void imprime_times(time cadastroTime){

    printf("_________________________________________________\n");
    printf("\nTime: %s", cadastroTime.nome_time);
    printf("\nTecnico: %s", cadastroTime.tecnico);
    printf("\nJogadores:\n ");
    for( int j = 0; j < 5; j++){
        printf("\n%d - %s - %s\n", cadastroTime.jogadores[j].id, cadastroTime.jogadores[j].nome, cadastroTime.jogadores[j].posicao);
        
    }
    
    printf("_________________________________________________\n\n");
}

//Void da linha 185 a 251 para editar o jogador caso queira.
void editar_time(time *cadastroTime){
    int busca_id;
    int i;
    int escolha; //Confirmação do usuário.
    int perdido = 1; //Variavel para verificar se o ID existe ou não.
    int jogador;

    printf("_________________________________________________\n");
    printf("\nDigite o ID do jogador que deseja editar: ");
    scanf("%d", &busca_id);
    setbuf(stdin, NULL);
    

    for(int j = 0; j < 5; j++){
        if((*cadastroTime).jogadores[(j)].id == busca_id){
            jogador = j;
            perdido = 0; //Caso o ID exista, perdido se iguala a 0.
            break;
        }
    }


    if(perdido == 1){ //Invalida o ID.
        printf("_________________________________________________\n\n");
        printf("\aNao achei esse ID! :(\n");
        printf("_________________________________________________\n\n");
        perdido++;
    }else{ //Caso exista o ID, recebe-se os novos dados do jogador com o ID compatível.
        
        printf("\nID - Nome - Posicao - Pontuacao\n");
        printf("\n%d - %s - %s - %d\n", (*cadastroTime).jogadores[jogador].id, (*cadastroTime).jogadores[jogador].nome, (*cadastroTime).jogadores[jogador].posicao, (*cadastroTime).jogadores[jogador].pontuacao);

        printf("_________________________________________________\n\n");
        printf("Deseja mesmo editar? Digite 1 para Sim e 2 para Nao\n"); 
        scanf("%d", &escolha);
        setbuf(stdin, NULL);
        if(escolha == 1){ //Se o usuário confirmar que deseja editar, segue-se para receber os novos dados do jogador.
            printf("_________________________________________________\n");
            printf("\nNome do jogador: ");
            scanf("%[^\n]%*c", (*cadastroTime).jogadores[jogador].nome);

            printf("\nPosicao do jogador: ");
            scanf("%[^\n]%*c", (*cadastroTime).jogadores[jogador].posicao);
                while(strcmp((*cadastroTime).jogadores[jogador].posicao, "ADC") != 0 && strcmp((*cadastroTime).jogadores[jogador].posicao, "SUP") != 0 && strcmp((*cadastroTime).jogadores[jogador].posicao, "TOP") != 0 && strcmp((*cadastroTime).jogadores[jogador].posicao, "JG") != 0 && strcmp((*cadastroTime).jogadores[jogador].posicao, "MID") != 0){
                    printf("_________________________________________________\n");
                    printf("\a\nSolicite uma posicao valida: ");
                    scanf("%[^\n]%*c", (*cadastroTime).jogadores[jogador].posicao);
                }

            printf("\nIdade do jogador: ");
            scanf("%d", &(*cadastroTime).jogadores[jogador].idade);
            setbuf(stdin, NULL);
                while((*cadastroTime).jogadores[jogador].idade < 0 || (*cadastroTime).jogadores[jogador].idade > 150){
                    printf("_________________________________________________\n");
                    printf("\a\nSolicite uma idade valida: ");
                    scanf("%d", &(*cadastroTime).jogadores[jogador].idade);
                    setbuf(stdin, NULL);
                }
            printf("_________________________________________________\n\n");
        

        }else{ //Se o usuário negar, então volta-se ao menu.
            return 0;
        }  
    }
}

//Função do tipo inteiro da linha 253 a 355 que recebe o cadastro de partida do time e devolve a variavel "quantidade_partidas", tal controla o numero de partidas.
int cadastrar_partida(partida cadastroPartida[], time *cadastroTime, int *quantidade_partidas, int resultado){

    int calculo_assistencia = 0;
    int calculo_kills = 0;
    int total_kills = 0;
    int confirmacao;
    int mortes = 0;
    int melhor_jogador_partida;
    int kills = 0;
    int pontuacao_partida;

    for(int j = 0; j < 5; j++){ //Segue-se a ordem de jogadores inseridos e recebe-se os dados de cada um.
        printf("_________________________________________________\n");
        printf("\n%d - %s - %s\n", (*cadastroTime).jogadores[j].id, (*cadastroTime).jogadores[j].nome, (*cadastroTime).jogadores[j].posicao);

        printf("\nInsira o numero de assistencias: ");
        scanf("%d", &cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_assistencias);
        setbuf(stdin, NULL);
            while(cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_assistencias < 0){ //Invalida assistencias negativas.
                printf("\n\aInsira um numero valido de assistencias: ");
                scanf("%d", &cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_assistencias);
            }
            
        calculo_assistencia = cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_assistencias * 1; //Calculo das assistencias para a pontuação do jogador.
    
        printf("\nInsira o numero de kills: ");
        scanf("%d", &kills);
        cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_kills = kills;
        setbuf(stdin, NULL);
            while(cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_kills < 0){ //Invalida kills negativas.
                printf("\n\aInsira um numero valido de kills: ");
                scanf("%d", &cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_kills);
            }

        total_kills += cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_kills; //Contabiliza o total de kills do time.
        calculo_kills = cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_kills * 3; //Calculo das kills para a pontuação do jogador.
    
        printf("\nInsira o numero de mortes: ");
        scanf("%d", &cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_mortes);
        setbuf(stdin, NULL);
            while(cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_mortes < 0){ //Invalida mortes negativas.
                printf("\n\aInsira um numero valido de mortes: "); 
                scanf("%d", &cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_mortes);
            }

        mortes += cadastroPartida[*quantidade_partidas].jogadores_partida[j].num_mortes; //Contabiliza as mortes para atribuir ao total de mortes aos jogadores na linha 198.
        cadastroPartida[*quantidade_partidas].total_mortes = mortes;

        (*cadastroTime).jogadores[j].pontuacao += (calculo_assistencia + calculo_kills); //Atribui os calculos das linhas 278 e 290 a pontuação do jogador.
        cadastroPartida[*quantidade_partidas].pontuacao_jogadores[j] = (calculo_assistencia + calculo_kills);
    }

    printf("_________________________________________________\n");
    printf("\nTotal de kills do seu time foi: %d \nConfirmar sim (1) nao (2): ", total_kills); //Mostra o total de kills já somadas, mas caso o usuário não concorde, ele mesmo pode inserir o somatório.
    scanf("%d", &confirmacao);
    if(confirmacao != 1){ //Recebe o novo total de kills.
        printf("\nDigite o total de kills de seu time: ");
        scanf("%d", &cadastroPartida[*quantidade_partidas].total_kills_time);
        setbuf(stdin, NULL);
    }else{ //Continua com o total já calculado.
        cadastroPartida[*quantidade_partidas].total_kills_time = 0;
        cadastroPartida[*quantidade_partidas].total_kills_time = total_kills;
    }

    printf("\nTotal de kills do time adversario: ");
    scanf("%d", &cadastroPartida[*quantidade_partidas].total_kills_adversario);
    setbuf(stdin, NULL);

    printf("\nO resultado foi vitoria (1) ou derrota (2): "); //Validação de vitoria ou derrota.
    scanf("%d", &resultado);
    setbuf(stdin, NULL);
        if(resultado == 1){ //Vitoria.
            cadastroPartida[*quantidade_partidas].vitoria = true;
        }else{ //Derrota.
            cadastroPartida[*quantidade_partidas].vitoria = false;
        }

    printf("\nTotal de torres destruidas pelo seu time: ");
    scanf("%d", &cadastroPartida[*quantidade_partidas].total_torres_destruidas_time);
    setbuf(stdin, NULL);
        while(cadastroPartida[*quantidade_partidas].total_torres_destruidas_time > 11 || cadastroPartida[*quantidade_partidas].total_torres_destruidas_time < 0){
            printf("\aInsira um numero valido (max. 11): "); //Invalida numero de torres maior que 11 ou de numeros negativos.
            scanf("%d", &cadastroPartida[*quantidade_partidas].total_torres_destruidas_time);
            setbuf(stdin, NULL);
        }

    printf("\nTotal de torres destruidas pelo time adversario: ");
    scanf("%d", &cadastroPartida[*quantidade_partidas].total_torres_destruidas_adversario);
    setbuf(stdin, NULL);
        while(cadastroPartida[*quantidade_partidas].total_torres_destruidas_adversario > 11 || cadastroPartida[*quantidade_partidas].total_torres_destruidas_adversario < 0){
            printf("\aInsira um numero valido (max. 11): "); //Invalida numero de torres maior que 11 ou de numeros negativos.
            scanf("%d", &cadastroPartida[*quantidade_partidas].total_torres_destruidas_adversario);
            setbuf(stdin, NULL);
        }

    printf("_________________________________________________\n");

    //Ao fim dessa função, se contabiliza uma partida.
    (*quantidade_partidas)++;
    return quantidade_partidas;
}

//Void que imprime alguns dos dados das partidas cadastradas, mostrando o MVP de cada uma delas.
void imprime_partidas(time cadastroTime, partida cadastroPartida[], int quantidade_partidas){
    int maior_pontuacao;
    
    for(int i = 0; i < quantidade_partidas; i++){
        maior_pontuacao = melhor_jogador(cadastroPartida[i]);
        printf("_________________________________________________\n");
        if(cadastroPartida[quantidade_partidas].vitoria == true){
            printf("Vitoria");
        }else{
            printf("Derrota");
        }
        printf("\nNumero de kills do time: %d", cadastroPartida[i].total_kills_time);
        printf("\nNumero de mortes do time: %d", cadastroPartida[i].total_mortes);
        printf("\nNumero de torres destruidas do time: %d", cadastroPartida[i].total_torres_destruidas_time);
        printf("\nNumero de torres destuidas adversario: %d", cadastroPartida[i].total_torres_destruidas_adversario); 
        printf("\nPosicao destaque: %s, com pontuacao %d\n", cadastroTime.jogadores[maior_pontuacao].nome, cadastroPartida[i].pontuacao_jogadores[maior_pontuacao]);
        printf("_________________________________________________\n");
    }
}

//Função do tipo inteiro para registrar o melhor jogador de uma partida.
int melhor_jogador(partida cadastroPartida){
    int maior;
    int pontuacao = 0;

    for(int i = 0; i < 5; i++){
        if(cadastroPartida.pontuacao_jogadores[i] > pontuacao){
            pontuacao = cadastroPartida.pontuacao_jogadores[i];
            maior = i;
        } 
    }
    return maior;
}

//Void de pesquisa do jogador a partir de seu ID.
void pesquisar_jogador(time cadastroTime){

    int busca_jogador;
    int inexistente = 0; //Variavel para caso o ID não exista.

    printf("\nDigite o ID do jogador que deseja pesquisar: ");
    scanf("%d", &busca_jogador);

    for(int i = 0; i < 5; i++){
        if(cadastroTime.jogadores[i].id == busca_jogador){
            printf("_________________________________________________\n");
            printf("\nID:%d \nNome: %s \nPosicao: %s \nIdade: %d \nPontuacao: %d\n", cadastroTime.jogadores[i].id, cadastroTime.jogadores[i].nome, cadastroTime.jogadores[i].posicao, cadastroTime.jogadores[i].idade, cadastroTime.jogadores[i].pontuacao);
            printf("_________________________________________________\n");
            inexistente = 0; //Zera quando o ID existe.
            break;
        }else{ //Contabiliza caso o ID não exista.
            inexistente++;
        }
    }

    while(inexistente != 0){ //Volta ao Menu caso o ID não exista.
        inexistente = 0;
        printf("_________________________________________________\n\n");
        printf("\aNao achei esse jogador!\n");
        printf("_________________________________________________\n\n");
    }
}

//Função do tipo inteiro para somar o total de kills de todas as partidas e retorna seu somatório.
int total_kills(partida cadastroPartida[], int quantidade_partidas){
    int soma_kills = 0;

    for(int i = 0; i < quantidade_partidas; i++){
        for(int j = 0; j < 5; j++){
            soma_kills += cadastroPartida[i].jogadores_partida[j].num_kills;
        }
    }
    return soma_kills;
}

//Função do tipo inteiro para somar o total de assistencias de todas as partidas e retorna seu somatório.
int total_assistencias(partida cadastroPartida[], int quantidade_partidas){
    int soma_assistencias = 0;

    for(int i = 0; i < quantidade_partidas; i++){
        for(int j = 0; j < 5; j++){
            soma_assistencias += cadastroPartida[i].jogadores_partida[j].num_assistencias;
        }
    }
    return soma_assistencias;
}

//Void que imprime o total de kills e assistencias de todas as partidas.
void imprime_total_kills(partida cadastroPartida[], int quantidade_partidas){
    int resultado_kills;
    int resultado_assistencias;
    //Funções da linha 448 e 450 responsáveis pelo somatório de kills e assistencias, respectivamente.
    resultado_kills = total_kills(cadastroPartida, quantidade_partidas);
    resultado_assistencias = total_assistencias(cadastroPartida, quantidade_partidas);

    printf("_________________________________________________\n\n");
    printf("\nEsse foi o total de kills do time: %d", resultado_kills);
    printf("\nEsse foi o total de assistencias do time: %d\n", resultado_assistencias);
    printf("_________________________________________________\n\n");
    
}

//Função do tipo inteiro que verifica o jogador de menor pontuação de acordo com todas as partidas.
int menor_pontuado(time cadastroTime){
    int menor;
    int pontuacao = 9999;

    for(int i = 0; i < 5; i++){
        if(cadastroTime.jogadores[i].pontuacao < pontuacao){
            pontuacao = cadastroTime.jogadores[i].pontuacao;
            menor = i;
        }
    }
    return menor;
}

//Imprime o menor pontuado.
void imprime_menor_pontuado(time cadastroTime, int quantidade_partidas){
    int menor;
    menor = menor_pontuado(cadastroTime); //função responsável pela verificação.

    printf("_________________________________________________\n");
    printf("\nEsse foi o jogador de menor pontuacao: \n");
    printf("\nID: %d \nNome: %s \nPosicao: %s \nIdade: %d \nPontuacao: %d\n", cadastroTime.jogadores[menor].id, cadastroTime.jogadores[menor].nome, cadastroTime.jogadores[menor].posicao, cadastroTime.jogadores[menor].idade, cadastroTime.jogadores[menor].pontuacao);
    printf("_________________________________________________\n");
    
}

//Função do tipo inteiro que verifica o jogador de maior pontuação de acordo com todas as partidas.
int maior_pontuado(time cadastroTime){
    int maior;
    int pontuacao = 0;

    for(int i = 0; i < 5; i++){
        if(cadastroTime.jogadores[i].pontuacao > pontuacao){
            pontuacao = cadastroTime.jogadores[i].pontuacao;
            maior = i;
        }
    }
    return maior;
}

//Imprime o jogador mais pontuado.
void imprime_maior_pontuado(time cadastroTime, int quantidade_partida){
    int maior;
    maior = maior_pontuado(cadastroTime); //função responsável pela verificação.

    printf("_________________________________________________\n");
    printf("\nEsse foi o jogador de maior pontuacao: \n");
    printf("\nID: %d \nNome: %s \nPosicao: %s \nIdade: %d \nPontuacao: %d\n", cadastroTime.jogadores[maior].id, cadastroTime.jogadores[maior].nome, cadastroTime.jogadores[maior].posicao, cadastroTime.jogadores[maior].idade, cadastroTime.jogadores[maior].pontuacao);
    printf("_________________________________________________\n");

}

//Voids da linha 513 a 543 destinadas a introdução do usuário, menu, saída e invalidação caso o usuário digite um número fora de 1 a 10.
void introducao(){
    printf("_________________________________________________\n");
    printf("            Ola! Seja bem vindo ^^\n");
    printf("_________________________________________________\n\n");
}

void menu(){
    printf("               MENU DE OPCOES\n");
    printf("_________________________________________________\n\n");
    printf("1) Cadastrar time\n");
    printf("2) Listar time\n");
    printf("3) Editar time\n");
    printf("4) Cadastrar partida\n");
    printf("5) Listar partidas\n");
    printf("6) Pesquisar jogador\n");
    printf("7) Mostrar numero total de kills e assistencias\n");
    printf("8) Mostrar jogador com menor pontuacao\n");
    printf("9) Mostrar jogador com maior pontuacao\n");
    printf("10) Sair\n");
    printf("_________________________________________________\n");
}

void sair(){
    printf("_________________________________________________\n");
    printf("\n");
    printf("Tchauzinho! :)\n");
    printf("_________________________________________________\n");
}

void opcao_invalida(){
    printf("_________________________________________________\n");
    printf("\aPor favor, digite um numero de 1 a 10!\n");
    printf("_________________________________________________\n");
}