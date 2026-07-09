#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

// Funções secundárias

void linha(){
    int z;
    printf("\n\n");
    for (z = 1; z<=30; z++){ // Para c de 1 ate 30, some 1 a cada repetição e imprima "-=". Quando acabar, pule uma linha
        printf("-=");

    }
    printf("\n");

}

void linha2(){
    int y;
    printf("\t");
    for(y = 1; y <= 20; y++){
        printf("-");

    }
    printf("\n");


}

// Função principal

int main ()
{
setlocale(LC_ALL, "Portuguese_Brazil");

// Variáveis

float a, b, c, delta, x1, x2, verif;
char resp, resp2;

// Entrada de dados
linha();
resp2 = 'S';
printf("\t\tBASHKARA CALCULATOR\n");
while (resp2 == 'S') {   
    printf("\tInforme o valor de a: ");
    scanf("%f", &a);
    printf("\tInforme o valor de b: ");
    scanf("%f", &b);
    printf("\tInforme o valor de c: ");
    scanf("%f", &c);

// Cálculo do delta

    delta = (b*b) -(4*a*c);

// Verificação do valor de delta

    if (delta < 0)
    {   
        linha();
        printf("\n\tDELTA (%f < 0)\n", delta);
        linha2();
        printf("\tDELTA = %.2f ---> CÁLCULO DE BASHKARA NÃO É POSSÍVEL.\n", delta);
        printf("\tTente novamente...\n");
        linha2();
        return 0;
    }
        else {

    // Cálculo do x1 e x2

    x1 = ((-b+ sqrt(delta))/(2*a));
    x2 = ((-b- sqrt(delta))/(2*a));
    printf("\tx1: %.2f\n", x1);
    printf("\tx2: %.2f", x2);
    }
    linha();
    printf("\n\tGostaria de verificar se as raízes estão corretas? [S/N] \n");
    scanf(" %c", &resp);
    resp = toupper(resp);
    if (resp == 'S'){

    // Verificação das raízezs

        verif = (a * pow(x1, 2)+ (x1*b) + c);
        if (verif == 0) {
        linha2();
        printf("\tCÁLCULO DE VERIFICAÇÃO: \n");
        linha2();
        printf("\t((%.2f^2)*%.2f) + (%.2f*%.2f) + %.2f = %.2f\n", x1, a, x1, b, c, verif);
        linha2();
        printf("\tRESULTADO = 0 --> Valores corretos! \n");
        printf("\tObrigado pela preferência !\n");
        linha2();
        printf("\n\n");
        return 0;
        } else {
        linha2();
        printf("\tCÁLCULO DE VERIFICAÇÃO: \n");
        printf("\t((%.2f^2)*%.2f) + (%.2f*%.2f) + %.2f = %.2f\n", x1, a, x1, b, c, verif);

        // Quando incorreto; para perguntar se quer calcular novamente. Se simn, reinicia o processo

        printf("\tRESULTADO = %.2f --> Valores incorretos! \n", verif);
        linha2();
        printf("\tTentar novamente? [S/N]");
        scanf(" %c", &resp2);
        resp2 = toupper(resp2);
        if (resp2 == 'N'){
            printf("\tObrigado pela preferência! ");
            linha();
            return 0;

        }
        }
    
    } else {
        printf("\tObrigado pela preferência! ");
        linha();
        return 0;
    }


}
return 0;
}