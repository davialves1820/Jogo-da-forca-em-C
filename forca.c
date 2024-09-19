#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define TAMAMANHO_PALAVRA 20
#define NUMEROS_DE_PALAVRAS 5
#define TENTATIVAS 7

void escolhe_palavra(char* palavraSecreta) {
    //FILE* f; 
    //f = fopen("MinGw./cplusplus./c./palavras.txt", "r");
    //fscanf(f, "%d", &qntPalavras);

    srand(time(NULL));
    int numeroRandom = rand() % NUMEROS_DE_PALAVRAS;
    if (numeroRandom == 0) {
        strcpy(palavraSecreta, "ABACAXI");
    } else if (numeroRandom == 1) {
        strcpy(palavraSecreta, "MORANGO");
    } else if (numeroRandom == 2) {
        strcpy(palavraSecreta, "MELANCIA");
    } else if (numeroRandom == 3) {
        strcpy(palavraSecreta, "MANGA");
    } else if (numeroRandom == 4) {
        strcpy(palavraSecreta, "LARANJA");
    }
}

void criarCopia(char* original, char* copia) {
    int i;
    int length = strlen(original);
    for (i = 0; i < length; i++) {
        copia[i] = '_';
    }
    copia[i] = '\0';
}



void desenharJogo(char* copia, int erros) {
    printf("QUANTIDADE DE ERROS: %d\n", erros);
    printf("PALAVRA A ADIVINHAR\n");
    printf("%s\n", copia);
}


void realizarJogada(int* tamanho, char* palavraSecreta, char* copia) {
    printf("CHUTE UMA LETRA:\n");
    char chute;
    scanf(" %c", &chute);
    int estarPresente = 0;
    chute = toupper(chute);
    for (int i = 0; palavraSecreta[i] != '\0'; i++) {
        if (chute == palavraSecreta[i]) {
            copia[i] = chute;
            estarPresente = 1;
        }
    }

    if (estarPresente == 0) {
        (*tamanho)++;
    }
}

int verificarVitoria(char* copia, char* palavraSecreta) {
    if (strcmp(copia, palavraSecreta) == 0) {
        return 1;
    }
    return 0;
}


int main() {
    char palavraSecreta[TAMAMANHO_PALAVRA], copia[TAMAMANHO_PALAVRA];
    escolhe_palavra(palavraSecreta);
    criarCopia(palavraSecreta, copia);

    int qntdErros = 0;
    int vitoria = verificarVitoria(copia, palavraSecreta);
    
    printf("JOGO DA FORCA\n\n");

    while (vitoria == 0 && qntdErros < 5) {
    
        desenharJogo(copia, qntdErros);
    
        if (!vitoria) {
            realizarJogada(&qntdErros, palavraSecreta, copia);
        }
        vitoria = verificarVitoria(copia, palavraSecreta);
    }
    printf("JOGO ENCERRADO\n");
    printf("A PALAVRA ERA %s\n", palavraSecreta);
    if (vitoria) {
        printf("PARABENS VOCE VENCEU\n");
    } else {
            printf("QUEM SABE NUMA PROXIMA VEZ\n");
        }
} 