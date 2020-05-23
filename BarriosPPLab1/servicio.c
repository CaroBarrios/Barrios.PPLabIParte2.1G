#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "servicio.h"
#include "datawarehouseServicios.h"

int listarServicios (Servicio* list, int len)
{
    int respuesta=-1;
    system("cls");
    printf("******Listar Servicios******\n");
    printf(" ID                  Descripcion     Precio\n\n");

    for(int i=0;i<len;i++)
    {
        printf("%5d    %25s   %3d\n\n", list[i].id, list[i].descripcion, list[i].precio);
        respuesta=0;
    }
    return respuesta;
}

void hardcodearServicios (Servicio* list, int cantidad)
{
	for (int i=0;i<cantidad;i++)
	{
		list[i].id=idServicio[i];
		strncpy (list[i].descripcion, descripcion[i],DESCRIPCIONSERVICIO_LEN);
		list[i].precio=precio[i];
	}
}
