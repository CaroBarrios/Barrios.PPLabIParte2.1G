#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"

#define QTY_MOTOS 100
#define QTY_TIPO 4
#define QTY_COLOR 5
#define QTY_SERVICIO 4
#define QTY_TRABAJO 100
#define QTY_CLIENTE 5

#define CANTIDADHARDCODEARMOTOS 5
#define CANTIDADHARDCODEARSERVICIOS 4

int menu(void)
{
    Motos arrayMotos[QTY_MOTOS];

    Tipo arrayTipo[QTY_TIPO]= { {1000, "Enduro"},
                                {1001, "Chopera"},
                                {1002, "Scooter"},
                                {1003, "Ciclomotor"},
                                };

    Color arrayColor[QTY_COLOR] = { {10000,"Gris"},
                                    {10001,"Negro"},
                                    {10002,"Blanco"},
                                    {10003,"Azul"},
                                    {10004,"Rojo"},
                                    };

    Servicio arrayServicio[QTY_SERVICIO]= { {20000,"Limpieza",250},
                                            {20001,"Ajuste",300},
                                            {20002,"Balanceo",17},
                                            {20003,"Cadena",190},
                                            };
    Trabajo arrayTrabajo[QTY_SERVICIO];

    Cliente arrayCliente[QTY_CLIENTE] = { {5000, "Juan", 'm'},
                                          {5001, "Cecilia", 'f'},
                                          {5002, "Gonzalo", 'm'},
                                          {5003, "Tobias", 'm'},
                                          {5004, "Elena", 'f'},
                                        };
	int option;
	int triggerAlta = 0;
	int triggerAltaTrabajo = 0;
	int auxiliaryIndex;
    int idMotos = 0;
    int idTrabajo = 0;
    int auxiliaryId;

    initMotos(arrayMotos,QTY_MOTOS);
	initTrabajos(arrayTrabajo,QTY_TRABAJO);


    hardcodearServicios (arrayServicio,CANTIDADHARDCODEARSERVICIOS);
	hardcodearMotos(arrayMotos,CANTIDADHARDCODEARMOTOS);
    idMotos += CANTIDADHARDCODEARMOTOS;

        do
        {
            if ((utn_getNumero (&option,"\n*****MENU DE OPCIONES*****\n\n"
                                        "1. ALTA MOTO\n"
                                        "2. MODIFICAR MOTO\n"
                                        "3. BAJA MOTO\n"
                                        "4. LISTAR MOTOS\n"
                                        "5. LISTAR TIPOS\n"
                                        "6. LISTAR COLORES\n"
                                        "7. LISTAR SERVICIOS\n"
                                        "8. ALTA TRABAJO\n"
                                        "9. LISTAR TRABAJOS\n"
                                        "10. INFORMES\n"
                                        "11. SALIR\n\n"
                                        "Ingrese una opcion: ",
                                        "Opcion invalida. Vuelva a intentarlo\n\n", 1, 11, 4))==0)
            {
                switch (option)
                {
                case 1:
                    auxiliaryIndex = getEmptyIndexMotos(arrayMotos,QTY_MOTOS);
                    if(auxiliaryIndex >= 0)
                    {
                        if(addMotos(arrayMotos,QTY_MOTOS,auxiliaryIndex,&idMotos,arrayTipo, QTY_TIPO, arrayColor, QTY_COLOR, arrayCliente,QTY_CLIENTE) == 0)
                        {
                            printf("\nSe realizo alta con exito\n\n");
                            triggerAlta = 1;
                        }
                    }
                    else
                    {
                        printf("\nNO HAY MAS LUGAR\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 2:
                    if (triggerAlta)
                    {
                        system ("cls");
                        printf("*****MODIFICACION MOTO*****\n");
                        printMotos(arrayMotos, QTY_MOTOS, arrayColor, QTY_COLOR, arrayTipo, QTY_TIPO, arrayCliente, QTY_CLIENTE);
                        if(utn_getNumero(&auxiliaryId,"\n\nindique el ID de la moto que desea modificar: ",
                                                     "\nID invalido\n\n",0,idMotos,0) == 0)
                        {
                            auxiliaryIndex = findMotoById(arrayMotos,QTY_MOTOS,auxiliaryId,arrayColor,QTY_COLOR,arrayTipo,QTY_TIPO,arrayCliente,QTY_CLIENTE);
                            if( auxiliaryIndex >= 0 &&
                                menuModifyMotos(arrayMotos,QTY_MOTOS,auxiliaryIndex) == 0)
                                {
                                    printf("\nLa modificacion se realizo con exito\n\n");
                                }
                        }
                    }
                    else
                    {
                        printf ("\nNo puede modificar una moto sin haber dado de alta una en la opcion A\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 3:
                    if (triggerAlta)
                    {
                        printMotos(arrayMotos, QTY_MOTOS, arrayColor, QTY_COLOR, arrayTipo, QTY_TIPO, arrayCliente, QTY_CLIENTE);
                        if(utn_getNumero(&auxiliaryId,"\n\nIndicar el ID de la moto que desea eliminar: ",
                                                     "\nID invalido.\n\n",0,idMotos,0) == 0)
                        {
                            auxiliaryId = findMotoById(arrayMotos,QTY_MOTOS,auxiliaryId,arrayColor,QTY_COLOR,arrayTipo,QTY_TIPO,arrayCliente,QTY_CLIENTE);
                            if( auxiliaryId >= 0 &&
                                removeMoto(arrayMotos,QTY_MOTOS,auxiliaryId) == 0)
                            {
                                printf("\nSe elimino con exito\n\n");
                            }
                        }
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 4:
                    if (triggerAlta)
                    {
                        printMotos(arrayMotos, QTY_MOTOS, arrayColor, QTY_COLOR, arrayTipo, QTY_TIPO, arrayCliente, QTY_CLIENTE);
                    }
                    else
                    {
                        printf ("\nNo puede listar motos sin haber dado de alta una en la opcion A\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 5:
                    if (triggerAlta)
                    {
                        listarTipos (arrayTipo,QTY_TIPO);
                    }
                    else
                    {
                        printf ("\nNo puede ingresar a esta opcion sin haber dado de alta una moto en la opcion A\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 6:
                    if (triggerAlta)
                    {
                        listarColores (arrayColor,QTY_COLOR);
                    }
                    else
                    {
                        printf ("\nNo puede ingresar a esta opcion sin haber dado de alta una moto en la opcion 1\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 7:
                    if (triggerAlta)
                    {
                        listarServicios(arrayServicio,QTY_SERVICIO);
                    }
                    else
                    {
                        printf ("\nNo puede ingresar a esta opcion sin haber dado de alta una moto en la opcion 1\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 8:
                    auxiliaryIndex = getEmptyIndexTrabajos(arrayTrabajo,QTY_TRABAJO);
                    if(auxiliaryIndex >= 0)
                    {
                        if(addTrabajo(arrayTrabajo,QTY_TRABAJO,auxiliaryIndex,&idTrabajo,idMotos, arrayMotos,QTY_MOTOS,arrayTipo,QTY_TIPO,arrayColor,QTY_COLOR,arrayServicio,QTY_SERVICIO,arrayCliente,QTY_CLIENTE) == 0)
                        {
                            printf("\nSe realizo alta con exito\n\n");
                            triggerAltaTrabajo = 1;
                        }
                    }
                    else
                    {
                        printf("\nNO HAY MAS LUGAR\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 9:
                    if (triggerAltaTrabajo)
                    {
                        printTrabajos(arrayTrabajo,QTY_TRABAJO);
                    }
                    else
                    {
                        printf ("\nNo puede ingresar a esta opcion sin haber dado de alta un trabajo en la opcion 8\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                case 10:
                    if (triggerAlta)
                    {
                        menuInformes(arrayMotos,QTY_MOTOS,arrayColor,QTY_COLOR,arrayTipo,QTY_TIPO,arrayCliente,QTY_CLIENTE);
                    }
                    else
                    {
                        printf ("\nNo puede ingresar a esta opcion sin haber dado de alta una moto en la opcion 1\n\n");
                    }
                    system ("pause");
                    system ("cls");
                    break;
                }
            }
        }while (option!=11);

        return EXIT_SUCCESS;
}
