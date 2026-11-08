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
#include <cstdlib>

using namespace std;

int main ()
{

    // Variáveis
    int choice = 0;
    float lado = 0, raio_cil = 0, altura_cil = 0, raio_cone = 0, altura_cone = 0, base_tri = 0, altura_tri = 0;
    string nome_arq;

    // Entrada de dados

    cout << "Digite o nome do arquivo: " << endl;
    cin >> nome_arq;

    ofstream saida (nome_arq + ".txt"); // Cria um arquivo com o nome dado pelo usuário e salva os elementos por ordem na variável saida

    while (choice != 5){
        system("cls"); // Limpa a tela antes de mostrar o menu 
        cout << "-------------- M E N U --------------" << endl;
        cout << "[1] Quadrado " << endl;
        cout << "[2] Cilindro " << endl;
        cout << "[3] Cone " << endl;
        cout << "[4] Triangulo " << endl;
        cout << "[5] Sair " << endl;
        cin >> choice; 

        // Escolhas e respectivas saídas no arquivo
        if (choice == 1){
            cout << "Insira o valor dos lados do quadrado [cm]: " << endl;
            cin >> lado;
            saida << "quadrado " << lado << " " << endl;

        } else if (choice == 2) {
            cout << "Insira o valor do raio do cilindro [cm]: " << endl;
            cin >> raio_cil;
            cout << "Insira o valor da altura do cilindro [cm]: " << endl; 
            cin >> altura_cil;
            saida << "cilindro " << raio_cil << " " << altura_cil << "" << endl;

        } else if (choice == 3) {
            cout << "Insira o valor do raio do cone [cm]: " << endl;
            cin >> raio_cone;
            cout << "Insira o valor da altura do cone [cm]: " << endl;
            cin >> altura_cone;
            saida << "cone " << raio_cone << " " << altura_cone << endl;

        } else if (choice == 4) {
            cout << "Insira o valor da base do triangulo [cm]: " << endl;
            cin >> base_tri;
            cout << "Insira o valor da altura do triangulo [cm]: " << endl;
            cin >> altura_tri;
            saida << "triangulo " << base_tri << " " << altura_tri << endl;
        }

    }
    saida << "fim";
    cout << "Encerrando... " << endl;
    
    // Cálculos


    // Saídas









}
