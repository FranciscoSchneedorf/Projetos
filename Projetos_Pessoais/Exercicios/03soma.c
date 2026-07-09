#include <stdio.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
// Declaração de variáveis
    int num1, num2, soma;

// Entrada de dados
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    soma = num1 + num2;
    printf("A soma de %d e %d é: %d", num1, num2, soma);


    return 0;
}