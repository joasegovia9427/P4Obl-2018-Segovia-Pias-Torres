#include "Brujas.h"


// =======================================================================
// Constructores
// =======================================================================

// Constructor Por Defecto
Brujas :: Brujas()
{
    ABB = NULL;
}


Brujas :: Brujas (const Brujas &otra)
{

    ABB = otra.ABB;
}


// =======================================================================
// Destrutores
// =======================================================================


Brujas :: ~Brujas()
{
    destruirArbol(ABB);
}
// =======================================================================

// =======================================================================
// Métodos
// =======================================================================

bool Brujas :: Member(String identificador)
{

    Bruja * b;
    return  BuscarBruja(ABB,identificador,b);;
}



void Brujas :: Insert(Bruja * brujaIN)
{
    inserta(ABB, brujaIN);
}

void Brujas :: inserta(NodoB * &a, Bruja * brujaIN)
{
    if (a == NULL)
    {
        a = new NodoB;
        a->info = brujaIN;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if ( brujaIN->getIdentificador() < a->info->getIdentificador())
            inserta(a->hizq, brujaIN);
        else
            inserta(a->hder, brujaIN);
    }
}

void Brujas :: GetAllBrujas(IteradorBrujas &ib)
{
    CargarIterador(ABB, ib);
}

void Brujas :: CargarIterador (NodoB * a, IteradorBrujas &iter)
{
    if (a != NULL)
    {
        CargarIterador (a->hder, iter);
        iter.Insertar(a->info);
        CargarIterador (a->hizq, iter);
    }
}

Bruja * Brujas :: Find(String identificador)
{
    Bruja * b;
    BuscarBruja(ABB,identificador,b);
    return b;
}

bool Brujas :: BuscarBruja(NodoB * a, String identificador, Bruja * &bruja)
{
    bool encontre = false;
    while (!encontre && a != NULL)
        if (identificador == a->info->getIdentificador())
        {
            encontre = true;
            bruja = a->info;
        }
        else if (identificador < a->info->getIdentificador())
            a = a->hizq;
        else
            a = a->hder;

    return encontre;
}

Suprema * Brujas :: GetBrujaSupremaMayor()
{
    Bruja * b;
    Fecha f_ini = Fecha();
    BuscarBrujaMayor(ABB,b,f_ini);
    return (Suprema*) b;
}

// debe cargar un iterador
void Brujas :: BuscarBrujaMayor(NodoB * a, Bruja * &bruja, Fecha f_ini)
{
    if(a != NULL)
    {
        if(a->info->getTipo() == SUPREMA)
        {
            Suprema * sup;
            sup = (Suprema *) a->info;
            if( sup->getFechaNacimiento()< f_ini)
            {
                f_ini = sup->getFechaNacimiento();
                bruja = sup;
            }
        }
        BuscarBrujaMayor(a->hder,bruja,f_ini);
        BuscarBrujaMayor(a->hizq,bruja,f_ini);
    }

}

bool Brujas :: HayAlgunaBruja()
{
    bool hay = false;
    if(ABB != NULL)
        hay = true;
    return hay;
}

void Brujas :: destruirArbol (NodoB * &a)
{
    if (a != NULL)
    {
        destruirArbol(a->hizq);
        destruirArbol(a->hder);
//        delete (a->info);
//        delete (a);
//        a = NULL;
    }
}

bool Brujas :: EstaRegistradaEstaBrujaSuprema(String identificador)
{

    bool esSuprema = false;
    bool existe = false;
    existe = Member(identificador);
    Bruja * b;
    b = Find(identificador);

    if((existe == true) && (b->getTipo() == SUPREMA))
    {
        esSuprema = true;
    }

    return esSuprema;
}

bool Brujas :: HayAlgunaBrujaSuprema()
{
    bool encontre = false;
    ExistenSupremas(ABB, encontre);
    return encontre;
}

void Brujas :: ExistenSupremas(NodoB * a, bool &encontre)
{

    if(a != NULL && !encontre)
    {
        if(a->info->getTipo() == SUPREMA)
        {
            encontre = true;
        }
        ExistenSupremas(a->hder,encontre);
        ExistenSupremas(a->hizq,encontre);
    }
}



// =======================================================================
// =======================================================================
