#ifndef COMUN_H
#define COMUN_H

#include "Suprema.h"

class Comun : public Bruja
{
    private:
        String regionOrigen;
        bool vuelaEscoba;
        Suprema * suprema_depende;

    public:
        // Constructores
        Comun();
        Comun(String, String, String, bool );//lo tuve que cambiar por como interactua el menu con la fachada
        Comun(const Comun &);
        // Destructor
        ~Comun();
        // Metodos
        String getRegionOrigen();
        bool getVuelaEscoba();
        Suprema * getSuprema();
        void setSuprema(Suprema *);
        // Metodos Polimorficos
        tiposDeBruja getTipo();
        int CalcularPuntosPoder();

    protected:

};

#endif // COMUN_H
