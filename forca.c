#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

//JOGO DA FORCA

void armazem_palavras(char *str){
    int i = rand() % 15 + 1;
    switch(i){
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

void gerar_string(int tam,char *string){
    int i;
    for (i = 0; i < tam; i++) {
        // Gera um número aleatório entre 97 e 122 (correspondendo ao intervalo ASCII das letras minúsculas)
        // e atribui o caractere correspondente à string
        string[i] = rand() % 26 + 'a'; // 'a' tem valor ASCII 97
    }
    string[i] = '\0';
}

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
        case 6:
            printf("---|\n");
            printf("   O\n");
            printf("  /|\\\n");
            printf("  / \\\n");
            break;
        default:
            break;
    }
}

void eliminar(char *str,int tam){
    int i;
    for(i = 0;i < tam; i++){
        if(str[i] == '\n')
            break;
        }
    str[i] = '\0';
}

void palavra_para_adivinhar(char *str){
    fgets(str,40,stdin);
    int d = strlen(str);
    eliminar(str,d);
}

int tentativa(char *str,char chute){
    int d =  strlen(str);
    for(int i = 0;i < d; i++){
        if(str[i] == chute){
            return 0;
        }
    }
    return 1;
}

char letra(){
    char c;
    scanf(" %c",&c);
    return tolower(c);
}

void preencher2(char *str,int tam){ 
    for (int i = 0; i < tam; i++)
    {
        if(str[i] == ' ')
            str[i] = ' ';
        else
            str[i] = '_';
    }
    str[tam] = '\0';
}

void montar_foca(char *str,char chute,char *armazenar){
    int d =  strlen(str), i;
    for(i = 0;i < d; i++){
        if(str[i] == chute){
            armazenar[i] = str[i];
        }
    }
    armazenar[i] = '\0';
}

void mostrar(char *str){
    printf("\n%s\n",str);
}

int main(){
    srand(time(NULL));
    int tentativas = 0, dificuldade;
    char palavra[20];

    do{
    printf("qual a dificuldade facil(1) dificil(2): ");
    scanf("%d",&dificuldade);
    }while(dificuldade > 2 || dificuldade < 1);

    getchar();
    
    if(dificuldade == 1){
        armazem_palavras(palavra);
    }
    else{
        gerar_string(10,palavra);
    }
    
    int tam = strlen(palavra);
    char reserva[tam];
    preencher2(reserva,tam);

    printf("boa sorte\n");
    do{
        char c;
        desenhar_forca(tentativas);
        mostrar(reserva);

        printf("chute uma letra:\n");
        c = letra();
        getchar();

        if(tentativa(palavra,c) == 1){
        tentativas++;
        }

        montar_foca(palavra,c,reserva);
        
    }while(tentativas < 7 && strcmp(reserva,palavra) != 0);

    if(tentativas == 7){
        printf("\n voce perdeu :(\n");
        printf("A palavra era %s\n",palavra);
        }
    else{ 
        printf("\n voce ganhou :)\n");
        printf("A palavra era %s\n",palavra);
    }

    return 0;
}