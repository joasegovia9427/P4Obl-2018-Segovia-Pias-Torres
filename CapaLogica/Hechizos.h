#ifndef HECHIZOS_H
#define HECHIZOS_H

#include "IteradorHechizos.h"


class Hechizos
{
    private:

        Hechizo * arreTope[MAX_HECHIZOS];
        int tope;

    public:

        Hechizos();
        ~Hechizos();
        void Insertar(Hechizo *);
        bool EsVacia();
        Hechizo Primero();
        int Largo();
        Hechizo * K_esimo(int);
        bool ExisteEsteHechizo(int);
        IteradorHechizos CargarIteradorH();
        void CantidadHechizosByTipo(int &, int &);

    protected:


};

#endif // HECHIZOS_H
