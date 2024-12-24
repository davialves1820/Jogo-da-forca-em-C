#include "jogo.h"

int tentativa(char *str, char chute) {

    int d = strlen(str);
    for (int i = 0; i < d; i++) {
        if (str[i] == chute) {
            return 0;
        }
    }
    return 1;
}

void montar_foca(char *str, char chute, char *armazenar) {

    int d = strlen(str);
    for (int i = 0; i < d; i++) {
        if (str[i] == chute) {
            armazenar[i] = str[i];
        }
    }
}

void esconder_palavra(char *str, int tam) {

    for (int i = 0; i < tam; i++) {
        str[i] = '_';
    }
    str[tam] = '\0';
}

char letra() {
    
    char c;
    scanf(" %c", &c);
    return tolower(c);
}