# list-of-exercises-on-algorithms
Lista de ejercios de algorimos
> Note: puede hacer click en cualquiero Archivo.c Ejemplo: [8_Count_words_characters_lines.c](8_Count_words_characters_lines.c) para verlo. 

[1_Number_is_Prime.c](1_Number_is_Prime.c)
 * Escribir una funcion que calcule si un numero es primo (un numero primo es
un numero natural mayor que 1 que tiene unicamente dos divisores positivos
Distintos:  el mismo y el 1)

 > La función comprueba si un número dado es primo o no.
 > @param numero un número entero que queremos comprobar si es un número primo o no.
 > @return La función `es_primo` devuelve un valor booleano (`verdadero` o `falso`) dependiendo de si
 > el `numero` de entrada es un número primo o no.

```c
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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
```

[2_Print_All_Prime_Numbers.c](2_Print_All_Prime_Numbers.c)
* Problem Realizar un programa que imprima todos los numeros primos entre 1 y n, siendo n un numero introducido por el usuario.

 > El programa imprime todos los números primos entre 1 y un número ingresado por el usuario.
 > @param numero El parámetro "numero" es una variable entera que representa el número cuya primalidad
 > se está comprobando en la función "es_primo".
 > @return La función `es_primo` devuelve un valor booleano (`verdadero` o `falso`) dependiendo de si
 > el `numero` de entrada es un número primo o no. La función principal devuelve un valor entero (`0`)
 > para indicar una ejecución exitosa.
 ```c 
 #include <stdio.h>
#include <stdbool.h>


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
 ```

[# 3_Decompose_number_prime_factors.c](3_Decompose_number_prime_factors.c)

* Problem:  Hacer un programa que descomponga un numero en sus factores primos 
 (en la teorıa de numeros, los factores primos de un numero entero son los numeros primos 
 divisores exactos de ese numero entero)
 > El programa toma un número de entrada y genera sus factores primos.
 > @param n El número de entrada que se factorizará en sus factores primos.
 > @return La función principal devuelve un valor entero de 0, lo que indica una ejecución exitosa del
 > programa. Las otras funciones no tienen declaración de retorno ya que son funciones nulas.
 ```c 
#include <stdio.h>
#include <math.h>


int es_primo(int n) {
    if (n <= 1) return 0;
    int limite = sqrt(n);
    for (int i = 2; i <= limite; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int siguiente_primo(int n) {
    do {
        n++;
    } while (!es_primo(n));
    return n;
}

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
 ```
[4_DistanciaEuclidiana.c](4_DistanciaEuclidiana.c)
 * Problem: Escriba una funcion que reciba las coordenadas de dos puntos del plano, y calcule
su distancia euclıdea. La distancia euclıdea entre dos puntos del plano cartesiano
viene dada por: d(p1,p2) = √(x1 - x2)² + (y1 - y2)²   donde p1 = (x1, y1) y p2 = (x2, y2)
 > La función calcula la distancia euclidiana entre dos puntos en un espacio bidimensional.
 > @param x1 La coordenada x del primer punto.
 > @param y1 La coordenada y del primer punto.
 > @param x2 La coordenada x del segundo punto.
 > @param y2 La coordenada y del segundo punto en un sistema de coordenadas cartesianas bidimensional.
 > @return La función "distanciaEuclidiana" devuelve un valor flotante, que es la distancia entre dos
 > puntos en un espacio bidimensional.
```c
 #include<stdio.h>
#include<math.h>


float distanciaEuclidiana(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float distancia = sqrt(dx*dx + dy*dy);
    return distancia;
}

// Ejemplo de uso:
int main() {
    float x1, y1, x2, y2;
    printf("Ingrese las coordenadas del primer punto (x,y): ");
    scanf("%f,%f", &x1, &y1);
    printf("Ingrese las coordenadas del segundo punto (x,y): ");
    scanf("%f,%f", &x2, &y2);
    float d = distanciaEuclidiana(x1, y1, x2, y2);
    printf("La distancia entre los puntos (%0.2f,%0.2f) y (%0.2f,%0.2f) es: %0.2f\n", x1, y1, x2, y2, d);
    return 0;
}
```
[5_ContarSubcadena.c](5_ContarSubcadena.c)
 * Problem Escriba una funcion que nos diga el numero de veces que aparece una subcadena
dentro de una cadena de caracteres. Por ejemplo, dada la cadena aabbababa, la
funcion debe devolver 2 cuando recibe como parametro la cadena aba.

 > La función cuenta el número de ocurrencias de una subcadena dada en una cadena dada.
 > @param str Una matriz de caracteres (cadena) que contiene la cadena principal en la que queremos
 > contar las ocurrencias de una subcadena.
 > @param substr La subcadena de la que queremos contar las ocurrencias en la cadena dada.
 > @return La función `count_substring` devuelve un valor entero que representa el número de veces que
 > aparece la subcadena dada en la cadena dada.
 ```c
#include <stdio.h>
#include <string.h>

int count_substring(char *str, char *substr) {
    int count = 0;
    int sublen = strlen(substr);
    while (*str) {
        if (strncmp(str, substr, sublen) == 0) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[50], substr[50];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    printf("Enter a substring to count: ");
    scanf(" %[^\n]", substr);
    printf("Substring '%s' appears %d times in '%s'\n", substr, count_substring(str, substr), str);
    return 0;
}
```
[6_Remove_Duplicates.c](6_Remove_Duplicates.c)
 *Problem: Escriba una funcion que elimine los caracteres repetidos de una cadena de caracteres
  > La función elimina los caracteres duplicados de una cadena determinada.
 > @param str una matriz de caracteres (cadena) que contiene la cadena de entrada que se procesará y
 > eliminará los duplicados.
 > @return La función `remove_duplicates` no devuelve nada. Modifica la cadena de entrada `str` al
 > eliminar los caracteres duplicados.
 ```c
#include <stdio.h>
#include <string.h>

void remove_duplicates(char *str) {
    int len = strlen(str);
    if (len < 2) {
        return;
    }
    int tail = 1;
    for (int i = 1; i < len; i++) {
        int j;
        for (j = 0; j < tail; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == tail) {
            str[tail] = str[i];
            tail++;
        }
    }
    str[tail] = '\0';
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    remove_duplicates(str);
    printf("String with duplicates removed: %s\n", str);
    return 0;
}
```

[*7_Find_median.c](7_Find_median.c)
 * Problem: Escriba una funcion que, dado un vector de numeros reales de size of the variable, 
nos devuelva la mediana de los valores incluidos en el vector.

 > El programa toma una matriz de números reales, los ordena y devuelve el valor de la mediana.
 > @param a La matriz de valores dobles para ordenar y encontrar la mediana.
 > @param b En la función `cmpfunc`, `b` no es un parámetro. No se utiliza en la función. La función
 > solo toma dos parámetros `a` y `b`, pero `b` no se usa.
 > @return La función `find_median` devuelve el valor de la mediana de una matriz dada de dobles.
 ```c
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}


double find_median(double arr[], int n) {
    qsort(arr, n, sizeof(double), cmpfunc);
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        return arr[n/2];
    }
}


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
```
[8_Count_words_characters_lines.c](8_Count_words_characters_lines.c)
 * Problem:     Diseñe implemente un programa en C que cuente el numero de caracteres,
    palabras y lıneas de un archivo de texto.
    
 > Este programa C++ lee un archivo y cuenta el número de caracteres, palabras y líneas que contiene.
 > @return El programa devuelve 0, lo que indica una ejecución exitosa.
 ```c
#include <stdio.h>
int main() {
    char filename[100];
    char ch;
    int chars = 0, words = 0, lines = 0, in_word = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        chars++;

        if (ch == '\n') {
            lines++;
            in_word = 0;
        } else if (ch == ' ' || ch == '\t') {
            in_word = 0;
        } else {
            if (in_word == 0) {
                words++;
                in_word = 1;
            }
        }
    }

    fclose(fp);

    printf("Number of characters: %d\n", chars);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);

    return 0;
}
```
> Note: `archivo.txt ` is required for [8_Count_words_characters_lines.c](8_Count_words_characters_lines.c) rendering.
