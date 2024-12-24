#include "palavras.h"

void armazem_palavras(char *str) {
    FILE *f = fopen("data/palavras.txt", "r");

    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    int qnt;
    fscanf(f, "%d", &qnt);

    srand(time(NULL));
    int numero_linha = rand() % qnt;

    char palavra[20];
    for (int i = 1; i < numero_linha; i++) {
        fscanf(f, "%s", palavra);
    }

    strcpy(str, palavra);
    fclose(f);
}

void gerar_string(int tam, char *string) {
    for (int i = 0; i < tam; i++) {
        string[i] = rand() % 26 + 'a';
    }
    string[tam] = '\0';
}