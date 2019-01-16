#ifndef ESPECIAL_H
#define ESPECIAL_H

#include "Hechizo.h"

class Especial : public Hechizo{

private:
    int anioManifesto;
    String descripcion;

public:
    Especial();
    Especial(String, int, String);
    Especial(const Especial &);
    int getAnioManifesto();
    String getDescripcion();
    tiposDeHechizo getTipo();
    ~Especial();

};

#endif // ESPECIAL_H
