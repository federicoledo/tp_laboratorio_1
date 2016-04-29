#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    ePersona persona[20];
    int opcion, indice, ord;
    inicializacion(persona, 20);
    do
    {
        printf("Que desea realizar?\n1.Agregar una persona\n2.Borrar una persona\n3.Imprimir lista ordenada por nombre\n4.Imprimir grafico de edades\n5.Salir\n\n");
        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            indice= buscarlibre(persona, 20);
            if(indice<0)
                {
                    printf("Error, no hay espacios libres\n");
                    break;
                }
            else
                {
                    ingresarPersona(persona, indice);
                    break;
                }
        case 2:
            borrarPersona(persona, 20);
            break;
        case 3:
            printf("\nComo desea ordenarlo?\n1.De A a Z\n2.De Z a A\n");
            scanf("%d", &ord);
            if(ord==1)
            {
                ordenarAtoZ(persona, 20);
                mostrarLista(persona, 20);
                break;
            }
            else
            {
                if(ord==2)
                    {
                        ordenarZtoA(persona, 20);
                        mostrarLista(persona, 20);
                        break;
                    }
                    else
                        {
                            printf("\nOpcion no valida\n");
                            break;
                        }
            }
        case 4:
            graficoEdades(persona, 20);
            break;
        }
    }while(opcion!=5);
    return 0;
}

