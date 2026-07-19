# Sistema de Consulta de Veículos

## Disciplina

AEDS I — Algoritmos e Estruturas de Dados I  
Prática

## Criação

Autor: Francisco Schneedorf Leite Ferreira

Data: 01/05/2026

## Descrição do projeto

Este projeto implementa um programa em C++ para leitura, armazenamento e consulta de informações sobre veículos a partir de um arquivo de texto.

O programa lê os dados de uma base chamada `BD_veiculos_2.txt`, armazena as informações em um vetor de registros e permite ao usuário realizar buscas e consultas por meio de um menu interativo.

## Objetivo

O objetivo do projeto é praticar conceitos fundamentais de programação em C++, como:

* uso de registros (`struct`);
* vetores de registros;
* leitura de arquivos com `ifstream`;
* estruturas condicionais;
* laços de repetição;
* menu interativo;
* busca sequencial;
* cálculo de média.

## Arquivos do projeto

O projeto é composto pelos seguintes arquivos:

* `carros.cpp`: contém todo o código-fonte do programa.
* `BD_veiculos_2.txt`: arquivo de entrada contendo os dados dos veículos.
* `README.md`: contém as informações do projeto, instruções de compilação e uso.

## Estrutura dos dados

Cada veículo é armazenado em um registro com as seguintes informações:

* modelo;
* marca;
* tipo;
* ano;
* quilometragem;
* potência do motor;
* tipo de combustível;
* tipo de câmbio;
* tipo de direção;
* cor;
* número de portas;
* placa;
* preço.

No código, essas informações são organizadas em uma `struct` chamada `registro_veiculos`.

## Funcionamento do programa

Ao iniciar, o programa tenta abrir o arquivo:

```txt
BD_veiculos_2.txt