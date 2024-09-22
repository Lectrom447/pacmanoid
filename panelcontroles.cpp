#include "panelcontroles.h"
#include "graphito.h"
#include "configuracion.h"
#include "boton.h"


using namespace graphito;
using namespace std;

PanelControles::PanelControles(int alto, Canon *canon) {
    this->alto = alto;
    this->canon = canon;
    this->limiteAbajoVentana = configuracion::ALTO_DE_VENTANA - 30;
    this->arriba = this->limiteAbajoVentana - this->alto;
    this->botonMoverIzquierda = new Boton( 
        10, this->arriba + 10,
        40,40, TIPO_BOTON::BT_3D, "3",  "Webdings"
    );
    this->botonMoverDerecha = new Boton( 
        60, this->arriba + 10,
        40,40, TIPO_BOTON::BT_3D, "4", "Webdings"
    );
    this->botonRotarIzquierda = new Boton( 
        110, this->arriba + 10,
        40,40, TIPO_BOTON::BT_3D, "RI", "Arial"
    );
    this->botonRotarDerecha = new Boton( 
        160, this->arriba + 10,
        40,40, TIPO_BOTON::BT_3D, "RD", "Arial"
    );
    this->botonDisparar = new Boton( 
        210, this->arriba + 10,
        80,40, TIPO_BOTON::BT_3D, "Pacan!", "Arial"
    );

    this->agregarHijo(this->botonMoverIzquierda);
    this->agregarHijo(this->botonMoverDerecha);
    this->agregarHijo(this->botonRotarIzquierda);
    this->agregarHijo(this->botonRotarDerecha);
    this->agregarHijo(this->botonDisparar);
}


void PanelControles::dibujar() {
    FormatoRelleno(ER_SOLIDO, CL_PLATA);
    FormatoBorde(EB_CONTINUO, 1, CL_PLATA);
    Rectangulo(
        0,
        this->limiteAbajoVentana - this->alto,
        configuracion::ANCHO_DE_VENTANA,
        this->limiteAbajoVentana
    );
    FormatoBorde(EB_CONTINUO, 2, CL_NEGRO);
    for (size_t i = 0; i < configuracion::PALETA_COLORES.size(); i++) {
        FormatoRelleno(ER_SOLIDO, configuracion::PALETA_COLORES[i]);
        Circulo(305 + (25 * i), this->arriba + 30, 10 );
    }
}

void PanelControles::manejarBotones() {
    if(this->botonMoverIzquierda->estaPresionado()){
        this->canon->moverH(this->canon->obtenerX() - configuracion::VELOCIDAD_MOVIMIENTO_CANON);
    }
    if(this->botonMoverDerecha->estaPresionado()){
        this->canon->moverH(this->canon->obtenerX() + configuracion::VELOCIDAD_MOVIMIENTO_CANON);
    }
    if(this->botonRotarIzquierda->estaPresionado()){
        this->canon->rotar(this->canon->obtenerAngulo() + configuracion::VELOCIDAD_ROTACION_CANON);
    }
    if(this->botonRotarDerecha->estaPresionado()){
       this->canon->rotar(this->canon->obtenerAngulo() - configuracion::VELOCIDAD_ROTACION_CANON);
    }
    if(this->botonDisparar->seHizoClick()){
       this->canon->disparar();
    }
}

void PanelControles::siguienteTiempo() {
    this->dibujar();
    this->manejarBotones();
}




