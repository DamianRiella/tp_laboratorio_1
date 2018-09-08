/* Funciones de SUMA, RESTA, MULTIPLICACION, DIVICION, FACTORIAL*/

int factorial(int num)
{
    int contador,acumuladorUno=0;
if(num<0)
{
    return -1;

}
else
{
    if(num==0 || num==1)
    {
        return 1;
    }
    else
    {
        for(contador=num-1; contador!=0; contador--)
        {
            acumuladorUno= num*contador+acumuladorUno;
        }

    }
    return acumuladorUno;
}

}



float suma(float num1, float num2)
{
    int resultado;
    resultado= num1 + num2;
    return resultado;
}

float resta(float num1, float num2)
{
    int resultado;
    resultado= num1 - num2;
    return resultado;
}

float multiplicacion(float num1, float num2)
{
    int resultado;
    resultado= num1 * num2;
    return resultado;
}
float division(float num1, float num2)
{
    int resultado;
    resultado= num1 / num2;
    return resultado;
}
