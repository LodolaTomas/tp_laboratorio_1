#include "myFunctions.h"

void cargarEmpleado(eEmployee* list, int len)
{
    int id=0;
    char nombre[32];
    char apellido[32];
    float salario;
    int sector;
    int respuesta;


    id++;
    getValidString("Ingrese el nombre: ","ERROR. solo letras",0,32,nombre);
    getValidString("Ingrese el apellido: ","ERROR. solo letras",0,32,apellido);
    getValidFloat("Ingrese el salrio: ","ERROR. solo numeros",0.00,100000.00,&salario);
    getValidInt("Ingrese el sector: ","ERROR. solo numeros",0,4,&sector);

    printf("\n\n%d--%s--%s--%.2f--%d",id,nombre,apellido,salario,sector);

}

int buscarLibre(eEmployee* list,int len)
{
    int retorno=-1;
    int i;

    if(list!=NULL && len !=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==TRUE)
            {
                retorno=i;
                break;
            }
        }
    }

 return retorno;
}
