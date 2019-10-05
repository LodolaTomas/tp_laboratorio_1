#include "ArrayEmployees.h"

int initEmployees(eEmployee* listE, int lenEmployee)
{
    int retorno=-1;
    int i;

    if( listE != NULL && lenEmployee != 0 )
    {
        for(i=0; i<lenEmployee; i++)
        {
            listE[i].isEmpty=TRUE;
        }
        retorno=0;
    }

    return retorno;
}

int findEmployeeById(eEmployee* listE, int lenEmployee,int id)
{
    int retorno=-1;
    int i;

    if(listE!=NULL && lenEmployee!=0)
    {
        for(i=0; i<lenEmployee; i++)
        {
            if(listE[i].isEmpty==FALSE)
            {
                if(listE[i].id==id)
                {
                    retorno=i;
                    break;
                }
            }
        }
    }

    return retorno;
}


int printEmployees(eEmployee* listE, int lenEmployee,eSector* listS,int lenSector)
{
    int retorno=-1;
    int i;
    int index;

    if(listE!=NULL && lenEmployee!=0)
    {
        printf("%5s %10s %15s %15s %15s\n","ID","Nombre","Apellido","Salario","Sector");
        for(i=0; i<lenEmployee; i++)
        {
            if(listE[i].isEmpty==FALSE)
            {
                index=findSectorbyID(listS,lenSector,listE[i].sector);
                printOneEmploye(listE[i],listS[index]);
            }
        }
        retorno=0;
    }
    return retorno;
}

void printOneEmploye(eEmployee OneEmployee,eSector OneSector)
{
    printf("%5d %10s %15s %15.2f %15s\n",OneEmployee.id,OneEmployee.name,OneEmployee.lastName,OneEmployee.salary,OneSector.description);
}

int findFree(eEmployee* listE,int lenEmployee)
{
    int retorno=-1;
    int i;

    if(listE!=NULL && lenEmployee !=0)
    {
        for(i=0; i<lenEmployee; i++)
        {
            if(listE[i].isEmpty==TRUE)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}



void hardcodearEmployees(eEmployee* listE, int lenEmployee,int* id)
{
    int i;
    int id_1;
    id_1=*id;
    float salary[]= {1200.66, 500,7000.66,100.00,7999.99,1,500,14000.30,90000,30.75};
    char name[][25]= {"Juan","Josefina","Maria","Flopy","Luca","Lucia","Alan","German","Brian","Pedro"};
    char lastName[][25]= {"Perez","Fernandez","Serrano","Gonzalez","Lodola","Morel","Passu","Villegas","Gonzalez","PeepeePoopPoop"};
    int sector[]= {1,3,2,1,1,3,3,2,1,3};
    for(i=0; i<lenEmployee; i++)
    {
        listE[i].id = id_1;
        strcpy(listE[i].name, name[i]);
        strcpy(listE[i].lastName,lastName[i]);
        listE[i].salary = salary[i];
        listE[i].sector=sector[i];
        listE[i].isEmpty = FALSE;
        id_1++;
    }
    *id=id_1;

}

int addEmployee(eEmployee* listE, int lenEmployee, eSector* listS, int lenSector,int* id)
{
    int retorno=-1;
    int indice;
    int i;
    int idAux;
    idAux=*id;
    eEmployee auxEmployee;
    eSector auxSector;

    if(listE!=NULL && lenEmployee!=0 && listS!=NULL && lenSector!=0)
    {
        indice=findFree(listE,lenEmployee);
        if(indice!=-1)
        {
            auxEmployee.id=idAux;
            getValidString("Ingrese nombre: ","Cuidado, solo letras",0,30,auxEmployee.name);
            getValidString("Ingrese apellido: ","Cuidado, solo letras",0,30,auxEmployee.lastName);
            getValidFloat("Ingrese salario: ","Cuidado, solo numeros",0,100000000,&auxEmployee.salary);
            mostrar_Sectores(listS,lenSector);
            getValidInt("Ingrese sector: ","Cuidado, solo numeros",0,lenSector,&auxEmployee.sector);
            i=findSectorbyID(listS,lenSector,auxEmployee.sector);
            auxSector=listS[i];
            auxEmployee.isEmpty=FALSE;
            borrar();
            mostrar("AGREGAR EMPLEADO",auxEmployee,auxSector);
            if(verifyConformity("Esta seguro de guardar este empleado?[Si/No]: ","Cuidado [Si/No]")==1)
            {
                listE[indice]=auxEmployee;
                retorno=0;
                idAux++;
                *id=idAux;
            }
            else
            {
                retorno=1;
            }

        }

    }



    return retorno;
}

int removeEmployee(eEmployee* listE, int lenEmployee,eSector* listS, int lenSector)
{
    int retorno=-1;
    int indice;
    int indice2;
    int respuesta;
    int empleados;
    eEmployee auxEmployee;
    eSector auxSector;

    empleados=cantidadEmpleados(listE,lenEmployee);
    if(listE!=NULL && lenEmployee!=0 && empleados!=0)
    {

        printf("%20s","BAJA EMPLEADO\n");
        printEmployees(listE,lenEmployee,listS,lenSector);
        getValidInt("Elija el Empleado a dar de baja: ","Cuidado, solo numeros",0,lenEmployee,&indice);
        respuesta=findEmployeeById(listE,lenEmployee,indice);
        if(respuesta!=-1)
        {
            auxEmployee=listE[respuesta];
            indice2=findSectorbyID(listS,lenSector,auxEmployee.sector);
            auxSector=listS[indice2];
            borrar();
            mostrar("BAJA EMPLEADO",auxEmployee,auxSector);
            if(verifyConformity("Esta seguro que quiere darlo de baja?[Si/No]","Cudiado, responda[Si/No]")==1)
            {
                retorno=0;
                auxEmployee.isEmpty=TRUE;
                listE[respuesta]=auxEmployee;
            }
            else
            {
                retorno=1;
            }

        }
    }
    return retorno;
}


int modifyEmployees(eEmployee* listE, int lenEmployee,eSector* listS,int lenSector)
{
    int option;
    int retorno=-1;
    int respuesta;
    int answer;
    int index;
    int empleados;

    eEmployee auxEmployee;
    eSector auxSector;
    empleados=cantidadEmpleados(listE,lenEmployee);

    if(listE!=NULL && lenEmployee!=0 && empleados!=0)
    {
        borrar();
        printEmployees(listE,lenEmployee,listS,lenSector);
        getValidInt("Ingrese el Id del empleado a Modificar: ","Cuidado, Solo los ID",0,lenEmployee,&option);
        respuesta=findEmployeeById(listE,lenEmployee,option);

        if(respuesta!=-1)
        {
            auxEmployee=listE[respuesta];

            do
            {
                index=findSectorbyID(listS,lenSector,auxEmployee.sector);
                auxSector=listS[index];
                borrar();
                mostrar("MODIFICAR",auxEmployee,auxSector);
                getValidInt("1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n5- Volver al menu\nEliga una opcion: ","Cuidado, solo ingrese numeros",1,5,&answer);

                switch(answer)
                {

                case 1:
                    borrar();
                    getValidString("Ingrese nuevo nombre: ","Cuidado, Solo letras",0,30,auxEmployee.name);
                    break;
                case 2:
                    borrar();
                    getValidString("Ingrese nuevo apellido: ","Cuidado, Solo letras",0,30,auxEmployee.lastName);
                    break;
                case 3:
                    borrar();
                    getValidFloat("Ingrese nuevo salario: ","Cuidado, Solo Numeros",0,100000000,&auxEmployee.salary);
                    break;
                case 4:
                    borrar();
                    mostrar_Sectores(listS,lenSector);
                    getValidInt("Ingrese nuevo sector: ","Cuidado, Solo Numeros",1,lenSector,&auxEmployee.sector);
                    break;
                case 5:
                    borrar();
                    mostrar("MODIFICAR",auxEmployee,auxSector);
                    if(verifyConformity("Esta seguro que desea guardar los cabios[Si/No]:","Cuidado, [Si/No]")==1)
                    {
                        listE[respuesta]=auxEmployee;
                        retorno=0;
                    }
                    else
                    {
                        retorno=1;
                    }
                    break;
                }


            }
            while(answer!=5);

        }
    }

    return retorno;
}

int infoEmployees(eEmployee* listE, int lenEmployee,eSector* listS,int lenSector)
{
    int opcion;
    int orden;
    int retorno=-1;
    int empleados;

    empleados=cantidadEmpleados(listE,lenEmployee);

    if(listE!=NULL && lenEmployee!=0 && empleados!=0)
    {
        retorno=0;
        do
        {
            printf("%10s\n","INFORMAR");
            getValidInt("1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n3- Volver al menu\nElija una opcion: ","Cuidado, Solo numeros",1,3,&opcion);
            switch(opcion)
            {

            case 1:
                borrar();
                getValidInt("1- Decedente\n2- Acendente\nElija una respuesta: ","Cuidado, solo numeros",1,2,&orden);
                sortEmployees(listE,lenEmployee,orden);
                printEmployees(listE,lenEmployee,listS,lenSector);
                pausa();
                break;
            case 2:
                borrar();
                salarioEmpleados(listE,lenEmployee,listS,lenSector);
                pausa();
                break;
            case 3:
                printf("bye bye\n");
                break;
            }
            borrar();
        }
        while(opcion!=3);
    }

    return retorno;
}
void sortEmployees(eEmployee* listE, int lenE, int order)
{
    int i;
    int j;
    eEmployee auxEmpleado;


    for(i=0; i<lenE-1; i++)
    {
        for(j=i+1; j<lenE; j++)
        {
            if(order==1)
            {
                if(strcmp(listE[i].lastName,listE[j].lastName)>0)
                {
                    auxEmpleado = listE[i];
                    listE[i] = listE[j];
                    listE[j] = auxEmpleado;
                }

                else
                {
                    if(strcmp(listE[i].lastName,listE[j].lastName)==0)
                    {
                        if(listE[i].sector>listE[j].sector)
                        {
                            auxEmpleado = listE[i];
                            listE[i] = listE[j];
                            listE[j] = auxEmpleado;

                        }
                    }
                }
            }
            if(order==2)
            {
                if(strcmp(listE[i].lastName,listE[j].lastName)<0)
                {
                    auxEmpleado = listE[i];
                    listE[i] = listE[j];
                    listE[j] = auxEmpleado;
                }

                else
                {
                    if(strcmp(listE[i].lastName,listE[j].lastName)==0)
                    {
                        if(listE[i].sector<listE[j].sector)
                        {
                            auxEmpleado = listE[i];
                            listE[i] = listE[j];
                            listE[j] = auxEmpleado;
                        }
                    }
                }
            }
        }

    }

}

void salarioEmpleados(eEmployee* listE,int lenE,eSector* listS,int lenS)
{
    int i;
    float totalSalario;
    int totalEmpleados;
    float promedioSalario;

    totalSalario = salarioAcumEmpleados(listE, lenE);
    totalEmpleados=cantidadEmpleados(listE,lenE);
    promedioSalario = totalSalario / totalEmpleados;

    printf("\nEl salario promedio es: %.2f\n", promedioSalario);
    printf("Los empleados que lo superan el salario promedio son: \n\n");
    for (i=0; i<lenE; i++)
    {
        if (listE[i].salary > promedioSalario && listE[i].isEmpty == FALSE)
        {
            printf("%s %s\n\n",listE[i].name, listE[i].lastName);
        }
    }
}

float salarioAcumEmpleados (eEmployee* listE, int lenE)
{
    int i;
    float salaryAcum=0;
    for (i=0; i<lenE; i++)
    {
        if (listE[i].isEmpty==FALSE)
        {
            salaryAcum+= listE[i].salary;
        }
    }

    return salaryAcum;
}
int cantidadEmpleados(eEmployee* listE,int lenE)
{
    int retorno=0;
    int i;

    for(i=0; i<lenE; i++)
    {
        if(listE[i].isEmpty==FALSE)
        {
            retorno++;
        }
    }

    return retorno;
}


void mostrar(char mensaje[],eEmployee employee,eSector sector)
{
    printf("%30s\n",mensaje);
    printf("**********************************************************************\n");
    printf("%5s %10s %15s %15s %15s\n","ID","Nombre","Apellido","Salario","Sector");
    printOneEmploye(employee,sector);
    printf("**********************************************************************\n");
}
