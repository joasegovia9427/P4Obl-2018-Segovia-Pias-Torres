#ifndef BRUJAS_H
#define BRUJAS_H

#include "IteradorBrujas.h"

class Brujas
{
    private:

        struct NodoB{
            Bruja * info;
            NodoB * hizq;
            NodoB * hder;
        };

        NodoB * ABB;

        void inserta(NodoB * &, Bruja * );
        void CargarIterador (NodoB *, IteradorBrujas &);
        bool BuscarBruja(NodoB *, String, Bruja * &);
        void BuscarBrujaMayor(NodoB *, Bruja * &, Fecha);
        void ExistenSupremas(NodoB * a, bool &encontre);
        void destruirArbol (NodoB * &);

    public:
        // Constructor Por Defecto
        Brujas();
        // Constructor de Copia
        Brujas(const Brujas &);
        // Destrutor
        ~Brujas();
        // Métodos
        bool Member(String identificador);
        void Insert(Bruja *);
        Bruja * Find(String);
        bool EstaRegistradaEstaBrujaSuprema(String);
        bool HayAlgunaBrujaSuprema();
        void GetAllBrujas(IteradorBrujas &);
        Suprema * GetBrujaSupremaMayor();
        bool HayAlgunaBruja();


    protected:

};

#endif // BRUJAS_H
