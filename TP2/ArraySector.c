#include "ArraySector.h"


eSector unSector(eSector* listS,int lenSector)
{
    eSector auxSector;
    int auxId;
    int i;
    mostrar_Sectores(listS,lenSector);
    getValidInt("Elija un Sector:","ERROR. Solo Numeros",1,3,&auxId);

    for(i=0; i<lenSector; i++)
    {
        if(auxId==listS[i].id)
        {
            auxSector=listS[i];

        }

    }
    return auxSector;

}
void hardcodearSectores(eSector* listS,int lenSector)
{
    int id[]= {1,2,3};
    char descripcion[][32]= {"Contabilidad","Sistemas","RRHH"};
    int i;

    for(i=0; i<lenSector; i++)
    {
        listS[i].id=id[i];
        strcpy(listS[i].description,descripcion[i]);
    }

}

void mostrar_UnSector(eSector OneSector)
{
    printf("%2d %15s\n",OneSector.id,OneSector.description);
}

int mostrar_Sectores(eSector* listS,int lenSector)
{
    int retorno=-1;
    int i;

    if(listS!=NULL && lenSector!=0)
    {
        retorno=0;
        printf("%s %13s\n","ID","Sector");
        for(i=0; i<lenSector; i++)
        {
            mostrar_UnSector(listS[i]);
        }
    }
    return retorno;
}

int findSectorbyID(eSector* listS,int lenSector,int idSector)
{
    int retorno=-1;
    int i;

    for(i=0; i<lenSector; i++)
    {
        if(listS[i].id==idSector)
        {
            retorno=i;
        }

    }
    return retorno;
}
