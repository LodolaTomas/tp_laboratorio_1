#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int state=1;//1 sino pudo abrir el archivo
    FILE* pArchive=fopen(path,"r");

    if(pArchive!=NULL && pArrayListEmployee!=NULL)
    {
        state=parser_EmployeeFromText(pArchive,pArrayListEmployee);//=-1 si pArrayList es NULL
        //=0 si fue exitoso
    }
    return state;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int state=1;//1 si el archivo no pudo ser abierto
    FILE* pArchivo=fopen(path,"rb");

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        state=parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    }

    return state;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int *id)
{
    int state=-1;
    Employee* this=employee_new();
    int idAux=*id;
    char nombre[50];
    int horasTrabajadas;
    int salario;

    if(pArrayListEmployee!=NULL && this!=NULL)
    {
        idAux++;
        employee_setId(this,idAux);
        printf("El id del empleado sera: [%d]\n",idAux);
        getValidName("Ingrese Nombre: ","Error, Solo Letras",0,49,nombre);
        employee_setNombre(this,nombre);
        getValidInt("Ingrese Horas Trabajadas: ","Error, Solo Numeros",1,100,&horasTrabajadas);
        employee_setHorasTrabajadas(this,horasTrabajadas);
        getValidInt("Ingrese Salario: ","Error, Solo Numeros",0,10000,&salario);
        employee_setSueldo(this,salario);
        borrar();
        printf("**************************************************************************************\n");
        employee_ShowOneEmployee(this);
        printf("**************************************************************************************\n");
        state=0;
        if(verifyConformity("Esta seguro de guardar este Empleado?[Si/No]:","Error, [Si/No]")==1)
        {
            ll_add(pArrayListEmployee,this);
            *id=idAux;
            state=1;
        }
    }
    return state;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int state=-1;//-1 si el pArrayListEmployee es NULL
    Employee* this=NULL;
    int answer;
    if(pArrayListEmployee!=NULL)
    {
        state=0;//0 si no se encontro al empleado buscado
        answer=controller_FindId(pArrayListEmployee);
        if(answer!=-1)
        {
            this=(Employee*)ll_get(pArrayListEmployee,answer);
            state=employee_ModifyEmployee(this);
        }
    }
    return state;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int state=-1;
    int answer;
    Employee* this=NULL;

    if(pArrayListEmployee!=NULL)
    {
        state=0;//0 si no se encontro al empleado buscado
        answer=controller_FindId(pArrayListEmployee);
        if(answer!=-1)
        {
            state=1;//1 si el empleado no se borro
            this=(Employee*)ll_get(pArrayListEmployee,answer);
            borrar();
            printf("**************************************************************************************\n");
            employee_ShowOneEmployee(this);
            printf("**************************************************************************************\n");
            if(verifyConformity("Esta seguro de Borrar este Empleado?[Si/No]: ","Error, [Si/No]")==1)
            {
                state=2;//2 si el empleado se borro
                ll_remove(pArrayListEmployee,answer);
            }
        }
    }
    return state;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int state=-1;
    int i;
    int len;
    Employee* this=NULL;

    if(pArrayListEmployee!=NULL)
    {
        printf("**************************************************************************************\n");
        printf("%5s %15s %15s %15s\n","ID","NOMBRE","HORAS","SUELDO");
        printf("**************************************************************************************\n");
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            this=(Employee*)ll_get(pArrayListEmployee,i);//Obtengo un Empleado segun id y lo muestro
            employee_ShowOneEmployee(this);
            /*
            if(i!=0 && i%150==0)
            {
                    pausa();
            }
            */
        }
        printf("**************************************************************************************\n");
        state=0;
    }
    return state;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int state=-1;//-1 si pArrayListEmployee es NULL
    int opcion;
    int orden;
    if(pArrayListEmployee!=NULL)
    {
        LinkedList* pArrayListEmployee2=ll_clone(pArrayListEmployee);//clono la lista
        //para que el ordenamiento no modifique mi archivo
        do
        {
            printf("%30s\n","ORDENAR");
            getValidInt("1. ID\n2. Nombre\n3. Horas Trabajadas\n4. Sueldo\n5. Salir\nElija una opcion: ","Error, Solo numeros",1,5,&opcion);
            switch(opcion)
            {
            case 1:
                borrar();
                getValidInt("1. Mayor a Menor\n2. Menor a Mayor\nElija una opcion: ","Error, Solo numeros",1,2,&orden);
                borrar();
                printf("Aguarde un Momento\n");
                if(ll_sort(pArrayListEmployee2,employee_compareById,orden-1)==0)
                {
                    controller_ListEmployee(pArrayListEmployee2);
                }
                pausa();
                break;
            case 2:
                borrar();
                getValidInt("1. Descendente\n2. Ascendente\nElija una opcion: ","Error, Solo numeros",1,2,&orden);
                borrar();
                printf("Aguarde un Momento\n");
                if(ll_sort(pArrayListEmployee2,employee_compareByName,orden-1)==0)
                {
                    controller_ListEmployee(pArrayListEmployee2);
                }
                pausa();
                break;
            case 3:
                borrar();
                getValidInt("1. Mayor a Menor\n2. Menor a Mayor\nElija una opcion: ","Error, Solo numeros",1,2,&orden);
                borrar();
                printf("Aguarde un Momento\n");
                if(ll_sort(pArrayListEmployee2,employee_compareByHoursWorked,orden-1)==0)
                {
                    controller_ListEmployee(pArrayListEmployee2);
                }
                pausa();
                break;
            case 4:
                borrar();
                getValidInt("1. Mayor a Menor\n2. Menor a Mayor\nElija una opcion: ","Error, Solo numeros",1,2,&orden);
                borrar();
                printf("Aguarde un Momento\n");
                if(ll_sort(pArrayListEmployee2,employee_compareBySalary,orden-1)==0)
                {
                    controller_ListEmployee(pArrayListEmployee2);
                }
                pausa();
                break;
            case 5:
                ll_deleteLinkedList(pArrayListEmployee2);//borro la lista para que no moleste
                break;
            }
            borrar();
        }
        while(opcion!=5);
        state=0;//si el ordenado se realizo con exito
    }
    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int state=-1;
    int i;
    Employee* this=NULL;
    int len;
    FILE* pArchivo=fopen(path,"w");

    int id;
    char nombre[50];
    int horasTrabajadas;
    int salario;
    int counter=0;

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        fprintf(pArchivo,"id,nombre,horasTrabajadas,Salario\n");
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            this=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(this,&id);
            employee_getNombre(this,nombre);
            employee_getHorasTrabajadas(this,&horasTrabajadas);
            employee_getSueldo(this,&salario);
            fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,salario);
            counter++;
        }
        state=0;
        fclose(pArchivo);
        printf("Fueron guardados: %d\n",counter);//idea de passu
    }
    return state;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int state=-1;
    int i;
    int len;
    Employee* this=NULL;
    int counter=0;
    FILE* pArchivo=fopen(path,"wb");//abro el archivo en modo write binary

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)//Verifico que nada sea NULL
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++) //Recorro el Array de empleados
        {
            this=(Employee*)ll_get(pArrayListEmployee,i);//obtengo el empleado en la posicion i
            fwrite(this,sizeof(Employee),1,pArchivo);//y lo escribo en el archivo
            counter++;
        }
        state=0;
        printf("Fueron Guardados: %d\n",counter);//idea de passu
        fclose(pArchivo);//Cierro el archivo
    }

    return state;
}

void controller_GetLastId(LinkedList* pArrayListEmployee,int* id)
{
    int len;
    int i,flag=0;
    Employee* OneEmployee;
    int max;
    int idAux;
    if(pArrayListEmployee!=NULL && id!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            OneEmployee=(Employee*)ll_get(pArrayListEmployee,i);//Obtengo un Empleado por cada iteracion del for
            employee_getId(OneEmployee,&idAux);// de cada Empleado obtengo el id
            if(idAux > max || flag == 0)
            {
                flag=1;
                max=idAux;
            }
        }

        *id=max;
    }
}

int controller_FindId(LinkedList* pArrayListEmployee)
{
    int retorno=-1;//-1 si el empleado no fue encontrado en la lista
    int opcion;
    int len;
    int i;
    Employee* this;
    int idAux=0;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        controller_ListEmployee(pArrayListEmployee);
        getValidInt("Ingrese el id del Empleado: ","Error, solo numeros",0,100000,&opcion);
        for(i=0; i<len; i++)
        {
            this=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(this,&idAux);
            if(opcion==idAux)
            {
                retorno=i;//si el empleado fue encontrado
                break;
            }
        }
    }
    return retorno;
}
