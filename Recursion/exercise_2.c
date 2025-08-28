/*2) Máximo em Lista
Crie uma função recursiva que receba uma lista de números e retorne o maior elemento.
Exemplo: maximo([3, 7, 2, 9, 1]) → 9.
*/

#include <stdio.h>
#include <stdlib.h>

int maximo(int *arr, int n) {
    if (n == 1) {
        return arr[0];
    }
    int max_rest = maximo(arr + 1, n - 1);
    return (arr[0] > max_rest) ? arr[0] : max_rest;
}

int main() {
    int n;
    printf("Digite o número de elementos na lista: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }
    printf("Digite os elementos da lista:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max_value = maximo(arr, n);
    printf("O maior elemento é: %d\n", max_value);
    free(arr);
    return 0;
}