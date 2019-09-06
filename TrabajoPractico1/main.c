#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/*
1.Ingresar 1er operando (A=x)
2.Ingresar 2do operando (B=y)
3.Calcular todas las operaciones
    a)Calcular la suma (A+B)
    b)Calcular la resta (A-B)
    c)Calcular la division (A/B)
    d)Calcular la multiplicacion (A*B)
    e)Calcular el factorial (A!)
4.Informar resultados
    a)“El resultado de A+B es: r”
    b)“El resultado de A-B es: r”
    c)“El resultado de A/B es: r” o “No es posible dividir por cero”
    d)“El resultado de A*B es: r”
    e)“El factorial de A es: r1 y El factorial de B es: r2”
5.Salir

•   Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
    que contenga las funciones para realizar las cinco operaciones.

•   En el menú deberán aparecer los valores actuales cargados en los operandos A y B
    (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

•   Deberán contemplarse los casos de error (división por cero, etc)

•   Documentar todas las funciones

*/

int main()
{
    float x=0;
    float y=0;
    int option;

    do
    {

        printf("1.Ingresar 1er operando (A=%.2f)\n",x);
        printf("2.Ingresar 2do operando (B=%.2f)\n",y);
        printf("3.Calcular todas las operaciones\n\ta)Calcular la suma (A+B)\n\tb)Calcular la resta (A-B)\n\tc)Calcular la division (A/B)\n\td)Calcular la multiplicacion (A*B)\n\te)Calcular el factorial (A!)\n");
        printf("4.Informar resultados\n\ta)“El resultado de A+B es: r”\n\tb)“El resultado de A-B es: r”\n\tc)“El resultado de A/B es: r” o “No es posible dividir por cero” \n\td)“El resultado de A*B es: r” \n\te)“El factorial de A es: r1 y El factorial de B es: r2”\n");
        printf("5.Salir\n\n");

        printf("Elija una opcion:");
        scanf("%d",&option);

        switch(option)
        {

        case 1:
            scanf("%f",&x);
            break;
        case 2:
            scanf("%f",&y);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            printf("\tbye bye..");
            break;
        default:
            printf("ERROR. Elija una opcion del 1-5\n");
            break;

        }
        system("clear");

    }
    while(option!=5);











    return 0;
}
