#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro (10x10)
#define NAVIO 3     // Valor que representa um navio no tabuleiro
#define TAM_NAVIO 3 // Tamanho fixo de cada navio

int main() {

    // ------------------------------------------------------------
    // 1. DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    // ------------------------------------------------------------
    int tabuleiro[TAM][TAM];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ------------------------------------------------------------
    // 2. DECLARAÇÃO DOS NAVIOS (vetores representando cada navio)
    // ------------------------------------------------------------
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // ------------------------------------------------------------
    // 3. DEFINIÇÃO DAS COORDENADAS INICIAIS DOS NAVIOS
    // (Podem ser alteradas, pois são fixas no código)
    // ------------------------------------------------------------

    // Navio horizontal começando na linha 2, coluna 4
    int linhaH = 2;
    int colunaH = 4;

    // Navio vertical começando na linha 5, coluna 7
    int linhaV = 5;
    int colunaV = 7;

    // ------------------------------------------------------------
    // 4. VALIDAÇÃO DO POSICIONAMENTO (dentro dos limites)
    // ------------------------------------------------------------
    // Valida navio horizontal
    if (colunaH + TAM_NAVIO > TAM) {
        printf("ERRO: Navio horizontal fora dos limites!\n");
        return 1;
    }

    // Valida navio vertical
    if (linhaV + TAM_NAVIO > TAM) {
        printf("ERRO: Navio vertical fora dos limites!\n");
        return 1;
    }

    // ------------------------------------------------------------
    // 5. VERIFICA SE HÁ SOBREPOSIÇÃO ENTRE OS DOIS NAVIOS
    // ------------------------------------------------------------
    for (int i = 0; i < TAM_NAVIO; i++) {
        int hLinha = linhaH;
        int hCol = colunaH + i;

        int vLinha = linhaV + i;
        int vCol = colunaV;

        if (hLinha == vLinha && hCol == vCol) {
            printf("ERRO: Navios sobrepostos!\n");
            return 1;
        }
    }

    // ------------------------------------------------------------
    // 6. POSICIONA OS NAVIOS NO TABULEIRO
    // ------------------------------------------------------------

    // Navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // ------------------------------------------------------------
    // 7. EXIBE O TABULEIRO NA TELA
    // ------------------------------------------------------------

    printf("\n--- TABULEIRO BATALHA NAVAL ---\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
