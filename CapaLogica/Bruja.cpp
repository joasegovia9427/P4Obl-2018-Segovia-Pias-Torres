#include "Bruja.h"

// =======================================================================
// Constructores
// =======================================================================

// Constructor Por Defecto
Bruja :: Bruja() : identificador(), nombre(), hechizos() {}

// Constructor Común
Bruja :: Bruja(String id, String nom): identificador(id), nombre(nom), hechizos() {}

// Constructor de Copia
Bruja :: Bruja (const Bruja &otra): identificador(otra.identificador), nombre(otra.nombre), hechizos(otra.hechizos) {}

// Sobrecarga del operador de Asignación


// =======================================================================
// Destrutores
// =======================================================================
Bruja::~Bruja()
{
    //no se hace ningun delete porque no se creo ningun new para algun atributo en sus ctores, fachada, menu, etc
}
// =======================================================================

// =======================================================================
// Métodos
// =======================================================================
String Bruja :: getIdentificador()
{
    return (this->identificador);
}

String Bruja :: getNombre()
{
    return nombre;
}

Hechizos Bruja :: getHechizos()
{
    return hechizos;
    //         Hechizos h;
    //         return h;
}

void Bruja :: setNewHechizo(Hechizo * newH)
{
    hechizos.Insertar(newH);
}


bool Bruja :: TieneAlgunHechizo()
{
    bool tieneAlguno = false;
    if (!hechizos.EsVacia())
    {
        tieneAlguno = true;
    }
    return tieneAlguno;
}

bool Bruja :: TieneEsteHechizo(int idH)
{

    return hechizos.ExisteEsteHechizo(idH);
}

