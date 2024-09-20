#include "fantasma.h"
#include "graphito.h"
#include "utilidades.h"
#include "configuracion.h"
#include <iostream>

using namespace graphito;
using namespace std;

Fantasma::Fantasma(int x, int y, int tamano) {
    this->x = x;
    this->y = y;
    this->dibujarX = x;
    this->dibujarY = y;
    this->tamano = tamano;
    this->color = color;
    this->mitadTamano = tamano/2;
    this->color = configuracion::PALETA_COLORES[
        utilidades::numeroAleatorio(configuracion::PALETA_COLORES.size() - 1)
    ];
}

void Fantasma::dibujar() {
    if(!this->esVisible) return;
    FormatoRelleno(ER_SOLIDO, this->color);
    FormatoBorde(EB_CONTINUO, 1, this->color);
    Sector(
        this->dibujarX, 
        this->dibujarY - (this->mitadTamano/2), 
        this->mitadTamano, 
        0, 
        180
    );
    int abajoRef = this->dibujarY + (this->mitadTamano/2);
    int izquierdaRef = this->dibujarX - this->mitadTamano;
    Rectangulo(
        izquierdaRef,
        this->dibujarY - (this->mitadTamano/2),
        this->dibujarX + this->mitadTamano + 1,
        abajoRef
    );
    int trianguloAbajoRef = abajoRef + mitadTamano/3;
    int anchoTriangulo = tamano/3;
    PoligonoIrregular({
        {izquierdaRef, abajoRef},
        {izquierdaRef, trianguloAbajoRef},
        {izquierdaRef + anchoTriangulo/2, abajoRef},
    });
    PoligonoIrregular({
        {izquierdaRef + anchoTriangulo/2, abajoRef},
        {izquierdaRef + anchoTriangulo, trianguloAbajoRef},
        {izquierdaRef + (anchoTriangulo/2) + anchoTriangulo, abajoRef},
    });
    PoligonoIrregular({
        {izquierdaRef + (anchoTriangulo/2) + anchoTriangulo, abajoRef},
        {izquierdaRef + anchoTriangulo * 2, trianguloAbajoRef},
        {izquierdaRef + (anchoTriangulo/2) + (anchoTriangulo * 2), abajoRef},
    });
    PoligonoIrregular({
        {izquierdaRef + (anchoTriangulo/2) + (anchoTriangulo * 2), abajoRef},
        {izquierdaRef + this->tamano, trianguloAbajoRef},
        {izquierdaRef + this->tamano, abajoRef},
    });

    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    FormatoBorde(EB_CONTINUO, 1, CL_NEGRO);
    int ojosY = this->y - this->mitadTamano/2;
    Circulo(
        this->dibujarX - (this->mitadTamano/4) -1, 
        ojosY,
        this->mitadTamano/4
    );
    Circulo(
        this->dibujarX + (this->mitadTamano/4) -1, 
        ojosY,
        this->mitadTamano/4
    );
    FormatoRelleno(ER_SOLIDO, CL_BLANCO);
    FormatoBorde(EB_CONTINUO, 1, CL_BLANCO);
    Circulo(
        this->dibujarX - (this->mitadTamano/4) -1, 
        ojosY,
       ( this->mitadTamano/6)
    );
    Circulo(
        this->dibujarX + (this->mitadTamano/4) -1, 
        ojosY,
        this->mitadTamano/6
    );
    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    FormatoBorde(EB_CONTINUO, 1, CL_NEGRO);
    Circulo(
        this->dibujarX - (this->mitadTamano/4) -1, 
        ojosY - (1 - this->mitadTamano/9),
        this->mitadTamano/6
    );
    Circulo(
        this->dibujarX + (this->mitadTamano/4) -1, 
         ojosY - (1 - this->mitadTamano/9),
        this->mitadTamano/6
    );

}

void Fantasma::animar() {

    this->dibujarX+= this->direccionAnimacion;
    if( (this->dibujarX <= (this->x - 3)) || (this->dibujarX >= (this->x + 3))) {
        this->direccionAnimacion *= -1;
    }
}


void Fantasma::siguienteTiempo() {
    this->animar();
    this->dibujar();
}
