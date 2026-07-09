# Processamento de Imagens PGM com Índices

## Disciplina

AEDS I — Algoritmos e Estruturas de Dados I  
Turma: 2026/1

## Autor

Francisco Schneedorf

## Descrição do projeto

Este projeto implementa um programa em C++ para processamento de imagens no formato PGM texto, tipo `P2`.

O programa permite carregar uma imagem PGM, aplicar operações de processamento e salvar uma nova imagem resultante. Nesta versão, as operações sobre os pixels são realizadas utilizando índices de matriz, acessando cada posição da imagem por meio de estruturas como `img[i][j]`.

## Arquivos do projeto

O projeto é composto pelos seguintes arquivos:

* `main.cpp`: contém a função principal, o menu de opções e as chamadas das funções de processamento.
* `imagens.cpp`: contém a implementação das funções de leitura, escrita e processamento das imagens.
* `imagens.h`: contém as constantes, o tipo da imagem e os protótipos das funções.
* `README.md`: contém as informações do projeto, instruções de compilação e uso.

## Como compilar

Para compilar o programa, execute no terminal, dentro da pasta do projeto:

```bash
g++ main.cpp imagens.cpp -o programa