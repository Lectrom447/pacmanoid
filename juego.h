#ifndef JUEGO_H
#define JUEGO_H
#include <vector>

#include "objetoraiz.h"
#include "panelcontroles.h"
#include "canon.h"
#include "fantasma.h"

class Juego {
    private:
        int puntos = 0;
        int fantasmasEliminados = 0;
        ObjetoRaiz objetoRaiz;
        PanelControles *panelControles;
        Canon *canon;
        std::vector<Fantasma*> fantasmas;
    public:
        Juego();
        void ejecutar();
};


#endif





 