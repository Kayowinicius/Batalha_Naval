#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_CAMPO 5
#define MAX_BARCO 8  // Número de barcos no total (4 para os dois jogadores)
#define PORTAAVIOES 4 // Nome e valor do barco 1
#define DESTROYER 3 // Nome e valor do barco 2
#define FRAGATA 2 // Nome e valor do barco 3
#define SUBMARINO 1  // Nome e valor do barco 4

//Função pra garantir que todos os campos sejam 0 no início
void inicializarCampo(int campo[TAMANHO_CAMPO][TAMANHO_CAMPO]) {
    for (int i = 0; i < TAMANHO_CAMPO; i++) {
        for (int j = 0; j < TAMANHO_CAMPO; j++) {
            campo[i][j] = 0;
        }
    }
}

//Função que posiciona os barcos de acordo com a posição X e Y do campo
void posicionarBarcos(int tipo_barco, int campo[TAMANHO_CAMPO][TAMANHO_CAMPO]){
    int x, y; //Variáveis que determinam a pocição do barco em relação ao campo
    // Verifica e solicita até que a posição seja válida
    while (1) { // Loop infinito para garantir repetição até inserir uma posição válida
        printf("Selecione a posicao X: ");
        scanf("%d", &x);
        printf("Selecione a posicao Y: ");
        scanf("%d", &y);

        // Verifica se a posição está dentro dos limites do campo
        if (x >= 0 && x < TAMANHO_CAMPO && y >= 0 && y < TAMANHO_CAMPO) {
            if (campo[x][y] == 0) {
                campo[x][y] = tipo_barco; // Insere o barco no campo
                printf("Barco %d posicionado em (%d , %d).\n", tipo_barco, x, y);
                printf("=================================================================\n");
                break; // Sai do loop quando a posição for válida
            } else {
                printf("Ja ha um barco nesta posicao! Tente novamente.\n");
            }
        } else {
            printf("Posicao invalida! Tente novamente.\n");
        }
    }

}

// Função para realizar a jogada de um jogador
int RealizarJogada(int campo[TAMANHO_CAMPO][TAMANHO_CAMPO]) {
    int x, y, Pontuacao = 0;

    // Bloco para escolher a coordenada de ataque
    while (1) { // Loop até que o jogador insira uma posição válida
        printf("X: ");
        scanf("%d", &x);
        printf("Y: ");
        scanf("%d", &y);

        // Verifica se a jogada está dentro dos limites do campo
        if (x >= 0 && x < TAMANHO_CAMPO && y >= 0 && y < TAMANHO_CAMPO) {
            if (campo[x][y] == 0) {
                printf("Chuaaa, Nada!\n");
                break; // Jogada errada, mas válida
            } else if (campo[x][y] == -1) { // Se um barco foi afundado
                printf("Este local já foi atacado! Tente outro.\n");
            } else {
                int pontuacaoBarco = campo[x][y];
                campo[x][y] = -1; // Afunda o barco
                
                // Atribui pontos conforme o tipo do barco atingido
                switch (pontuacaoBarco) {
                    case SUBMARINO:
                        Pontuacao += SUBMARINO;
                        printf("Você acertou um Submarino! +%d ponto.\n", SUBMARINO);
                        break;
                    case FRAGATA:
                        Pontuacao += FRAGATA;
                        printf("Você acertou uma Fragata! +%d ponto.\n", FRAGATA);
                        break;
                    case DESTROYER:
                        Pontuacao += DESTROYER;
                        printf("Você acertou um Destroyer! +%d ponto.\n", DESTROYER);
                        break;
                    case PORTAAVIOES:
                        Pontuacao += PORTAAVIOES;
                        printf("Você acertou um Porta-Aviões! +%d ponto.\n", PORTAAVIOES);
                        break;
                }
                break; // Jogada válida, sai do loop
            }
        } else {
            printf("Posição inválida! As coordenadas devem estar entre 0 e %d.\n", TAMANHO_CAMPO - 1);
        }
    }

    return Pontuacao;
}

int main() {
    char jogador1[30], jogador2[30];  // Vetores para armazenar os nomes dos jogadores
    int campo_a[TAMANHO_CAMPO][TAMANHO_CAMPO];
    int campo_b[TAMANHO_CAMPO][TAMANHO_CAMPO];
    int Pontuacao1 = 0, Pontuacao2 = 0;

    inicializarCampo(campo_a);
    inicializarCampo(campo_b);

    // Leitura dos nomes dos jogadores
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogador1);  // Lê o nome do jogador 1

    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogador2);  // Lê o nome do jogador 2

    // Exibe os nomes informados
    printf("Jogador 1: %s\n", jogador1);
    printf("Jogador 2: %s\n", jogador2);

 
    printf("=================================================================\n");

    printf("%s posicione o Submarino com valor de 1 ponto:\n", jogador1);
    posicionarBarcos(SUBMARINO, campo_a);

    printf("%s posicione a Fragata com valor de 2 pontos:\n", jogador1);
    posicionarBarcos(FRAGATA, campo_a);

    printf("%s posicione o Destroyer com valor de 3 pontos:\n", jogador1);
    posicionarBarcos(DESTROYER, campo_a);

    printf("%s posicione o Porta Avioes com valor de 4 pontos:\n", jogador1);
    posicionarBarcos(PORTAAVIOES, campo_a);

    printf("Vez do Jogador %s:\n", jogador2);

    printf("%s posicione o Submarino com valor de 1 ponto:\n", jogador2);
    posicionarBarcos(SUBMARINO, campo_b);

    printf("%s posicione a Fragata com valor de 2 pontos:\n", jogador2);
    posicionarBarcos(FRAGATA, campo_b);

    printf("%s posicione o Destroyer com valor de 3 pontos:\n", jogador2);
    posicionarBarcos(DESTROYER, campo_b);

    printf("%s posicione o Porta Avioes com valor de 4 pontos:\n", jogador2);
    posicionarBarcos(PORTAAVIOES, campo_b);
    
    printf("Hora de atacar! 5 tentativas para cada jogador.\n");
    
    for(int i = 0; i < 5; i++){ //Loop pra permitir a jogada de cada jogador 5 vezes - Igor
        printf("\n%s sua vez de jogar!\n", jogador1);
        Pontuacao1 += RealizarJogada(campo_a);
        printf("\n%s sua vez de jogar!\n", jogador2);
        Pontuacao2  += RealizarJogada(campo_a);
    }
    
    if(Pontuacao1 > Pontuacao2) {
       printf("\nCom %d pontos, %s ganhou!!!", Pontuacao1, jogador1); 
    } else if(Pontuacao1 < Pontuacao2) {
       printf("\nCom %d pontos, %s ganhou!!!",  Pontuacao2, jogador2); 
    } else {
        printf("Empate!");
    }
}