#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <vector>


namespace utilidades{
    float convertirARadianes(int angulo);
    int restringir(int valor, int minimo, int maximo);
    int numeroAleatorio(int limite);
    void mezclarVector(std::vector<int> *lista);
} // namespace utilidades

#endif