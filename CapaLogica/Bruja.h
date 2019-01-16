#ifndef BRUJA_H
#define BRUJA_H

#include "Hechizos.h"

class Bruja
{
private:

    String identificador;
    String nombre;
    Hechizos hechizos;

public:
    // Constructor Por Defecto
    Bruja();
    // Constructor Común
    Bruja(String, String);
    // Constructor de Copia
    Bruja(const Bruja &);
    // Destrutor
    virtual ~Bruja();
    // Métodos
    String getIdentificador();
    String getNombre();
    void setNewHechizo(Hechizo *);
    Hechizos getHechizos();
    bool TieneAlgunHechizo();
    bool TieneEsteHechizo(int);
    // Métodos Polimórficos
    virtual int CalcularPuntosPoder() = 0;
    virtual tiposDeBruja getTipo() = 0;
};

#endif // BRUJA_H
