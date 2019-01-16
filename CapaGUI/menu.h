#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../CapaLogica/FachadaLogica.h"

//Menu inicial
void MenuInicial();

//Despliega y lee la opcion para el menu principal de XX opciones
void MenuPrincipal(int &opcion);

//Seccion mensajes respecto a menu

//Emite mensaje, espera anyKey y limpia la pantalla dependiendo del SO
void LimpiarYPausa();

void OpcionCarga(bool &booleanoAcargar);

void MensajeSalida();

void logo();
void logoOut();

void opcion1(FachadaLogica &);
void opcion2(FachadaLogica &);
void opcion3(FachadaLogica);
void opcion4(FachadaLogica);
void opcion5(FachadaLogica);
void opcion6(FachadaLogica &);
void opcion7(FachadaLogica);
void opcion8(FachadaLogica);

#endif // MENU_H_INCLUDED
