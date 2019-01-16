#ifndef ITERADORHECHIZOS_H
#define ITERADORHECHIZOS_H

#include "Especial.h"

class IteradorHechizos
{
    private:

        Hechizo * arreTopeIterator[MAX_HECHIZOS];
        int tope;

    public:
        // Constructor Por Defecto
        IteradorHechizos();
        ~IteradorHechizos();
        void Insertar(Hechizo *);
        bool HayMasObjetos();
        Hechizo * ProximoObjeto();
};

#endif // BRUJA_H
