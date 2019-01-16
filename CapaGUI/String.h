#ifndef STRING_H
#define STRING_H

#include "Constantes.h"

class String
{
private:

    char * cadena;

public:
    String(); // constructor por defecto.

    String(char* s); // constructor común

    String(const String &); // constructor de copia

    ~String(); // destructor

    String operator =(const String &); // sobrecarga de asignación

    bool operator == (String); // compara dos strings por igualdad.

    bool operator < (String); // compara dos strings alfabéticamente

    String operator + (String); // concatenación de strings.

    void scan(); // lee un string desde la entrada estándar.

    void print(); // muestra un string en la salida estándar

    String getConstanteRegionEspecial();

};

#endif // STRING_H
