////UDE, Lic. En Informática, Curso 2018 - Nocturno - Programacion 4 - Tutor: Calvo, Juan
////Integrantes: Pías, Richard - 1.924.591-2 ; Segovia, Joaquín - 4.739.544-4 ; Torres, Mathias - 4.223.291-4

#include "menu.h"

int main()
{
    system(COLOR);
    system(TITULO);

    int i,j;
    logo();

    printf("\n***********************BIENVENIDO A PROGRAMA C.O.V.E.N.*******************");
    printf("\n*******(Comunidad occidental de virtuosas empoderadas y nocturnas)********");

    MenuInicial();

    //closure

    printf("\n%c*****************<<<______About this software______>>>***********************%c",186,186);
    printf("\n%cUDE-TRABAJO OBLIGATORIO PROG4 LIC.INFO.Nocturno2018-Docente: Calvo, Juan     %c",186,186);
    printf("\n%c# proudlyDevelopedBy:                                                        %c",186,186);
    printf("\n%c# Segovia, Joaquin     - 4.739.544-4                                         %c",186,186);
    printf("\n%c# Pias, Richard        - 1.924.591-2                                         %c",186,186);
    printf("\n%c# Torres, Mathias      - 4.223.291-4                                         %c",186,186);
    printf("\n%c*****************************************************************************%c",186,186);
    printf("\n%c",200);
    for (i=0; i<78 ; i++ )
    {
        printf("%c",205);
    }
    for (j=176; j<179; j++)
    {
        printf("\n");
        for (i=0; i<80 ; i++ )
        {
            printf("%c",j);
        }
    }
    LimpiarYPausa();
}
////UDE, Lic. En Informática, Curso 2018 - Nocturno - Programacion 4 - Tutor: Calvo, Juan
////Integrantes: Pías, Richard - 1.924.591-2 ; Segovia, Joaquín - 4.739.544-4 ; Torres, Mathias - 4.223.291-4
