#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

// Funções secundárias

    void linha (){
        int z;
        printf("\n\n");
        for (z =1; z<=30; z++){
            printf("-=");

        }
        printf("\n");


    }

int main()
{   

setlocale(LC_ALL, "Portuguese_Brazil");

    // Variáveis
    int resp1, resp2;
    char resp_tent = 'N';

    // Entrada de dados
while (resp2 != 5) // O loop continua até que o usuário digite 5
{ 
    linha();  
    printf("\nCalculadora");
    printf("\n[1] SOMAR");
    printf("\n[2] SUBTRAIR");
    printf("\n[3] MULTIPLICAR");
    printf("\n[4] BASKHARA");
    printf("\n[5] SAIR\n");
    scanf("%i", &resp2);
linha();

    // Casos correspondentes a escolha do usuário

    switch (resp2)
    {
    case 1:
    {
        system("cls");
        linha();
        int c, num_valores_soma;
        float soma = 0;
        printf("Deseja somar quantos valores? ");
        scanf("%i", &num_valores_soma);
        float numeros_soma[num_valores_soma];
        // Armazena os valores a somar até o número correspondente a quantidade de valroes a somar (num_valores_soma)
        for (c = 0; c < num_valores_soma; c++)
        {
            printf("Digite o %i valor: ", c + 1);
            // Armazena o valor digitado naquela posição em um array
            scanf("%f", &numeros_soma[c]);
        }
        // Soma os valores do array numeros_soma
        for (c = 0; c < num_valores_soma; c++)
        {
            soma = soma + numeros_soma[c];
        }
        printf("A soma dos valores é %.2f\n", soma);

        break;
    }

    case 2:
    {
        system("cls");
        linha();
        // Variáveis
        int c, num_valores_subtrair;
        // Números de valores a subtrair
        printf("Deseja subtrair quantos valores? ");
        scanf("%i", &num_valores_subtrair);

        // Declarando o array após ter o número de espaços no vetor
        float numeros_subtrair[num_valores_subtrair];

        // Armazena o valor digitado naquela posição do array numeros_subtrair
        for (c = 0; c < num_valores_subtrair; c++)
        {
            printf("Digite o %i valor: ", c + 1);
            scanf("%f", &numeros_subtrair[c]);
        }
        float sub = numeros_subtrair[0];

        // Subtração

        for (c = 1; c < num_valores_subtrair; c++)
        {
            sub = sub - numeros_subtrair[c];
        }

        printf("A subtração dos valores é %.2f ", sub);

        break;
    }

    case 3:
    {   
        system("cls");
        linha();
        // Variáveis

        int c, num_valores_mult;

        printf("Deseja multiplicar quantos valores? ");
        scanf("%i", &num_valores_mult);

        // Declaração do array
        float numeros_mult[num_valores_mult];

        // Armazena o valor digitado naquela posição do array numeros_mult
        for (c = 0; c < num_valores_mult; c++)
        {
            printf("Digite o %i valor: ", c + 1);
            scanf("%f", &numeros_mult[c]);
        }

        // Cálculo da multiplicação
        float mult = numeros_mult[0];

        for (c = 1; c < num_valores_mult; c++)
        {
            mult = mult * numeros_mult[c];
        }

        // Saída

        printf("A multiplicação dos valores é %.2f. ", mult);

        break;
    }

    case 4:
    {   
        system("cls");
        linha();
        // Variáveis

        char verif_resp = 'N', resp_tent = 'S';
        float a, b, c, delta, x1, x2, calc_verif;

        // Laço para manter o programa, até que, ao dar != zero na verificação, o usuário digite N

        while (resp_tent == 'S')
        {

            // Entrada de dados

            printf("Digite o valor de a: ");
            scanf("%f", &a);
            printf("Digite o valor de b: ");
            scanf("%f", &b);
            printf("Digite o valor de c: ");
            scanf("%f", &c);

            // Cálculos

            delta = (pow(b, 2) - (4 * a * c));

            // Saída de dados
            if (delta < 0){
                printf("DELTA < 0\nNÃO EXISTEM RAÍZES REAIS. ");
 
            } else {

            x1 = ((-b + sqrt(delta)) / (2 * a));
            x2 = ((-b - sqrt(delta)) / (2 * a));

            printf("\tDELTA = %.2f\n", delta);
            printf("\tX1 = %.2f\n", x1);
            printf("\tX2 = %.2f\n", x2);
            
            // Verificação da resposta

            printf("Deseja verificar os valores? [S/N]: ");
            scanf(" %c", &verif_resp);
            verif_resp = toupper(verif_resp);
            }     

            // Se sim, faz o cálculo

            if (verif_resp == 'S')
            {
                calc_verif = ((pow(x1, 2) * a) + (x1 * b) + c);
                if (fabs(calc_verif) < 0.01)
                {
                    printf("%.2f*%.2f^2 + %.2f*%.2f + %.2f = %.2f\n", a, x1, b, x1, c, calc_verif);
                    printf("Valores corretos! ");
                }
                else
                {
                    printf("%.2f*%.2f^2 + %.2f*%.2f + %.2f = %.2f\n", a, x1, b, x1, c, calc_verif);
                    printf("\nValores incorretos.");
                }
            }
            printf("Deseja calcular outro Baskhara? [S/N]: ");
            scanf(" %c", &resp_tent);
            resp_tent = toupper(resp_tent);
            
            // Se sim, limpa-se a tela
            if (resp_tent == 'S'){
                system("cls");
            }


    
        }
        break ;
    }
    
    case 5:
    {
    
        system("cls");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\nEncerrando o programa... ");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=");



    }


    }

}
    return 0;
}