#ifndef ITERADORBRUJAS_H
#define ITERADORBRUJAS_H

#include "Comun.h"


class IteradorBrujas
{
    private:
        struct NodoI {
            Bruja * info;
            NodoI * sig;
        };

        NodoI * lista;
    public:
        // Constructor Por Defecto
        IteradorBrujas();
        // Destrutor
        ~IteradorBrujas();
        // M�todos
        void Insertar(Bruja *);
        bool HayMasObjetos();
        Bruja * ProximoObjeto();
};

#endif // BRUJA_H

