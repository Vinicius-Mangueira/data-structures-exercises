/* 1) Inverter String
Escreva uma função recursiva que receba uma string e retorne a string invertida.
Exemplo: inverter("recursao") → "oasrucer".*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inverter(char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inverter(str, inicio + 1, fim - 1);
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove o caractere de nova linha, se presente
    int len = strlen(str);
    inverter(str, 0, len - 1);
    printf("String invertida: %s\n", str);
    return 0;
}


