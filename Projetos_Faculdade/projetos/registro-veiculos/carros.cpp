// Autor: Francisco Schneedorf Leite Ferreira
// Data: 01/05/2026
// Disciplina: AEDs I - Pratica
// Objetivo: desenvolver um programa que leia as entradas de um arquivo txt, registre suas informacoes em vetores e imprima para o usuario condicoes previa e posteriormente escolhidas

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

// Variaveis globais
int choice = 0;

// Criacao do registro 
typedef struct 
{
    
    // Variaveis
    string model, brand, type, pwr, oil, clutch, drive, color, license;
    float yr, km, doors, price;

} registro_veiculos; // Nome do registro

// Funcoes secundarias
int menu()
{
    // Estrutura do menu
    cout << endl;
    cout << "//////////////////////////////////////////////////////////////////////" << endl;
    cout << "//////////////////////////////////////////////////////////////////////" << endl;
    cout << endl;
    cout << "------------- M E N U --------------" << endl;
    cout << "[1] Busca por modelo " << endl;
    cout << "[2] Busca por placa " << endl;
    cout << "[3] Media dos precos " << endl;
    cout << "[4] Lista de veiculos acima da media por placa " << endl;
    cout << "[5] Registro completo dos veiculos " << endl;
    cout << "[0] Sair " << endl;

    // Laco para exibicao do menu dentro dos valores possiveis
    while (!(cin >> choice) || choice < 0 || choice > 5) // Enquanto a negação do input choice em cin for verdadeira OU choice < 1 OU choice > 5
    {
        cout << "Digite um valor valido: " << endl;
        cin.clear(); // Reseta o estado de erro do cin
        cin.ignore(1000, '\n'); // Limpa o que resultou no buffer
    }

    // Retorno da funcao
    return choice;
}

void archive (registro_veiculos bd[], int qt)
{
    // Variaveis
    int z = 0;

    // Saida de dados
    for (z =0; z < qt; z++)
    {
        cout << bd[z].model << " " << bd[z]. brand << " "
        << bd[z].type << " " << bd[z].yr << " " << bd[z].pwr << " "
        << bd[z].oil << " " << bd[z].clutch << " " << bd[z].drive << " "
        << bd[z].doors << " " << bd[z].license << " " << bd[z].price << " "
        << endl;
    }

}

// Funcao principal
int main ()
{   

    // Variaveis
    string archive_name, next, model_user, lic_user;
    int qt = 0, size = 50, c = 0, qt_suv = 0, qtauto = 0, qtflex = 0, qt_el_pwr = 0, i = 0, z = 0, qt_model = 0, var_assist = 0;
    float sum_prices = 0, avg_prices = 0, pricesuv = 0;
        // Declaracao do vetor
        registro_veiculos arraycar[size]; 
    
    // Entrada do nome do arquivo
    /*archive(arraycar, qt);
    cout << "Digite o nome do arquivo a ser aberto: " << endl;
    cin >> archive_name;*/

    // Abertura do arquivo
    ifstream read ("BD_veiculos_2.txt");
    
    // Verificacao 
    if (!read.is_open())
    {
        cout << "ERRO: Arquivo nao encontrado. " << endl;
        cout << "Tente novamente. " << endl;
        return 1;
    }

    // Leitura dos dados do arquivo
    read >> next; // Verificacao previa para caso encontre a palavra FIM

    while (next != "FIM")
    {

       arraycar[qt].model = next;  
       read >> arraycar[qt].brand;
       read >> arraycar[qt].type;
       read >> arraycar[qt].yr;
       read >> arraycar[qt].km;
       read >> arraycar[qt].pwr;
       read >> arraycar[qt].oil;
       read >> arraycar[qt].clutch;
       read >> arraycar[qt].drive;
       read >> arraycar[qt].color;
       read >> arraycar[qt].doors;
       read >> arraycar[qt].license;
       read >> arraycar[qt].price;

       // Verificacao das condicoes previas
       if (arraycar[qt].type == "SUV") // Soma do preco dos SUVs
       {
            pricesuv = pricesuv + arraycar[qt].price;
            qt_suv++; // Quantidade de SUVs
       }

       if (arraycar[qt].clutch == "Automatico") // Quantidade de automaticos 
       {
            qtauto++; 
       }

       if (arraycar[qt].oil == "Flex") // Quantidade de veiculos flex
       {
            qtflex++;
       }

       if ((arraycar[qt].pwr == "1.8") && (arraycar[qt].drive == "Eletrica")) // Quantidade de veiculos 1.8 com direcao eletrica
       {  
            qt_el_pwr++;
       }

       // Acrescenta-se 1 a quantidade para manter o laco
       qt++;
       read >> next; // Verificacao posterior para caso encontre a palavra FIM
    }

    // Laco para calcular a soma dos precos
    while(c < qt)
    {
        sum_prices = sum_prices + arraycar[c].price; 
        c++;
    }

    // Saida de dados
    /*cout << "--------- SAIDA DE DADOS ----------" << endl;
    cout << qt << " veiculos registrados " << endl;
    cout << "Media de precos: R$" << avg_prices << endl;
    cout << "Media de precos - SestaticaUVs: R$ " << avg_prices_suv << endl;
    cout << "Porcentagem de veiculos com cambio automatico: " << perc_auto << "%" << endl;
    cout << "Quantidade de veiculos com combustivel FLEX: " << qtflex << endl;
    cout << "Porcentagem de veiculos com motor 1.8 e direcao eletrica: " << perc_el_pwr << "%" << endl;*/

    // Calculos
    avg_prices = (sum_prices/qt); // Media de precos

    // Laço para repetir o menu até que o usuário queira sair (digite 0)
    while((choice = menu())!=0)
    {


        // Definição do valor da variavel de assitência sempre que executar o menu para caso não exista a placaS
        var_assist = 0;
        qt_model = 0;
        // Casos
        switch (choice)
        {
    
            case 1:
            
            // Entrada de dados
            cout << "Digite o nome do modelo desejado: " << endl;
            cin >> model_user;
            cout << "Buscando... " << endl;
            cout << endl;
            cout << "------------------------------------------" << endl;

            // Laço for para buscar na posição de z o modelo digitado pelo usuário, por todas as linhas do arquivo
            for(z = 0; z < qt; z++)
            {
                // Condição que verifica se o modelo naquela posição é igual ao digitado pelo usuário
                if(arraycar[z].model == model_user)
                {   
                    qt_model++;
                    // Impressão dos dados do carro naquela linha
                    cout << "------------------------------------------" << endl;
                    cout << "MARCA: " << arraycar[z].model << endl;
                    cout << "MODELO: " << arraycar[z].brand << endl;
                    cout << "TIPO: " << arraycar[z].type << endl;
                    cout << "ANO: " << arraycar[z].yr << endl;
                    cout << "KILOMETRAGEM: " << arraycar[z].km << endl;
                    cout << "POTENCIA DO MOTOR " << arraycar[z].pwr << endl;
                    cout << "TIPO DE COMBUSTIVEL: " << arraycar[z].oil << endl;
                    cout << "TIPO DE CAMBIO: " << arraycar[z].clutch << endl;
                    cout << "TIPO DE DIRECAO: "<< arraycar[z].drive << endl;
                    cout << "COR: " << arraycar[z].color << endl;
                    cout << "NUMERO DE PORTAS: " << arraycar[z].doors << endl;
                    cout << "PLACA: " << arraycar[z].license << endl;
                    cout << "VALOR: R$" << arraycar[z].price << endl;
                    cout << "------------------------------------------" << endl;
                }
            }

            // Número de veículos encontrados
            cout << qt_model << " " << model_user << " foram encontrados" << endl; 
            break;

            case 2:
            // Entrada de dados
            cout << "Digite a placa do veiculo desejado: " << endl;
            cin >> lic_user;

            // Laço for para buscar na posição de z a placa digitada pelo usuário, por todas as linhas do arquivo
            for(z = 0; z < qt; z++)
            {
                // Condição que verifica se o modelo naquela posição é igual ao digitado pelo usuário
                if(arraycar[z].license == lic_user)
                {   
                    
                    // Se a placa existir, atribui-se 1 a variavel
                    var_assist = 1;

                    // Impressão dos dados do carro naquela linha
                    cout << "------------------------------------------" << endl;
                    cout << "MARCA: " << arraycar[z].model << endl;
                    cout << "MODELO: " << arraycar[z].brand << endl;
                    cout << "TIPO: " << arraycar[z].type << endl;
                    cout << "ANO: " << arraycar[z].yr << endl;
                    cout << "KILOMETRAGEM: " << arraycar[z].km << endl;
                    cout << "POTENCIA DO MOTOR " << arraycar[z].pwr << endl;
                    cout << "TIPO DE COMBUSTIVEL: " << arraycar[z].oil << endl;
                    cout << "TIPO DE CAMBIO: " << arraycar[z].clutch << endl;
                    cout << "TIPO DE DIRECAO: "<< arraycar[z].drive << endl;
                    cout << "COR: " << arraycar[z].color << endl;
                    cout << "NUMERO DE PORTAS: " << arraycar[z].doors << endl;
                    cout << "PLACA: " << arraycar[z].license << endl;
                    cout << "VALOR: R$" << arraycar[z].price << endl;
                    cout << "------------------------------------------" << endl;
                    cout << endl;
                } 
    
            }

            if (var_assist == 0)
                {
                    cout << "Placa nao encontrada. " << endl;

                }
            break;

            case 3:
                // Saida de dados
                cout << "------------------------------------------" << endl;
                cout << "Media de precos: R$" << avg_prices << endl;
                
                break;

            case 4:
                // Laco para imprimir na tela uma listagem de placas de veiculos com preco acima da media
                cout << "----- PLACA DE VEICULOS COM PRECO ACIMA DA MEDIA ------" << endl;
                for (i = 0; i < qt; i++)
                {
                    if (arraycar[i].price > avg_prices)
                    {
                        cout << i << " -> " << arraycar[i].license << endl;
                    }
                }

                break;
            
            case 5:
                // Saida de dados
                cout << "MODELO | MARCA | TIPO | ANO | MOTOR | COMBUSTIVEL | CAMBIO | DIRECAO | PORTAS | PLACA | VALOR" << endl;
                archive(arraycar, qt);
                
                break;
        
                
        }
    }
    cout << "Encerrando o sistema... " << endl; 
}