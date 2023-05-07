/* 
Escriba una funcion que nos diga el numero de veces que aparece una subcadena
dentro de una cadena de caracteres. Por ejemplo, dada la cadena aabbababa, la
funcion debe devolver 2 cuando recibe como parametro la cadena aba.
*/

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
