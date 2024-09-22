#include "utilidades.h"
#include <math.h>
#include <random>
#include <algorithm>

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
}

void utilidades::mezclarVector(std::vector<int> *lista) {
    std::random_device dispositivo;
    std::default_random_engine generador(dispositivo());
    std::shuffle(lista->begin(), lista->end(), generador);
}