#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
typedef struct
{
    char* titulo;
    char* genero;
    char* descripcion;
    int* puntaje;
    int* duracion;
    char* link;
}eMovie;
int menu();
void modificar(eMovie* M, int largo);
void ingresar(eMovie* pelicula, int cont);
void borrar (eMovie* M, int largo);
void generarWeb(eMovie* M, int largo);
