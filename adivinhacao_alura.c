#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {

    // imprimindo cabecalho bonito do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    //declarando variaveis
    int chute;
    int acertou;
    int nivel;
    int tentativas;

    //definindo pontos
    double pontos = 1000;
    srand(time(0));
    int numerosecreto = rand() % 100;

    //niveis de dificuldade
    printf("Qual nivel voce deseja?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n");
    printf("Escolha:\n");

    scanf("%d", &nivel);

    switch(nivel) {
        case 1 :
        tentativas = 15;
        break;

        case 2 :
        tentativas = 10;
        break;

        case 3 :
        tentativas = 5;
        break;
    }

    for(int i = 1; i <= tentativas; i++) {

        printf("-> Tentativa %d de %d\n", i, tentativas);
        printf("Qual o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o numero secreto\n");
        } 

        else {
            printf("Seu chute foi menor que o numero secreto\n");
        }

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("\n");
    if(acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nParabens! Voce acertou!\n");
        printf("Voce fez %.2f pontos. Ate a proxima!\n\n", pontos);
    } else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

        printf("\nVoce perdeu! Tente novamente!\n\n");
    }
}