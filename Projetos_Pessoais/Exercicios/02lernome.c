#include <stdio.h>
#include <locale.h>
#include <string.h>


int main(){
char n[100];
    setlocale(LC_ALL, "Portuguese");
    printf ("Qual o seu nome? ");
    fgets(n, sizeof(n), stdin); // fgets lê toda a linha até o enter, adiciona um \n no final e um \0 para indicar o fim da string. 
    if (strchr(n, '\n') == NULL){
        printf("O nome é muito grande. Por favor, tente novamente.");
        return 1;
    }
 
    printf("Prazer em conhecê-lo, %s", n);

    return 0;
}