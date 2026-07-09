#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <locale>

using namespace std;

int main()
{
//std::locale::global(std::locale(".UTF-8"));
setlocale(LC_ALL, "Portuguese_Brazil");

// Variáveis
string car, brand, type, oil, clutch, drive, color, id, peng;
float yr = 0, km = 0, door = 0, price = 0, nauto = 0, nflex = 0;
float notauto = 0, totauto = 0, porcauto = 0, preco_suv = 0, num_suv = 0, med_suv = 0, porc_eng18 = 0, tot_eng18 = 0, not_eng18 = 0, eng18 = 0;

// Entrada de dados

ifstream read ("veiculos.md"); // Abrindo o arquivo

if (!read.is_open()){  // Verificará se o arquivo está aberto; se retornar falso:
    cout << "\nErro: Arquivo não encontrado. \n";
    return 1;
}

read >> car; // Variável car recebe o elemento na primeira posição do arquivo
// Armazenando os elementos do arquivo em suas respectivas variáveis
while(car!="FIM"){
    //cout << car;
        read >> brand;
    //cout << brand;
        read >> type;
    //cout << type;
        read >> yr;
    //cout << yr;
        read >> km;
    //cout << km;
        read >> peng;
    //cout << peng;
        read >> oil;
    //cout << oil;
        read >> clutch;
    //cout << clutch;
        read >> drive;
    //cout << drive;
        read >> color;
    //cout << color;
        read >> door;
    //cout << door;
        read >> id;
    //cout << id;
        read >> price;
    //cout << price;

    if (clutch == "Manual"){
        notauto = notauto + 1;
      
    } else {
        nauto = nauto + 1;
    }
    if (oil == "Flex"){
        nflex = nflex + 1;
    }
    if (type == "SUV"){
        preco_suv = preco_suv + price;
        num_suv = num_suv + 1;
    }
    if (peng == "1.8"  && drive == "Eletrica"){
        eng18 = eng18 + 1;
    } else {
        not_eng18 = not_eng18 + 1;
    }
        
    

read >> car;
}




// Cálculos

    // Porcentagem de automáticos
    totauto = nauto + notauto;
    porcauto = ((nauto*totauto)*0.1);

    // Média de SUVs
    med_suv = preco_suv/num_suv;

    // Porcentagem de 1.8 elétricos
    tot_eng18 = (eng18 + not_eng18);
    porc_eng18 = ((tot_eng18 * eng18)*0.1);

// Saída de dados

    cout << "----------------------------------------------------" << endl;
    cout << "Porcentagem de veículos com câmbio automático: " << porcauto << "%" << endl;
    cout << "Quantidade de veículos flex: " << nflex << endl;
    cout << "Preço médio dos veículos SUV: " << med_suv << endl;
    cout << "Porcentagem de veículos 1.8 com direção elétrica: " << porc_eng18 << "%" << endl;
    cout << "----------------------------------------------------" << endl;
    

    return 0;
}
