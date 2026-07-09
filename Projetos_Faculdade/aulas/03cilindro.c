/* Autor: Francisco Schenedorf Leite Ferreira
   Disciplina: AEDs I - Prática
   Data: 12/03/2026
   */



#include <stdio.h>

int main (){
	float h, d, a;
	printf("\n\tDigite o valor da altura: ");
	scanf("%f", &h);
	printf("\n\tDigite o valor do diâmetro: ");
	scanf("%f", &d);
	a = ((d/2)*(d/2)*3.14*h);
        printf("\n\tA área do cilindro vale %.2f\n\n", (a));

return 0;
}

