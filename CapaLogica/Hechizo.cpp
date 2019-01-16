#include "Hechizo.h"

// Constructor Por Defecto
Hechizo::Hechizo(): nombre()
{
    numero = 0;
}

// Constructor Común
Hechizo::Hechizo(String _nombre)
{
    nombre = _nombre;
}

// Constructor de Copia
Hechizo :: Hechizo (const Hechizo &otro): nombre(otro.nombre)
{

    numero = otro.numero;
}

// Sobrecarga del operador de Asignación
Hechizo Hechizo :: operator = (const Hechizo &otro)
{

    if(this != &otro)
    {

        numero = otro.numero;
        nombre = otro.nombre;

    }

    return (*this);

}

int Hechizo :: getNumero()
{

    return numero;
}

String Hechizo :: getNombre()
{

    return this->nombre;
}

void Hechizo :: setNumero(int id)
{
    numero = id;
}



tiposDeHechizo Hechizo :: getTipo ()
{

    return HECHIZO;

}

Hechizo::~Hechizo()
{
    //no se hace ningun delete porque no se creo ningun new para algun atributo en sus ctores, fachada, menu, etc
}





