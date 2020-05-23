#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"

int initTrabajos(Trabajo* list, int len)
{
    int answer = -1;
	if(list != NULL && len > 0)
	{
		answer = 0;
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return answer;
}

int getEmptyIndexTrabajos(Trabajo* list,int len)
{
	int answer = -1;
	if(list != NULL && len > 0)
	{
		answer = 0;
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				answer = i;
				break;
			}
		}
	}
	return answer;
}

int addTrabajo(Trabajo* list,int len,int index, int* id, int idMoto, Motos* listMotos, int lenMoto, Tipo* listTipo,int lenTipo,Color* listColor,int lenColor, Servicio* listServicio, int lenServicio, Cliente* listCliente, int lenCliente)
{
    int answer = -1;
	Trabajo bufferTrabajos;
	system ("cls");

	printf("*****ALTA DE TRABAJO*****\n");

	if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL && listTipo != NULL && lenTipo>0 && listColor != NULL && lenColor>0)
	{
		if(	printMotos(listMotos,lenMoto,listColor,lenColor,listTipo,lenTipo,listCliente,lenCliente)== 0 &&
            utn_getNumero(&bufferTrabajos.idMoto,"\nIngrese id de la moto: ",
                                                "\nERROR, el dato ingresado no pertenece al ID de una moto activa. Vuelva a intentarlo.\n",0,idMoto,2)==0 &&

            listarServicios(listServicio, lenServicio)== 0 &&
            utn_getNumero(&bufferTrabajos.idServicio,"\nIngrese id del servicio que le quiere realizar a la moto: ",
                                                    "\nERROR, el dato ingresado no pertenece al ID de un servicio. Vuelva a intentarlo.\n",20000,20003,2)== 0 &&

            utn_getNumero(&bufferTrabajos.fecha.dia,"\nIngrese un dia: ",
                                                    "\nERROR, el dato ingresado no es un dia. Vuelva a intentarlo.\n",1,31,2)==0 &&

            utn_getNumero(&bufferTrabajos.fecha.mes,"\nIngrese un mes: ",
                                                    "\nERROR, el dato ingresado no es un mes. Vuelva a intentarlo.\n",1,12,2)==0 &&

            utn_getNumero(&bufferTrabajos.fecha.anio,"\nIngrese un anio: ",
                                                     "\nERROR, el dato ingresado no es un anio. Vuelva a intentarlo.\n",2020,2020,2)==0)
            {
                answer = 0;
                bufferTrabajos.id = *id;
                bufferTrabajos.isEmpty = 0;
                list[index] = bufferTrabajos;
                (*id)++;
            }
	}
	return answer;
}

int trabajoPrint(Trabajo* pElement)
{
	int answer = -1;

	if(pElement != NULL && pElement->isEmpty == 0)
	{
		answer = 0;

		printf ("%3d     %3d      %3d    %02d/%02d/%4d\n\n", pElement->id, pElement->idMoto, pElement->idServicio, pElement->fecha.dia, pElement->fecha.mes, pElement->fecha.anio);
	}
	return answer;
}

/**
* \brief
* \param
* \param
* \return
*
*/
int printTrabajos(Trabajo* list, int length)
{
    int answer = -1;

	if(list != NULL && length > 0)
	{
		answer = 0;
		printf ("\n******Datos Trabajo******\n\n");
        printf ("  ID   ID Moto   ID Servicio    Fecha\n\n");
		for(int i=0;i<length;i++)
		{
			if (list[i].isEmpty != 1)
            {
                trabajoPrint(&list[i]);
            }
		}
	}
	return answer;
}
