#include "ArraySector.h"
#define TRUE 1
#define FALSE 0

typedef struct
{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

/** \brief To indicate that all position in the array are empty,
 *              this function put the flag (isEmpty) in TRUE in all
 *               position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* listE, int lenEmployee);

/** \brief Agrega un empleado y le asigna un id unico
 *
 * \param listE Employee*
 * \param lenEmployee int
  * \param listS Sector*
 * \param lenSector int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find free space] - (0) if Ok
 *
 */
int addEmployee(eEmployee* listE, int lenEmployee, eSector* listS, int lenSector,int *id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find employees] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* listE, int lenEmployee,eSector* listS, int lenSector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* listE, int lenEmployee,int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return void --
 *
 */
void sortEmployees(eEmployee* listE, int lenEmployee, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee* listE, int lenEmployee,eSector* listS,int lenSector);

/** \brief print one employee
 *
 * \param Employee
 * \return --
 *
 */
void printOneEmploye(eEmployee OneEmployee,eSector OneSector);

/** \brief search a free position of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return(-1) if Error [Invalid length or NULL pointer or if can't find a free position] - (position of employees array) if Ok
 *
 */
int findFree(eEmployee* listE,int lenEmployee);

/** \brief Hardcodea los empleados y por acumula el id
 *
 * \param list Employee*
 * \param len int
 * \param id int*
 * \return void --
 *
 */
void hardcodearEmployees(eEmployee* listE, int lenEmployee,int* id);

/** \brief Modifica el empleado
 *
 * \param listE Employee*
 * \param lenEmployee int
  * \param listS Sector*
 * \param lenSector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find employees] - (0) if Ok - (1) if Cancel modify
 *
 */
int modifyEmployees(eEmployee* listE, int lenEmployee,eSector* listS,int lenSector);

/** \brief Verifica los informes pedidos, el ordenamiento por apellido y sector  y
el total y promedio de salarios
 *
 * \param listE Employee*
 * \param lenEmployee int
  * \param listS Sector*
 * \param lenSector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find employees] - (0) if Ok
 *
 */
int infoEmployees(eEmployee* listE, int lenEmployee,eSector* listS,int lenSector);

/** \brief Acumula el salario de los empleados y devuelve los salarios de los empleados cargados
 *
 * \param listE Employee*
 * \param lenEmployee int
 * \return float return retorna los salarios acumulados
 *
 */
float salarioAcumEmpleados (eEmployee* listE, int lenE);

/** \brief Calcula la cantidad de los empleados dados de alta y los devuelve
 *
 * \param listE Employee*
 * \param lenEmployee int
 * \return int return retorna los cantidad de empleados dados de alta
 *
 */
int cantidadEmpleados(eEmployee* listE,int lenE);

/** \brief Muestra el promedio de los salarios y la cantidad de empleados que superan el mismo
 *
 * \param listE Employee*
 * \param lenE int
  * \param listS Sector*
 * \param lenSr int
 * \return void --
 *
 */
void salarioEmpleados(eEmployee* listE,int lenE,eSector* listS,int lenS);


void mostrar(char mensaje[],eEmployee employee,eSector sector);
