#include "Hechizos.h"

Hechizos :: Hechizos()
{
    tope = 0;
    for (int i = 0 ; i < MAX_HECHIZOS ; i++)
    {
        arreTope[i] = NULL;
    }
}



void Hechizos :: Insertar(Hechizo * H)
{
    arreTope[tope] = H;
    tope++;
}

bool Hechizos :: EsVacia()
{

    return (bool) (tope == 0);
}

Hechizo Hechizos :: Primero()
{

    Hechizo * H = arreTope[0];
    return * H;
}

Hechizos::~Hechizos()
{

}


int Hechizos :: Largo()
{

    return tope;
}


Hechizo * Hechizos :: K_esimo(int i)
{

    Hechizo * H = arreTope[i];
    return H;

}


bool Hechizos :: ExisteEsteHechizo(int i)
{

    return (bool) (i < tope);

}


IteradorHechizos Hechizos :: CargarIteradorH()
{
    IteradorHechizos iH = IteradorHechizos();
    for (int i = 0 ; i < tope ; i++)
    {
        iH.Insertar(arreTope[i]);
    }
    return iH;
}

void  Hechizos :: CantidadHechizosByTipo(int &cantHComunes, int &cantHEspeciales)
{
    cantHComunes    = 0;
    cantHEspeciales = 0;
    for (int i = 0 ; i < tope ; i++)
    {
        if (arreTope[i]->getTipo() == HECHIZO)
        {
            cantHComunes++;
        }
        else
        {
            cantHEspeciales++;
        }
    }
}

