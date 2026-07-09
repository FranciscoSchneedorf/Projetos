/*
Autor: Francisco Schneedorf Leite Ferreira
Início do projeto: 29/05/2026
Última alteração: 1/06/2026
Disciplina: AEDs I - Pratica
Objetivo: Gerar 10.000 números aleatorios e salva-los em vetores de forma crescente, aleatoria e decrescente.
*/

#include <stdio.h>
#include <cstdlib>
#include <iostream> 
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
srand(time(0));

// Variaveis
    const int tam = 10000;
    int randomNum[tam];
    int c = 0, posicaoSorteada, aux;

    // Gerando os numeros
    for (c = 0; c < tam; c++)
    {
        randomNum[c] = c;

    }

    // Embaralhando o vetor
    for (c = 0; c < tam; c++)
    {
        posicaoSorteada = rand() % (c + 1);
        aux = randomNum[c];
        randomNum[c] = randomNum[posicaoSorteada];
        randomNum[posicaoSorteada] = aux;
    }

    // Criação do arquivp
    ofstream arquivo("numeros.txt");
    
    if (!arquivo)
    {
        cout << "ERRO: Nao foi possivel criar o arquivo. " << endl;
        return 1;
    }

    // Imprime o vetor em ordem aleatoria
    for (c = 0; c < tam; c++)
    {
        arquivo << randomNum[c] << endl;
    }

    arquivo.close();

    cout << "Arquivo numeros.txt criado com sucesso. " << endl;
    
    return 0;
}