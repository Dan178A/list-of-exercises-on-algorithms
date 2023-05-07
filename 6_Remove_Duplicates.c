/*Escriba una funcion que elimine los caracteres repetidos de una cadena de caracteres.*/
#include <stdio.h>
#include <string.h>
/**
 * La función elimina los caracteres duplicados de una cadena determinada.
 * 
 * @param str Un puntero a una matriz de caracteres (cadena) que contiene los caracteres que se van a
 * procesar y eliminar los duplicados.
 * 
 * @return La función no tiene un valor de retorno, ya que tiene un tipo de retorno de `vacío`.
 */
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
