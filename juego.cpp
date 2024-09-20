#include "juego.h"
#include "canon.h"
#include "fantasma.h"
#include "graphito.h"
#include "configuracion.h"
#include <iostream>
#include <string>


using namespace graphito;
using namespace std;

Juego::Juego() {
    // this->canon = Canon()

    this->objetoRaiz.agregarHijo(new Fantasma(50,80,40));
    this->objetoRaiz.agregarHijo(new Fantasma(110,80,40));
    this->objetoRaiz.agregarHijo(new Fantasma(170,80,40));
    this->objetoRaiz.agregarHijo(new Fantasma(230,80,40));
    this->objetoRaiz.agregarHijo(new Fantasma(290,80,40));
    this->objetoRaiz.agregarHijo(new Fantasma(350,80,40));
    // Segunda
    this->objetoRaiz.agregarHijo(new Fantasma(70,170,40));
    this->objetoRaiz.agregarHijo(new Fantasma(130,170,40));
    this->objetoRaiz.agregarHijo(new Fantasma(190,170,40));
    this->objetoRaiz.agregarHijo(new Fantasma(250,170,40));
    this->objetoRaiz.agregarHijo(new Fantasma(310,170,40));

    this->canon = new Canon(
        configuracion::ANCHO_DE_VENTANA/2,
        configuracion::ALTO_DE_VENTANA * (3.2/4.0),
        50
    );
    this->objetoRaiz.agregarHijo(this->canon);
    this->panelControles = new PanelControles(60, this->canon);
    this->objetoRaiz.agregarHijo(this->panelControles);
}

void Juego::ejecutar() {
    while(true) {
        VLimpia();
        FormatoBorde(EB_RAYAS, 3, CL_ROJO);
        Linea(
            0, 
            configuracion::LIMITE_DE_DIBUJO_DE_TRAYECTORIA, 
            configuracion::ANCHO_DE_VENTANA,
            configuracion::LIMITE_DE_DIBUJO_DE_TRAYECTORIA
        );
        this->objetoRaiz.siguienteTiempo();
        VRefresca();
        Espera(16);
    }
}