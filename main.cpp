#include "graphito.h"
#include "juego.h"
#include "utilidades.h"
#include "configuracion.h"


using namespace graphito;

int main() {
    VDefine(
        configuracion::ANCHO_DE_VENTANA, 
        configuracion::ALTO_DE_VENTANA, 
        "Pacmanoid"
    );
    Juego juego;
    juego.ejecutar();
    return 0;
}