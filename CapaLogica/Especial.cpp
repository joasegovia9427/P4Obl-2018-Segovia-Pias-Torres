#include "Especial.h"

Especial::Especial(): Hechizo(), descripcion()
{
    anioManifesto = 0;

} //Constructor por defecto


Especial::Especial(String _nombre, int _anio, String _descripcion): Hechizo(_nombre), descripcion(_descripcion) //constructor comun
{

    anioManifesto = _anio;

}

Especial :: Especial (const Especial &otro): Hechizo(otro)  //constructor de copia
{

    anioManifesto = otro.anioManifesto;
    descripcion = otro.descripcion;
}

int Especial :: getAnioManifesto()
{

    return this->anioManifesto;
}

String Especial :: getDescripcion()
{

    return this->descripcion;
}

tiposDeHechizo Especial :: getTipo ()
{

    return ESPECIAL;
}


Especial :: ~Especial()
{
    //no se hace ningun delete porque no se creo ningun new para algun atributo en sus ctores, fachada, menu, etc
}
