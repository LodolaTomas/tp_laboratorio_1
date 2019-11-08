#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
} Employee;

Employee* employee_new();

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
void employee_ShowOneEmployee(Employee* this);
int employee_ModifyEmployee(Employee* this);
void employee_showEmployee(Employee oneEmployee);
int employee_compareById(void* pElementOne, void* pElementTwo);
int employee_compareByName(void* pElementOne, void* pElementTwo);
int employee_compareByHoursWorked(void* pElementOne, void* pElementTwo);
int employee_compareBySalary(void* pElementOne, void* pElementTwo);


#endif // employee_H_INCLUDED
