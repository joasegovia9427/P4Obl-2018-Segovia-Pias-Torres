#ifndef SUPREMA_H
#define SUPREMA_H

#include "Bruja.h"

class Suprema : public Bruja
{
    private:
        Fecha fechaNacimiento;
        int cantPoderes;

    public:
        // Constructores
        Suprema();
        Suprema(String, String, Fecha, int);
        Suprema(const Suprema &);
        // Destructor
        ~Suprema();
        // Metodos
        Fecha getFechaNacimiento();
        int getCantPoderes();
        // Metodos Polimorficos
        tiposDeBruja getTipo();
        int CalcularPuntosPoder();

    protected:

};

#endif // SUPREMA_H
