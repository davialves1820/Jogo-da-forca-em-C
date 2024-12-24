#include "jogo.h"

// Função que verifica se o jogador acertou a letra chutada
int tentativa(char *str, char chute) {

    int d = strlen(str);
    for (int i = 0; i < d; i++) {
        if (str[i] == chute) {
            return 0;
        }
    }
    return 1;
}

// Função que cria uma palavra substituindo os caracteres a adivinhar por '_'
void esconder_palavra(char *str, int tam) {

    for (int i = 0; i < tam; i++) {
        str[i] = '_';
    }
    str[tam] = '\0';
}

// Função que vai desvendando a palavra_escondida de acordo com os acertos do jogador
void montar_foca(char *str, char chute, char *armazenar) {

    int d = strlen(str);
    for (int i = 0; i < d; i++) {
        if (str[i] == chute) {
            armazenar[i] = str[i];
        }
    }
}

// Função que ler o caracter chutado pelo jogador
char letra() {
    
    char c;
    scanf(" %c", &c);
    return tolower(c);
}
