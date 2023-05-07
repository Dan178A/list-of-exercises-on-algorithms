// Escribir una funcion que calcule si un numero es primo (un numero primo es
// un numero natural mayor que 1 que tiene unicamente dos divisores positivos
// distintos:  el mismo y el 1)
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * La función comprueba si un número dado es primo o no.
 * 
 * @param numero un número entero que queremos comprobar si es un número primo o no.
 * 
 * @return La función `es_primo` devuelve un valor booleano (`verdadero` o `falso`) dependiendo de si
 * el `numero` de entrada es un número primo o no.
 */
bool es_primo(int numero) {
    if (numero < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numero;
    printf("Introduzca un número: ");
    scanf("%d", &numero);

    if (es_primo(numero)) {
        printf("El número %d es primo.\n", numero);
    } else {
        printf("El número %d no es primo.\n", numero);
    }

    return 0;
}