#include "utilidades.h"
#include <math.h>
#include <random>
#include <algorithm>
#include <chrono>

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
    auto tiempoActual = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 generador(tiempoActual);
    std::uniform_int_distribution<int> distribucion(0, limite);
    return distribucion(generador);
}

void utilidades::mezclarVector(std::vector<int> *lista) {
    auto tiempoActual = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 generador(tiempoActual);
    std::shuffle(lista->begin(), lista->end(), generador);
}