#include "mathematicalOperations.h"


int sumador(float number1, float number2, float* sum)
{
    int state=1;

    *sum=number1+number2;

    return state;
}
int divicion(float number1, float number2, float* div)
{
    int state=1;
    if(number2==0)
    {

        state=0;

    }
    else
    {

        *div=number1/number2;

    }
    return state;
}
int factorial(float number,int* factorial)
{
    int i,state=1;

    if(number==0)
    {
        *factorial=1;
    }
    else
    {
        *factorial=1;

        for(i=1; i<=(int)number; i++)
        {

            *factorial=*factorial * i;
        }

    }

    return state;
}
int restador(float number1, float number2,float* res)
{
    int state=1;

    *res=number1-number2;

    return state;
}
int multiplicador(float number1, float number2, float* mul)
{
    int state=1;

    *mul=number1*number2;

    return state;
}
