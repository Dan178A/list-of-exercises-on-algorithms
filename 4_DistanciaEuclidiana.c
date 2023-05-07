/*
Escriba una funcion que reciba las coordenadas de dos puntos del plano, y calcule
su distancia euclıdea. La distancia euclıdea entre dos puntos del plano cartesiano
viene dada por: d(p1,p2) = √(x1 - x2)² + (y1 - y2)²   donde p1 = (x1, y1) y p2 = (x2, y2) 
*/
#include<stdio.h>
#include<math.h>

/**
 * La función calcula la distancia euclidiana entre dos puntos en un espacio bidimensional.
 * 
 * @param x1 La coordenada x del primer punto.
 * @param y1 El parámetro y1 representa la coordenada y del primer punto en la fórmula de la distancia
 * euclidiana.
 * @param x2 El parámetro x2 representa la coordenada x del segundo punto en el plano cartesiano.
 * @param y2 El parámetro y2 representa la coordenada y del segundo punto en un sistema de coordenadas
 * cartesianas bidimensional.
 * 
 * @return la distancia euclidiana entre dos puntos en un espacio bidimensional, dadas sus coordenadas
 * (x1, y1) y (x2, y2).
 */
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