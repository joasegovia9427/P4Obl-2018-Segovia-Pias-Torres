#include "Fecha.h"

//    ////Constructores
Fecha :: Fecha()
{
    time_t tiempo = time(NULL);
    struct tm *tlocal = localtime(&tiempo);
//    (*this).dia  = tlocal->tm_mday;
    dia = tlocal->tm_mday;
    mes  = tlocal->tm_mon+1;
    anio = 1900+tlocal->tm_year;
}

Fecha :: Fecha(int inDia, int inMes, int inAnio)
{
    dia  = inDia;
    mes  = inMes;
    anio = inAnio;
}

Fecha :: Fecha(const Fecha &f)
{
    dia  = f.dia;
    mes  = f.mes;
    anio = f.anio;
}

//    ////Selectoras
int Fecha :: getDia()
{
    return dia;
}

int Fecha :: getMes()
{
    return mes;
}

int Fecha :: getAnio()
{
    return anio;
}

//    ////Sobrecarga de operadores
bool Fecha :: operator <(Fecha fecha2)
{
    bool isMenor = false;
    int val;
    val = CompararFechas(fecha2);
    if (val == -1)
    {
        isMenor = true;
    }
    return isMenor;
}

bool Fecha :: operator ==(const Fecha &fecha2)
{
    bool isIgual = false;
    if (this == &fecha2) // si apuntan a lo mismo son iguales
    {
        isIgual = true;
    }
    else{
        int val;
        val = CompararFechas(fecha2);
        if (val == 0)
        {
            isIgual = true;
        }
    }
    return isIgual;
}

Fecha Fecha :: operator ++()
{
    SumarN(1);
    return (*this);

}//PREFIJA: ++r//retorna la fecha correpspondiente al dia siguiente a la fecha dada(mas que dada la del pto)

Fecha Fecha :: operator ++(int inNum)
{
    Fecha aux (*this);
    SumarN(1);
    return aux;
}//POSTFIJA r++//retorna la fecha correpspondiente al dia siguiente a la fecha dada(mas que dada la del pto)

Fecha Fecha :: operator +(int inNum)
{
    SumarN(inNum);
    return (*this);
}





int Fecha :: operator -(Fecha fecha2)//arreglar, mejorar
{
////    //falso intento para diferencia si algun año es antes de cristo
//////    if (anio < 0)
//////        anio--;
//////    if (fecha2.anio < 0)
//////        fecha2.anio--;

    int outCantidadDiasTotales = 0, diferenciaAnios = 0, diferenciaMeses = 0, diferenciaDias = 0;
    int i = 0, anioMayor = 0, anioMenor = 0;
    Fecha fechaMenor, fechaMayor;
//    función comparaFecha, devuelve:
//     -1 si fecha1 < fecha2
//      0 si fecha1 = fecha2
//      1 si fecha1 > fecha2
    if (CompararFechas(fecha2) != 0) // 0 si fecha1 = fecha2
    {
       //si no son fechas iguales entonces continuo
        if (CompararFechas(fecha2) == 1) //1 si fecha1 > fecha2
        {
            anioMayor = anio;
            anioMenor = fecha2.anio;
            fechaMayor  = (*this);
            fechaMenor  = fecha2;
        }
        else //-1 si fecha1 < fecha2
        {
            anioMenor = anio;
            anioMayor = fecha2.anio;
            fechaMenor  = (*this);
            fechaMayor  = fecha2;
        }
        ////AÑOS (en caso que la diferencia sea mayor o igual a 2 años)
        diferenciaAnios = fecha2.anio - anio;
        if (diferenciaAnios < 0)
            diferenciaAnios = diferenciaAnios * (-1);
        if ( diferenciaAnios >= 2 )
        {
            for (i = anioMenor+1; i < anioMayor; i++)
            {
                outCantidadDiasTotales = outCantidadDiasTotales + CantidadDiasAnio(i);
            }
        }
        //si la diferencia no es mayor o igual a 2 no se suman cantidad de dias por años en si...
        //se valuara a continuacion los meses si hay diferencia y analogamente para dias


        ////MECES y DIAS
        if ( diferenciaAnios != 0)//entonces significa que el año no es el mismo, tiene 1 o mas años de diferencia
        //por ende contare desde la fecha menor hasta el 31 de diciembre
        // y contare desde el 1 de enero hasta la fecha mayor
        //los dias entre estos 2 años se contemplan con la seccion anterior donde si la diferencia es 2 o mas se calcula y se suman
        {
            ////año menor
            outCantidadDiasTotales = outCantidadDiasTotales + fechaMenor.DiasParaCompletarElMesActual();
            for (i = fechaMenor.mes+1; i <= 12 ; i++)
            {
                outCantidadDiasTotales = outCantidadDiasTotales + CantidadDiasMesByAnio(fechaMenor.anio, i);
            }
            ////AÑO MAYOR
            outCantidadDiasTotales = outCantidadDiasTotales + fechaMayor.dia;
            for (i = 1; i < fechaMayor.mes; i++)
            {
                outCantidadDiasTotales = outCantidadDiasTotales + CantidadDiasMesByAnio(fechaMayor.anio, i);
            }
        }
        else //significa que es 0 entonces las 2 fechas estan en el mismo año
            //por ende tengo que validar lo mismo como si fueran años pero para los mese... fijarme cortes y diferencias
        {
            diferenciaMeses = mes - fecha2.mes;
            if (diferenciaMeses < 0)
                diferenciaMeses = diferenciaMeses * (-1);
            if (diferenciaMeses == 0)//entonces significa que son el mismo mes por lo que solo acumulo la diferencia de dais
            {
                diferenciaDias = dia - fecha2.dia;
                if (diferenciaDias < 0)
                    diferenciaDias = diferenciaDias * (-1);
                outCantidadDiasTotales = outCantidadDiasTotales + diferenciaDias;
            }
            else//sino, significa que hay una diferencia de meses
            {
                if ( diferenciaMeses >= 2 )//si la dif es mayor o igual a 2, entonces significa que contare los dias de los meses entre los de las 2 fechas
                {
                    //repito: este conteo solo se hace cuando la diferencia de de 2 o mas meses, los dias se sumaran luego cortando hasta fin de mes y los dias de la segunda fecha
                    for (i=fechaMenor.mes+1; i<fechaMayor.mes ; i++)
                    {
                        //es el mismo año
                        outCantidadDiasTotales = outCantidadDiasTotales + CantidadDiasMesByAnio(fechaMayor.anio, i);
                    }
                }
                outCantidadDiasTotales = outCantidadDiasTotales + fechaMenor.DiasParaCompletarElMesActual();
                outCantidadDiasTotales = outCantidadDiasTotales + fechaMayor.dia;
            }
        }
    }//sino, si son iguales retorno el 0 que inicialice
    return outCantidadDiasTotales;
}//retonra la cantidad de dias de diferencia entre 2 fechas

/////////////////////////Metodos Especificos/////////////////////////////////////////////////

void Fecha :: CargarFecha()
{
    printf("\nIngrese d%sa: ", LETRA_i);
    scanf("%d",&dia);
    printf("\nIngrese mes: ");
    scanf("%d",&mes);
    printf("\nIngrese a%so: ", LETRA_n);
    scanf("%d",&anio);
}

void Fecha :: ImprimirFecha()
{
    printf("%d/%d/%d",dia,mes,anio);
}

//recibe un año y retorna si es biciesto o no
bool Fecha :: esAnioBisiesto(int inAnio){
    bool esAnioBiciesto = false;
    if (inAnio%4 == 0) // es divisible entre 4
    {
        if (inAnio%100 != 0) // es entre 4 y NO es divisible entre 100
        {
            esAnioBiciesto = true;
        }
        else{ // es entre 4 y SI es divisible entre 100
            if (inAnio%400 == 0) // es entre 4, es entre 100 y SI es divisible entre 400
            {
                esAnioBiciesto = true;
            }
        }
    }
   return esAnioBiciesto;
}
//////Años bisiestos: 1600, 1604, 1608, 1612, 1616...1684, 1688, 1692, 1696, 1704 (1700 no, ¿ves por qué?), 1708, 1712...1792, 1796, 1804 (1800 no), 1808, 1812...1892, 1896, 1904 (1900 no), 1908, 1912...1992, 1996, 2000 (existe el 2000, ¿ves por qué?), 2004, 2008, 2012...2092, 2096, 2104 (2100 no)...2196, 2204...2296, 2304...2396, 2400 (¿ves por qué?), 2404...etc.

bool Fecha :: esValida()
{
    bool esValida = false;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dia>=1 && dia<=31)
            esValida = true;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia>=1 && dia<=30)
            esValida = true;
        break;
    case 2:
        if (esAnioBisiesto(anio))
        {
            if (dia>=1 && dia<=29)
                esValida = true;
        }
        else //no es año bisiesto
        {
            if (dia>=1 && dia<=28)
                esValida = true;
        }
        break;
    }
    return esValida;
}

//Precondición: las dos fechas tienen que ser validas
int Fecha :: CompararFechas(Fecha fecha2)
{
    /**
    función comparaFecha, devuelve:
     -1 si fecha1 < fecha2
      0 si fecha1 = fecha2 //bien
      1 si fecha1 > fecha2 //bien
    **/
    int val;
    if ( anio < fecha2.anio )
        val = -1;
    else if ( anio > fecha2.anio )
        val = 1;
    else   // año igual
    {
        if ( mes < fecha2.mes )
            val = -1;
        else if ( mes > fecha2.mes )
            val = 1;
        else   // mes igual
        {
            if ( dia < fecha2.dia )
                val = -1;
            else if ( dia > fecha2.dia )
                val = 1;
            else // dia igual
                val = 0;
        }
    }
    return val;
}

//Precondición: la fecha tiene que ser valida
//calcula en base al mes y al año(bisiesto o no), la cantidad de dias que falta para sumarle 1 mes a la fecha
int Fecha :: DiasParaCompletarElMesActual(){
    int outCantidadDiasTotales = 0;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        outCantidadDiasTotales = 31 - dia;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        outCantidadDiasTotales = 30 - dia;
        break;
    case 2:
        if (esAnioBisiesto(anio))
        {
            outCantidadDiasTotales = 29 - dia;
        }
        else //no es año bisiesto
        {
            outCantidadDiasTotales = 28 - dia;
        }
        break;
    }
    return outCantidadDiasTotales;
}

//Precondición: la fecha tiene que ser valida y el valor mayor o igual a 0
//buscar en internet esta mal, hay que iterar por si ingresa suma de 60 dias
void Fecha :: SumarN(int inInt){
    if (inInt > 0)
    {
        int diasASumarAcumulados    = inInt;
        int diasParaSaltoDelMes     = DiasParaCompletarElMesActual();;
        while (diasASumarAcumulados > 0 )
        {
            diasParaSaltoDelMes = DiasParaCompletarElMesActual();
            if (diasASumarAcumulados <= diasParaSaltoDelMes) //si la cantidad que se quiere agregar es menor o igual a los que se pueden agregar sin tener que cambiar el mes, entonces
            {
                dia = dia + diasASumarAcumulados;
                diasASumarAcumulados = 0;
            }
            else //sino, o sea es mayor a los disponibles, entonces significa que voy a tener que modificar el acumulado y saltar de mes
            {
                dia                     = 1;
                diasASumarAcumulados    = diasASumarAcumulados - diasParaSaltoDelMes - 1;
                if (mes == 12) //si el mes es diciembre cambio de año y el mes lo dejo en enero
                {
                    mes = 1;
                    anio++;
                }
                else //sino simplemente salto de mes, el año se mantiene
                {
                    mes++;
                }
            }
        }

    }
    else
    {
        int diasARestarAcumulados       = 0 - inInt;
        int cantidadDiasMesActualByAnio = CantidadDiasMesByAnio(anio, mes);
        while (diasARestarAcumulados > 0)
        {
            if (diasARestarAcumulados < dia)
            {
                dia = dia - diasARestarAcumulados;
                diasARestarAcumulados = 0;
            }
            else
            {
                if (mes == 1)
                {
                    mes = 12;
                    anio--;
                }
                else
                {
                    mes--;
                }
                diasARestarAcumulados = diasARestarAcumulados - dia;
                cantidadDiasMesActualByAnio = CantidadDiasMesByAnio(anio, mes);
                if (diasARestarAcumulados < cantidadDiasMesActualByAnio)
                {
                    dia = cantidadDiasMesActualByAnio - diasARestarAcumulados;
                    diasARestarAcumulados = 0;
                }
                else
                {
                    dia = 1;
                    diasARestarAcumulados = diasARestarAcumulados - (cantidadDiasMesActualByAnio-1);
                }
            }
        }
        if (anio <= 0)
        {
            anio--;
        }
    }
}

//recibe un año y un mes y retorna los dias de ese mes
int Fecha :: CantidadDiasMesByAnio(int inAnio, int inMes){
    int outCantidadDiasTotales = 0;
    switch (inMes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        outCantidadDiasTotales = outCantidadDiasTotales + 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        outCantidadDiasTotales = outCantidadDiasTotales + 30;
        break;
    case 2:
        if (esAnioBisiesto(inAnio))
        {
            outCantidadDiasTotales = outCantidadDiasTotales + 29;
        }
        else //no es año bisiesto
        {
            outCantidadDiasTotales = outCantidadDiasTotales + 28;
        }
        break;
    }
    return outCantidadDiasTotales;
}

//recibe un año y retorna la cantidad de dias de ese año
int Fecha :: CantidadDiasAnio(int inAnio){
    int outCantidadDiasTotales = 0;
    if (esAnioBisiesto(inAnio))
    {
        outCantidadDiasTotales = 366;
    }
    else //no es año bisiesto
    {
        outCantidadDiasTotales = 365;
    }
    return outCantidadDiasTotales;


//    //meses: 1 3 5 7 8 10 12
//    outCantidadDiasTotales = (outCantidadDiasTotales + 31)*7;
//    //meses: 4 6 9 11
//    outCantidadDiasTotales = (outCantidadDiasTotales + 30)*4;
//    //mes 2:
//    if (esAnioBisiesto(inAnio))
//    {
//        outCantidadDiasTotales = outCantidadDiasTotales + 29;
//    }
//    else //no es año bisiesto
//    {
//        outCantidadDiasTotales = outCantidadDiasTotales + 28;
//    }
}


