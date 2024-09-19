#ifndef PANLECONTROLES_H
#define PANLECONTROLES_H
#include "objetoui.h"
#include "boton.h"
#include "canon.h"

class PanelControles: public ObjetoUI{
    private:
        int alto;
        int arriba;
        int limiteAbajoVentana;
        Boton *botonMoverIzquierda;
        Boton *botonMoverDerecha;
        Boton *botonRotarIzquierda;
        Boton *botonRotarDerecha;
        Boton *botonDisparar;
        Canon *canon;
        void dibujar();
        void manejarBotones();
    public:
        PanelControles(int alto, Canon *canon);
        void siguienteTiempo();
    };
#endif