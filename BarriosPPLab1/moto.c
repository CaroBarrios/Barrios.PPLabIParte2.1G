#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "moto.h"
#include "datawarehouse.h"


/**
* \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Motos* Pointer to array of motos
* \param len int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initMotos(Motos* list, int len)
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

/**
 * \brief Find fist empty position in the array
 * \param list Motos* Pointer to array of motos
 * \param len int Array length
 * \return Returns the index of the position empty and -1 in case of error
 *
 */
int getEmptyIndexMotos(Motos* list,int len)
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

/**
* \brief
* \param
* \param
* \param
* \param
* \return
*
*/
int addMotos(Motos* list,int len,int index,int* id, Tipo* listTipo,int lenTipo,Color* listColor,int lenColor, Cliente* listCliente, int lenCliente)
{
    int answer = -1;
	Motos bufferMotos;
	system ("cls");

	printf("*****ALTA DE MOTO*****\n");

	if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL && listTipo != NULL && lenTipo>0 && listColor != NULL && lenColor>0)
	{
		if(	utn_getString(bufferMotos.marca,MARCA_LEN,"\nIngrese la marca de la moto: ",
                                                       "\nERROR, el dato ingresado es invalido. Solo puede ingresar letras con un maximo de 20 letras consecutivas sin espacios, numeros ni caracteres especiales.\n",2) == 0 &&

            listarTipos (listTipo,lenTipo) == 0 &&
            utn_getNumero(&bufferMotos.idTipo,"\nIngrese id del tipo de moto: ",
                                                "\nERROR, el dato ingresado no es un ID Tipo. Solo puede ingresar un numero entero entre 1000 y 10003. Vuelva a intentarlo.\n",1000,10003,2)==0 &&

            listarColores(listColor, lenColor) == 0 &&
            utn_getNumero(&bufferMotos.idColor,"\nIngrese id del color que quiere de la moto: ",
                                                "\nERROR, el dato ingresado no es un ID Color. Solo puede ingresar un numero entero entre 10000 y 10004. Vuelva a intentarlo.\n",10000,10004,2)==0 &&

            utn_getNumero(&bufferMotos.cilindrada,"\n*****Cilindradas*****"
                                                 "\n1 - 50\n"
                                                 "\n2 - 125\n"
                                                 "\n3 - 500\n"
                                                 "\n4 - 600\n"
                                                 "\n5 - 750\n"
                                                 "\nIngrese la opcion de la cilindrada de la moto: ",
                                                 "\nERROR, el dato ingresado es invalido. Solo puede ingresar un numero entero entre 1 y 5. Vuelva intentarlo\n",1,5,2) == 0 &&

            listarClientes (listCliente,lenCliente) == 0 &&
            utn_getNumero(&bufferMotos.idCliente,"\nIngrese id del cliente de la moto: ",
                                                "\nERROR, el dato ingresado no es un ID Cliente. Solo puede ingresar un numero entero entre 5000 y 5004. Vuelva a intentarlo.\n",5000,5004,2)==0)
		{
			answer = 0;
			bufferMotos.id = *id;
			bufferMotos.isEmpty = 0;
			list[index] = bufferMotos;
			(*id)++;
		}
	}
	return answer;
}

/**
 * \brief
 * \param
 * \return
 *
 */
int motoPrint(Motos* pElement, Color* listColor, int lenColor, Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente)
{
	int answer = -1;

	char nombreColor[COLOR_LEN];
	char descripcion[DESCRIPCIONTIPO_LEN];
	char nombre [NOMBRE_LEN];

	cargarDescripcionColor(listColor,lenColor,nombreColor,pElement->idColor);
	cargarDescripcionTipo (listTipo, lenTipo,descripcion,pElement->idTipo);
	cargarDescripcionCliente(listCliente,lenCliente,nombre,pElement->idCliente);

	if(pElement != NULL && pElement->isEmpty == 0)
	{
		answer = 0;

		printf ("%3d     %20s      %20s       %20s      %3d    %10s\n\n", pElement->id, pElement->marca, descripcion, nombreColor, pElement->cilindrada, nombre);
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
int printMotos(Motos* list, int length, Color* listColor, int lengthColor, Tipo* listTipo, int lengthTipo, Cliente* listCliente, int lengthCliente)
{
    int answer = -1;

	if(list != NULL && length > 0 && listColor !=NULL && lengthColor>0 && listTipo != NULL && lengthTipo>0)
	{
		answer = 0;
		printf ("\n******Datos Moto******\n\n");
        printf ("  ID                   Marca                     Tipo                       Color        Cilindrada    NombreCliente\n\n");
		for(int i=0;i<length;i++)
		{
			if (list[i].isEmpty != 1)
            {
                motoPrint(&list[i], &listColor[i], lengthColor,&listTipo[i],lengthTipo,&listCliente[i],lengthCliente);
            }
		}
	}
	return answer;
}

/**
* \brief
* \param
* \param
* \param
* \return
*
*/
int findMotoById(Motos* list, int len, int id, Color* listColor, int lenColor, Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente)
{
	int answer = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		answer = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				printf("\nLa moto seleccionada es la siguiente: \n\n");
				printf ("  ID                   Marca                     Tipo                       Color        Cilindrada    NombreCliente\n\n");
				answer = i;
				motoPrint(&list[i], &listColor[i], lenColor,&listTipo[i],lenTipo,&listCliente[i],lenCliente);
				break;
			}
		}
	}
	return answer;
}


int menuModifyMotos(Motos* list, int len, int index)
{
	int answer = -1;
	int opcionMenu;
	Motos bufferMotos;

    if(list != NULL && len > 0 && index < len && index >= 0)
	{
		do
		{
			if ((utn_getNumero (&opcionMenu,"\nQue desea modificar?\n\n"
											"1. Color.\n"
											"2. Cilindrada.\n"
											"3. Volver.\n"
											"Ingrese una opcion: ",
											"No es una opcion valida. Vuelva a intentarlo. Solo puede ingresar numeros.\n\n", 1, 3, 1))==0)
			{

				switch(opcionMenu)
				{
					case 1:
						if (utn_getNumero(&bufferMotos.idColor, "\n*****ID Color*****"
                                                                "\n10000 - Gris\n"
                                                                "\n10001 - Negro\n"
                                                                "\n10002 - Blanco\n"
                                                                "\n10003 - Azul\n"
                                                                "\n10004 - Rojo\n"
                                                                "\nIngrese id del color que quiere de la moto: ",
                                                                "\nERROR, el dato ingresado no es un ID de los colores mostrados. Solo puede ingresar numeros sin letras o caracteres especiales.\n",10000,10004,2)==0)
						{
							bufferMotos.id = list[index].id;
							bufferMotos.isEmpty = 0;
							list[index].idColor = bufferMotos.idColor;
							printf("\nEl color fue modificado con exito\n\n");
						}
						answer = 0;
						system ("pause");
						system ("cls");
						break;
					case 2:
						if (utn_getNumero(&bufferMotos.cilindrada,"\n*****Cilindradas*****"
                                                                "\n1 - 50\n"
                                                                "\n2 - 125\n"
                                                                "\n3 - 500\n"
                                                                "\n4 - 600\n"
                                                                "\n5 - 750\n"
                                                                "\nIngrese la cilindrada de la moto: ",
                                                                "\nERROR, el dato ingresado es invalido. Solo puede ingresar un numero entre 1 y 5. Vuelva a intentarlo.\n",1,5,2) == 0)
						{
							bufferMotos.id = list[index].id;
							bufferMotos.isEmpty = 0;
							list[index].cilindrada = bufferMotos.cilindrada;
							printf("\nLa cilindrada fue modificada con exito\n\n");
						}
						answer = 0;
						system ("pause");
						system ("cls");
						break;
				}
			}
		}while (opcionMenu!=3);
	}
		return answer;
}

int cargarDescripcionColor (Color* list, int len, char* nombreColor, int id)
{
    int respuesta=-1;

    for (int i=0;i<len;i++)
    {
        if (list[i].id == id)
        {
            strncpy(nombreColor, list[i].nombreColor, COLOR_LEN);
            respuesta=0;
        }
    }
    return respuesta;
}

void hardcodearMotos (Motos* list, int cantidad)
{
	for (int i=0;i<cantidad;i++)
	{
		list[i].id=ids[i];
		strncpy (list[i].marca, marca [i],MARCA_LEN);
		list[i].idTipo=idsTipo[i];
		list[i].idColor=idsColor[i];
		list[i].cilindrada=cilindradas[i];
		list[i].idCliente=idsCliente[i];
		list[i].isEmpty=0;
	}
}

int listarColores (Color* list, int len)
{
    int respuesta=-1;
    system("cls");
    printf("******Listar Colores******\n");
    printf("ID          NombreColor\n\n");

    for(int i=0;i<len;i++)
    {
        printf("%d    %10s\n", list[i].id, list[i].nombreColor);
        respuesta=0;
    }

    return respuesta;
}

int cargarDescripcionTipo (Tipo* list, int len, char* descripcion, int id)
{
    int respuesta=-1;

    for (int i=0;i<len;i++)
    {
        if (list[i].id == id)
        {
            strncpy(descripcion, list[i].descripcion, DESCRIPCIONTIPO_LEN);
            respuesta=0;
        }
    }
    return respuesta;
}

int listarTipos (Tipo* list, int len)
{
    int respuesta=-1;
    system("cls");
    printf("******Listar Tipos******\n");
    printf("ID      Descripcion\n\n");

    for(int i=0;i<len;i++)
    {
        printf("%d    %10s\n", list[i].id, list[i].descripcion);
        respuesta=0;
    }

    return respuesta;
}


int removeMoto(Motos* list,int len, int id)
{
	int answer = -1;
	if(list != NULL && len > 0 && id >= 0 && list[id].isEmpty == 0)
	{
		list[id].isEmpty = 1;
		answer = 0;
	}
	return answer;
}

int cargarDescripcionCliente (Cliente* list, int len, char* nombre, int id)
{
    int respuesta=-1;

    for (int i=0;i<len;i++)
    {
        if (list[i].id == id)
        {
            strncpy(nombre, list[i].nombre, NOMBRE_LEN);
            respuesta=0;
        }
    }
    return respuesta;
}

int listarClientes (Cliente* list, int len)
{
    int respuesta=-1;
    system("cls");
    printf("******Listar Clientes******\n");
    printf("ID  Nombre   Sexo\n\n");

    for(int i=0;i<len;i++)
    {
        printf("%d    %10s   %c\n", list[i].id, list[i].nombre, list[i].sexo);
        respuesta=0;
    }

    return respuesta;
}

int menuInformes(Motos* list, int len, Color* listColor, int lenColor,Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente)
{
	int answer = -1;
	int opcionMenu;

    if(list != NULL && len > 0 && listColor != NULL && lenColor > 0)
	{
		do
		{
			if ((utn_getNumero (&opcionMenu,"\n*****MENU DE INFORMES*****\n\n"
											"1. Mostrar las motos del color seleccionado por el usuario.\n"
											"2. Volver.\n"
											"Ingrese una opcion: ",
											"No es una opcion valida. Vuelva a intentarlo. Solo puede ingresar numeros entre 1 y 2.\n\n", 1, 2, 1))==0)
			{

				switch(opcionMenu)
				{
					case 1:
						listarMotosSeleccionadaXColor(Motos* list, int len,Color* listColor, int lenColor, Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente);
						system ("pause");
						system ("cls");
						break;
				}
			}
		}while (opcionMenu!=2);
	}
		return answer;
}

void listarMotosSeleccionadaXColor (Motos* list, int len,Color* listColor, int lenColor, Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente)
{
	int idColor=0;
	int flag = -1;

	system ("cls");
	if(listarColores(listColor, lenColor) == 0 &&
            utn_getNumero(&list->idColor,"\nIngrese id del color que quiere de la moto: ",
                                        "\nERROR, el dato ingresado no es un ID Color. Solo puede ingresar un numero entero entre 10000 y 10004. Vuelva a intentarlo.\n",10000,10004,2)==0)

	{
		printf ("\n******Datos Moto******\n\n");
		printf ("  ID                   Marca                     Tipo                       Color        Cilindrada    NombreCliente\n\n");
		for (int i=0;i<len;i++)
		{
			if (list[i].isEmpty == 0 && list[i].idColor == idColor)
			{
				printMotos(list,len,listColor,lenColor,listTipo,lenTipo,listCliente,lenCliente);
				flag = 0;
			}
		}
		if (flag == -1)
		{
			printf ("No hay motos que tengan ese id como color");
		}
	}
}
