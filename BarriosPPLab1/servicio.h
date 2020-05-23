#ifndef servicio_H_INCLUDED
#define servicio_H_INCLUDED

#define DESCRIPCIONSERVICIO_LEN 26

typedef struct
{
    int id;
    char descripcion [DESCRIPCIONSERVICIO_LEN];
    int precio;

}Servicio;

int listarServicios (Servicio* list, int len);
void hardcodearServicios (Servicio* list, int cantidad);

#endif // SERVICIO_H_INCLUDED
