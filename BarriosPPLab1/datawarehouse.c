#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "moto.h"
#include "datawarehouse.h"

void hardcodearMotos (Motos* list, int cantidad)
{
	for (int i=0;i<cantidad;i++)
	{
		list[i].id=ids[i];
		strncpy (list[i].marca, marca [i],MARCA_LEN);
		list[i].idTipo=idsTipo[i];
		list[i].idColor=idsColor[i];
		list[i].cilindrada=cilindradas[i];
		list[i].isEmpty=0;
	}
}
