#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).***LISTO
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).***LISTO
     3. Alta de empleado***LISTO
     4. Modificar datos de empleado***LISTO
     5. Baja de empleado***LISTO
     6. Listar empleados***LISTO
     7. Ordenar empleados***LISTO
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).***LISTO
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).***LISTO
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    int respuesta;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int id;

    do
    {
        borrar();
        getValidInt("Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10.Salir\nElija una opcion: ","Error",0,10,&opcion);
        switch(opcion)
        {
        case 1:
            borrar();
            if(controller_loadFromText("data.csv",listaEmpleados)==0)
            {
                flag=1;
                printf("Cargado exitosamente en Texto\n");
                controller_GetLastId(listaEmpleados,&id);
            }
            pausa();
            break;
        case 2:
            borrar();
            if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
            {
                flag=1;
                printf("Cargado exitosamente en Binario\n");
                controller_GetLastId(listaEmpleados,&id);
            }
            pausa();
            break;
        case 3:
            borrar();
            if(flag!=0)
            {
                respuesta=controller_addEmployee(listaEmpleados,&id);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("pArrayListEmployee is NULL\n");
                    break;
                case 0:
                    borrar();
                    printf("Accion Cancelada por el Usuario\n");
                    break;
                case 1:
                    borrar();
                    printf("Empleado Agregado\n");
                    break;
                }
            }
            else
            {
                printf("Debe abrir el archivo[.txt o .bin] antes de agregar un empleado\n");
            }
            pausa();
            break;
        case 4:
            borrar();
            if(flag!=0)
            {
                respuesta=controller_editEmployee(listaEmpleados);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("pArrayListEmployee is NULL\n");
                    break;
                case 0:
                    borrar();
                    printf("Employee no encontrado\n");
                    break;
                case 1:
                    borrar();
                    printf("Accion Cancelada por el Usuario\n");
                    break;
                case 2:
                    borrar();
                    printf("Employee Modificado\n");
                    break;
                }
            }
            else
            {
                printf("Debe abrir el archivo[.txt o .bin] antes de editar un empleado\n");
            }
            pausa();
            break;
        case 5:
            borrar();
            if(flag!=0)
            {
                respuesta=controller_removeEmployee(listaEmpleados);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("pArrayListEmployee is NULL\n");
                    break;
                case 0:
                    borrar();
                    printf("Employee no encontrado\n");
                    break;
                case 1:
                    borrar();
                    printf("Accion Cancelada por el Usuario\n");
                    break;
                case 2:
                    borrar();
                    printf("Employee Borrado\n");
                    break;
                }
            }
            else
            {
                printf("Debe abrir el archivo[.txt o .bin] antes de remover un empleado\n");
            }
            pausa();
            break;
        case 6:
            borrar();
            if(flag!=0)
            {
                if(controller_ListEmployee(listaEmpleados)==0)
                {
                    printf("Listado realizado con Exito\n");
                }
            }
            else
            {
                printf("Debe abrir el archivo[.txt o .bin] antes de listar los empleados\n");
            }
            pausa();
            break;
        case 7:
            borrar();
            if(flag!=0)
            {
                if(controller_sortEmployee(listaEmpleados)==0)
                {
                    printf("Listado realizado con Exito\n");
                }
            }
            else
            {
                printf("Debe abrir el archivo[.txt o .bin] antes de ordenar los empleados\n");
            }
            pausa();
            break;
        case 8:
            borrar();
            if(flag!=0)
            {
                if(controller_saveAsText("data.csv",listaEmpleados)==0)
                {
                    printf("Ha sido guardado Exitosamente\n");
                    pausa();
                }
            }
            else
            {
                printf("Debe abrir el archivo[.txt o .bin] antes de Guardar\n");
            }
            pausa();
            break;
        case 9:
            borrar();
            if(flag!=0)
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados)==0)
                {
                    printf("Ha sido guardado Exitosamente\n");
                    pausa();
                }
            }
            else
            {
                printf("Debe abrir el archivo[.txt o .bin] antes de Guardar\n");
            }
            pausa();
            break;
        case 10:
            printf("Saliendo..\n");
            ll_deleteLinkedList(listaEmpleados);
            break;
        }
        borrar();
    }
    while(opcion!=10);

    return 0;
}

/**
do
{

    switch(opcion)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }

}
while(opcion);

*/
