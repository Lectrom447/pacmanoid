#include <iostream>
#include <string>
#include <math.h>

#include "graphito.h"
#include "canon.h"
#include "utilidades.h"
#include "configuracion.h"
#include "proyectil.h"
#include "puntotrayectoria.h"
#include "fantasma.h"

using namespace graphito;
using namespace std;

Canon::Canon(int x, int y, int size, int* puntos, std::vector<Fantasma*> *fantasmas) {
    this->x = x;
    this->y = y;
    this->dibujarX = x;
    this->dibujarY = y;
    this->size = size;
    this->radio = size / 2;
    this->puntos = puntos;
    this->fantasmas = fantasmas;
    utilidades::mezclarVector(&configuracion::PALETA_COLORES);
    this->calcularTrayectoria();
}

void Canon::dibujar() {
    float angRad = utilidades::convertirARadianes(this->angulo);
    int angSuperiorBoca = this->angulo + this->desfaseAnimacionDisparo;
    int angInferiorBoca = this->angulo - this->desfaseAnimacionDisparo;
    // this->calcularTrayectoria();

    FormatoRelleno(ER_SOLIDO, CL_AMARILLO);
    FormatoBorde(EB_CONTINUO, 3, CL_ORO);
    Circulo(this->dibujarX, this->dibujarY, this->radio);
    LineaPolar(this->dibujarX, this->dibujarY, this->radio, angSuperiorBoca);
    LineaPolar(this->dibujarX, this->dibujarY, this->radio, angInferiorBoca);

    // Se dibuja el ojo
    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    FormatoBorde(EB_CONTINUO, 2, CL_NEGRO);
    float ojoAngRad = utilidades::convertirARadianes(angulo + 60);
    Circulo(
        this->dibujarX + cos(ojoAngRad) * (this->radio/2), 
        this->dibujarY - sin(ojoAngRad) * (this->radio/2), 
        4 
    );

    if(!ejecutandoAnimacionDisparo) return;
    Sector(
        this->dibujarX, 
        this->dibujarY, 
        this->radio + 1, 
        angSuperiorBoca+1, 
        angInferiorBoca -1
    );
}

void Canon::animar() {
    if(!this->ejecutandoAnimacionDisparo) return;
    float animacionAngRad = utilidades::convertirARadianes(this->angulo + 180);
    this->dibujarX = this->x + cos(animacionAngRad) * this->desfaseAnimacionDisparo;
    this->dibujarY = this->y - sin(animacionAngRad) * this->desfaseAnimacionDisparo;

    if(this->desfaseAnimacionDisparo <= 0 && this->direccionAnimacionDisparo == -1) {
        this->finalizarAnimacionDisparo();
        return;
    }


    if(this->desfaseAnimacionDisparo >= 20) {
        this->direccionAnimacionDisparo *= -1;
    }

    this->desfaseAnimacionDisparo += configuracion::VELOCIDAD_ANIMACION_DIPARO_CANON * this->direccionAnimacionDisparo;

}

void Canon::siguienteTiempo() {
    this->dibujar();
    this->animar();
    this->manejarProyectil();
}

void Canon::iniciarAnimacionDisparo() {
    if(this->ejecutandoAnimacionDisparo) return;
    this->ejecutandoAnimacionDisparo = true;
}
void Canon::finalizarAnimacionDisparo() {
    if(!this->ejecutandoAnimacionDisparo) return;
    this->ejecutandoAnimacionDisparo = false;
    this->desfaseAnimacionDisparo = 0;
    this->direccionAnimacionDisparo = 1;
}

void Canon::disparar() {
    if(this->proyectil != nullptr) return;
    this->iniciarAnimacionDisparo();
    float proyectilAngrad = utilidades::convertirARadianes(this->angulo);
    this->proyectil = new Proyectil(
        this->x + cos(proyectilAngrad) * this->radio,
        this->y - sin(proyectilAngrad) * this->radio,
        &this->trayectoria
    );
    this->agregarHijo(this->proyectil);
}

// Modificadores de estado
void Canon::rotar(int angulo) {
    this->angulo = utilidades::restringir(angulo, 15, 165);
    this->calcularTrayectoria();
}

void Canon::moverH(int x) {
    this->x = utilidades::restringir(
        x, 
        this->radio + 40, 
        configuracion::ANCHO_DE_VENTANA - this->radio - 40
    );
    this->dibujarX = this->x;
    this->calcularTrayectoria();
}


// Funciones de obtencion
int Canon::obtenerX() {
    return this->x;
}

int Canon::obtenerY() {
    return this->y;
}

int Canon::obtenerAngulo() {
    return this->angulo;
}

int Canon::obtenerRadio() {
    return this->radio;
}

// Funciones Privadas
void Canon::calcularTrayectoria() {

    for (size_t i = 0; i < this->trayectoria.size(); i++) {
        PuntoTrayectoria* puntoTrayectoria = this->trayectoria[i];
        this->eliminarHijo(puntoTrayectoria);
        delete puntoTrayectoria;
    }

    this->trayectoria.clear();
    int multiplicadorDistanciaOrigen = 0;
    int direccion = this->angulo;
    float direccionRad = utilidades::convertirARadianes(this->angulo);
    int origenX = this->x + cos(direccionRad) * (this->radio + 10);
    int origenY = this->y - sin(direccionRad) * (this->radio + 10);

    int colorIndex = 0;

    while(true){
        int color = configuracion::PALETA_COLORES[colorIndex];
        int puntoX = origenX + cos(direccionRad) * (multiplicadorDistanciaOrigen * 15);
        int puntoY = origenY - sin(direccionRad) * (multiplicadorDistanciaOrigen * 15);
        if(
            puntoY < configuracion::LIMITE_DE_DIBUJO_DE_TRAYECTORIA + this->radioPuntosDeTrayectoria && (
                ((puntoY - this->radioPuntosDeTrayectoria) < 0) ||
                ((puntoX - this->radioPuntosDeTrayectoria) < 0) ||
                ((puntoX + this->radioPuntosDeTrayectoria) > configuracion::ANCHO_DE_VENTANA)
            )
        ) break;

        if((puntoX + this->radioPuntosDeTrayectoria > 400) || (puntoX - this->radioPuntosDeTrayectoria < 0) ) {
            direccion = 180 - direccion;
            direccionRad = utilidades::convertirARadianes(direccion);
            origenX = puntoX;
            origenY =  puntoY;
            multiplicadorDistanciaOrigen = 0;
            colorIndex++;

            if(colorIndex >= configuracion::PALETA_COLORES.size()) {
                colorIndex = 0;
            }

        }

        
        PuntoTrayectoria* puntoTrayectoria = new PuntoTrayectoria(
            puntoX, puntoY, color ,(puntoY - this->radioPuntosDeTrayectoria) > configuracion::LIMITE_DE_DIBUJO_DE_TRAYECTORIA
        );
        this->trayectoria.push_back(puntoTrayectoria);
        this->agregarHijo(puntoTrayectoria);
        multiplicadorDistanciaOrigen ++;
    }
}

void Canon::manejarProyectil() {
    if(this->proyectil == nullptr) return;

    if(!this->proyectil->estaAvanzando()) {
        *this->puntos -= 2;
        this->reiniciar();
        return;
    }

    for (size_t i = 0; i < this->fantasmas->size(); i++){
        Fantasma *fantasma = this->fantasmas->at(i);
        if(!fantasma->esVisible()) continue;

        if(
            !((
                (this->proyectil->obtenerDer() <= fantasma->obtenerDer() && this->proyectil->obtenerDer() >= fantasma->obtenerIzq()) ||
                (this->proyectil->obtenerIzq() <= fantasma->obtenerDer() && this->proyectil->obtenerIzq() >= fantasma->obtenerIzq())
            )
            &&
            (
                (this->proyectil->obtenerArr() >= fantasma->obtenerArr() && this->proyectil->obtenerArr() <= fantasma->obtenerAba()) ||
                (this->proyectil->obtenerAba() >= fantasma->obtenerArr() && this->proyectil->obtenerAba() <= fantasma->obtenerAba())
            ))
        ) continue;
        if(fantasma->obtenerColor() != this->proyectil->obtenerColor()) {
            *this->puntos -=2;
            this->reiniciar();
            break;
        }
        fantasma->ocultar();
        *this->puntos += 10;

        this->reiniciar();
        break;
        
    }
    

}

void Canon::reiniciar() {
    this->eliminarHijo(this->proyectil);
    delete this->proyectil;
    this->proyectil = nullptr;

    this->calcularTrayectoria();
    utilidades::mezclarVector(&configuracion::PALETA_COLORES);
}