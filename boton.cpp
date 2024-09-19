#include "boton.h"
#include "graphito.h"

using namespace graphito;

Boton::Boton(int x, int y, int ancho, int alto, TIPO_BOTON tipo, std::string texto, std::string fuente) {
    this->x = x;
    this->y = y;
    this->ancho = ancho;
    this->alto = alto;
    this->tipo = tipo;
    this->fuente = fuente;
    this->color = CL_PLATA;
    this->texto = texto;
}

void Boton::dibujar() {
    if (!this->visible) return;
    switch (this->tipo){
        case TIPO_BOTON::BT_PLANO:
            FormatoRelleno(ER_SOLIDO, (this->presionado) ? CL_GRIS : this->color);
            FormatoBorde(EB_CONTINUO, 1, CL_NEGRO);
            Rectangulo(this->x, this->y, this->x + this->ancho, this->y + this->alto);
            break;
        case TIPO_BOTON::BT_3D:
            FormatoRelleno(ER_SOLIDO, this->color);
            FormatoBorde(EB_CONTINUO, 0);
            Rectangulo(this->x, this->y, this->x + this->ancho, this->y + this->alto);
            FormatoBorde(EB_CONTINUO, 3, (this->presionado) ? CL_NEGRO : CL_BLANCO);
            Linea(this->x, this->y, this->x + this->ancho, y);
            Linea(this->x, this->y, this->x, this->y + this->alto);
            FormatoBorde(EB_CONTINUO, 3, (this->presionado) ? CL_BLANCO : CL_NEGRO);
            Linea(this->x + this->ancho, this->y, this->x + this->ancho, this->y + this->alto);
            Linea(this->x, this->y + this->alto, this->x + this->ancho, this->y + this->alto);
            break;
        case TIPO_BOTON::BT_MENU:
            FormatoRelleno(ER_SOLIDO, this->color);
            FormatoBorde(EB_CONTINUO, 0, CL_NEGRO);
            Rectangulo(this->x, this->y, this->x + this->ancho, this->y + this->alto);
            break;
    }
    TFormato(this->fuente, 20, 0, FT_NORMAL, CL_NEGRO);
    TJustificar(JT_CENTRO);
    TMostrar(this->x + this->ancho / 2, this->y + this->alto / 2, this->ancho, this->alto, this->texto);
}

bool Boton::mouseEstaSobre() {
    int mouseX,mouseY;
    Raton(mouseX, mouseY);
    return (
        (mouseX>=this->x)&&(mouseX<=(x+this->ancho))&&
        (mouseY>=this->y)&&( mouseY<=(y+this->alto))
    );
}

void Boton::validarPresionado() {
    if(!this->visible) return;
    this->click = false;
    if(!this->mouseEstaSobre()) {
        this->presionado = false;
        return;
    }
    if(RatonBotonIzq()) {
        this->presionado = true;
        return;
    }
    if(this->presionado) {
        this->click = true;
    }
    this->presionado = false;

}

void Boton::siguienteTiempo() {
    this->dibujar();
    this->validarPresionado();
}

bool Boton::estaPresionado() {
    return this->presionado;
}

bool Boton::seHizoClick() {
    return this->click;
}