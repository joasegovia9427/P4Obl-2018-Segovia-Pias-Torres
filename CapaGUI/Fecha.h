#ifndef FECHA_H
#define FECHA_H

#include "String.h"

class Fecha{

private:
    int dia;
    int mes;
    int anio;

public:
    ////Constructores
    Fecha();
    Fecha(int, int, int);
    Fecha(const Fecha &);

    ////Selectoras
    int getDia();
    int getMes();
    int getAnio();

    ////Sobrecarga de operadores
    bool operator <(Fecha);
    bool operator ==(const Fecha &);

//    // Declare prefix and postfix increment operators.
//   Point& operator++();       // Prefix increment operator.
//    f.operator++();
//    ---------------------
//   Point operator++(int);     // Postfix increment operator.
//f++;
// f2 = ++f;

//   // Declare prefix and postfix decrement operators.
//   Point& operator--();       // Prefix decrement operator.
//   Point operator--(int);     // Postfix decrement operator.

    Fecha operator ++();//PREFIJA: ++r//retorna la fecha correpspondiente al dia siguiente a la fecha dada(mas que dada la del pto)
    Fecha operator ++(int);//POSTFIJA r++//retorna la fecha correpspondiente al dia siguiente a la fecha dada(mas que dada la del pto)

    //https://es.planetcalc.com/410/
    Fecha operator +(int);

    //https://es.planetcalc.com/274/
    int operator -(Fecha);//retonra la cantidad de dias de diferencia entre 2 fechas

    ////Metodos Especificos

    void CargarFecha();
    void ImprimirFecha();
    bool esAnioBisiesto(int);//GREGORIANO//recibe un año y retorna si es biciesto o no
    bool esValida();
    int CompararFechas(Fecha);//Precondición: las fechas tienen que ser validas
    int DiasParaCompletarElMesActual();//Precondición: la fecha tiene que ser valida
    void SumarN(int);//Precondición: la fecha tiene que ser valida
    int CantidadDiasMesByAnio(int, int);//recibe un año y un mes y retorna los dias de ese mes
    int CantidadDiasAnio(int); //recibe un año y retorna la cantidad de dias de ese año

};

#endif // FECHA_H
