#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <vector>
#include "objetoui.h"
#include "puntotrayectoria.h"

class Proyectil: public ObjetoUI {
    private:
        int x;
        int y;
        int izq;
        int der;
        int aba;
        int arr;
        int dibujarX;
        int dibujarY;
        int visible = true;
        int posicion = 0;
        int color;
        int avanzando = true;
        std::vector<PuntoTrayectoria*> *trayectoria;
        void dibujar();
        void avanzar();
        void calcularLimites();
    public:
        Proyectil(int x, int y, std::vector<PuntoTrayectoria*> *trayectoria);
        void siguienteTiempo();
        bool estaAvanzando();
        int obtenerIzq();
        int obtenerDer();
        int obtenerArr();
        int obtenerAba();
        int obtenerColor();
};
#endif