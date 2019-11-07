#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int state=1;// si pFile o pArrayListEmployee son NULL
    int counter=0;//Cuento los empleados que son leidos y agregados a la Lista
    Employee* this=NULL;
    char idStr[20];
    char nameStr[51];
    char hoursWorkedStr[10];
    char salaryStr[20];

    if(pFile!=NULL && pArrayListEmployee!=NULL)//Verifico que lo ingresado sea
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameStr,hoursWorkedStr,salaryStr);//Falsa lectura
        //leo el primer renglon
        while(!feof(pFile))//leo el archivo hasta el final
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nameStr,hoursWorkedStr,salaryStr);//leo datos del archivo
            this=employee_newParametros(idStr,nameStr,hoursWorkedStr,salaryStr);//agrego los parametros en mi aux
            ll_add(pArrayListEmployee,this);//los agrego al LinkedList
            counter++;
        }
        state=0;//Cambio el estado
        fclose(pFile);
        printf("Fueron cargados : %d\n",counter);//idea de passu
    }
    return state;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int state=1;//1 si pArrayListEmployee o pFIle son NULL
    Employee* this;
    int counter=0;
    if(pFile!=NULL && pArrayListEmployee!=NULL)//Verifico que no sea NULL
    {
        while(!feof(pFile))//Recorro hasta el final del archivo
        {
            this=employee_new();//creo un empleadoAux
            if(this!=NULL)
            {
                fread(this,sizeof(Employee),1,pFile);//guardo en el aux lo de tipo FILE
                if(feof(pFile))
                {
                    break;
                }
                ll_add(pArrayListEmployee,this);//lo agrego la linkedList
                counter++;
            }
        }
        state=0;//cambio el estado
        fclose(pFile);//cierro el archivo
        printf("Fueron cargados : %d\n",counter);//idea de passu
    }
    return state;// -1 si pFile o pArrayLinkedList es NULL
    // 0 si todo salio correctamente
}
