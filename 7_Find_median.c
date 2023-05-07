/*7_Find_median.c*/
/*
Escriba una funcion que, dado un vector de numeros reales de size of the variable, 
nos devuelva la mediana de los valores incluidos en el vector.
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * La función es una función de comparación utilizada para clasificar una matriz de dobles en orden
 * ascendente.
 * 
 * @param a a es un puntero a un tipo de vacío constante. Esto significa que el tipo de datos de la
 * variable a la que apunta es desconocido y no se puede modificar dentro de la función.
 * @param b El parámetro "b" es un puntero a un tipo de vacío constante. En el contexto de la función,
 * se utiliza para representar el segundo elemento que se compara en el algoritmo de clasificación.
 * 
 * @return La función `cmpfunc` está devolviendo la diferencia entre los valores señalados por `a` y
 * `b`, que se convierten en punteros `dobles` mediante el encasillado. Esta es una forma común de
 * implementar una función de comparación para usar con la función `qsort` en C. El valor devuelto debe
 * ser negativo si el valor señalado por `a` es menor que el valor señalado por
 */
int cmpfunc(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}

/**
 * La función encuentra la mediana de una matriz dada de dobles mediante ordenación rápida y la
 * devuelve.
 * 
 * @param arr una matriz de valores dobles de los que queremos encontrar la mediana.
 * @param n El número de elementos en la matriz.
 * 
 * @return La función `find_median` devuelve el valor de la mediana de una matriz dada de dobles. Si el
 * arreglo tiene un número impar de elementos, la mediana es el elemento del medio. Si el arreglo tiene
 * un número par de elementos, la mediana es el promedio de los dos elementos del medio.
 */
/**
 * La función encuentra la mediana de una matriz dada de dobles mediante ordenación rápida y la
 * devuelve.
 * 
 * @param arr una matriz de valores dobles de los que queremos encontrar la mediana.
 * @param n El número de elementos en la matriz.
 * 
 * @return La función `find_median` devuelve el valor de la mediana de una matriz dada de dobles. Si el
 * arreglo tiene un número impar de elementos, la mediana es el elemento del medio. Si el arreglo tiene
 * un número par de elementos, la mediana es el promedio de los dos elementos del medio.
 */
double find_median(double arr[], int n) {
    qsort(arr, n, sizeof(double), cmpfunc);
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}

/**
 * Esta función solicita al usuario que ingrese una matriz de números reales y luego calcula e imprime
 * la mediana de esos números.
 * 
 * @return La función principal devuelve un valor entero de 0.
 */
int main() {
    int n;
    double arr[50];
    printf("Enter the size of the array (maximum 50): ");
    scanf("%d", &n);
    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    printf("Median of the values in the array: %lf\n", find_median(arr, n));
    return 0;
}
