#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
#include "calculadora.c"


int main()
{
     float ope1=0, ope2=0, resSuma, resResta, resMulti, resDivi;
        int opcion, flag=0, resFacA, resFacB, vandera=0;

    do
    {


        printf("\nMenu");
        printf("\n\n1. Ingresar primer operando:(A=0).2f",ope1);
        printf("\n2. Ingresar segundo operando:(B=0).2f",ope2);
        printf("\n3. Calcular todas las operaciones.");
        printf("\n4. Informar resultados.");
        printf("\n5. Salir.");
        scanf("%d",&opcion);

        switch(opcion)
        {

        case 1:
               system("cls");
               printf("\n Ingrese un numero:");
               scanf("%f",&ope1);
               break;
        case 2:
               system("cls");
               printf("\n Ingrese un numero:");
               scanf("%f",&ope2);
               vandera=1;
               break;
        case 3:
               system("cls");
               resSuma= suma(ope1, ope2);
               resResta= resta(ope1, ope2);
               resMulti= multiplicacion(ope1,ope2);
               if(ope2 != 0)
               {
                   resDivi= division(ope1,ope2);
               }
               else
               {
                   flag= 1;
               }
               resFacA= factorial((int) ope1);
               resFacB= factorial((int) ope2);
               break;
        case 4:
               system("cls");
               printf("\na_ Resultado de A+B:%.2f", resSuma);
               printf("\nb_ Resultado de A-B:%.2f", resResta);
               printf("\nc_ Resultado de A*B:%.2f", resMulti);
               if(flag==1)
               {
                   printf("\nd_ Resultado de A/B: Error.");
               }
               else if(ope1 ==0 && ope2 ==0)
               {
                   printf("\nd_ Resultado de A/B: Error.");
               }
               else
               {
                    printf("\nd_ Resultado de A/B:%.2f",resDivi);
               }
               printf("\ne_ El factorial de A es:%d y el factorial de B es:%d", resFacA,resFacB);
               break;
        case 5:
               system("cls");
               break;
        default:
                system("cls");
                printf("\n La opcion ingresada es incorrecta.");
                break;
        }
    } while(opcion!=5);

    return 0;

}
