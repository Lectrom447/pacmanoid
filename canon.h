#ifndef CANON_H
#define CANON_H
#include "objetoui.h"

class Canon: public ObjetoUI {
    private:
        int x;
        int y;
        int dibujarX;
        int dibujarY;
        int size = 10;
        int angulo = 15;
        int radioPuntosDeTrayectoria = 4;
        int radio;
        bool ejecutandoAnimacionDisparo = false;
        int direccionAnimacionDisparo = 1;
        int desfaseAnimacionDisparo = 0;
        void calcularTrayectoria();
        void dibujar();
        void iniciarAnimacionDisparo();
        void finalizarAnimacionDisparo();
        void animar();
    public:
        Canon(int x, int y, int size);
        void siguienteTiempo();
        void disparar();
        void rotar(int angulo);
        void moverH(int x);

        int obtenerX();
        int obtenerY();
        int obtenerRadio();
        int obtenerAngulo();

};
#endif




