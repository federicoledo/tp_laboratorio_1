#include <stdio.h>
#include <stdlib.h>
#include"misFunciones.h"
int main()
{
    int opcion, flagA=0, flagB=0;
    float resultado, num1, num2;
    printf("\n\t\t\tBienvenido a Calculadora\n\n");
    do
    {
    printf("Elegir la opcion que desea\n\n1.Ingresar el primer numero\n2.Ingresar el segundo numero\n3.Suma\n4.Resta\n5.Producto\n6.Cociente\n7.Factorial\n8.Todas las operaciones\n9.Salir\n");
    printf("\nHasta el momento, los numeros ingresados son: \nA:%f\nB:%f\n", num1, num2);
    scanf("%d", &opcion);
    system("cls");
    switch(opcion)
    {
    case 1:
        {
            ingreso(num1);
            flagA=1;
            break;
        }
    case 2:
        {
            ingreso(num2);
            flagB=1;
            break;
        }
    case 3:
        {
            if(flagA==0||flagB==0)
                printf("No ingreso los dos numeros, verifique el ingreso\n");
            else
                {
                    resultado=suma(num1,num2);
                    printf("\nLa suma es %f ", resultado);
                }
            break;
        }
    case 4:
        {
            if(flagA==0||flagB==0)
                printf("No ingreso los dos numeros, verifique el ingreso\n");
            else
            {
                resultado=resta(num1,num2);
                printf("\nLa resta es %f ", resultado);
            }
        break;
        }
    case 5:
        {
            if(flagA==0||flagB==0)
                printf("No ingreso los dos numeros, verifique el ingreso\n");
            else
            {
                resultado=producto(num1,num2);
                printf("\nEl producto es %f ", resultado);
            }
        break;
        }
    case 6:
        {
            if(flagA==0||flagB==0)
               {
                    printf("No ingreso los dos numeros, verifique el ingreso\n");
                    break;
                }
            else
                {
                    if(num2==0)
                        {
                            printf("\nError, no se puede dividir por '0'");
                            break;
                        }
                        else
                        {
                            resultado=division(num1,num2);
                            printf("\nLa division es %f ", resultado);
                            break;
                        }
                }
        }
    case 7:
        {
            if(flagA==0)
                printf("No ingreso el primer numero, verifique el ingreso\n");
            else
                {
                    resultado=factorial(num1);
                    printf("\nEl factorial es %f", resultado);
                }
        break;
        }
    case 8:
        {
            if(flagA==0||flagB==0)
            {
                printf("No ingreso los dos numeros, verifique el ingreso\n");
                break;
            }
            else
            {
                resultado=suma(num1,num2);
                printf("\nLa suma es %f ", resultado);
                resultado=resta(num1,num2);
                printf("\nLa resta es %f ", resultado);
                resultado=producto(num1,num2);
                printf("\nEl producto es %f ", resultado);
                if(num2==0)
                    {
                        printf("\nError, no se puede dividir por '0'");
                    }
                else
                    {
                        resultado=division(num1,num2);
                        printf("\nLa division es %f ", resultado);
                    }
                resultado=factorial(num1);
                printf("\nEl factorial es %f\n\n", resultado);
            }
        break;
        }
    case 9:
        {
            printf("Gracias por utilizar el programa\n");
            break;
        }
    default:
        printf("Error al ingresar la opcion\n");
    }
    }while(opcion!=9);
return 0;
}
