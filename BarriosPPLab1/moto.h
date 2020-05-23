#ifndef moto_H_INCLUDED
#define moto_H_INCLUDED

#define DESCRIPCIONTIPO_LEN 21
#define COLOR_LEN 21
#define MARCA_LEN 21
#define NOMBRE_LEN 11

typedef struct
{
    int id;
    char nombre [NOMBRE_LEN];
    char sexo;

}Cliente;

typedef struct
{
    int id;
    char descripcion [DESCRIPCIONTIPO_LEN];

}Tipo;

typedef struct
{
    int id;
    char nombreColor [COLOR_LEN];

}Color;

typedef struct
{
    int id;
    char marca [MARCA_LEN];
    int idTipo;
    int idColor;
    int cilindrada;
    int idCliente;
    int isEmpty;

}Motos;

int initMotos(Motos* list, int len);
int getEmptyIndexMotos(Motos* list,int len);
int addMotos(Motos* list,int len,int index,int* id, Tipo* listTipo,int lenTipo,Color* listColor,int lenColor, Cliente* listCliente, int lenCliente);
int motoPrint(Motos* pElement, Color* listColor, int lenColor, Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente);
int printMotos(Motos* list, int length, Color* listColor, int lengthColor, Tipo* listTipo, int lengthTipo, Cliente* listCliente, int lengthCliente);
int findMotoById(Motos* list, int len, int id, Color* listColor, int lenColor, Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente);
int menuModifyMotos(Motos* list, int len, int index);
int cargarDescripcionColor (Color* list, int len, char nombreColor [], int id);
void hardcodearMotos (Motos* list, int cantidad);
int listarColores (Color* list, int len);
int cargarDescripcionTipo (Tipo* list, int len, char* descripcion, int id);
int listarTipos (Tipo* list, int len);
int removeMoto(Motos* list,int len, int id);
int cargarDescripcionCliente (Cliente* list, int len, char* nombre, int id);
int listarClientes (Cliente* list, int len);
int menuInformes(Motos* list, int len, Color* listColor, int lenColor,Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente);
void listarMotosSeleccionadaXColor (Motos* list, int len,Color* listColor, int lenColor, Tipo* listTipo, int lenTipo, Cliente* listCliente, int lenCliente);

#endif // MOTO_H_INCLUDED
