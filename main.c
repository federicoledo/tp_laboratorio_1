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
    if(flagA==0)//Inicializo el valor en A en 0 mientras no se ingrese ningun valor
        num1=0;
    if(flagB==0)//Inicializo el valor de B en 0 mientras no se ingrese ningun valor
        num2=0;
    printf("\nHasta el momento, los numeros ingresados son: \nA:%f\nB:%f\n", num1, num2);
    scanf("%d", &opcion);
    system("cls");
    switch(opcion)
    {
    case 1:
        {
            printf("Ingrese el primer numero\n");
            scanf("%f", &num1);
            flagA=1;
            break;
        }
    case 2:
        {
            printf("Ingrese el segundo numero\n");
            scanf("%f", &num2);
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
                    int aux=(int)num1;
                    if((num1-aux)==0)
                    {
                        resultado=factorial(num1);
                        int res2;
                        res2=(int)resultado;//paso a entero el resultado que es flotante, para que no aparezca ,000000
                        printf("\nEl factorial es %d\n", res2);
                    }
                    else
                        printf("El numero no es entero, por lo tanto no se puede hacer el factorial");
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
                    int aux=(int)num1;
                    if((num1-aux)==0)
                    {
                        resultado=factorial(num1);
                        int res2;
                        res2=(int)resultado;//paso a entero el resultado que es flotante, para que no aparezca ,000000
                        printf("\nEl factorial es %d\n", res2);
                    }
                    else
                        printf("El numero no es entero, por lo tanto no se puede hacer el factorial\n");
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
