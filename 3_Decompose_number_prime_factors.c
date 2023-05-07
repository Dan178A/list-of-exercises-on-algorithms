/*
 Hacer un programa que descomponga un numero en sus factores primos 
 (en la teorıa de numeros, los factores primos de un numero entero son los numeros primos 
 divisores exactos de ese numero entero)
*/
#include <stdio.h>
#include <math.h>

/**
 * La función comprueba si un número entero dado es un número primo o no.
 * 
 * @param n El entero de entrada para el que queremos determinar si es un número primo o no.
 * 
 * @return La función `es_primo` devuelve un valor entero de 0 o 1. Devuelve 0 si el número de entrada
 * `n` es menor o igual a 1 o si no es un número primo. Devuelve 1 si el número de entrada `n` es un
 * número primo.
 */
int es_primo(int n) {
    if (n <= 1) return 0;
    int limite = sqrt(n);
    for (int i = 2; i <= limite; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

/**
 * La función "siguiente_primo" devuelve el siguiente número primo después del entero de entrada.
 * 
 * @param n El parámetro "n" es un número entero que representa el punto de partida a partir del cual
 * queremos encontrar el siguiente número primo. La función "siguiente_primo" devuelve el menor número
 * primo mayor que "n".
 * 
 * @return La función `siguiente_primo` devuelve el siguiente número primo mayor que el parámetro de
 * entrada `n`.
 */
int siguiente_primo(int n) {
    do {
        n++;
    } while (!es_primo(n));
    return n;
}

/**
 * La función "descomponer_factores" imprime los factores primos de un entero dado.
 * 
 * @param n El parámetro "n" representa el número entero que queremos descomponer en sus factores
 * primos.
 */
void descomponer_factores(int n) {
    int factor_primo = 2;
    printf("Factores primos de %d: ", n);
    while (n > 1) {
        if (n % factor_primo == 0) {
            printf("%d ", factor_primo);
            n /= factor_primo;
        } else {
            factor_primo = siguiente_primo(factor_primo);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Ingrese un número (>1): ");
    scanf("%d", &n);
    if (n <= 1)
        printf("Debe ingresar un número mayor que uno\n");
    else
        descomponer_factores(n);
    return 0;
}
