#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    // Variáveis
    float nota1, nota2, media;

// Entrada de dados
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    media = (nota1 + nota2) / 2;
    printf("A média das notas é: %.2f\n\n", media);
    if (media >= 6){
        printf ("Aprovado! ");
    } else{
        printf("Reprovado! ");
    
    }
    return 0;

}