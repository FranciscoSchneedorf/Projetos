/* Autor: Francisco Schneedorf Leite Ferreira
 Data: 19/04/2026
 Disciplina: AEDs I - Prática
 Objetivo: Criar um projeto que permita ao usuário descrever as figuras de uma 
 cena gráfica por meio de um menu e escrever esses dados em um arquivo de saída;
 criar outro projeto que leia o arquivo gerado e calcule a área e o volume total da cena gráfica.
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main (){

    // Variáveis
    float lado = 0, raio_cil = 0, altura_cil = 0, raio_cone = 0, altura_cone = 0;
    float base_tri = 0, altura_tri =0, vol_total = 0, area_total = 0;
    string nome_arq, linha;


    // Entrada de dados
    cout << "Digite o nome do arquivo a ser lido: " << endl;
    cin >> nome_arq;

    ifstream read (nome_arq + ".txt"); // Abrindo o arquivo e salvando os elementos em sequência na variável read
    
    // Verificação da leitura do arquivo
    if (!read){
        cout << "Arquivo não encontrado. " << endl;
        return 0;
    }

    // Laço para verificar os elementos e salvar nas respectivas variáveis
    while (read >> linha && linha != "fim"){ // Se retornar verdadeiro para a leitura e o que foi armazenado for diferente de "fim", entra no laço
        // Comparações e cálculos
        if (linha == "quadrado"){
            read >> lado; 
            area_total += (lado*lado);

        } else if (linha == "cilindro"){
            read >> raio_cil;
            read >> altura_cil;
            vol_total += ((3.14 * (raio_cil * raio_cil)) * altura_cil);
            
        } else if (linha == "cone"){
            read >> raio_cone;
            read >> altura_cone;
            vol_total += (((3.14 * (raio_cone * raio_cone)) * altura_cone)/3);

        } else if (linha == "triangulo"){
            read >> base_tri;
            read >> altura_tri;
            area_total += ((base_tri * altura_tri)/2);
        }
    }


    // Saída de dados
    cout << "------------------------------------------" << endl;
    cout << "Area total: " << area_total << fixed << setprecision(2) << endl; 
    cout << "Volume total: " << vol_total << fixed << setprecision(2) << endl;
   


    
}