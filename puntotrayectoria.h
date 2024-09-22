#ifndef PUNTOTRAYECTORIA_H
#define PUNTOTRAYECTORIA_H
#include "objetoui.h"

class PuntoTrayectoria: public ObjetoUI{
    private:
        int x;
        int y;
        bool visible;
        int angulo;
        int radio = 4;
        int color;
        void dibujar();
    public:
        PuntoTrayectoria(int x, int y, int angulo,int color, bool visible = true);
        void siguienteTiempo();
        int obtenerX();
        int obtenerY();
        int obtenerAngulo();
        int obtenerColor();
        void ocultar();
};

#endif