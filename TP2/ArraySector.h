#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

typedef struct
{
    int id;
    char description[40];

} eSector;

void hardcodearSectores(eSector* listS,int lenSector);

eSector unSector(eSector* listS,int lenSector);

int mostrar_Sectores(eSector* listS,int lenSector);

int findSectorbyID(eSector* listS,int lenSector,int idSector);

void mostrar_UnSector(eSector OneSector);
