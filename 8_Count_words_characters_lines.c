/*
    Diseñe implemente un programa en C que cuente el numero de caracteres,
    palabras y lıneas de un archivo de texto.
*/
#include <stdio.h>

/**
 * Esta función lee un archivo y cuenta el número de caracteres, palabras y líneas que contiene.
 * 
 * @return La función principal devuelve un valor entero de 0, lo que indica que el programa se ha
 * ejecutado correctamente.
 */
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
