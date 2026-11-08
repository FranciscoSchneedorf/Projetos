/*
Autor: Francisco Schneedorf Leite Ferreira
Data: 08/04/2026
Disciplina: AEDs I - Prática
Objetivo: Informar ao usuário se os valores inseridos formam ou não um triângulo e, se formam
de qual tipo.


*/


#include <stdio.h>

int main(){

// Variáveis
double l1, l2, l3;

// Entrada de dados
    printf("Insira o valor do primeiro lado do triângulo: ");
    scanf("%lf", &l1);
    printf("Insira o valor do segundo lado do triângulo: ");
    scanf("%lf", &l2);
    printf("Insira o valor do terceiro lado do triângulo: ");  
    scanf("%lf", &l3);


// Validação
    if (l1 <=0 || l2 <=0 || l3 <=0){
        printf("Insira valores positivos. ");
        return 1;
        
    }


// Cálculos e saída de dados
    if ((l1 + l2 > l3) && (l1 + l3 > l2) && (l2 + l3 > l1)){  
        printf("Os valores formam um triângulo");

        // Determinação do tipo
        if ((l1 == l2) && (l2 == l3)){
            printf(" equilátero. ");
        } 
        else if ((l1 == l2) || (l1 == l3) || (l2 == l3)){
            printf(" isósceles. ");
        } 
        else {
            printf(" escaleno. ");
        }
        
    } 
    else {
        printf("Os valores não formam um triângulo.");
    }












    return 0;
}