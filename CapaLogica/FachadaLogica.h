#ifndef FACHADALOGICA_H
#define FACHADALOGICA_H

#include "Brujas.h"

class FachadaLogica
{
private:
    Brujas DiccioBrujasDelSistema;

public:

    FachadaLogica();
    void R1_AltaBruSup(Bruja *, bool &);
    void R2_AltaBruCom(String, Comun *, bool &, bool &);
    void R3_ListTodasLasBrujas(IteradorBrujas &, bool &);
    void R4_ListUnaBru(String, Bruja * &, IteradorHechizos &, bool &);
    void R5_ListBrujasSupsMay(IteradorBrujas &, bool &);
    void R6_AltaHechi(String, Hechizo *, bool &, bool &);
    void R7_ListHechi(String, int, Hechizo * &, bool &, bool &);
    void R8_CantHechiComYEspe(String, int &, int &, bool &, bool &);
};

#endif // FACHADALOGICA_H











