#ifndef FANTASMA_H
#define FANTASMA_H
#include "objetoui.h"
#include "graphito.h"

class Fantasma: public ObjetoUI {
    private:
        int x;
        int y;
        int dibujarX;
        int dibujarY;
        int tamano;
        int esVisible = true;
        int mitadTamano;
        int direccionAnimacion = 1;
        graphito::COLOR color;
        void dibujar();
        void animar();
    public:
        Fantasma(int x, int y, int tamano, graphito::COLOR color);
        void siguienteTiempo();
};

#endif