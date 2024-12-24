#ifndef JOGO_H
#define JOGO_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tentativa(char *str, char chute);

void montar_foca(char *str, char chute, char *armazenar);

void esconder_palavra(char *str, int tam);

char letra();

#endif