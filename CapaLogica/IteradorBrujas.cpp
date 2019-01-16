#include "IteradorBrujas.h"

// =======================================================================
// Constructores
// =======================================================================

// Constructor Por Defecto
IteradorBrujas :: IteradorBrujas()
{
    lista = NULL;
}

// =======================================================================
// Destrutores
// =======================================================================
IteradorBrujas :: ~IteradorBrujas()
{

}
// =======================================================================

// =======================================================================
// Métodos
// =======================================================================

void IteradorBrujas :: Insertar(Bruja * brujaIN)
{
    // Insert Front de Lista
    NodoI * aux = new NodoI;
    aux->info   = brujaIN;
    aux->sig    = lista;//this->lista;
    lista = aux;//this->lista = aux;
}


bool IteradorBrujas :: HayMasObjetos()
{
    return (bool)(lista != NULL);
}

Bruja * IteradorBrujas :: ProximoObjeto()
{
    Bruja * resu = lista->info;
    lista = lista->sig;
    return resu;
}

// =======================================================================
// =======================================================================
