/* Autor: Francisco Schneedorf Leite Ferreira
   Data: 16/05/2026
   Disciplina: AEDs I - Prática
   Objetivo: Adquirir conhecimentos sobre manipulação de registros em vetores e construção de estatísticas utilizando variáveis simples e estruturas de controle
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// Criacao do registro de variaveis
typedef struct
{
    // Variaveis
    string modelo, marca, tipo, pot, combus, cambio, direcao, cor, placa;
    int ano, portas;
    float km, valor;

} registro_veiculos; // Nome do registro

// Funcoes secundarias
void registro(registro_veiculos bd[], int qt)
{
    // Variaveis
    int c = 0;

    // Laco para realizar a leitura dos dados
    for (c = 0; c < qt; c++)
    {
        cout << bd[c].modelo << " " << bd[c].marca
             << " " << bd[c].tipo << " " << fixed << setprecision(0) << bd[c].ano << " " << bd[c].km << " " << bd[c].pot
             << " " << bd[c].combus << " " << bd[c].cambio << " " << bd[c].direcao
             << " " << bd[c].cor << " " << bd[c].portas << " " << bd[c].placa << " " << fixed << setprecision(2) << bd[c].valor << endl;
    }
}

int menu()
{
    // Variaveis
    int escolha_menu;

    // Saida de dados
    cout << endl;
    cout << "---------------- M E N U ----------------" << endl;
    cout << "[1] Inclusao de novo veiculo " << endl;
    cout << "[2] Busca por placa " << endl;
    cout << "[3] Busca por cambio " << endl;
    cout << "[4] Busca por combustivel e potencia do motor " << endl;
    cout << "[5] Busca por faixa de valores " << endl;
    cout << "[6] Relatorio da base de dados " << endl;
    cout << "[0] Sair " << endl;
    cout << ": ";

    // Verificacao da resposta do usuario
    while (!(cin >> escolha_menu) || escolha_menu < 0 || escolha_menu > 6)
    {
        cout << "Valor invalido. Tente novamente. " << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return escolha_menu;
}

void salvar_arquivo(registro_veiculos bd[], int qt)
{
    // Variavel que escrevera no arquivo
    ofstream gravacao("BD_veiculos_2.txt");

    // Verificacao se o arquivo foi aberto corretamente
    if (!gravacao.is_open())
    {
        cout << "ERRO: Nao foi possivel abrir o arquivo" << endl;
        return;
    }

    // Inserindo dados no arquivo
    for (int i = 0; i < qt; i++)
    {

        gravacao << bd[i].modelo << " "
                 << bd[i].marca << " "
                 << bd[i].tipo << " "
                 << bd[i].ano << " "
                 << bd[i].km << " "
                 << bd[i].pot << " "
                 << bd[i].combus << " "
                 << bd[i].cambio << " "
                 << bd[i].direcao << " "
                 << bd[i].cor << " "
                 << bd[i].portas << " "
                 << bd[i].placa << " "
                 << bd[i].valor << " " << endl;
    }

    gravacao << "FIM" << endl;
    gravacao.close();

    cout << "Alteracoes salvas no arquivo. " << endl;
}

void remover_placa(registro_veiculos bd[], int &qt, string placa_remover)
{
    // Variaveis
    int pos = -1;

    // Laco para encontrar a posicao da placa no vetor
    for (int i = 0; i < qt; i++)
    {
        if (bd[i].placa == placa_remover)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        cout << "ERRO: Placa nao encontrada. " << endl;
        return;
    }
    
    // Saida de dados
    cout << "-------- VEICULO REMOVIDO --------" << endl;
    cout << bd[pos].modelo << " " << bd[pos].marca << " "
         << bd[pos].tipo << " " << bd[pos].ano << " "
         << bd[pos].km << " " << bd[pos].pot << " "
         << bd[pos].combus << " " << bd[pos].cambio << " "
         << bd[pos].direcao << " " << bd[pos].cor << " "
         << bd[pos].portas << " " << bd[pos].placa << " "
         << bd[pos].valor << " " << endl;

    // Laco para substituir o vetor na posicao i pelo seguinte
    for (int i = pos; i < qt - 1; i++)
    {
        bd[i] = bd[i + 1];
    }

    qt--;
}

void calculos_relatorio(int qt,
    int hatch, int suv, int pickup, int seda, int passeio, int van,
    int flex, int diesel, int gasolina,
    float &porc_hatch, float &porc_suv, float &porc_pickup,
    float &porc_seda, float &porc_passeio, float &porc_van,
    float &porc_flex, float &porc_diesel, float &porc_gasolina,
    float &financ, float mais_barato, float taxa, int n_prestacoes,
    float &seguro_mais_caro, float mais_caro,
    float &media_cinco_anos, float km_cinco_anos, int qt_cinco_anos)
{

    // Calculos

    // Porcentagem por tipos
    if (qt > 0)
    {
        porc_hatch = ((hatch * 100.00) / qt);
        porc_suv = ((suv * 100.00) / qt);
        porc_pickup = ((pickup * 100.00) / qt);
        porc_seda = ((seda * 100.00) / qt);
        porc_passeio = ((passeio * 100.00) / qt);
        porc_van = ((van * 100.00) / qt);

        // Porcentagem por combustivel
        porc_flex = ((flex * 100.00) / qt);
        porc_diesel = ((diesel * 100.00) / qt);
        porc_gasolina = ((gasolina * 100.00) / qt);
    }

    // Financiamento do mais barato
    financ = mais_barato * (taxa * pow(1 + taxa, n_prestacoes)) /
         (pow(1 + taxa, n_prestacoes) - 1); // Seguro estimado: 5% do valor do veiculo

    // Seguro do mais caro
    seguro_mais_caro = (mais_caro * 0.05);

    // Media de quilometragem de veiculos com 5 anos ou mais
    if (qt_cinco_anos > 0)
    {
    media_cinco_anos = (km_cinco_anos / qt_cinco_anos);
    }
    else
    {
        media_cinco_anos = 0;
    }   
}

// Funcao principal
int main()
{
    // Variaveis
    string prox, placa_mais_barato, placa_mais_caro;
    int qt = 0, hatch = 0, suv = 0, pickup = 0, seda = 0, passeio = 0, van = 0, flex = 0, c = 0, diesel = 0, gasolina = 0, qt_cinco_anos = 0, a = -1;
    const int tam = 50, n_prestacoes = 60; 
    const float taxa = 0.0179; // Taxa de financiamento adotada: 1.79% ao mes
    float financ = 0, valor_min_user = 0, valor_max_user = 0, mais_barato = 9999999, mais_caro = 0, seguro_mais_caro = 0, km_cinco_anos = 0, media_cinco_anos = 0;
    float porc_flex = 0, porc_diesel = 0, porc_gasolina = 0, porc_hatch = 0, porc_suv = 0, porc_pickup = 0, porc_seda = 0, porc_passeio = 0, porc_van = 0;
    // Escolhas do usuário
    int escolha_user = 10;
    string placa_user, cambio_user, pot_user, combus_user;
    char resposta_user = '\0';

    // Declaracao do vetor
    registro_veiculos vetorveiculos[tam];

    // Abertura do arquivomarca
    ifstream leitura("BD_veiculos_2.txt");

    // Verificação
    if (!leitura.is_open())
    {
        cout << "ERRO: Arquivo não encontrado. " << endl;
        cout << "Tente novamente. " << endl;
        return 1;
    }

    // Leitura dos dados do arquivo

    leitura >> prox; // Verificacao previa para caso encontre a palavra FIM

    // Laco para salvar as informacoes do arquivo
    while (prox != "FIM" && qt < 50)
    {   
        if (prox == "FIM")
        {
            break;
        }

        vetorveiculos[qt].modelo = prox;
        leitura >> vetorveiculos[qt].marca;
        leitura >> vetorveiculos[qt].tipo;
        leitura >> vetorveiculos[qt].ano;
        leitura >> vetorveiculos[qt].km;
        leitura >> vetorveiculos[qt].pot;
        leitura >> vetorveiculos[qt].combus;
        leitura >> vetorveiculos[qt].cambio;
        leitura >> vetorveiculos[qt].direcao;
        leitura >> vetorveiculos[qt].cor;
        leitura >> vetorveiculos[qt].portas;
        leitura >> vetorveiculos[qt].placa;
        leitura >> vetorveiculos[qt].valor;
        leitura >> prox; // Verificacao posterior para caso encontre a palavra FIM

        // Verificacao de condicoes

        // Tipos
        if (vetorveiculos[qt].tipo == "Hatch")
        {
            hatch = hatch + 1;
        }

        if (vetorveiculos[qt].tipo == "SUV")
        {
            suv = suv + 1;
        }

        if (vetorveiculos[qt].tipo == "Pick-up")
        {
            pickup = pickup + 1;
        }

        if (vetorveiculos[qt].tipo == "Seda")
        {
            seda = seda + 1;
        }

        if (vetorveiculos[qt].tipo == "Passeio")
        {
            passeio = passeio + 1;
        }

        if (vetorveiculos[qt].tipo == "Van")
        {
            van = van + 1;
        }

        // Encontrando o numero de veiculos flex e o flex automatico mais caro (sua placa e valor)
        if (vetorveiculos[qt].combus == "Flex")
        {
            flex = flex + 1;
            if (vetorveiculos[qt].cambio == "Automatico")
            {
                if (vetorveiculos[qt].valor >= mais_caro)
                {
                    mais_caro = vetorveiculos[qt].valor;
                    placa_mais_caro = vetorveiculos[qt].placa;
                }
            }
        }

        // Encontrando veiculos com combustivel igual a diesel
        if (vetorveiculos[qt].combus == "Diesel")
        {
            diesel = diesel + 1;
        }

        // Encontrando veiculos com combustivel igual a gasolina
        if (vetorveiculos[qt].combus == "Gasolina")
        {
            gasolina = gasolina + 1;
        }

        // Encontrando o veiculo mais barato e sua placa
        if (vetorveiculos[qt].pot == "1.6")
        {
            if (vetorveiculos[qt].valor < mais_barato)
            {
                mais_barato = vetorveiculos[qt].valor;
                placa_mais_barato = vetorveiculos[qt].placa;
            }
        }

        // Encontrando veiculos com ano maior ou igual a 2020
        if (vetorveiculos[qt].ano >= 2020)
        {
            qt_cinco_anos = qt_cinco_anos + 1;
            km_cinco_anos = km_cinco_anos + vetorveiculos[qt].km;
        }

        qt++;
    }
    leitura.close();

    // Entrada de dados
    while ((escolha_user = menu()) != 0)
    {
        switch (escolha_user)
        {
        case 1:
            // Verificacao da quantidade de veiculos
            if (qt >= tam)
            {
                cout << "Base cheia. Nao e possivel inserir novo veiculO" << endl;
                break;
            }

            // Entrada de dados
            cout << "-------- Entrada de informacoes do veiculo --------" << endl;
            cout << "MODELO: " << endl;
            cin >> vetorveiculos[qt].modelo;
            cout << "MARCA: " << endl;
            cin >> vetorveiculos[qt].marca;
            cout << "TIPO: " << endl;
            cin >> vetorveiculos[qt].tipo;
            cout << "ANO" << endl;
            cin >> vetorveiculos[qt].ano;
            cout << "KM: " << endl;
            cin >> vetorveiculos[qt].km;
            cout << "POTENCIA DO MOTOR: " << endl;
            cin >> vetorveiculos[qt].pot;
            cout << "COMBUSTIVEL: " << endl;
            cin >> vetorveiculos[qt].combus;
            cout << "CAMBIO: " << endl;
            cin >> vetorveiculos[qt].cambio;
            cout << "DIRECAO: " << endl;
            cin >> vetorveiculos[qt].direcao;
            cout << "COR: " << endl;
            cin >> vetorveiculos[qt].cor;
            cout << "PORTAS: " << endl;
            cin >> vetorveiculos[qt].portas;
            cout << "PLACA: " << endl;
            cin >> vetorveiculos[qt].placa;
            cout << fixed << setprecision(2);
            cout << "VALOR: R$" << fixed << setprecision(2) << endl;
            cin >> vetorveiculos[qt].valor;

            // Saida de dados
            cout << endl;
            cout << "------- VEICULO REGISTRADO --------" << endl;
            cout << "MARCA: " << vetorveiculos[qt].marca << endl;
            cout << "MODELO: " << vetorveiculos[qt].modelo << endl;
            cout << "TIPO: " << vetorveiculos[qt].tipo << endl;
            cout << "ANO: " << vetorveiculos[qt].ano << endl;
            cout << "QUILOMETRAGEM: " << vetorveiculos[qt].km << endl;
            cout << "POTENCIA DO MOTOR: " << vetorveiculos[qt].pot << endl;
            cout << "COMBUSTIVEL: " << vetorveiculos[qt].combus << endl;
            cout << "CAMBIO: " << vetorveiculos[qt].cambio << endl;
            cout << "DIRECAO: " << vetorveiculos[qt].direcao << endl;
            cout << "COR: " << vetorveiculos[qt].cor << endl;
            cout << "PORTAS: " << vetorveiculos[qt].portas << endl;
            cout << "PLACA: " << vetorveiculos[qt].placa << endl;
            cout << "VALOR: R$" << fixed << setprecision(2) << vetorveiculos[qt].valor << endl;
            qt++;

            break;

        case 2:
            // Variaveis
            a = -1;
            resposta_user = '\0';

            // Entrada de dados
            cout << "------- BUSCA POR PLACA -------- " << endl;
            cout << "Insira a placa do veiculo que deseja pesquisar: " << endl;
            cin >> placa_user;

            // Laco para encontrar os veiculos por placa
            for (c = 0; c < qt; c++)
            {
                if (vetorveiculos[c].placa == placa_user)
                {
                    cout << vetorveiculos[c].modelo << " " << vetorveiculos[c].marca
                         << " " << vetorveiculos[c].tipo << " " << vetorveiculos[c].ano << " " << vetorveiculos[c].km << " " 
                         << vetorveiculos[c].pot << " " << vetorveiculos[c].combus << " " << vetorveiculos[c].cambio
                         << " " << vetorveiculos[c].direcao << " " << vetorveiculos[c].cor << " " << vetorveiculos[c].portas << " " << vetorveiculos[c].placa << " " << vetorveiculos[c].valor << endl;
                    a = 1;
                }
            }
            if (a == 1)
            {
            cout << "-----------------------------------------------------------------------------------------------------" << endl;
            while(resposta_user != 'S' && resposta_user != 'N')
            {
            cout << "Deseja remover este veiculo do registro [S/N]? " << endl;
            cin >> resposta_user;
            }
            if(resposta_user == 'S')
            {
                remover_placa(vetorveiculos, qt, placa_user);

            } else
            {
                cout << "Voltando ao menu principal..." << endl;
                break;
            }
            } else if (a == -1)
            {
                cout << "ERRO: Veiculo nao encontrado. " << endl;

            }
            break;

        case 3:
            // Entrada de dados
            cout << "------- BUSCA POR CAMBIO -------- " << endl;
            cout << "Insira o tipo de cambio que deseja pesquisar [Automatico/Manual]: " << endl;
            cin >> cambio_user;
            cout << "-------- Lista de veiculos com cambio " << cambio_user << "--------" << endl;

            // Laco para encontrar os veiculos por cambio
            for (c = 0; c < qt; c++)
            {
                if (vetorveiculos[c].cambio == cambio_user)
                {
                    cout << vetorveiculos[c].modelo << " " << vetorveiculos[c].marca
                         << " " << vetorveiculos[c].tipo << " " << vetorveiculos[c].ano << " " << vetorveiculos[c].km << " " 
                         << vetorveiculos[c].pot << " " << vetorveiculos[c].combus << " " << vetorveiculos[c].cambio
                         << " " << vetorveiculos[c].direcao << " " << vetorveiculos[c].cor << " " << vetorveiculos[c].portas << " " << vetorveiculos[c].placa << " " << vetorveiculos[c].valor << endl;
                }
            }
            cout << "-----------------------------------------------------------------------------------------------------" << endl;
            break;

        case 4:
        {
            // Variaveis
            bool sucesso_pot = false, sucesso_combus = false;

            // Entrada de dados
            cout << "------- BUSCA POR COMBUSTIVEL E POTENCIA DO MOTOR --------" << endl;
            cout << "Insira a potencia do motor que deseja buscar: " << endl;
            cin >> pot_user;
            cout << "Insira o tipo de combustivel que deseja buscar: " << endl;
            cin >> combus_user;
            cout << "------- VEICULOS COM POTENCIA " << pot_user << " E COMBUSTIVEL " << combus_user << "--------" << endl;

            // Laco para encontrar os veiculos por potencia e combustivel
            for (c = 0; c < qt; c++)
            {  
                if (vetorveiculos[c].pot == pot_user)
                {
                    sucesso_pot = true;
                    if (vetorveiculos[c].combus == combus_user)
                    {
                        sucesso_combus = true;
                        cout << vetorveiculos[c].modelo << " " << vetorveiculos[c].marca
                         << " " << vetorveiculos[c].tipo << " " << vetorveiculos[c].ano << " " << vetorveiculos[c].km << " " 
                         << vetorveiculos[c].pot << " " << vetorveiculos[c].combus << " " << vetorveiculos[c].cambio
                         << " " << vetorveiculos[c].direcao << " " << vetorveiculos[c].cor << " " << vetorveiculos[c].portas << " " << vetorveiculos[c].placa << " " << vetorveiculos[c].valor << endl;
                    } 
                } 
            }   

            // Saida de dados
                if (sucesso_pot == false && sucesso_combus == false)
                {
                    cout << "Nao ha veiculos com potencia igual a " << pot_user << " e combustivel " << combus_user << endl;
                }
                if (sucesso_pot == true && sucesso_combus == false)
                {
                    cout << "Nao ha veiculos com combustivel " << combus_user << " para a potencia de " << pot_user << endl;
                }
            cout << "-----------------------------------------------------------------------------------------------------" << endl;
        }
        break;

        case 5:
        {
            // Variaveis
            bool sucesso = false;

            // Entrada de dados
            cout << "-------- BUSCA POR FAIXA DE VALORES --------" << endl;
            cout << "Valor minimo: R$" << endl;
            cin >> valor_min_user;
            cout << "Valor maximo: R$" << endl;
            cin >> valor_max_user;
            cout << "------- VEICULOS COM VALOR ENTRE R$" << valor_min_user << "-" << valor_max_user << " --------" << endl;

            // Laco para encontrar os veiculos por faixa de valores
            for (c = 0; c < qt; c++)
            {
                if (vetorveiculos[c].valor >= valor_min_user && vetorveiculos[c].valor <= valor_max_user)
                {
                    sucesso = true;
                    cout << vetorveiculos[c].modelo << " " << vetorveiculos[c].marca
                         << " " << vetorveiculos[c].tipo << " " << vetorveiculos[c].ano << " " << vetorveiculos[c].km << " " 
                         << vetorveiculos[c].pot << " " << vetorveiculos[c].combus << " " << vetorveiculos[c].cambio
                         << " " << vetorveiculos[c].direcao << " " << vetorveiculos[c].cor << " " << vetorveiculos[c].portas << " " << vetorveiculos[c].placa << " " << vetorveiculos[c].valor << endl;
                }
            }

            // Saida de dados
            if (sucesso == false)
            {
                cout << "Nao ha veiculos com valor entre R$" << valor_min_user << "-" << valor_max_user << endl;
            }
            cout << "-----------------------------------------------------------------------------------------------------" << endl;
        }
            break;

        case 6:
            // Zerando contadores para recontagem
            hatch = suv = pickup = seda = passeio = van = 0;
            flex = diesel = gasolina = 0;
            mais_barato = 9999999;
            mais_caro = 0;
            placa_mais_barato = "";
            placa_mais_caro = "";
            km_cinco_anos = 0;
            qt_cinco_anos = 0;

            // Recontagem completa
            for (c = 0; c < qt; c++)
            {
                // Tipos
                if (vetorveiculos[c].tipo == "Hatch") 
                    {
                        hatch = hatch + 1;
                    }
                if (vetorveiculos[c].tipo == "SUV") 
                    {
                        suv = suv + 1;
                    }
                if (vetorveiculos[c].tipo == "Pick-up") 
                    {
                        pickup = pickup + 1;
                    }
                if (vetorveiculos[c].tipo == "Seda") 
                    {
                        seda = seda + 1;
                    }
                if (vetorveiculos[c].tipo == "Passeio") 
                    {
                        passeio = passeio + 1;
                    }
                if (vetorveiculos[c].tipo == "Van") 
                    {
                        van = van + 1;
                    }

                // Combustivel
                // Encontrando o numero de veiculos flex e o flex automatico mais caro (sua placa e valor)
                if (vetorveiculos[c].combus == "Flex")
                {
                    flex = flex + 1;
                    if (vetorveiculos[c].cambio == "Automatico")
                    {
                        if (vetorveiculos[c].valor >= mais_caro)
                        {
                            mais_caro = vetorveiculos[c].valor;
                            placa_mais_caro = vetorveiculos[c].placa;
                        }
                    }
                }

                // Encontrando veiculos com combustivel igual a diesel
                if (vetorveiculos[c].combus == "Diesel")
                {
                    diesel = diesel + 1;
                }

                // Encontrando veiculos com combustivel igual a gasolina
                if (vetorveiculos[c].combus == "Gasolina")
                {
                    gasolina = gasolina + 1;
                }

                // Encontrando o veiculo mais barato e sua placa
                if (vetorveiculos[c].pot == "1.6")
                {
                    if (vetorveiculos[c].valor < mais_barato)
                    {
                        mais_barato = vetorveiculos[c].valor;
                        placa_mais_barato = vetorveiculos[c].placa;
                    }
                }

                // Encontrando veiculos com ano maior ou igual a 2020
                if (vetorveiculos[c].ano >= 2020)
                {
                    qt_cinco_anos = qt_cinco_anos + 1;
                    km_cinco_anos = km_cinco_anos + vetorveiculos[c].km;
                }
            }

            // Funcao que calcula os indices
            calculos_relatorio(qt,
                               hatch, suv, pickup, seda, passeio, van,
                               flex, diesel, gasolina,
                               porc_hatch, porc_suv, porc_pickup,
                               porc_seda, porc_passeio, porc_van,
                               porc_flex, porc_diesel, porc_gasolina,
                               financ, mais_barato, taxa, n_prestacoes,
                               seguro_mais_caro, mais_caro,
                               media_cinco_anos, km_cinco_anos, qt_cinco_anos);

            // Saida de dados
            cout << "-------- REGISTRO DE VEICULOS COMPLETO --------" << endl;
            registro(vetorveiculos, qt);
            cout << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "PORCENTAGEM DE VEICULOS POR TIPO" << endl;
            cout << "HATCH: " << porc_hatch << "%" << endl;
            cout << "SUV: " << porc_suv << "%" << endl;
            cout << "PICKUP: " << porc_pickup << "%" << endl;
            cout << "SEDA: " << porc_seda << "%" << endl;
            cout << "PASSEIO: " << porc_passeio << "%" << endl;
            cout << "VAN: " << porc_van << "%" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "PORCENTAGEM DE VEICULOS POR TIPO DE COMBUSTIVEL" << endl;
            cout << "FLEX: " << porc_flex << "%" << endl;
            cout << "DIESEL: " << porc_diesel << "%" << endl;
            cout << "GASOLINA: " << porc_gasolina << "%" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << "VEICULO MAIS BARATO 1.6" << endl;
            cout << "PLACA: " << placa_mais_barato << endl;
            cout << "VALOR: R$" << fixed << setprecision(2) << mais_barato << endl;
            cout << "FINANCIAMENTO EM 60 MESES - JUROS: 1.79%" << endl;
            cout << "VALOR DAS PRESTACOES: R$" << fixed << setprecision(2) << financ << endl;
            cout << "------------------------------------------------------" << endl;
            cout << "VEICULO MAIS CARO FLEX COM CAMBIO AUTOMATICO " << endl;
            cout << "PLACA: " << placa_mais_caro << endl;
            cout << "VALOR: R$" << fixed << setprecision(2) << mais_caro << endl;
            cout << "VALOR ESTIMADO DO SEGURO: R$" << fixed << setprecision(2) << seguro_mais_caro << endl;
            cout << "------------------------------------------------------" << endl;
            cout << "VEICULOS COM ATE 5 ANOS " << endl;
            cout << "QUANTIDADE: " << fixed << setprecision(0) << qt_cinco_anos << endl;
            cout << "MEDIA DA QUILOMETRAGEM: " << fixed << setprecision(2) << media_cinco_anos << "km" << endl;
            cout << "------------------------------------------------------" << endl;
            cout << endl;

            break;
        }
    }

    // Funcao para salvar as alteracoes
    salvar_arquivo(vetorveiculos, qt);
    cout << "Encerrando... " << endl;
    
    return 0;
}
