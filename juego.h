#ifndef JUEGO_H
#define JUEGO_H
#include "objetoraiz.h"
#include "panelcontroles.h"
#include "canon.h"

class Juego {
    private:
        // Canon canon;
        // int puntos = 0;
        ObjetoRaiz objetoRaiz;
        PanelControles *panelControles;
        Canon *canon;
    public:
        Juego();
        void ejecutar();
};


#endif





 