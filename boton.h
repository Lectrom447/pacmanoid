#ifndef BOTON_H
#define BOTON_H
#include "objetoui.h"
#include "graphito.h"

enum TIPO_BOTON {
    BT_PLANO,
    BT_3D,
    BT_MENU
};

class Boton: public ObjetoUI {
    private:
        int x;
        int y;
        int ancho;
        int alto;
        graphito::COLOR color;
        TIPO_BOTON tipo;
        std::string texto;
        bool visible = true;
        bool presionado = false;
        bool click  = false;
        std::string fuente;
        void dibujar();
        bool mouseEstaSobre();
        void validarPresionado();
    public:
        Boton(int x, int y, int ancho, int alto, TIPO_BOTON tipo, std::string texto, std::string fuente = "Times New Roman");
        void siguienteTiempo();
        bool estaPresionado();
        bool seHizoClick();
};

#endif