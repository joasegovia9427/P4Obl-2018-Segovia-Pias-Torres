#include "Comun.h"

// =======================================================================
// Constructores
// =======================================================================

// Constructor Por Defecto
Comun::Comun() : Bruja(), regionOrigen(), suprema_depende(){

    vuelaEscoba = false;

}

// Constructor Común
Comun::Comun(String _identificador, String _nombre,
             String _regionOrigen, bool _vuelaEscoba ) :
                Bruja(_identificador, _nombre), regionOrigen(_regionOrigen){
    vuelaEscoba = _vuelaEscoba;
}

// Constructor de Copia
Comun::Comun (const Comun &otra): Bruja(otra){

    regionOrigen = otra.regionOrigen;
    vuelaEscoba = otra.vuelaEscoba;
    suprema_depende = otra.suprema_depende;

}



// =======================================================================
// Desstrutores --
Comun :: ~Comun(){
    //no se hace ningun delete porque no se creo ningun new para algun atributo en sus ctores, fachada, menu, etc
}

// =======================================================================

// =======================================================================

// =======================================================================
// Métodos
// =======================================================================

String Comun :: getRegionOrigen(){
    return this->regionOrigen;
}

bool Comun :: getVuelaEscoba(){
    return this->vuelaEscoba;
}

Suprema * Comun :: getSuprema(){
    return suprema_depende;
//    return *this->suprema_depende;
}

void Comun :: setSuprema(Suprema * supremaDepende){
    suprema_depende = supremaDepende;
}



// =======================================================================
// Métodos Polimorficos
// =======================================================================

int Comun :: CalcularPuntosPoder(){
    int puntos = 0;
    String PaisOrigen = "Salem\0";
    Hechizos hs = Hechizos();
    hs = this->getHechizos();
    for(int i = 0; i < hs.Largo(); i++){
        tiposDeHechizo th;
        th =  hs.K_esimo(i)->getTipo();
        if(th == ESPECIAL){
            puntos = puntos + 2;
        }else{
             puntos = puntos + 1;
        }
    }
    if(regionOrigen == PaisOrigen)
         puntos = puntos + 1;

    return puntos;
}

tiposDeBruja Comun :: getTipo(){

    return COMUN;
}



// =======================================================================
// =======================================================================
