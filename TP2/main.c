#include "ArrayEmployees.h"

#define LE 11 //lengh Employees
#define LS 3 //lengh Sector

int main()
{
    eEmployee ListEmployee[LE];
    eSector ListSector[LS];
    initEmployees(ListEmployee,LE);
    int id=0;// id unico, en tiempo de ejecucion claro..
    int option;
    int respuesta;
    int flag=0;

    //******************************************************************************
    hardcodearEmployees(ListEmployee,10,&id);//Hardcodeo Empleado, OPCIONAL
    //******************************************************************************

    hardcodearSectores(ListSector,LS);//Hardcodeo sectores, OBLIGATORIO

    do
    {
        getValidInt("1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\nElija una opcion: ","Error, solo numeros[1-5]",1,5,&option);

        switch(option)
        {
        case 1:
            borrar();
            respuesta =addEmployee(ListEmployee,LE,ListSector,LS,&id);
            switch(respuesta)
            {
            case -1:
                borrar();
                printf("No hay espacio disponible\n");
                pausa();
                break;
            case 0:
                borrar();
                printf("Empleado Cargado\n");
                flag=1;
                pausa();
                break;
            case 1:
                borrar();
                printf("Accion cancelada por el usuario\n");
                pausa();
                break;
            }
            break;
        case 2:
            borrar();
            if(flag!=0)
            {
                respuesta =modifyEmployees(ListEmployee,LE,ListSector,LS);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("No se encontro el Empleado o No hay empelados Cargados\n");
                    pausa();
                    break;
                case 0:
                    borrar();
                    printf("Empleado Modificado\n");
                    pausa();
                    break;
                case 1:
                    borrar();
                    printf("Accion cancelada por el usuario\n");
                    pausa();
                    break;
                }
            }
            else
            {
                printf("Debe cargar Empleados Antes de Modificar uno\n");
                pausa();
            }
            break;
        case 3:
            borrar();
            if(flag!=0)
            {
                respuesta =removeEmployee(ListEmployee, LE,ListSector, LS);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("No se encontro el Empleado o No hay empelados Cargados\n");
                    pausa();
                    break;
                case 0:
                    borrar();
                    printf("Empleado Borrado\n");
                    pausa();
                    break;
                case 1:
                    borrar();
                    printf("Accion cancelada por el usuario\n");
                    pausa();
                    break;
                }
            }
            else
            {
                printf("Debe cargar Empleados Antes de Darlos de Baj\n");
                pausa();
            }
            break;
        case 4:
            borrar();
            if(flag!=0)
            {
                respuesta=infoEmployees(ListEmployee,LE,ListSector,LS);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("No se encontro el Empleado o No hay empelados Cargados\n");
                    pausa();
                    break;
                case 0:
                    borrar();
                    printf("Informes Realizados\n");
                    pausa();
                    break;
                }
            }
            else
            {
                printf("Debe cargar Empleados Antes de Mostrarlos\n");
                pausa();
            }
            break;
        case 5:
            borrar();
            printf("ADIOS...(Vuelva prontos).\n\n");
            break;
        }
        borrar();
    }
    while(option!=5);


    return 0;
}
