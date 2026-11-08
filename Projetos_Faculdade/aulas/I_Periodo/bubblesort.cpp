/*
Autor: Francisco Schneedorf Leite Ferreira
Início do projeto: 01/05/2026
Última alteração: 01/05/2026
Disciplina: AEDs I - Pratica
Objetivo: Utilizar bubblesort, insertionsort e selectionsort para contabilizar o custo de operacao de cada, a partir de um arquivo .txt contendo 10000 numeros aleatorios
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

// Funcoes secundarias

void copiarVetor(int destino[], int origem[], int tam)
{
    for (int c = 0; c < tam; c++)
    {
        destino[c] = origem[c];
    }
}

void bubbleSort(int vetor[], int tam, int &comparacoes, int &atribuicoes)
{
    int aux;
    comparacoes = 0;
    atribuicoes = 0;

    for (int j = 0; j < tam - 1; j++)
    {
        for (int c = 0; c < tam - j - 1; c++)
        {
            comparacoes++;

            if (vetor[c] > vetor[c + 1])
            {
                aux = vetor[c];
                vetor[c] = vetor[c + 1];
                vetor[c + 1] = aux;

                atribuicoes = atribuicoes + 9;
            }
        }
    }
}

void insertionSort(int vetor[], int tam, int &comparacoes, int &atribuicoes)
{
    int chave, j = 0;
    comparacoes = 0;
    atribuicoes = 0;

    for (int i = 1; i < tam; i++)
    {
        chave = vetor[i];
        j = i - 1;
        atribuicoes = atribuicoes + 3;

        while (j >= 0 && vetor[j] > chave)
        {

            comparacoes++; // vetor[j] > chave

            vetor[j + 1] = vetor[j];
            j--;

            atribuicoes = atribuicoes + 3;
        }

        vetor[j + 1] = chave;

        atribuicoes = atribuicoes + 3; // Uma atribuicao
    }
}

void selectionSort(int vetor[], int tam, int &comparacoes, int &atribuicoes)
{
    int aux;
    comparacoes = 0;
    atribuicoes = 0;

    for (int i = 0; i < tam - 1; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < tam; j++)
        {
            comparacoes++;

            if (vetor[j] < vetor[minIdx])
            {
                minIdx = j;
            }
        }

        // Comparacao auxiliar, optei por nao somar um tempo
        if (minIdx != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[minIdx];
            vetor[minIdx] = aux;

            atribuicoes = atribuicoes + 9;
        }
    }
}

// Funcao principal
int main()
{
    // Variaveis
    const int tam = 10000;
    int numeros[tam], vetorCrescente[tam], vetorDecrescente[tam], vetorAleatorio[tam], vetorTeste[tam];
    int c = 0, aux, j = 0, bs_comparacoes = 0, bs_atribuicoes = 0, is_comparacoes = 0, is_atribuicoes = 0, ss_comparacoes = 0, ss_atribuicoes = 0;
    int tamanhos[19] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

    // Abertura do arquivo
    ifstream arquivo("numeros.txt");

    if (!arquivo)
    {
        cout << "ERRO: Nao foi possivel abrir o arquivo ." << endl;
        return 1;
    }

    while (c < tam && arquivo >> numeros[c])
    {
        vetorCrescente[c] = numeros[c];
        vetorDecrescente[c] = numeros[c];
        vetorAleatorio[c] = numeros[c];

        c++;
    }

    arquivo.close();

    cout << "Quantidade de numeros lidos: " << c << endl;

    // Ordenando os vetores
    for (j = 0; j < tam - 1; j++)
    {
        for (c = 0; c < tam - 1; c++)
        {
            if (vetorCrescente[c] > vetorCrescente[c + 1])
            {
                aux = vetorCrescente[c];
                vetorCrescente[c] = vetorCrescente[c + 1];
                vetorCrescente[c + 1] = aux;
            }
        }
    }

    for (j = 0; j < tam - 1; j++)
    {
        for (c = 0; c < tam - 1; c++)
        {
            if (vetorDecrescente[c] < vetorDecrescente[c + 1])
            {
                aux = vetorDecrescente[c];
                vetorDecrescente[c] = vetorDecrescente[c + 1];
                vetorDecrescente[c + 1] = aux;
            }
        }
    }

    ofstream resultado("resultados.csv"); // Salvando as saidas para gerar o grafico

    if (!resultado)
    {
        cout << "ERRO: Nao foi possivel criar o arquivo. " << endl;
        return 1;
    }

    resultado << "algoritmo;caso;n;comparacoes;atribuicoes" << endl;

    // Saida de dados
    cout << " ------------ BUBBLESORT ------------" << endl;
    cout << " ------------ VETOR CRESCENTE ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorCrescente, n);
        bubbleSort(vetorTeste, n, bs_comparacoes, bs_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << bs_comparacoes << endl;
        cout << "ATRIBUICOES: " << bs_atribuicoes << endl;
        cout << endl;

        resultado << "BubbleSort;crescente" << ";" << n << ";" << bs_comparacoes << ";" << bs_atribuicoes << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << " ------------ VETOR DECRESCENTE ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorDecrescente, n);
        bubbleSort(vetorTeste, n, bs_comparacoes, bs_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << bs_comparacoes << endl;
        cout << "ATRIBUICOES: " << bs_atribuicoes << endl;
        cout << endl;

        resultado << "BubbleSort;decrescente" << ";" << n << ";" << bs_comparacoes << ";" << bs_atribuicoes << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << " ------------ VETOR ALEATORIO ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorAleatorio, n);
        bubbleSort(vetorTeste, n, bs_comparacoes, bs_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << bs_comparacoes << endl;
        cout << "ATRIBUICOES: " << bs_atribuicoes << endl;
        cout << endl;

        resultado << "BubbleSort;aleatorio" << ";" << n << ";" << bs_comparacoes << ";" << bs_atribuicoes << endl;
    }
    cout << endl;
    cout << " ------------ INSERTIONSORT ------------" << endl;
    cout << " ------------ VETOR CRESCENTE ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorCrescente, n);
        insertionSort(vetorTeste, n, is_comparacoes, is_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << is_comparacoes << endl;
        cout << "ATRIBUICOES: " << is_atribuicoes << endl;
        cout << endl;

        resultado << "InsertionSort;crescente" << ";" << n << ";" << is_comparacoes << ";" << is_atribuicoes << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << " ------------ VETOR DECRESCENTE ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorDecrescente, n);
        insertionSort(vetorTeste, n, is_comparacoes, is_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << is_comparacoes << endl;
        cout << "ATRIBUICOES: " << is_atribuicoes << endl;
        cout << endl;

        resultado << "InsertionSort;decrescente" << ";" << n << ";" << is_comparacoes << ";" << is_atribuicoes << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << " ------------ VETOR ALEATORIO ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorAleatorio, n);
        insertionSort(vetorTeste, n, is_comparacoes, is_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << is_comparacoes << endl;
        cout << "ATRIBUICOES: " << is_atribuicoes << endl;
        cout << endl;

        resultado << "InsertionSort;aleatorio" << ";" << n << ";" << is_comparacoes << ";" << is_atribuicoes << endl;
    }
    cout << endl;
    cout << " ------------ SELECTIONSORT ------------" << endl;
    cout << " ------------ VETOR CRESCENTE ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorCrescente, n);
        selectionSort(vetorTeste, n, ss_comparacoes, ss_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << ss_comparacoes << endl;
        cout << "ATRIBUICOES: " << ss_atribuicoes << endl;
        cout << endl;

        resultado << "SelectionSort;crescente" << ";" << n << ";" << ss_comparacoes << ";" << ss_atribuicoes << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << " ------------ VETOR DECRESCENTE ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorDecrescente, n);
        selectionSort(vetorTeste, n, ss_comparacoes, ss_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << ss_comparacoes << endl;
        cout << "ATRIBUICOES: " << ss_atribuicoes << endl;
        cout << endl;

        resultado << "SelectionSort;decrescente" << ";" << n << ";" << ss_comparacoes << ";" << ss_atribuicoes << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << " ------------ VETOR ALEATORIO ------------" << endl;

    for (int k = 0; k < 19; k++)
    {
        int n = tamanhos[k];

        copiarVetor(vetorTeste, vetorAleatorio, n);
        selectionSort(vetorTeste, n, ss_comparacoes, ss_atribuicoes);

        cout << n << ":" << endl;
        cout << "COMPARACOES: " << ss_comparacoes << endl;
        cout << "ATRIBUICOES: " << ss_atribuicoes << endl;
        cout << endl;

        resultado << "SelectionSort;aleatorio" << ";" << n << ";" << ss_comparacoes << ";" << ss_atribuicoes << endl;
    }

    resultado.close();
    cout << "Arquivo resultados.csv criado com sucesso. " << endl;

    return 0;
}
