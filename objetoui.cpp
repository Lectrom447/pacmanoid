#include "objetoui.h"


void ObjetoUI::propagarTiempo() {
    for (size_t i = 0; i < this->hijos.size(); i++) {
        hijos[i]->_siguienteTiempo();
    }
}

void ObjetoUI::_siguienteTiempo() {
    this->siguienteTiempo();
    this->propagarTiempo();

}

void ObjetoUI::siguienteTiempo() {

}

void ObjetoUI::agregarHijo(ObjetoUI *hijo) {
    this->hijos.push_back(hijo);
}
