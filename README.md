# Jogo da Forca
Este é um simples jogo da forca implementado em C, onde o jogador pode escolher entre duas dificuldades: fácil (com palavras predefinidas) ou difícil (com palavras geradas aleatoriamente). O objetivo do jogo é adivinhar a palavra antes de atingir o limite de erros.

---

## 📋 Funcionalidades
- Escolha de dificuldade:
  - Fácil: O jogo seleciona uma palavra aleatória de uma lista predefinida.
  - Difícil: O jogo gera uma palavra com caracteres aleatórios.
  
- Sistema de desenho da forca que evolui a cada erro.  
- Visualização do progresso do jogador com uma interface de texto simples.  
- Detecção de vitória ou derrota.

---

## 📂 Estrutura do Código
- **src**: Arquivos de implementação.
    - forca.c: Controla o fluxo principal do jogo.
    - palavras.c: Gerencia a seleção de palavras (do banco ou geradas aleatoriamente).
    - jogo.c: Lógica principal do jogo da forca.
    - exibir_jogo.c: Funções para desenhar a forca e exibir informações.
- **include**: Cabeçalhos correspondentes aos módulos.
    - palavras.h
    - jogo.h
    - exibir_jogo.h
- **data**:
    - palavras.txt: Banco de dados contendo as palavras.
- **Makefile**: Automação da compilação do projeto.

---


## Compilação e execução

### Compilação
```
make
```

### Execução
```
./bin/programa
```

---

## 🚀 Instruções do jogo

- Escolha a dificuldade:
  - 1: Palavras do banco de dados.
  - 2: Palavras geradas aleatoriamente.
 
- O jogo inicia com o desenho da forca e espaços representados por _ para cada letra da palavra.
- Digite letras para adivinhar a palavra.
- Cada acerto revela a posição da letra na palavra.
- Cada erro adiciona uma parte ao desenho da forca.
- O jogo termina quando:
  - O jogador adivinha a palavra completamente.
  - O jogador comete 7 erros.

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

---

## 📌 Observações
- Em caso de dúvida sobre as letras disponíveis, lembre-se que o jogo utiliza somente letras minúsculas do alfabeto.
- A dificuldade difícil gera palavras aleatórias que podem não fazer sentido.
