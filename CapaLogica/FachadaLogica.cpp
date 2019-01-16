#include "FachadaLogica.h"

FachadaLogica::FachadaLogica()
{
    Brujas DiccioBrujasDelSistema = Brujas();
}

void FachadaLogica::R1_AltaBruSup(Bruja * nuevaSuprema, bool &hayError1){
//hayError1 = La bruja (suprema) a ingresar ya existe?
    hayError1 = false;
    if (DiccioBrujasDelSistema.Member(nuevaSuprema->getIdentificador()))
        hayError1 = true;
    else
        DiccioBrujasDelSistema.Insert(nuevaSuprema);
}

//precondicion: los id deben ser distintos
void FachadaLogica::R2_AltaBruCom(String idBrujaSuprema, Comun * nuevaComun, bool &hayError1, bool &hayError2){
//hayError1 = La bruja suprema no existe (y es suprema)
//hayError2 = La bruja (comun) a ingresar ya existe
    hayError1 = false;
    hayError2 = false;
    if (!DiccioBrujasDelSistema.EstaRegistradaEstaBrujaSuprema(idBrujaSuprema))
        hayError1 = true;
    else
    {
        if (DiccioBrujasDelSistema.Member(nuevaComun->getIdentificador()))
            hayError2 = true;
        else
        {
            nuevaComun->setSuprema((Suprema *)DiccioBrujasDelSistema.Find(idBrujaSuprema));
            DiccioBrujasDelSistema.Insert(nuevaComun);
        }
    }
}

void FachadaLogica::R3_ListTodasLasBrujas(IteradorBrujas &iB, bool &hayError1){
//hayError1 = No Hay alguna bruja
    hayError1 = false;
    if (!DiccioBrujasDelSistema.HayAlgunaBruja())
        hayError1 = true;
    else
    {
        DiccioBrujasDelSistema.GetAllBrujas(iB);
    }
}

void FachadaLogica::R4_ListUnaBru(String idBrujaAretornar, Bruja * &brujaARetornar, IteradorHechizos &iH, bool &hayError1){
//hayError1 = La bruja no existe
    hayError1 = false;
    if (!DiccioBrujasDelSistema.Member(idBrujaAretornar)   )
    {
        hayError1 = true;
    }
    else
    {
        brujaARetornar = DiccioBrujasDelSistema.Find(idBrujaAretornar);
        bool tieneAlgunHechizo = brujaARetornar->TieneAlgunHechizo();
        if (tieneAlgunHechizo == true)
        {
            iH = IteradorHechizos();
            iH = brujaARetornar->getHechizos().CargarIteradorH();
        }
    }
}

void FachadaLogica::R5_ListBrujasSupsMay(IteradorBrujas &iB, bool &hayError1){
//hayError1 = No Hay alguna bruja suprema
    hayError1 = false;
    if (!DiccioBrujasDelSistema.HayAlgunaBrujaSuprema())
        hayError1 = true;
    else
    {
        iB = IteradorBrujas();
//////        iB = DiccioBrujasDelSistema.GetBrujasMayores();
        iB.Insertar(DiccioBrujasDelSistema.GetBrujaSupremaMayor());
    }
}

void FachadaLogica::R6_AltaHechi(String idBrujaACargarle, Hechizo * hACargarle, bool &hayError1, bool &hayError2){
//hayError1 = La bruja no existe
//hayError2 = No Se le puede cargar un hechizo a esta bruja
    hayError1 = false;
    hayError2 = false;
    if (!DiccioBrujasDelSistema.Member(idBrujaACargarle))
        hayError1 = true;
    else
    {
        if (DiccioBrujasDelSistema.Find(idBrujaACargarle)->getHechizos().Largo() == 20)
            hayError2 = true;
        else
        {
            int nextID = DiccioBrujasDelSistema.Find(idBrujaACargarle)->getHechizos().Largo();
//            nextID++;
            hACargarle->setNumero(nextID);
            DiccioBrujasDelSistema.Find(idBrujaACargarle)->setNewHechizo(hACargarle);
//            DiccioBrujasDelSistema.Find(idBrujaACargarle)->getHechizos().Insertar(hACargarle);
        }
    }
}

void FachadaLogica::R7_ListHechi(String idBrujaABuscarle, int idHechizoEncontradoARetornar, Hechizo * &hARetornar, bool &hayError1, bool &hayError2){
//hayError1 = La bruja no existe
//hayError2 = La bruja no tiene ese hechizo
    hayError1 = false;
    hayError2 = false;
    if (!DiccioBrujasDelSistema.Member(idBrujaABuscarle))
        hayError1 = true;
    else
    {
//        if (!DiccioBrujasDelSistema.Find(idBrujaABuscarle)->getHechizos().ExisteEsteHechizo(idHechizoEncontradoARetornar) )
//
    fflush(stdin);
        if (!DiccioBrujasDelSistema.Find(idBrujaABuscarle)->TieneEsteHechizo(idHechizoEncontradoARetornar-1))

            hayError2 = true;
        else
            hARetornar = DiccioBrujasDelSistema.Find(idBrujaABuscarle)->getHechizos().K_esimo(idHechizoEncontradoARetornar-1);
    }
}

void FachadaLogica::R8_CantHechiComYEspe(String idBrujaAContarle, int &cantHComunes, int &cantHEspeciales, bool &hayError1, bool &hayError2){
//hayError1 = La bruja no existe
//hayError2 = La bruja no tiene algun hechizo
    hayError1 = false;
    hayError2 = false;
    if (!DiccioBrujasDelSistema.Member(idBrujaAContarle))
        hayError1 = true;
    else
    {
        if (  DiccioBrujasDelSistema.Find(idBrujaAContarle)->getHechizos().EsVacia()  )
            hayError2 = true;
        else
            DiccioBrujasDelSistema.Find(idBrujaAContarle)->getHechizos().CantidadHechizosByTipo(cantHComunes, cantHEspeciales);
    }
}
