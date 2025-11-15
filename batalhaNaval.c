#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define HABILIDADE 5

// ---------- Função para inicializar tabuleiro ----------
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
}

// ---------- Função para posicionar navio horizontal ----------
int navioHorizontal(int tab[TAM][TAM], int linha, int coluna) {
    if (coluna + 3 > TAM) return 0;

    for (int i = 0; i < 3; i++) {
        if (tab[linha][coluna + i] != 0) return 0;
    }

    for (int i = 0; i < 3; i++) {
        tab[linha][coluna + i] = NAVIO;
    }

    return 1;
}

// ---------- Função para posicionar navio vertical ----------
int navioVertical(int tab[TAM][TAM], int linha, int coluna) {
    if (linha + 3 > TAM) return 0;

    for (int i = 0; i < 3; i++) {
        if (tab[linha + i][coluna] != 0) return 0;
    }

    for (int i = 0; i < 3; i++) {
        tab[linha + i][coluna] = NAVIO;
    }

    return 1;
}

// ---------- Navio diagonal principal (↘) ----------
int navioDiagonalPrincipal(int tab[TAM][TAM], int linha, int coluna) {
    if (linha + 3 > TAM || coluna + 3 > TAM) return 0;

    for (int i = 0; i < 3; i++) {
        if (tab[linha + i][coluna + i] != 0) return 0;
    }

    for (int i = 0; i < 3; i++) {
        tab[linha + i][coluna + i] = NAVIO;
    }

    return 1;
}

// ---------- Navio diagonal secundária (↙) ----------
int navioDiagonalSec(int tab[TAM][TAM], int linha, int coluna) {
    if (linha + 3 > TAM || coluna - 2 < 0) return 0;

    for (int i = 0; i < 3; i++) {
        if (tab[linha + i][coluna - i] != 0) return 0;
    }

    for (int i = 0; i < 3; i++) {
        tab[linha + i][coluna - i] = NAVIO;
    }

    return 1;
}

// ---------- Exibir tabuleiro ----------
void imprimirTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

// ---------- Criar matriz habilidade Cone 5x5 ----------
void criarCone(int cone[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// ---------- Criar Cruz 5x5 ----------
void criarCruz(int cruz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// ---------- Criar Octaedro 5x5 ----------
void criarOctaedro(int oct[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((abs(i - centro) + abs(j - centro)) <= 2)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
}

// ---------- Aplicar habilidade no tabuleiro ----------
void aplicarHabilidade(int tab[TAM][TAM], int hab[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (hab[i][j] == 1) {

                int linhaTab = origemLinha + (i - 2);
                int colunaTab = origemColuna + (j - 2);

                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    if (tab[linhaTab][colunaTab] == 0)
                        tab[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

// -------------------------------------------------------------

int main() {

    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    navioHorizontal(tabuleiro, 1, 2);
    navioVertical(tabuleiro, 4, 5);
    navioDiagonalPrincipal(tabuleiro, 6, 1);
    navioDiagonalSec(tabuleiro, 2, 8);

    // Matrizes das habilidades
    int cone[5][5], cruz[5][5], oct[5][5];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 3);
    aplicarHabilidade(tabuleiro, cruz, 7, 7);
    aplicarHabilidade(tabuleiro, oct, 5, 5);

    // Exibir resultado final
    printf("\n===== TABULEIRO FINAL =====\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
