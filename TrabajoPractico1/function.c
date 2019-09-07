#include "functions.h"
#include "mathematicalOperations.h"

void menu()
{

    float x=0;
    float y=0;
    int option;
    float suma=0;
    float resta;
    float multiplicacion;
    float divicion;
    int factorialA;
    int factorialB;

    int flag=0;
    int flag1=0;
    int flag2=0;

    do
    {

        printf("1.Ingresar 1er operando (A=%.2f)\n",x);
        printf("2.Ingresar 2do operando (B=%.2f)\n",y);
        printf("3.Calcular todas las operacione\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n\n");

        printf("Elija una opcion:");
        scanf("%d",&option);

        switch(option)
        {

        case 1:
            PedirNumero(&x);
            flag=1;
            break;
        case 2:
            PedirNumero(&y);
            flag1=1;
            break;
        case 3:
            if(flag1!=1 && flag!=1)
            {
                printf("\nERROR. DEBE INGRESAR LOS DOS NUMERO ANTES DE CALCULAR ALGO..\n");
            }
            else
            {
                borrar();
                calcularOperaciones(x,y,&suma,&resta,&multiplicacion,&divicion,&factorialA,&factorialB);
                flag2=1;
                pausa();
            }
            break;
        case 4:
            if(flag1!=1 && flag!=1)
            {
                printf("\nERROR. DEBE INGRESAR LOS DOS NUMERO ANTES DE MOSTRAR ALGO..\n");
            }
            else if(flag2==1)
            {
                borrar();
                mostrarResultados(suma,resta,divicion,multiplicacion,factorialA,factorialB);
                pausa();
            }
            else
            {
                printf("\nERROR. DEBE CALCULAR LOS NUMEROS ANTES DE PODER MOSTRARLOS..\n");
            }

            break;
        case 5:
            printf("\nHASTA LUEGO..\n");
            break;
        default:
            printf("ERROR. Elija una opcion del 1-5\n");
            break;

        }
        borrar();

    }
    while(option!=5);
}

void calcularOperaciones(float numero1, float numero2, float* suma, float* resta, float* div,float* multiplcacion, int* factorialA, int* factorialB)
{
    printf("Calculando Operaciones Matematicas\n");

    if(sumador(numero1,numero2,suma))
    {
        printf("\ta)Calculada la suma (A+B).\n");
    }
    if(restador(numero1,numero2,resta))
    {
        printf("\tb)Calculada la resta (A-B)\n");
    }
    if(divicion(numero1,numero2,div))
    {
        printf("\tc)Calculada la division (A/B).\n");
    }
    else
    {

        printf("\tc)Error. Division no calculada (No se puede dividir por 0)\n");
        *div=0;

    }
    if(multiplicador(numero1,numero2,multiplcacion))
    {
        printf("\td)Calculada la multiplicacion (A*B)\n");
    }
    if(factorial(numero1,factorialA))
    {
        printf("\te)Calculado el factorial (A!)\n");
    }
    if(factorial(numero2,factorialB))
    {
        printf("\te)Calculado el factorial (B!)\n");
    }



}

void mostrarResultados(float suma, float resta, float divicion, float multiplicacion, int factorialA, int factorialB)
{
    printf("\n\ta)El resultado de A+B es: %.2f\n",suma);
    printf("\tb)El resultado de A-B es: %.2f\n",resta);
    printf("\tc)El resultado de A/B es: %.2f\n",divicion);
    printf("\td)El resultado de A*B es: %.2f\n",multiplicacion);
    printf("\te)El factorial de A es: %d y El factorial de B es: %d\n",factorialA,factorialB);

}
void PedirNumero(float* numero)
{
    printf("Ingrese el Numero:");
    scanf("%f",numero);
}

void pausa(int option)
{
    /*if(option==1)
    {
    system("read -p 'Press Enter to continue...' var");
    }
    else
    {
        system("pause");
    }*/
    system("read -p 'Press Enter to continue...' var");

}
void borrar(int option)
{
    /*if(option==1)
    {
    system("clear");
    }else
    {
    system("cls");
    }*/
    system("clear");
}
