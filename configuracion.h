#ifndef CONFIGURACION_H
#define CONFIGURACION_H
#include "vector"


namespace configuracion{
    const int LIMITE_DE_DIBUJO_DE_TRAYECTORIA = 230;
    const int ANCHO_DE_VENTANA = 400;
    const int ALTO_DE_VENTANA = 800;
    const int VELOCIDAD_ROTACION_CANON = 1;
    const int VELOCIDAD_MOVIMIENTO_CANON = 2;
    const int VELOCIDAD_ANIMACION_DIPARO_CANON = 3;
    extern std::vector<int> PALETA_COLORES;

} // namespace configuracion

#endif