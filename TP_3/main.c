#include "funciones.h"
int main()
{
    int cont=0, flag=0;
    eMovie* pelicula;
    eMovie* auxP;
    FILE* cartelera;
    FILE* lect;
    int opc;
    cartelera=fopen("Archivo.bin", "w+");
    lect=fopen("Archivo.bin", "r");
    if(lect==NULL)
    {
        printf("No se pudo leer\n");
        exit(1);
    }
    do
    {
        opc=menu();
        switch(opc)
        {
            case 1:
                system("cls");
                cont++;
                if(flag==0)
                {
                    pelicula=(eMovie*)malloc(cont*sizeof(eMovie));
                    if(pelicula==NULL)
                    {
                        printf("No se encontro memoria\n");
                        exit(1);
                    }
                    flag=1;
                }
                else
                {
                    auxP=(eMovie*)realloc(pelicula, cont*sizeof(eMovie));
                    if(auxP==NULL)
                    {
                        printf("No se encontro memoria\n");
                        exit(1);
                    }
                    pelicula=auxP;
                }
                ingresar(pelicula, cont);
                break;
            case 2:
                system("cls");
                if(cont==0)
                {
                    printf("No hay peliculas ingresadas\n");
                    break;
                }
                borrar(pelicula, cont);
                auxP=(eMovie*)realloc(pelicula, cont*sizeof(eMovie));
                if(auxP==NULL)
                {
                    printf("No se encontro lugar\n");
                    exit(1);
                }
                cont--;
                break;
            case 3:
                system("cls");
                if(cont==0)
                {
                    printf("No hay peliculas ingresadas\n");
                    break;
                }
                modificar(pelicula, cont);
                break;
            case 4:
                system("cls");
                if(cont==0)
                {
                    printf("No hay peliculas ingresadas\n");
                    break;
                }
                generarWeb(pelicula, cont);
                break;
            case 5:
                system("cls");
                printf("Gracias por utilizar el programa\n");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n");
        }
    }while(opc!=5);
    fclose(cartelera);
    fclose(lect);
    free(pelicula);
    return 0;
}
