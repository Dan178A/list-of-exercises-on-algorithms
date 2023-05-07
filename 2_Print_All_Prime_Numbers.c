// Realizar un programa que imprima todos los numeros primos entre 1 y n, siendo
// n un numero introducido por el usuario.
#include <stdio.h>
#include <stdbool.h>

/**
 * La función comprueba si un número entero dado es un número primo o no.
 * 
 * @param numero un número entero que queremos comprobar si es un número primo o no.
 * 
 * @return La función `es_primo` devuelve un valor booleano que indica si la entrada `numero` es un
 * número primo o no. Si `numero` es menor o igual a 1, la función devuelve `falso`. Si `numero` es
 * igual a 2, la función devuelve `true`. De lo contrario, la función comprueba si `numero` es
 * divisible por cualquier número entero entre 2 y el cuadrado
 */
bool es_primo(int numero) {
    if (numero <= 1) {
        return false;
    }
    if (numero == 2) {
        return true;
    }
    for (int divisor = 2; divisor * divisor <= numero; divisor++) {
        if (numero % divisor == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    printf("Introduce un número: ");
    scanf("%d", &n);

    printf("Números primos entre 1 y %d:\n", n);
    for (int i = 1; i <= n; i++) {
        if (es_primo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}