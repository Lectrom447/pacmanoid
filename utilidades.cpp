#include "utilidades.h"
#include <math.h>

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

