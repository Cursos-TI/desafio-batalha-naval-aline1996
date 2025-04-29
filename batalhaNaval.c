#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void exibirMatriz(int matriz[5][5], const char* nome) {
    printf("\nHabilidade: %s\n", nome);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionamento dos navios
    int linha_horizontal = 2; // linha 3 (índice 2)
    int coluna_horizontal = 3; // coluna D (índice 3)

    int linha_vertical = 5; // linha 6 (índice 5)
    int coluna_vertical = 7; // coluna H (índice 7)

    // Posiciona navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posiciona navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Posiciona navio na diagonal principal
    int inicio_diagonal_principal = 0;
    for (int i = 0; i < 3; i++) {
        tabuleiro[inicio_diagonal_principal + i][inicio_diagonal_principal + i] = 3;
    }

    // Posiciona navio na diagonal secundária
    int inicio_diagonal_secundaria_linha = 0;
    int inicio_diagonal_secundaria_coluna = 9;
    for (int i = 0; i < 3; i++) {
        tabuleiro[inicio_diagonal_secundaria_linha + i][inicio_diagonal_secundaria_coluna - i] = 3;
    }

    // Exibe o cabeçalho do tabuleiro
    printf("   TABULEIRO BATALHA NAVAL\n");
    printf("    ");
    for (char letra = 'A'; letra < 'A' + 10; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Exibe o conteúdo do tabuleiro com numeração lateral
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", i + 1);  // Número da linha
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Preencher CONE: base larga na parte inferior
    for (int i = 0; i < 5; i++) {
        int start = 2 - i;
        int end = 2 + i;
        if (start < 0) start = 0;
        if (end >= 5) end = 5 - 1;
        for (int j = start; j <= end; j++) {
            cone[i][j] = 1;
        }
    }

    // Preencher CRUZ 
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // linha central
        cruz[i][2] = 1; // coluna central
    }

    // Preencher OCTAEDRO
    for (int i = 0; i < 5; i++) {
        int distancia = (i < 3) ? i : 4 - i;
        for (int j = 2 - distancia; j <= 2 + distancia; j++) {
            octaedro[i][j] = 1;
        }
    }

    // Exibir as matrizes
    exibirMatriz(cone, "CONE");
    exibirMatriz(cruz, "CRUZ");
    exibirMatriz(octaedro, "OCTAEDRO");

    return 0;
}