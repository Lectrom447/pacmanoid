#include <math.h>

#include "proyectil.h"
#include "graphito.h"
#include "utilidades.h"

using namespace graphito;

Proyectil::Proyectil(int x, int y, std::vector<PuntoTrayectoria*>* trayectoria) {
    this->x = x;
    this->y = y;
    this->dibujarX = x;
    this->dibujarY = y;
    // this->angulo = angulo;
    this->trayectoria = trayectoria;
    this->color = trayectoria->at(0)->obtenerColor();
    this->calcularLimites();

}

void Proyectil::dibujar() {
    if(!this->visible) return;
    FormatoBorde(EB_CONTINUO, 1, CL_NEGRO);
    FormatoRelleno(ER_SOLIDO, this->color);
    Circulo(this->dibujarX, this->dibujarY, 10);
}

void Proyectil::siguienteTiempo() {
    this->dibujar();
    this->avanzar();
    this->calcularLimites();
}

void Proyectil::avanzar() {
    if(this->posicion == this->trayectoria->size()) {
        this->avanzando = false;
        return;
    };
    PuntoTrayectoria* puntoTrayectoria = this->trayectoria->at(this->posicion);
    this->x = puntoTrayectoria->obtenerX();
    this->dibujarX =  this->x;
    this->y = puntoTrayectoria->obtenerY();
    this->dibujarY = this->y;
    this->color = puntoTrayectoria->obtenerColor();
    puntoTrayectoria->ocultar();
    this->posicion ++;
}

bool Proyectil::estaAvanzando() {
    return this->avanzando;
}

void Proyectil::calcularLimites() {
    this->izq = this->x - 10;
    this->arr = this->y - 10;
    this->der = this->x + 10;
    this->aba = this->y + 10;
}

int Proyectil::obtenerIzq() {
    return this->izq;
}

int Proyectil::obtenerArr() {
    return this->arr;
}

int Proyectil::obtenerDer() {
    return this->der;
}

int Proyectil::obtenerAba() {
    return this->aba;
}

int Proyectil::obtenerColor() {
    return this->color;
}