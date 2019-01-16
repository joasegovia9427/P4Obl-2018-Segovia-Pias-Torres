#include "menu.h"

void MenuInicial()
{
    int opcion;
    bool isSalir=false;

    FachadaLogica FL;
    FL = FachadaLogica();

    do
    {
        fflush(stdin);
        MenuPrincipal(opcion);
        switch (opcion)
        {
        case 1:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n1- Registrar una nueva bruja suprema en el aquelerre");
            opcion1(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 2:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n2- Registrar una nueva bruja com%sn en el aquelarre",LETRA_u);
            opcion2(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 3:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n3- Listado simple de todas las brujas registradas en el aquelarre");
            opcion3(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 4:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n4- Listado en detalle de una bruja registrada en el aquelarre");
            opcion4(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 5:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n5- Listado en detalle de la mayor(edad) bruja suprema registrada en el aquelerre");
            opcion5(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 6:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n6- Registrar un nuevo hechizo a una bruja registrada en el aquelerre");
            opcion6(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 7:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n7- Listado en detalle de un hechizo correspondiente a una bruja registrada en el aquelerre");
            opcion7(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 8:
        {
            printf("\n***Opci%sn %d***", LETRA_o,opcion);
            printf("\n8- Listado de la cantidad de tipos de hechizos correspondiente a una bruja registrada en el aquelerre");
            opcion8(FL);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        case 0:
        {
            printf("\n***Opci%sn %d - Est%s seguro que desea salir?***", LETRA_o,opcion, LETRA_a);
            isSalir = false;
            OpcionCarga(isSalir);
            if (!isSalir)
            {
                opcion = 99;//opcion=1;
                // system(LIMPIAR);
            }
            else
            {
                system(LIMPIAR);
                opcion=0;
                MensajeSalida();
            }
            // LimpiarYPausa();
        }
        break;
        default:
        {
            system(LIMPIAR);
            printf("\n***Error, reintente con un car%scter v%slido.***", LETRA_a,LETRA_a);
            LimpiarYPausa();
            opcion = 99;
        }
        break;
        }
    }
    while (opcion != 0);
}

void MenuPrincipal(int &opcion)
{
    fflush(stdin);
    printf("\n**********************Men%s de Opciones Principales************************\n\n", LETRA_u);
    printf("Seleccione un n%smero como opci%sn del men%s:\n", LETRA_u, LETRA_o, LETRA_u);
    printf("\n1- Registrar una nueva bruja suprema en el aquelerre");
    printf("\n2- Registrar una nueva bruja com%sn en el aquelarre",LETRA_u);
    printf("\n3- Listado simple de todas las brujas registradas en el aquelarre");
    printf("\n4- Listado en detalle de una bruja registrada en el aquelarre");
    printf("\n5- Listado en detalle de la mayor(edad) bruja suprema registrada en el aquelerre");
    printf("\n6- Registrar un nuevo hechizo a una bruja registrada en el aquelerre");
    printf("\n7- Listado en detalle de un hechizo correspondiente a una bruja registrada en el aquelerre");
    printf("\n8- Listado de la cantidad de tipos de hechizos correspondiente a una bruja registrada en el aquelerre");

    printf("\n\n0- Para terminar el programa");//op0
    printf("\n\nOpci%sn: ", LETRA_o);
    scanf("%d",&opcion);
}

void LimpiarYPausa()
{
    char limpiar;
    fflush(stdin);
    printf("\n\nPresione enter para continuar ");
    scanf("%c",&limpiar);
    system(LIMPIAR);
}

void OpcionCarga(bool &booleanoAcargar)
{
    char opcion;
    do
    {
        fflush(stdin);
        printf("\nIngrese una opci%sn:\nSI: S o 1\nNO: N o 0\n-> ", LETRA_o);
        scanf("%c",&opcion);
        switch (opcion)
        {
        case 's':
            booleanoAcargar=true;
            break;
        case 'S':
            booleanoAcargar=true;
            break;
        case '1':
            booleanoAcargar=true;
            break;
        case '0':
            booleanoAcargar=false;
            break;
        case 'n':
            booleanoAcargar=false;
            break;
        case 'N':
            booleanoAcargar=false;
            break;
        default:
            printf("\nError al leer dato, reintente...");
            break;
        }
    }
    while (opcion != 'S' && opcion != 's' && opcion != '1' && opcion != '0' && opcion != 'N' && opcion != 'n');
}

void opcion1(FachadaLogica &FL)
{
//1) Registrar una nueva bruja suprema que se incorpora al aquelarre.
    bool continuar                      = false;
    bool isFechaValida                  = false;
    String identificadorBrujaSuprema    = String();
    String nombreBrujaSuprema           = String();
    Fecha fechaNacimientoBrujaSuprema   = Fecha();
    int cantPoderesBrujaSuprema         = 0;
    fflush(stdin);
    printf("\nIngrese identificador para la nueva Bruja de tipo Suprema: ");
    identificadorBrujaSuprema.scan();
    fflush(stdin);
    printf("\nIngrese nombre para la nueva Bruja de tipo Suprema: ");
    nombreBrujaSuprema.scan();
    do
    {
        printf("\nIngrese fecha de nacimiento para la nueva Bruja de tipo Suprema: ");
        fechaNacimientoBrujaSuprema.CargarFecha();
        isFechaValida = fechaNacimientoBrujaSuprema.esValida();
        if (!isFechaValida)
            printf("\n***Error, fecha invalida, reintente...");
    }
    while(!isFechaValida);
    continuar = false;
    do
    {
        printf("\nIngrese cantidad (mayor o igual a 0) de poderes para la nueva Bruja de tipo Suprema: ");
        scanf("%d",&cantPoderesBrujaSuprema);
        if (cantPoderesBrujaSuprema < 0)
        {
            printf("\n***Error, cantidad de poderes invalida, reintente...");
            continuar = false;
        }
        else
        {
            continuar = true;
        }
    }
    while(!continuar);

    printf("\n\nDATOS PARA LA NUEVA BRUJA DE TIPO SUPREMA: ");
    printf("\nEl identificador ingresado fue: ");
    identificadorBrujaSuprema.print();
    printf("\nEl nombre ingresado fue: ");
    nombreBrujaSuprema.print();
    printf("\nLa fecha ingresada fue: ");
    fechaNacimientoBrujaSuprema.ImprimirFecha();
    printf("\nLa cantidad de poderes ingresada fue: %d",cantPoderesBrujaSuprema);
    continuar = false;
    printf("\n\nConfirme los datos ingresados para continuar: ");
    OpcionCarga(continuar);
    if (continuar)
    {

        Bruja * nuevaBrujaSuprema = new Suprema(identificadorBrujaSuprema,
                                                nombreBrujaSuprema,
                                                fechaNacimientoBrujaSuprema,
                                                cantPoderesBrujaSuprema);
        ////hayError1 = La bruja (suprema) a ingresar ya existe?
        bool hayError1 = true;
        FL.R1_AltaBruSup(nuevaBrujaSuprema, hayError1);
        if (hayError1)
        {
            printf("\n***Error, esta Bruja Suprema ya esta registrada en el sistema");
            delete(nuevaBrujaSuprema);
        }
        else
        {
            printf("\n\nLa Bruja Suprema se creo correctamente");
        }
    }
    else
    {
        printf("\n***Se cancelo correctamente la carga");
    }
}

void opcion2(FachadaLogica &FL)
{
//2) Dados el identificador de una bruja suprema y los datos de una nueva bruja común que se
//incorpora al aquelarre, registrar la bruja común en el aquelarre, asignándole la suprema
//con dicho identificador.
    bool continuar                      = false;
    bool idsDistintos                   = false;
    String identificadorBrujaComun      = String();
    String nombreBrujaComun             = String();
    String regionOrigenBrujaComun       = String();
    bool vuelaEscobaComun               = false;
    String identificadorBrujaSuprema    = String();

    do
    {
        fflush(stdin);
        printf("\nIngrese identificador de la bruja de tipo Suprema, a la cual la nueva bruja de tipo Com%sn a ingresar, le responde: ",LETRA_u);
        identificadorBrujaSuprema.scan();
        printf("\nIngrese identificador de la nueva bruja de tipo Com%sn a ingresar: ",LETRA_u);
        identificadorBrujaComun.scan();
        idsDistintos = false;
        if (identificadorBrujaSuprema == identificadorBrujaComun)
        {
            idsDistintos = false;
            printf("\n***Error, los identificadores de las brujas deben ser diferentes, reintente...");
        }
        else
        {
            idsDistintos = true;
        }

    }
    while(!idsDistintos);
    fflush(stdin);
    printf("\nIngrese nombre para la nueva bruja Com%sn: ",LETRA_u);
    nombreBrujaComun.scan();
    fflush(stdin);
    printf("\nIngrese nombre de regi%sn de origen para la nueva bruja Com%sn: ",LETRA_o,LETRA_u);
    regionOrigenBrujaComun.scan();
    printf("\nLa nueva bruja Com%sn, vuela en escoba? ",LETRA_u);
    OpcionCarga(vuelaEscobaComun);

    printf("\n\nDATOS PARA LA NUEVA BRUJA DE TIPO COM%sN: ",LETRA_U);
    printf("\nEl identificador de su Suprema a la que le responde ingresado fue: ");
    identificadorBrujaSuprema.print();
    printf("\nEl identificador de la Com%sn ingresado fue: ",LETRA_u);
    identificadorBrujaComun.print();
    printf("\nEl nombre ingresado fue: ");
    nombreBrujaComun.print();
    printf("\nEl nombre de la regi%sn de origen ingresado fue: ",LETRA_o);
    regionOrigenBrujaComun.print();
    printf("\nLa opci%sn de vuelo en escoba ingresado fue: ",LETRA_o);
    if (vuelaEscobaComun)
    {
        printf(" SI vuela en escoba");
    }
    else
    {
        printf(" NO vuela en escoba");
    }
    continuar = false;
    printf("\n\nConfirme los datos ingresados para continuar: ");
    OpcionCarga(continuar);
    if (continuar)
    {
        Bruja * nuevaBrujaComun = new Comun(identificadorBrujaComun,
                                            nombreBrujaComun,
                                            regionOrigenBrujaComun,
                                            vuelaEscobaComun);
        ////hayError1 = La bruja suprema no existe (y es suprema)
        ////hayError2 = La bruja (comun) a ingresar ya existe
        bool hayError1 = true;
        bool hayError2 = true;
        FL.R2_AltaBruCom(identificadorBrujaSuprema,(Comun *)nuevaBrujaComun, hayError1, hayError2);
        if (hayError1)
        {
            printf("\n***Error, la Bruja Suprema seleccionada no esta registrada en el sistema");
        }
        else
        {
            if (hayError2)
            {
                printf("\n***Error, la Bruja Com%sn a ingresar ya esta registrada en el sistema",LETRA_u);
            }
            else
            {
                printf("\n\nLa Bruja Comun se creo correctamente");
            }
        }
    }
    else
    {
        printf("\n***Se cancel%s correctamente la carga",LETRA_o);
    }
}

void opcion3(FachadaLogica FL)
{
//3) Listado simple de todas las brujas registradas en el aquelarre, ordenado alfabéticamente
//por identificador de bruja. De cada bruja se listará su identificador, su nombre y su tipo de
//bruja (común o suprema). Los datos de una misma bruja se listarán en una misma línea.

    IteradorBrujas iB = IteradorBrujas();
////hayError1 = No Hay alguna bruja
    bool hayError1 = true;
    FL.R3_ListTodasLasBrujas(iB, hayError1);
    if (hayError1)
    {
        printf("\n***Error, no hay ninguna bruja registrada en el sistema para mostrar");
    }
    else
    {
        while (iB.HayMasObjetos())
        {
            Bruja * brujaAMostrar = iB.ProximoObjeto();
            printf("\nID Bruja: ");
            brujaAMostrar->getIdentificador().print();
            printf(" || Nombre Bruja: ");
            brujaAMostrar->getNombre().print();
            printf(" || Tipo de Bruja: ");
            if (brujaAMostrar->getTipo() == COMUN)
            {
                printf(" COM%sN",LETRA_U);
            }
            else
            {
                printf(" SUPREMA");
            }
        }
    }
}

void opcion4(FachadaLogica FL)
{
//4) Dado el identificador de una bruja, listar en detalle todos sus datos junto con sus puntos de
//poder. En caso de que sea una bruja común, listar también los datos de la bruja suprema a
//la cual responde junto con los puntos de poder de la suprema.
    String identificadorBrujaAListar = String();
    Bruja * brujaAMostrar;
    IteradorHechizos iH = IteradorHechizos();
    fflush(stdin);
    printf("\nIngrese identificador de la bruja para mostrar sus datos en detalle: ");
    identificadorBrujaAListar.scan();
    ////hayError1 = La bruja no existe
    bool hayError1 = true;
    FL.R4_ListUnaBru(identificadorBrujaAListar, brujaAMostrar, iH, hayError1);
    if (hayError1)
    {
        printf("\n***Error, la bruja seleccionada no esta registrada en el sistema");
    }
    else
    {
        printf("\n------------------------------------------------------\n");
        printf("\nID Bruja: ");
        brujaAMostrar->getIdentificador().print();
        printf("\nNombre Bruja: ");
        brujaAMostrar->getNombre().print();
        printf("\nTipo de Bruja: ");
        if (brujaAMostrar->getTipo() == COMUN)
        {
            printf(" COM%sN",LETRA_U);
            Comun * com = (Comun *)brujaAMostrar;
            printf("\nPuntos de poder: %d", com->CalcularPuntosPoder() );
            printf("\nRegi%sn de origen: ",LETRA_o);
            com->getRegionOrigen().print();
            printf("\nCapacidad de vuelo en escoba: ");
            if (com->getVuelaEscoba())
            {
                printf(" SI vuela en escoba");
            }
            else
            {
                printf(" NO vuela en escoba");
            }
            Suprema * supResponde = (Suprema *)com->getSuprema();
            printf("\n        --------------------------------------------");
            printf("\n              ***Esta bruja com%sn le responde a:***",LETRA_u);
            printf("\n              Tipo de Bruja: SUPREMA");
            printf("\n              ID Bruja suprema: ");
            supResponde->getIdentificador().print();
            printf("\n              Nombre Bruja suprema: ");
            supResponde->getNombre().print();
            printf("\n              Puntos de poder: %d",supResponde->CalcularPuntosPoder() );
            printf("\n              Fecha de nacimiento: ");
            supResponde->getFechaNacimiento().ImprimirFecha();
            printf("\n              Cantidad de poderes: %d",supResponde->getCantPoderes());
            printf("\n        --------------------------------------------");
        }
        else
        {
            printf(" SUPREMA");
            Suprema * sup = (Suprema *)brujaAMostrar;
            printf("\nPuntos de poder: %d",sup->CalcularPuntosPoder() );
            printf("\nFecha de nacimiento: ");
            sup->getFechaNacimiento().ImprimirFecha();
            printf("\nCantidad de poderes: %d",sup->getCantPoderes());
        }
        if (iH.HayMasObjetos())
        {
            printf("\n\n***Lista de sus hechizos:***");
            while (iH.HayMasObjetos())
            {
                Hechizo * hechizoAMostrar = iH.ProximoObjeto();
                printf("\nID Hechizo: %d",hechizoAMostrar->getNumero()+1);
                printf(" || Nombre Hechizo: ");
                hechizoAMostrar->getNombre().print();
                printf(" || Tipo de Hechizo: ");
                if (hechizoAMostrar->getTipo() == HECHIZO)
                {
                    printf(" HECHIZO");
                }
                else
                {
                    printf(" ESPECIAL");
                    Especial * esp = (Especial *)hechizoAMostrar;
                    printf(" || A%so de manifestaci%sn: %d",LETRA_n, LETRA_o, esp->getAnioManifesto() );
                    printf(" || Descripci%sn Hechizo: ",LETRA_o);
                    esp->getDescripcion().print();
                }
            }
        }
        else{printf("\n\n***La bruja no tiene hechizos para mostras");}
        printf("\n\n------------------------------------------------------");
    }
}

void opcion5(FachadaLogica FL)
{
//5) Listar los datos de la mayor bruja suprema registrada en el aquelarre. Es decir, la bruja
//suprema con la fecha de nacimiento más antigua de todas.
    IteradorBrujas iB = IteradorBrujas();
    ////hayError1 = No Hay alguna bruja suprema
    bool hayError1 = true;
    FL.R5_ListBrujasSupsMay(iB, hayError1);
    if (hayError1)
    {
        printf("\n***Error, no hay ninguna bruja suprema registrada en el sistema para mostrar");
    }
    else
    {
        while (iB.HayMasObjetos())
        {
            Suprema * supremaAMostrar = (Suprema * )iB.ProximoObjeto();
            printf("\n------------------------------------------------------\n");
            printf("\nID Bruja suprema: ");
            supremaAMostrar->getIdentificador().print();
            printf("\nNombre Bruja suprema: ");
            supremaAMostrar->getNombre().print();
            printf("\nPuntos de poder: %d",supremaAMostrar->CalcularPuntosPoder());
            printf("\nFecha de nacimiento: ");
            supremaAMostrar->getFechaNacimiento().ImprimirFecha();
            printf("\nCantidad de poderes: %d",supremaAMostrar->getCantPoderes());
            printf("\n\n------------------------------------------------------");
        }
    }
}

void opcion6(FachadaLogica &FL)
{
//6) Dados el identificador de una bruja y los datos de un nuevo hechizo que realiza, registrar el
//nuevo hechizo para dicha bruja. El número del nuevo hechizo deberá ser consecutivo al
//número del último hechizo registrado hasta el momento para dicha bruja.
    bool continuar                      = false;
    String idBrujaACargarHechizoNuevo   = String();
    String nombreNuevoHechizo           = String();
    bool isHEspecial                    = false;
    int anioManifesto                   = 0;
    String descripcionNuevoHechizo      = String();
    fflush(stdin);
    printf("\nIngrese identificador de la bruja para cargarle un hechizo: ");
    idBrujaACargarHechizoNuevo.scan();
    fflush(stdin);
    printf("\nIngrese un nombre para el nuevo hechizo: ");
    nombreNuevoHechizo.scan();
    fflush(stdin);
    printf("\nDesea cargar un hechizo de tipo ESPECIAL (se le pediran 2 datos extras) ?");
    OpcionCarga(isHEspecial);
    if (isHEspecial)
    {
        fflush(stdin);
        printf("\nIngrese a%so en que se manifest%s el hechizo especial: ",LETRA_n,LETRA_o);
        scanf("%d",&anioManifesto);
        fflush(stdin);
        printf("\nIngrese un descripci%sn para el hechizo especial : ",LETRA_o);
        descripcionNuevoHechizo.scan();
    }
    printf("\n\nDATOS PARA EL NUEVO HECHIZO: ");
    printf("\nEl identificador de la abruja a cargarle el nuevo hechizo es: ");
    idBrujaACargarHechizoNuevo.print();
    printf("\nEl nombre ingresado para el nuevo hechizo fue: ");
    nombreNuevoHechizo.print();
    if (isHEspecial)
    {
        printf("\nEl a%so ingresado en que se manifest%s el hechizo especial fue: %d",LETRA_n,LETRA_o,anioManifesto);
        printf("\nLa descripci%sn ingresada para el hechizo especial fue: ",LETRA_o);
        descripcionNuevoHechizo.print();
    }
    continuar = false;
    printf("\n\nConfirme los datos ingresados para continuar: ");
    OpcionCarga(continuar);
    if (continuar)
    {
        Hechizo * nuevoHechizoACargar;
        if (isHEspecial)
        {
            nuevoHechizoACargar = new Especial(nombreNuevoHechizo, anioManifesto, descripcionNuevoHechizo);

        }
        else
        {
            nuevoHechizoACargar = new Hechizo(nombreNuevoHechizo);
        }
        ////hayError1 = La bruja no existe
        ////hayError2 = No Se le puede cargar un hechizo a esta bruja
        bool hayError1 = true;
        bool hayError2 = true;
        FL.R6_AltaHechi(idBrujaACargarHechizoNuevo, nuevoHechizoACargar, hayError1, hayError2);
        if (hayError1)
        {
            printf("\n***Error, la Bruja seleccionada no esta registrada en el sistema");
        }
        else
        {
            if (hayError2)
            {
                printf("\n***Error, no se le pueden agregar nuevos hechizos a la Bruja seleccionada");
            }
            else
            {
                printf("\n\nEl hechizo se agrego correctamente a la bruja seleccionada");
            }
        }
    }
    else
    {
        printf("\n***Se cancel%s correctamente la carga del hechizo",LETRA_o);
    }
}

void opcion7(FachadaLogica FL)
{
//7) Dados el identificador de una bruja y un número de hechizo, listar todos los datos del
//hechizo correspondiente a ese número realizado por dicha bruja.
    String idBrujaABruscarleH   = String();
    int idHechizoABuscarle;
    bool isIdEntre1y20;
    fflush(stdin);
    printf("\nIngrese identificador de la bruja a buscarle un hechizo: ");
    idBrujaABruscarleH.scan();
    do
    {
        fflush(stdin);
        printf("\nIngrese n%smero id del hechizo a buscar para la bruja dada: ",LETRA_u);
        scanf("%d",&idHechizoABuscarle);
        if (idHechizoABuscarle >= 1 && idHechizoABuscarle <= 20)
        {
            isIdEntre1y20 = true;
        }
        else
        {
            isIdEntre1y20 = false;
            printf("\n***Error, n%smero id del hechizo a buscar debe ser entre 1 y 20 (incluyendolos), reintente...",LETRA_u);
        }
    }
    while(!isIdEntre1y20);

    ////hayError1 = La bruja no existe
    ////hayError2 = La bruja no tiene ese hechizo
    bool hayError1 = true;
    bool hayError2 = true;
    Hechizo * hechizoAListar;
    FL.R7_ListHechi(idBrujaABruscarleH,
                    idHechizoABuscarle,
                    hechizoAListar,
                    hayError1,
                    hayError2);
    if (hayError1)
    {
        printf("\n***Error, la Bruja seleccionada no esta registrada en el sistema");
    }
    else
    {
        if (hayError2)
        {
            printf("\n***Error, la Bruja seleccionada no tiene el numero de hechizo seleccionado");
        }
        else
        {
            printf("\n------------------------------------------------------\n");
            printf("\nID Hechizo: %d",hechizoAListar->getNumero()+1);
            printf("\nNombre Hechizo: ");
            hechizoAListar->getNombre().print();
            printf("\nTipo de Hechizo: ");
            if (hechizoAListar->getTipo() == HECHIZO)
            {
                printf(" HECHIZO");
            }
            else
            {
                printf(" ESPECIAL");
                Especial * esp = (Especial *)hechizoAListar;
                printf("\nA%so de manifestaci%sn: %d",LETRA_n, LETRA_o, esp->getAnioManifesto() );
                printf("\nDescripci%sn Hechizo: ",LETRA_o);
                esp->getDescripcion().print();
            }
            printf("\n\n------------------------------------------------------");
        }
    }
}

void opcion8(FachadaLogica FL)
{
//8) Dado el identificador de una bruja, contar cuántos hechizos comunes y cuántos hechizos
//especiales ha realizado dicha bruja.
    String idBrujaCantidades    = String();
    int cantCOMUNES             = 0;
    int cantESPECIALES          = 0;
    fflush(stdin);
    printf("\nIngrese identificador de la bruja a para contar sus tipos de hechizo: ");
    idBrujaCantidades.scan();
    ////hayError1 = La bruja no existe
    ////hayError2 = La bruja no tiene algun hechizo
    bool hayError1 = true;
    bool hayError2 = true;
    FL.R8_CantHechiComYEspe(idBrujaCantidades, cantCOMUNES, cantESPECIALES, hayError1, hayError2);
    if (hayError1)
    {
        printf("\n***Error, la Bruja seleccionada no esta registrada en el sistema");
    }
    else
    {
        if (hayError2)
        {
            printf("\n***Error, la Bruja seleccionada no tiene ningun hechizo cargado");
        }
        else
        {
            printf("\n------------------------------------------------------\n");
            printf("\nCantidad de Hechizo tipo HECHIZO  = %d",cantCOMUNES);
            printf("\n\nCantidad de Hechizo tipo ESPECIAL = %d",cantESPECIALES);
            printf("\n\n------------------------------------------------------");
        }
    }
}

void MensajeSalida()
{
    int i,j;
    logoOut();
    printf("\n*******<<<_______FIN DEL PROGRAMA C.O.V.E.N._______>>>*******");
    printf("\n*******<<<*******************************************>>>*******");
    for (j=176; j<179; j++)
    {
        printf("\n");
        for (i=0; i<80 ; i++ )
            printf("%c",j);
    }
    printf("\n%c",201);
    for (i=0; i<78 ; i++ )
        printf("%c",205);
}

void logo()
{
    printf("\n   _____          ____        __      __       ______         _   _        ");
    printf("\n  / ____|        / __ %c       %c %c    / /      |  ____|       | %c | |       ",92,92,92,92);
    printf("\n | |            | |  | |       %c %c  / /       | |__          |  %c| |       ",92,92,92);
    printf("\n | |            | |  | |        %c %c/ /        |  __|         | . ` |       ",92,92);
    printf("\n | |____    _   | |__| |   _     %c  /     _   | |____    _   | |%c  |   _   ",92,92);
    printf("\n  %c_____|  (_)   %c____/   (_)     %c/     (_)  |______|  (_)  |_| %c_|  (_)  ",92,92,92,92);
    printf("\n                                                                           ");
}

void logoOut()
{


    printf("\n                                                                      ");
    printf("\n               _..--.._       _..--.      _..--..                         ");
    printf("\n             ,'      ,'`.   ,','.--.%c   ,' %c   `.`.         ",92,92);
    printf("\n            /  /    /  /|  : : /  _ %c:  |%c  %c    %c %c       ",92,92,92,92,92);
    printf("\n           /  :    :  /`.  | |:| ,'' _``. %c                                        ",92);
    printf("\n         | ,;,   .  `:%c _:   | `,/_%c.   :`/;'  ,   .:%c )      ",92,92,92);
    printf("\n         `'/'   _ %c   %c:%c(  _|__`>_/`' /(:/   /     .%c`           ",92,92,92,92);
    printf("\n          /:  .'  ,`.._|_%c%c'  ( _=`;._//_|_..'`      %c%c           ",92,92,92,92);
    printf("\n         :: /   '|    (__=`, :`||| `,.__)     %c      :             ",92);
    printf("\n          | %c           %c`.%c%c__%c;|| //`|/       :     |                ",92,92,92,92,92);
    printf("\n          |  `.._____.-,`'| %c%c___||// /`-._           |             ",92,92);
    printf("\n          :         | : ,<''_%c%c,.|//_`>.  :`._       ;:          ",92,92);
    printf("\n          %c         ; ; )`-..______..-'(  :%c  `-.__.' /       ",92,92);
    printf("\n          ;        / /|:                : | `.._____.':           ");
    printf("\n         :      _.' / ||                | |   `.       :          ");
    printf("\n         :  _.-'   /  ::                ; :     `-.____;          ");
    printf("\n          %c;     ,'   ( %c              /  )%c          /           ",92,92,92);
    printf("\n         ,'    ,'____,' ,`-,.______..-') (__%c        _`.      ",92);
    printf("\n        (___..'>_>____`.`.'._)_%c_>._)-' ,'___`._________)         ",92);
    printf("\n                                                                              ");


}
