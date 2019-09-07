#include <stdio.h>
#include <stdlib.h>

/** \brief  Calcula todas las operaciones registradas y devuleve con punteros sus resultados
 *
 * \param float Numero por el cual las operaciones van a funcionar
 * \param float Segundo numero que permite realizar las operaciones
 * \param float* guardo la suma en una variable usando puntero para luego mostrarla
 * \param float* guardo la resta en un variable usando puntero para luego mostarla
 * \param float* guardo la divicion en un variable usando puntero para luego mostarla
 * \param float* guardo la multiplicacion en un variable usando puntero para luego mostarla
 * \param int* guardo el factorial del primer numero en un variable usando puntero para luego mostarla
 * \param int* guardo el factorial del segundo numero en un variable usando puntero para luego mostarla
 * \return void
 *
 */
void calcularOperaciones(float, float, float*, float*, float* ,float*, int*, int*);

/** \brief Muestro todos las Operaciones Realizadas( suma, resta, divicion, multiplicacion, factorial)
 *
 * \param float recibo la suma para mostrarla
 * \param float recibo la resta realizada para mostarla
 * \param float recibo la divicion calculada para mostarla
 * \param float recibo la multiplicacion para mostrarla
 * \param int  recibo el factorial del primer numero para mostarlo
 * \param int recibo el factorial del segundo numero para mostarlo
 * \return void
 *
 */
void mostrarResultados(float, float, float, float, int, int);

/** \brief Pido un numero
 *
 * \param float* guardo el numero ingresado utilizando punteros
 * \return void
 *
 */
void PedirNumero(float*);

/** \brief Muestro el menu en una funcion
 *
 * \return void
 *
 */
void menu();

/** \brief Realizo una pausa en la pantalla
 *
 * \return void
 *
 */
void pausa();

/** \brief Realizo un clear de la pantalla
 *
 * \return void
 *
 */
void borrar();
