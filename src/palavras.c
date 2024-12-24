#include "palavras.h"

// Função que vai pegar de forma aleatória uma das palavras do arquivo .txt
void armazem_palavras(char *str) {
    FILE *f = fopen("data/palavras.txt", "r");

    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    int qnt;
    fscanf(f, "%d", &qnt); // Ler a primeira linha do arquivo que está a quantidade de palavras presentes

    // Escolhe um número aleatório que será a posição da palavra a ser adivinhada
    srand(time(NULL));
    int numero_linha = rand() % qnt;

    // Ler as linhas do arquivo até chegar na linha sorteada
    char palavra[21];
    for (int i = 0; i < numero_linha; i++) {
        fscanf(f, "%s", palavra);
    }

    // Copia a palavra do arquivo na variável str
    strcpy(str, palavra);
    
    fclose(f);
}

// Função que gera uma palavra com caracteres aleatórios
void gerar_string(int tam, char *str) {
    srand(time(NULL));
    
    for (int i = 0; i < tam; i++) {
        str[i] = rand() % 26 + 'a'; // Pega o resto da divisão por 26 e soma com o caracter 'a', a soma resultará em um caracter de acordo com a tabela ASCII
    }
    str[tam] = '\0';
}
