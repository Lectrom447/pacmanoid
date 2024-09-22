#ifndef CANON_H
#define CANON_H
#include <vector>
#include "objetoui.h"
#include "proyectil.h"
#include "puntotrayectoria.h"
#include "fantasma.h"

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
        int* puntos;
        bool ejecutandoAnimacionDisparo = false;
        int direccionAnimacionDisparo = 1;
        int desfaseAnimacionDisparo = 0;
        std::vector<PuntoTrayectoria*> trayectoria;
        std::vector<Fantasma*> *fantasmas;
        Proyectil *proyectil = nullptr;
        void calcularTrayectoria();
        void dibujar();
        void iniciarAnimacionDisparo();
        void finalizarAnimacionDisparo();
        void manejarProyectil();
        void animar();
        void reiniciar();
    public:
        Canon(int x, int y, int size, int* puntos, std::vector<Fantasma*> *fantasmas);
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




