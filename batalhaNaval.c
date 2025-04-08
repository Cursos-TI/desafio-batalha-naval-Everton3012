#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Inicializa o tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0; // água
        }
    }

    // Adicionando navios manualmente como exemplo
    tabuleiro[1][2] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;
}

// Exibe o tabuleiro no console
void mostrarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
}

// Cria a área de efeito em forma de cone
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i)
                habilidade[i][j] = 1; // afetado
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria a área de efeito em forma de cruz
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria a área de efeito em forma de octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Aplica a habilidade no tabuleiro a partir de um ponto de origem
void aplicarHabilidadeNoTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                                   int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                                   int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha - TAM_HABILIDADE / 2 + i;
            int colunaTab = origemColuna - TAM_HABILIDADE / 2 + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO &&
                colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {
                
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0) {
                    tabuleiro[linhaTab][colunaTab] = 5; // marca como área afetada
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    // -------- HABILIDADE: CONE --------
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeCone(habilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidade, 2, 2); // origem (2,2)
    printf("Exemplo de habilidade em forma de CONE:\n");
    mostrarTabuleiro(tabuleiro);

    // -------- HABILIDADE: CRUZ --------
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeCruz(habilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidade, 2, 2); // origem (2,2)
    printf("Exemplo de habilidade em forma de CRUZ:\n");
    mostrarTabuleiro(tabuleiro);

    // -------- HABILIDADE: OCTAEDRO --------
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeOctaedro(habilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidade, 2, 2); // origem (2,2)
    printf("Exemplo de habilidade em forma de OCTAEDRO:\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}
