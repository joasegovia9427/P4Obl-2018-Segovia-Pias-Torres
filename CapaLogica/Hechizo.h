#ifndef HECHIZO_H
#define HECHIZO_H

#include "../CapaGUI/Fecha.h"

class Hechizo
{
private:

    int numero;
    String nombre;
public:

    // Constructor Por Defecto
    Hechizo();
    // Constructor Común
    Hechizo(String);
    // Constructor de Copia
    Hechizo(const Hechizo &);
    // Sobrecarga del operador de Asignación
    Hechizo operator = (const Hechizo &);
    int getNumero();
    String getNombre();
    void setNumero(int);
    virtual tiposDeHechizo getTipo();
    virtual ~Hechizo();

protected:


};

#endif // HECHIZO_H
