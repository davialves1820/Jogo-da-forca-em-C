#include "palavras.h"
#include "exibir_jogo.h"
#include "jogo.h"

int main(void) {

    int dificuldade, jogar_novamente;
    char palavra[20];

    do {
        do {
            printf("Qual a dificuldade facil(1) dificil(2): ");
            scanf("%d", &dificuldade);
        } while (dificuldade > 2 || dificuldade < 1);

        getchar();
        if (dificuldade == 1) {
            armazem_palavras(palavra);
        } else {
            gerar_string(10, palavra);
        }

        int tam = strlen(palavra);
        char palavra_escondida[tam];
        esconder_palavra(palavra_escondida, tam);

        printf("Boa sorte\n");
        
        int tentativas = 0;
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
        } while (tentativas < 7 && strcmp(palavra_escondida, palavra) != 0);

        if (tentativas == 7) {

            printf("\nVoce perdeu :(\n");
            printf("A palavra era %s\n", palavra);
        } else {

            printf("\nVoce ganhou :)\n");
            printf("A palavra era %s\n", palavra);
        }
        printf("Voce quer jogar novamente? \n1-sim\n0-nao\n");
        scanf("%d", &jogar_novamente);
    } while (jogar_novamente == 1);

    

    return 0;
}