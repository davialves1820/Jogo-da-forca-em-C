#include "palavras.h"
#include "exibir_jogo.h"
#include "jogo.h"

int main(void) {
    
    int dificuldade, jogar_novamente;
    char palavra[21];

    // Looping de uma partida
    do {
        // Seleciona a dificuldade escolhida pelo jogador
        do {
            printf("Qual a dificuldade? \n1-Medio\n2-Dificil\n ");
            scanf("%d", &dificuldade);
        } while (dificuldade > 2 || dificuldade < 1);

        getchar();
        // Seleciona a palavra de acordo com a dificuldade
        if (dificuldade == 1) {
            armazem_palavras(palavra);
        } else {
            gerar_string(10, palavra);
        }

        // Esconde os caracteres da palavra com '_' e armazena em palavra_escondida
        int tam = strlen(palavra);
        char palavra_escondida[tam];
        esconder_palavra(palavra_escondida, tam);

        printf("Boa sorte\n");
        
        int tentativas = 0;
        // Inicia o looping do jogo 
        do {
            desenhar_forca(tentativas);
            printf("\n%s\n", palavra_escondida);

            printf("Chute uma letra:\n");
            char c = letra();
            getchar();

            if (tentativa(palavra, c)) {
                tentativas++;
            }

            montar_foca(palavra, c, palavra_escondida);
        } while (tentativas < 7 && strcmp(palavra_escondida, palavra) != 0); // Acaba quando acabarem as tentativas ou a palavra for totalmente desvendada

        // Informa que o jogador perdeu
        if (tentativas == 7) {
            
            printf("\nVoce perdeu :(\n");
            printf("A palavra era %s\n", palavra);
        } else { // Informa que ele ganhou
            
            printf("\nVoce ganhou :)\n");
            printf("A palavra era %s\n", palavra);
        }
        // Pergunta se o jogador quer jogar novamente
        printf("Voce quer jogar novamente? \n1-sim\n0-nao\n");
        scanf("%d", &jogar_novamente);
    } while (jogar_novamente == 1);

    return 0;
}
