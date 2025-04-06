#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 1;
    int linha_vertical = 5, coluna_vertical = 7;

    // Posiciona navio horizontal
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posiciona navio vertical
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Exibe o tabuleiro
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}