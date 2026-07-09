/* Autor: Francisco Schneedorf Leite Ferreira
   Disciplina: AEDs I - Prática
   Data: 10/03/2026 */


#include <stdio.h> // inclui uma biblioteca

int main(){ // int: retorna um valor inteiro 
  // Declaração das variáveis
  float prova_1, prova_2, projeto;  
  float media;
  
  // Entrada de dados  
    printf("\n\tDigite a nota da primeira prova: ");
    scanf("%f", &prova_1);
    printf("\n\tDigite a nota da segunda prova: ");
    scanf("%f", &prova_2);
    printf("\n\tDigite a nota do projeto: ");
    scanf("%f", &projeto);
  // Cálculos
    media = ((prova_1 * 30 + prova_2 * 30 + projeto * 40)/100);
  
  // Saída dos Resultados
  printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("\n\tA média é: ");
  printf("\n\tMemória    Expressão    Resultado    Tela\n");
  printf("\n\tint        int          int          int: %d\n", (int) (prova_1 * 30 + prova_2 * 30 + projeto * 40)/100);
  printf("\n\tint        float        int          float: %5.2f\n", (30.0 * prova_1 + 30 * prova_2 + 40 * projeto) / 100);
  printf("\n\tint/float  float        float        float: %5.2f\n", (30.0 * prova_1 + 30 * prova_2 + 40 * projeto) / 100);
  printf("\n\tint/float  float        float        int: %d\n", (int) (30.0 * prova_1 + 30 * prova_2 + 40 * projeto) / 100); // (int) é um cast; força-se uma conversão 
  printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  if (media >= 6.0){
      printf("\n\tVocê está aprovado\n\n");
      
  } else{
    printf("\n\tVocê está reprovado\n\n");
      
  }
}
