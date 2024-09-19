
// #include <iostream>

#include "graphito.h"
#include  "juego.h"
// #include "canon.h"
// #include "boton.h"
// #include "utilidades.h"
#include "configuracion.h"

// using namespace std;
using namespace graphito;

// // Configuraciones
// int GRADOS_POR_PASO_CANON = 1;


// int direccionCanon = 25;


// int main() {
//     VDefine(
//         configuracion::ANCHO_DE_VENTANA, 
//         configuracion::ALTO_DE_VENTANA, 
//         "Pacmanoid"
//     );
//     FormatoBorde(EB_RAYAS, 3, CL_ROJO);
//     Linea(
//         0, 
//         configuracion::LIMITE_DE_DIBUJO_DE_TRAYECTORIA, 
//         configuracion::ANCHO_DE_VENTANA,
//         configuracion::LIMITE_DE_DIBUJO_DE_TRAYECTORIA
//     );

//     FormatoRelleno(ER_SOLIDO, CL_PLATA);
//     FormatoBorde(EB_CONTINUO, 3, CL_PLATA);
//     Rectangulo(0, 710, 400, 770);
//     Boton botonMoverIzquierda(10,720, 40, 40, BT_3D, "<");
//     botonMoverIzquierda.Mostrar();
//     Boton botonMoverDerecha(60,720, 40, 40, BT_3D, ">");
//     botonMoverDerecha.Mostrar();
//     Boton botonRotarIzquierda(110,720, 40, 40, BT_3D, "RI");
//     botonRotarIzquierda.Mostrar();
//     Boton botonRotarDerecha(160,720, 40, 40, BT_3D, "RD");
//     botonRotarDerecha.Mostrar();
//     Boton botonDisparar(210,720, 80, 40, BT_3D, "Pacan!");
//     botonDisparar.Mostrar();

//     // Se crea el cañón
//     Canon canon(200, 650, 50);
//     canon.rotar(direccionCanon);
//     canon.mostrar();

//     int contador = 15;

//     while(true) {
//         if(botonMoverIzquierda.Click()){
//             canon.moverH(utilidades::restringir(
//                 canon.obtenerX() - 5,
//                 canon.obtenerRadio(),
//                 configuracion::ANCHO_DE_VENTANA - canon.obtenerRadio()
//             ));
//             // Se Limpia el tablero
//             FormatoBorde(EB_CONTINUO, 3, CL_NEGRO);
//             FormatoRelleno(ER_SOLIDO, CL_NEGRO);
//             Rectangulo(0, 232, 400, 710);
//             //
//             canon.mostrar();
//             cout << canon.obtenerX() << endl;
//         }
//         if(botonMoverDerecha.Click()){
//             canon.moverH(utilidades::restringir(
//                 canon.obtenerX() + 5,
//                 canon.obtenerRadio(),
//                 configuracion::ANCHO_DE_VENTANA - canon.obtenerRadio()
//             ));
//             // Se Limpia el tablero
//             FormatoBorde(EB_CONTINUO, 3, CL_NEGRO);
//             FormatoRelleno(ER_SOLIDO, CL_NEGRO);
//             Rectangulo(0, 232, 400, 710);
//             //
//             canon.mostrar();
//             cout << canon.obtenerX() << endl;
//         }
//         if(botonRotarIzquierda.Click()){
//             FormatoBorde(EB_CONTINUO, 3, CL_NEGRO);
//             FormatoRelleno(ER_SOLIDO, CL_NEGRO);
//             Rectangulo(0, 232, 400, 710);
//             direccionCanon = utilidades::restringir( 
//                 direccionCanon + GRADOS_POR_PASO_CANON,
//                 15,
//                 165
//             );
//             canon.rotar(direccionCanon);
//             canon.mostrar();
//         }
//         if(botonRotarDerecha.Click()){
//             FormatoBorde(EB_CONTINUO, 3, CL_NEGRO);
//             FormatoRelleno(ER_SOLIDO, CL_NEGRO);
//             Rectangulo(0, 232, 400, 710);
//             direccionCanon = utilidades::restringir( 
//                 direccionCanon - GRADOS_POR_PASO_CANON,
//                 10,
//                 170
//             );
//             canon.rotar(direccionCanon);
//             canon.mostrar();
//         }
        
//         VRefresca();
//     }
//     return 0;
// }

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