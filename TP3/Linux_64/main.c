#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

/**                 IMPORTANTE

        settings/Environment.../Terminal to lunch console programs

        yo no utilizo la terminal del codeBlocks[xterm -T $TITLE -e]
        utilizo la terminal base del Linux[gnome-terminal -t $TITLE -x ]
        no cambia mucho pero al realizar el listado de empleados, muestra toda la lista
        sin la necesidad de tener que mostrar de a 250 empleados

        Aun asi voy a commitiar en la funcion Controller_ListEmployee
        para que el listado se vea de a cada 150 empleados.
*/


/*                                                      Que hace la variable flag?
La variable flag se encarga de INutilizar las opciones [3-9], si es que no se realizo la carga de empleados[.txt o .bin].
Una vez relizada la carga de empleados [.txt o .bin], flag INutiliza cualquier otra carga de empleados para que no se
vuelva a cargar en el arrayList.
Una vez guardado los datos de los empleados[.txt o .bin] (que realizan un ll_clear), cambia el estado de la variable flag
para que se pueda realizar otra carga de empleados[.txt o .bin].
*/

int main()
{
    int opcion;
    int respuesta;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();;
    int id;

    do
    {
        borrar();
        getValidInt("Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10.Salir\nElija una opcion: ","Error",0,10,&opcion);
        switch(opcion)
        {
        case 1:
            borrar();
            if(flag==0)
            {
                respuesta=controller_loadFromText("data.csv",listaEmpleados);
                switch(respuesta)
                {
                case 0:
                    flag=1;
                    printf("Cargado exitosamente en Texto\n");
                    controller_GetLastId(listaEmpleados,&id);
                    break;
                case 1:
                    borrar();
                    printf("pFile no pudo ser abierto o ListaEmpleado es NULL\n");
                    break;
                }
            }
            else{
                printf("Un archivo ya ha sido Abierto\n");
                printf("Por favor, guarde el archivo para poder realizar otra carga\n");
            }
            pausa();
            break;
        case 2:
            borrar();
            if(flag==0)
            {
                respuesta=controller_loadFromBinary("data.bin",listaEmpleados);
                switch(respuesta)
                {
                case 0:
                    flag=1;
                    printf("Cargado exitosamente en Binario\n");
                    controller_GetLastId(listaEmpleados,&id);
                    break;
                case 1:
                    borrar();
                    printf("pFile no pudo ser abierto o ListaEmpleado es NULL\n");
                    break;
                }
            }
            else{
                printf("Un archivo ya ha sido Abierto\n");
                printf("Por favor, guarde el archivo para poder realizar otra carga\n");
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
                    ll_clear(listaEmpleados);
                    flag=0;
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
                    ll_clear(listaEmpleados);
                    flag=0;
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
