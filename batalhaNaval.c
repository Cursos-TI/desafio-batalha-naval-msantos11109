#include <stdio.h>

#define TAM 10          // Tamanho do tabuleiro 10x10
#define NAVIO 3         // Valor que marca um navio no tabuleiro
#define TAM_NAVIO 3     // Tamanho fixo de cada navio

// ------------------------------------------------------------
// Função que verifica se um navio pode ser colocado em certas
// coordenadas (horizontal, vertical ou diagonal) SEM sair do
// tabuleiro e SEM sobrepor outro navio.
// ------------------------------------------------------------
int podeColocar(int tabuleiro[TAM][TAM], int coords[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int lin = coords[i][0];
        int col = coords[i][1];

        // Verifica limites
        if (lin < 0 || lin >= TAM || col < 0 || col >= TAM)
            return 0;

        // Verifica sobreposição
        if (tabuleiro[lin][col] == NAVIO)
            return 0;
    }
    return 1;
}

// ------------------------------------------------------------
// Função que coloca um navio no tabuleiro
// ------------------------------------------------------------
void colocarNavio(int tabuleiro[TAM][TAM], int coords[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int lin = coords[i][0];
        int col = coords[i][1];
        tabuleiro[lin][col] = NAVIO;
    }
}

int main() {

    // ------------------------------------------------------------
    // 1. CRIAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    // ------------------------------------------------------------
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // ------------------------------------------------------------
    // 2. DEFINIÇÃO DOS 4 NAVIOS (2 normais + 2 diagonais)
    //    Todos com tamanho 3 e coordenadas fixas no código.
    // ------------------------------------------------------------

    // NAVIO 1 - Horizontal
    int navio1[TAM_NAVIO][2] = {
        {2, 1},
        {2, 2},
        {2, 3}
    };

    // NAVIO 2 - Vertical
    int navio2[TAM_NAVIO][2] = {
        {5, 7},
        {6, 7},
        {7, 7}
    };

    // NAVIO 3 - Diagonal principal (↘)
    int navio3[TAM_NAVIO][2] = {
        {1, 1},
        {2, 2},
        {3, 3}
    };

    // NAVIO 4 - Diagonal secundária (↙)
    int navio4[TAM_NAVIO][2] = {
        {1, 8},
        {2, 7},
        {3, 6}
    };

    // ------------------------------------------------------------
    // 3. VALIDAÇÃO E POSICIONAMENTO DOS NAVIOS
    // ------------------------------------------------------------
    if (!podeColocar(tabuleiro, navio1, TAM_NAVIO)) {
        printf("Erro: Navio 1 inválido ou sobreposto!\n");
        return 1;
    }
    colocarNavio(tabuleiro, navio1, TAM_NAVIO);

    if (!podeColocar(tabuleiro, navio2, TAM_NAVIO)) {
        printf("Erro: Navio 2 inválido ou sobreposto!\n");
        return 1;
    }
    colocarNavio(tabuleiro, navio2, TAM_NAVIO);

    if (!podeColocar(tabuleiro, navio3, TAM_NAVIO)) {
        printf("Erro: Navio 3 inválido ou sobreposto!\n");
        return 1;
    }
    colocarNavio(tabuleiro, navio3, TAM_NAVIO);

    if (!podeColocar(tabuleiro, navio4, TAM_NAVIO)) {
        printf("Erro: Navio 4 inválido ou sobreposto!\n");
        return 1;
    }
    colocarNavio(tabuleiro, navio4, TAM_NAVIO);


    // ------------------------------------------------------------
    // 4. EXIBIÇÃO DO TABULEIRO
    // ------------------------------------------------------------
    printf("\n--- TABULEIRO BATALHA NAVAL (Nível Intermediário) ---\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

