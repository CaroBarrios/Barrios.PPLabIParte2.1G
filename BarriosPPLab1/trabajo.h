#ifndef trabajo_H_INCLUDED
#define trabajo_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}Fecha;


typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    Fecha fecha;
    int isEmpty;

}Trabajo;

int initTrabajos(Trabajo* list, int len);
int getEmptyIndexTrabajos(Trabajo* list,int len);
int addTrabajo(Trabajo* list,int len,int index, int* id, int idMoto, Motos* listMotos, int lenMoto, Tipo* listTipo,int lenTipo,Color* listColor,int lenColor, Servicio* listServicio, int lenServicio, Cliente* listCliente, int lenCliente);
int trabajoPrint(Trabajo* pElement);
int printTrabajos(Trabajo* list, int length);

#endif // TRABAJO_H_INCLUDED
