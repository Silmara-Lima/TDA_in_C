#include <stdio.h>
#include <unistd.h>

// Função recursiva para calcular fatorial e mostrar a pilha
unsigned long long fatorial(int n, int nivel) {
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("-> Chamando fatorial(%d)\n", n);
    usleep(300000);

    if (n == 0 || n == 1) { // caso base
        for (int i = 0; i < nivel; i++) printf("  ");
        printf("OK Retornando 1 (caso base)\n");
        usleep(300000);
        return 1;
    } else {
        unsigned long long resultado = n * fatorial(n - 1, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("  ");
        printf("<- Retornando %llu para fatorial(%d)\n", resultado, n);
        usleep(300000);
        return resultado;
    }
}

int main() {
    int numero;

    printf("Digite um valor inteiro para calcular o fatorial: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Não é possível calcular o fatorial de números negativos.\n");
    } else {
        unsigned long long resultado = fatorial(numero, 0);
        printf("\nO fatorial de %d vale: %llu\n", numero, resultado);
    }

    return 0;
}
