#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define TAMAMANHO_PALAVRA 20 
#define NUMEROS_DE_PALAVRAS 5
#define TENTATIVAS 5

void escolhe_palavra(char* palavraSecreta) { // Função que tem a finalidade de selecionar uma palavra atraves de um numero gerado aleatóriamente
    srand(time(NULL));
    int numeroRandom = rand() % NUMEROS_DE_PALAVRAS; // O numero é gerado limitado pela quantidade de palavras disponiveis para seleção
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

void criarCopia(char* original, char* copia) { // Função cria uma cópia da palavra seleciona para ficar melhor na impressao do jogo
    int i;
    int length = strlen(original);
    for (i = 0; i < length; i++) {
        copia[i] = '_';
    }
    copia[i] = '\0';
}



void desenharJogo(char* copia, int erros) { // Função que exibe o jogo mostrando quantos erros o jogador cometeu e a palavra a adivinhar
    printf("QUANTIDADE DE ERROS: %d\n", erros);
    printf("PALAVRA A ADIVINHAR\n");
    printf("%s\n", copia);
}


void realizarJogada(int* tamanho, char* palavraSecreta, char* copia) { // Função que realiza a jogada
    printf("CHUTE UMA LETRA:\n");
    char chute;
    scanf(" %c", &chute); // ler o chute do usuário
    int estarPresente = 0; // variavel auxiliar que ajuda a saber se o jogador acertou uma letra ou não
    chute = toupper(chute);
    for (int i = 0; palavraSecreta[i] != '\0'; i++) {
        if (chute == palavraSecreta[i]) { // caso o chute esteja certo ele substitui o caracter '_' da copia pela letra presente na palavra secreta
            copia[i] = chute;
            estarPresente = 1;
        }
    }

    if (estarPresente == 0) { // se o jogador não acertou a letra contabiliza mais um erro
        (*tamanho)++; 
    }
}

int verificarVitoria(char* copia, char* palavraSecreta) { // Função que verifica se o jogador já descobriu todas as letras da palavra
    if (strcmp(copia, palavraSecreta) == 0) { // caso a palavra copia seja igual a palavra secreta o jogador ganhou
        return 1;
    }
    return 0;
}


int main() {
    char palavraSecreta[TAMAMANHO_PALAVRA], copia[TAMAMANHO_PALAVRA]; 
    escolhe_palavra(palavraSecreta); // define a palavra secreta
    criarCopia(palavraSecreta, copia); // faz a copia da palavra secreta

    int qntdErros = 0; // variavel para contar os erros
    int vitoria = verificarVitoria(copia, palavraSecreta); // variavel para verificar se o jogador venceu
    
    printf("JOGO DA FORCA\n\n");

    while (vitoria == 0 && qntdErros < TENTATIVAS) { // looping que se encerra caso o jogador ganhe ou se chegar a 5 erros
    
        desenharJogo(copia, qntdErros); // desenha o jogo
    
        if (!vitoria) { // verifica se o jogador ganhou, caso falso realiza mais uma jogada
            realizarJogada(&qntdErros, palavraSecreta, copia); 
        }
        vitoria = verificarVitoria(copia, palavraSecreta); //verifica se o jogador ganhou
    }
    printf("JOGO ENCERRADO\n");
    printf("A PALAVRA ERA %s\n", palavraSecreta); // revela a palavra secreta
    if (vitoria) {
        printf("PARABENS VOCE VENCEU\n"); // caso o jogador tenha vencido
    } else {
            printf("QUEM SABE NUMA PROXIMA VEZ\n"); // caso ele tenha perdido
        }
} 
