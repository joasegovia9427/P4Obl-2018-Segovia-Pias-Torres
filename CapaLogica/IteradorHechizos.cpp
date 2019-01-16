#include "IteradorHechizos.h"

// Constructor Por Defecto
IteradorHechizos :: IteradorHechizos()
{
    tope = 0;
}



void IteradorHechizos :: Insertar(Hechizo * H)
{
    arreTopeIterator[tope] = H;
    tope++;
}


bool IteradorHechizos :: HayMasObjetos()
{
    return (bool) (tope != 0);
}

IteradorHechizos :: ~IteradorHechizos() {

}

Hechizo * IteradorHechizos :: ProximoObjeto()
{
    Hechizo * H = arreTopeIterator[0];

    for (int i = 0 ; i < tope ; i++)
    {
        arreTopeIterator[i]=arreTopeIterator[i+1];
    }
    tope--;

    return H;

}


