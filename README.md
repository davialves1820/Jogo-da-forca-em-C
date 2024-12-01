# Jogo da Forca
Este é um simples jogo da forca implementado em C, onde o jogador pode escolher entre duas dificuldades: fácil (com palavras predefinidas) ou difícil (com palavras geradas aleatoriamente). O objetivo do jogo é adivinhar a palavra antes de atingir o limite de erros.

## 📋 Funcionalidades
Escolha de dificuldade:
- Fácil: O jogo seleciona uma palavra aleatória de uma lista predefinida.
- Difícil: O jogo gera uma palavra com caracteres aleatórios.
  
Sistema de desenho da forca que evolui a cada erro.
Palavras parciais mostradas ao jogador com os caracteres descobertos preenchidos.
Detecção de vitória ou derrota.

## 🚀 Como Jogar
**Ao iniciar o jogo, escolha a dificuldade:**
Digite 1 para Fácil.
Digite 2 para Difícil.
Tente adivinhar a palavra chutando uma letra por vez.
Para cada erro, o desenho da forca será atualizado.
**O jogo termina quando:**
Você descobre a palavra antes de errar 7 vezes (Vitória).
Você erra 7 vezes antes de descobrir a palavra (Derrota).

## 🛠️ Como Executar
Copie o código para um arquivo com extensão .c, por exemplo, jogo_da_forca.c.

## 📂 Estrutura do Código
Funções principais:
- armazem_palavras(char *str)
Escolhe uma palavra aleatória de uma lista predefinida.

- gerar_string(int tam, char *string)
Gera uma palavra aleatória com caracteres minúsculos do alfabeto.

- desenhar_forca(int erros)
Desenha a forca de acordo com o número de erros.

- preencher2(char *str, int tam)
Substitui os caracteres de uma string por _, exceto os espaços.

- montar_foca(char *str, char chute, char *armazenar)
Atualiza a string com os caracteres acertados pelo jogador.

- tentativa(char *str, char chute)
Verifica se o jogador acertou ou errou o chute.

## 🎮 Demonstração
Exemplo de Execução:
```
qual a dificuldade facil(1) dificil(2): 1
boa sorte

---|
______

chute uma letra:
a
---|
a______a

chute uma letra:
v
---|
av_____a
...

voce ganhou :)
A palavra era aventura
```

## 📌 Observações
Em caso de dúvida sobre as letras disponíveis, lembre-se que o jogo utiliza somente letras minúsculas do alfabeto.
A dificuldade difícil gera palavras aleatórias que podem não fazer sentido.
