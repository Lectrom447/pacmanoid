#include "puntotrayectoria.h"
#include "graphito.h"

using namespace graphito;

PuntoTrayectoria::PuntoTrayectoria(int x, int y, int color, bool visible) {
    this->x = x;
    this->y = y;
    this->visible = visible;
    this->color = color;
}

void PuntoTrayectoria::dibujar() {
    if(!this->visible) return; 
    FormatoBorde(EB_CONTINUO, 1, CL_BLANCO);
    FormatoRelleno(ER_SOLIDO, CL_BLANCO);

    Circulo(this->x, this->y, this->radio);
}

void PuntoTrayectoria::ocultar() {
    this->visible = false;
}

void PuntoTrayectoria::siguienteTiempo() {
    this->dibujar();
}

int PuntoTrayectoria::obtenerX() {
    return this->x;
}

int PuntoTrayectoria::obtenerY() {
    return this->y;
}


int PuntoTrayectoria::obtenerColor() {
    return this->color;
}