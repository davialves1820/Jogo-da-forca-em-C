#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

//JOGO DA FORCA

// Escolha uma das palavras para ser adivinhada
void armazem_palavras(char *str){
    int i = rand() % 15 + 1;
    switch(i) {
        case 1:
            strcpy(str,"abracadabra");
            break;
        case 2:
            strcpy(str,"aventura");
            break;
        case 3:
            strcpy(str,"chocolate");
            break;
        case 4:
            strcpy(str,"diversao");
            break;
        case 5:
            strcpy(str,"elefante");
            break;
        case 6:
            strcpy(str,"futebol");
            break;
        case 7:
            strcpy(str,"girassol");
            break;
        case 8:
            strcpy(str,"hipopotamo");
            break;
        case 9:
            strcpy(str,"inverno");
            break;
        case 10:
            strcpy(str,"ketchup");
            break;
        case 11:
            strcpy(str,"computador");
            break;
        case 12:
            strcpy(str,"abacaxi");
            break;
        case 13:
            strcpy(str,"morango");
            break;
        case 14:
            strcpy(str,"biblioteca");
            break;
        case 15:
            strcpy(str,"livraria");
            break;
    }
}

// Gerar uma string com caracteres aleatorios
void gerar_string(int tam, char *string) {
    int i;
    for (i = 0; i < tam; i++) {
        // Gera um número aleatório entre 97 e 122 (correspondendo ao intervalo ASCII das letras minúsculas)
        // e atribui o caractere correspondente à string
        string[i] = rand() % 26 + 'a'; // 'a' tem valor ASCII 97
    }
    string[i] = '\0';
}

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

// Elimina o caracter \n
void eliminar(char *str, int tam) {
    int i;
    for(i = 0;i < tam; i++) {
        if (str[i] == '\n')
            break;
        }
    str[i] = '\0';
}

// Copia a palavra a ser adivinhada
void palavra_para_adivinhar(char *str) {
    fgets(str,40,stdin);
    int d = strlen(str);
    eliminar(str,d);
}

// Retorna se o jogador acertou o caracter(1) ou se errou(0)
int tentativa(char *str, char chute) {
    int d =  strlen(str);
    for (int i = 0;i < d; i++) {
        if (str[i] == chute) {
            return 0;
        }
    }
    return 1;
}

// Retorna o caracter em minusculo que o usuario digitou
char letra() {
    char c;
    scanf(" %c",&c);
    return tolower(c);
}

// Preenche a string para exibição substituindo os espaços em branco por '_'
void preencher2(char *str, int tam) { 
    for (int i = 0; i < tam; i++)
    {
        if (str[i] == ' ')
            str[i] = ' ';
        else
            str[i] = '_';
    }
    str[tam] = '\0';
}

// Substitui as posições da string com '_' pelo caracter se for correto o chute
void montar_foca(char *str, char chute, char *armazenar) {
    int d =  strlen(str), i;
    for (i = 0;i < d; i++) {
        if (str[i] == chute) {
            armazenar[i] = str[i];
        }
    }
    armazenar[i] = '\0';
}

// Exibe a palavra
void mostrar(char *str) {
    printf("\n%s\n",str);
}

int main() {
    srand(time(NULL));
    int tentativas = 0, dificuldade;
    char palavra[20];

    do {
    printf("qual a dificuldade facil(1) dificil(2): "); // 1-Palavra presente no armazem_palavras(), 2-String de caracter totalmente aleatorio
    scanf("%d",&dificuldade);
    } while (dificuldade > 2 || dificuldade < 1); // Verifica se o usuário não digitou um número fora do intervalo

    getchar(); // Captura '\n'
    
    if (dificuldade == 1) {
        armazem_palavras(palavra);
    }
    else {
        gerar_string(10, palavra); // Gera uma string de até 10 caracteres
    }
    
    int tam = strlen(palavra); // tamanho da palavra a adivinhar
    char reserva[tam]; // Copia auxiliar 
    preencher2(reserva,tam); // Inicializa todas as posições de reserva com '_'

    printf("boa sorte\n");
    do { // Looping do jogo
        char c;
        desenhar_forca(tentativas); // Desenha a forca
        mostrar(reserva); // Mostra quantos caracteres falta para adivinhar a palavra

        printf("chute uma letra:\n");
        c = letra();
        getchar();

        if (tentativa(palavra,c) == 1) { // Verifica se o jogador acertou o chute, caso tiver errado adiciona mais um erro
            tentativas++;
        }

        montar_foca(palavra,c,reserva);
        
    } while (tentativas < 7 && strcmp(reserva,palavra) != 0); // Looping encerra se o jogador acertar a palavra o chegar no limite de erros

    if (tentativas == 7) { // Caso ele tenha perdido
        printf("\n voce perdeu :(\n");
        printf("A palavra era %s\n",palavra);
    }
    else { // Caso acertou a palavra
        printf("\n voce ganhou :)\n");
        printf("A palavra era %s\n",palavra);
    }

    return 0;
}
