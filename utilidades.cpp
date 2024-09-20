#include "utilidades.h"
#include <math.h>
#include <ctime>
// #include <stdlib.h>
#include <random>

float utilidades::convertirARadianes(int angulo) {
    return angulo * M_PI / 180;
}
    

int utilidades::restringir(int valor, int minimo, int maximo) {
    if(valor <= maximo && valor >= minimo)
        return valor;
    
    if(valor < minimo)
        return minimo;
    
    return maximo;
}

int utilidades::numeroAleatorio(int limite) {
    std::random_device dispositivo;
    std::mt19937 generador(dispositivo());
    std::uniform_int_distribution<> distribucion(0, limite);
    return distribucion(generador);
    // srand(time());
    // return rand() % (limite + 1);
}