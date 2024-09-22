#ifndef OBJETOUI_H
#define OBJETOUI_H
#include <vector>


class ObjetoUI {
    private:
        bool propagacionFinalizada = false;
        std::vector<ObjetoUI*> hijos;
        void _siguienteTiempo();
    protected:
        void propagarTiempo();
    public:
        virtual void siguienteTiempo();
        void agregarHijo(ObjetoUI *hijo);
        void eliminarHijo(ObjetoUI *hijo);

};




#endif