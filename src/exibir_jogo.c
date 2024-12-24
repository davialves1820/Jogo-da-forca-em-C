#include "exibir_jogo.h"

// Atualiza o desenho de acordo com a quantidade de erros do jogador
void desenhar_forca(int erros) {
    
    switch (erros) {
        case 0:
            printf(" ---|\n");
            break;
        case 1:
            printf("---|\n");
            printf("   O\n");
            break;
        case 2:
            printf("---|\n");
            printf("   O\n");
            printf("   |\n");
            break;
        case 3:
            printf("---|\n");
            printf("   O\n");
            printf("  /|\n");
            break;
        case 4:
            printf("---|\n");
            printf("   O\n");
            printf("  /|\\\n");
            break;
        case 5:
            printf("---|\n");
            printf("   O\n");
            printf("  /|\\\n");
            printf("  /\n");
            break;
        case 6: // Fim de jogo
            printf("---|\n");
            printf("   O\n");
            printf("  /|\\\n");
            printf("  / \\\n");
            break;
        default:
            break;
    }
}