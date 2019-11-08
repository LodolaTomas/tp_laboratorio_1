#include "Employee.h"

Employee* employee_new()
{
    Employee* oneEmployee;

    oneEmployee=(void*)malloc(sizeof(Employee));

    return oneEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* p=employee_new();

    if(p!=NULL)
    {
        employee_setId(p,atoi(idStr));
        employee_setNombre(p,nombreStr);
        employee_setHorasTrabajadas(p,atoi(horasTrabajadasStr));
        employee_setSueldo(p,atof(sueldoStr));
    }
    return  p;
}
void employee_delete(Employee* this)
{
    free(this);
    this=NULL;
}

int employee_setId(Employee* this,int id)
{
    int state=-1;
    if(this!=NULL && id>0)
    {
        this->id=id;
        state=0;
    }
    return state;
}

int employee_getId(Employee* this,int* id)
{
    int state=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        state=0;
    }
    return state;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int state=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        state=0;
    }
    return state;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int state=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        state=0;
    }
    return state;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int state=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        state=0;
    }
    return state;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int state=-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        state=0;
    }
    return state;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int state=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        state=0;
    }
    return state;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int state=-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        state=0;
    }
    return state;
}
void employee_ShowOneEmployee(Employee* this)
{
    if(this!=NULL)
    {
        printf("%5d %15s %15d %15.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }
}

int employee_ModifyEmployee(Employee* this)
{
    int state=1;
    Employee auxEmployee;
    int option;
    if(this!=NULL)
    {
        auxEmployee=*this;//Obtengo una copia del Empleado
        borrar();
        do
        {
            printf("%30s\n","MODIFICAR");
            employee_showEmployee(auxEmployee);//Muestro el Empleado
            getValidInt("1. Nombre\n2. Horas Trabajadas\n3. Sueldo\n4. Salir\nElija una opcion: ","Error, solo numeros",1,4,&option);
            switch(option)
            {
            case 1:
                getValidString("Ingrese el nuevo Nombre: ","Error, solo letras",0,50,auxEmployee.nombre);
                break;
            case 2:
                getValidInt("Ingrese nuevas Horas Trabajadas: ","Error, solo Numeros",0,100,&auxEmployee.horasTrabajadas);
                break;
            case 3:
                getValidFloat("Ingrese nuevo salario: ","Error, solo Numeros",0,100000,&auxEmployee.sueldo);
                break;
            case 4:
                borrar();
                employee_showEmployee(auxEmployee);
                if(verifyConformity("Esta seguro de guardar los cambios?[Si/No]: ","Error, [Si/No]")==1)//pregunto si la modificacion es correcta
                {
                    state=2;// retorno 2 si lo modifico
                    *this=auxEmployee;
                }
                break;
            }
            borrar();
        }
        while(option!=4);
    }
    return state;
}



void employee_showEmployee(Employee oneEmployee)
{
    printf("**************************************************************************************\n");
    printf("%5s %15s %15s %15s\n","ID","NOMBRE","HORAS","SUELDO");
    printf("%5d %15s %15d %15.2f\n",oneEmployee.id,oneEmployee.nombre,oneEmployee.horasTrabajadas,oneEmployee.sueldo);
    printf("**************************************************************************************\n");
}

int employee_compareById(void* pElementOne, void* pElementTwo)
{
    int state = -1;
    Employee* auxEmp1 = (Employee*) pElementOne;
    Employee* auxEmp2 = (Employee*) pElementTwo;
    int id;
    int id2;
    employee_getId(auxEmp1,&id);
    employee_getId(auxEmp2,&id2);

    if (id > id2)
    {
        state = 1;
    }
    else if (id == id2)
    {
        state = 0;
    }

    auxEmp1 = NULL;
    auxEmp2 = NULL;
    return state;
}

int employee_compareByName(void* pElementOne, void* pElementTwo)
{
    int retorno=1;
    Employee* oneEmployee=(Employee*)pElementOne;
    Employee* twoEmployee=(Employee*)pElementTwo;
    char name1[49];
    char name2[49];
    employee_getNombre(oneEmployee,name1);
    employee_getNombre(twoEmployee,name2);
    if(strcmp(name1,name2)<0)
    {
        retorno=-1;
    }
    if(strcmp(name1,name2)==0)
    {
        retorno=2;
    }
    return retorno;
}

int employee_compareByHoursWorked(void* pElementOne, void* pElementTwo)
{
    int retorno=-1;
    int oneHoursWorked;
    int twoHoursWorked;
    Employee* oneEmployee=(Employee*)pElementOne;
    Employee* twoEmployee=(Employee*)pElementTwo;
    employee_getHorasTrabajadas(oneEmployee,&oneHoursWorked);
    employee_getHorasTrabajadas(twoEmployee,&twoHoursWorked);

    if(oneHoursWorked>twoHoursWorked)
    {
        retorno=1;
    }
    else if(oneHoursWorked==twoHoursWorked)
    {
        retorno=0;
    }

    return retorno;
}

int employee_compareBySalary(void* pElementOne, void* pElementTwo)
{
    int retorno=-1;
    int oneSalary;
    int twoSalary;
    Employee* oneEmployee=(Employee*)pElementOne;
    Employee* twoEmployee=(Employee*)pElementTwo;
    employee_getSueldo(oneEmployee,&oneSalary);
    employee_getSueldo(twoEmployee,&twoSalary);

    if(oneSalary>twoSalary)
    {
        retorno=1;
    }
    else if(oneSalary==twoSalary)
    {
        retorno=0;
    }

    return retorno;
}
