#include "Suprema.h"

// =======================================================================
// Constructores
// =======================================================================

// Constructor Por Defecto
Suprema::Suprema() : Bruja(), fechaNacimiento(){

    cantPoderes = 0;
}

// Constructor Común
Suprema::Suprema(String identificadorIN, String nombreIN,
                 Fecha fechaNacimientoIN, int cantPoderesIN) :
                     Bruja(identificadorIN, nombreIN), fechaNacimiento(fechaNacimientoIN){
   cantPoderes = cantPoderesIN;
}

// Constructor de Copia
Suprema::Suprema(const Suprema &otra) : Bruja(otra){

    fechaNacimiento = otra.fechaNacimiento;
    cantPoderes = otra.cantPoderes;
}



// =======================================================================
// Desstrutores --
// =======================================================================
Suprema :: ~Suprema(){
    //no se hace ningun delete porque no se creo ningun new para algun atributo en sus ctores, fachada, menu, etc
}
// =======================================================================
// =======================================================================
// Métodos
// =======================================================================

Fecha Suprema :: getFechaNacimiento(){
    return this->fechaNacimiento;
}

int Suprema :: getCantPoderes(){
    return this->cantPoderes;
}


// =======================================================================
// Métodos Polimorficos
// =======================================================================

int Suprema :: CalcularPuntosPoder(){
    int puntos = 0;
    Fecha fecha_ini = Fecha(1,1,1900);
    int cant_pod = this->getHechizos().Largo();

    for(int i = 0; i < cant_pod; i++){

        tiposDeHechizo th;
        th =  this->getHechizos().K_esimo(i)->getTipo();

        if(th == ESPECIAL){

            puntos = puntos + 4;

        }else{

             puntos = puntos + 2;
        }

    }

    puntos = puntos + cantPoderes;

    if(fechaNacimiento < fecha_ini){

         puntos = puntos + 5;

    }


    return puntos;
}

tiposDeBruja Suprema :: getTipo(){

    return SUPREMA;
}


// =======================================================================
// =======================================================================





