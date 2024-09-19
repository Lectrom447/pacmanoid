#include <iostream>
#include <string>
#include <math.h>

#include "graphito.h"
#include "canon.h"
#include "utilidades.h"
#include "configuracion.h"

using namespace graphito;
using namespace std;

Canon::Canon(int x, int y, int size) {
    this->x = x;
    this->y = y;
    this->dibujarX = x;
    this->dibujarY = y;
    this->size = size;
    this->radio = size / 2;
}

void Canon::dibujar() {
    float angRad = utilidades::convertirARadianes(this->angulo);
    int angSuperiorBoca = this->angulo + this->desfaseAnimacionDisparo;
    int angInferiorBoca = this->angulo - this->desfaseAnimacionDisparo;
    this->calcularTrayectoria();

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
    this->iniciarAnimacionDisparo();
    cout << "Disparar" << endl;
}

// Modificadores de estado
void Canon::rotar(int angulo) {
    this->angulo = utilidades::restringir(angulo, 15, 165);
}

void Canon::moverH(int x) {
    this->x = utilidades::restringir(
        x, 
        this->radio + 40, 
        configuracion::ANCHO_DE_VENTANA - this->radio - 40
    );
    this->dibujarX = this->x;
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
    int multiplicadorDistanciaOrigen = (this->radio/25) + 1;

    FormatoRelleno(ER_SOLIDO, CL_BLANCO);
    FormatoBorde(EB_CONTINUO, 1, CL_BLANCO);

    int direccion = this->angulo;
    int origenX = this->x;
    int origenY = this->y;
    float direccionRad = utilidades::convertirARadianes(this->angulo);

    while(true){
        int puntoX = origenX + cos(direccionRad) * (multiplicadorDistanciaOrigen * 25);
        int puntoY = origenY - sin(direccionRad) * (multiplicadorDistanciaOrigen * 25);

        if( puntoY < configuracion::LIMITE_DE_DIBUJO_DE_TRAYECTORIA + this->radioPuntosDeTrayectoria) break;

        if((puntoX + this->radioPuntosDeTrayectoria > 400) || (puntoX - this->radioPuntosDeTrayectoria < 0) ) {
            // int desplazamiento_x = (dot_x < 0 )? (dot_x * -1): (dot_x - 400);
            // float desplazamiento_y = desplazamiento_x  * tan(obtenerRadianes(direccion));
            direccion = 180 - direccion;
            direccionRad = utilidades::convertirARadianes(direccion);
            origenX = puntoX;
            origenY =  puntoY;
            multiplicadorDistanciaOrigen = 0;
            // continue;
        }

        Circulo( puntoX,  puntoY, this->radioPuntosDeTrayectoria);
        multiplicadorDistanciaOrigen ++;

    }
}

