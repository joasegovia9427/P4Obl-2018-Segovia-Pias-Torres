#ifndef STRING_H
#define STRING_H

#include "Constantes.h"

class String
{
private:

    char * cadena;

public:
    String(); // constructor por defecto.

    String(char* s); // constructor com�n

    String(const String &); // constructor de copia

    ~String(); // destructor

    String operator =(const String &); // sobrecarga de asignaci�n

    bool operator == (String); // compara dos strings por igualdad.

    bool operator < (String); // compara dos strings alfab�ticamente

    String operator + (String); // concatenaci�n de strings.

    void scan(); // lee un string desde la entrada est�ndar.

    void print(); // muestra un string en la salida est�ndar

    String getConstanteRegionEspecial();

};

#endif // STRING_H
