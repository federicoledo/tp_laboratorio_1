#include "funciones.h"
/** \brief Funcion que muestra un menu para que el usuario escoja la opcion que desee
 *
 * \return int Devuelve el numero de la opcion escogida
 *
 */
int menu()
{
    int opc;
    printf("Que desea realizar?\n1.Agregar pelicula\n2.Borrar pelicula\n3.Modificar pelicula\n4.Generar pagina web\n5.Salir\n");
    scanf("%d", &opc);
    return opc;
}
/** \brief Funcion que ingresa una nueva pelicula
 *
 * \param pelicula eMovie* Estructura que tiene los distintos elementos a ingresar
 * \param cont int Posicion donde se guardara el dato
 * \return void No devuelve nada
 *
 */
void ingresar(eMovie* pelicula, int cont)
{
    int largo;
    char aux[400];
    printf("Ingrese el titulo\n");
    fflush(stdin);
    gets(aux);
    largo=strlen(aux)+1;
    while(largo>400)
    {
        printf("Error, excedio el numero maximo de caracteres posible(399), reingrese por favor\n");
        gets(aux);
        largo=strlen(aux+1);
    }
    (pelicula+cont-1)->titulo=(char*)malloc(sizeof(char)*largo);
    strcpy((pelicula+cont-1)->titulo, aux);
    printf("Ingrese el genero\n");
    fflush(stdin);
    gets(aux);
    largo=strlen(aux)+1;
    while(largo>400)
    {
        printf("Error, excedio el numero maximo de caracteres posible(399), reingrese por favor\n");
        gets(aux);
        largo=strlen(aux+1);
    }
    (pelicula+cont-1)->genero=(char*)malloc(sizeof(char)*largo);
    strcpy((pelicula+cont-1)->genero, aux);
    printf("Ingrese la descripcion\n");
    fflush(stdin);
    gets(aux);
    largo=strlen(aux)+1;
    while(largo>400)
    {
        printf("Error, excedio el numero maximo de caracteres posible(399), reingrese por favor\n");
        gets(aux);
        largo=strlen(aux+1);
    }
    (pelicula+cont-1)->descripcion=(char*)malloc(sizeof(char)*largo);
    strcpy((pelicula+cont-1)->descripcion, aux);
    printf("Ingrese el duracion(en minutos)\n");
    scanf("%d", &(pelicula+cont-1)->duracion);
    while((pelicula+cont-1)->duracion<0)
    {
        printf("Error, la duracion debe ser positiva\n");
        scanf("%d", &(pelicula+cont-1)->duracion);
    }
    printf("Ingrese el puntaje, valores validos de 1 a 10 estrellas(en el caso de ingresar numeros decimales se tomara la parte entera solamente\n");
    scanf("%d", &(pelicula+cont-1)->puntaje);
    while((pelicula+cont-1)->puntaje<0||(pelicula+cont-1)->puntaje>10)
    {
        printf("El puntaje no puede ser negativo y no puede ser mayor que 10.En el caso de ingresar numeros decimales se tomara la parte entera solamente\n");
        scanf("%d", &(pelicula+cont-1)->puntaje);
    }
    printf("Ingrese el link de imagen\n");
    fflush(stdin);
    gets(aux);
    largo=strlen(aux)+1;
    while(largo>400)
    {
        printf("Error, excedio el numero maximo de caracteres posible(399), reingrese por favor\n");
        gets(aux);
        largo=strlen(aux+1);
    }
    (pelicula+cont-1)->link=(char*)malloc(sizeof(char)*largo);
    strcpy((pelicula+cont-1)->link, aux);
}
/** \brief Funcion que modifica una pelicula
 *
 * \param M eMovie* Estructura que contiene los distintos tipos de datos
 * \param largo int Lugar donde se va a modificar
 * \return void No devuelve nada
 *
 */
void modificar(eMovie* M, int largo)
{
    char aux[50];
    int i;
    for(i=0; i<largo; i++)
    {
        printf("%s\n", (M+i)->titulo);
    }
    printf("Ingrese el titulo de la pelicula que desee modificar\n");
    fflush(stdin);
    gets(aux);
    for(i=0; i<largo; i++)
    {
        if(strcmp(aux, (M+i)->titulo)==0)
        {
            ingresar(M, i+1);
        }
    }
}
/** \brief Funcion que borra una pelicula
 *
 * \param M eMovie* Estructura que contiene los datos de la pelicula que va a ser eliminada
 * \param largo int Cantidad de valores que tiene el vector estructura, para realizar el burbujeo
 * \return void No devuelve nada
 *
 */
void borrar(eMovie* M, int largo)
{
    int i, j;
    char aux[50];
    eMovie* auxPeli;
    for(i=0; i<largo; i++)
    {
        printf("%s\n", (M+i)->titulo);
    }
    printf("Ingrese el titulo de la pelicula que desee borrar\n");
    fflush(stdin);
    gets(aux);
    for(i=0; i<largo-1; i++)
    {
        for(j=i+1; j<largo; j++)
        {
            if(strcmp((M+i)->titulo, aux)==0)
            {
                *auxPeli=*(M+i);
                *(M+i)=*(M+j);
                *(M+j)=*auxPeli;
            }
        }
    }
}
/** \brief Funcion que genera una pagina web
 *
 * \param M eMovie* Tipo de dato que genera la pagina web
 * \param largo int cantidad de veces que se generara la pagina web
 * \return void No devuelve nada
 *
 */
void generarWeb(eMovie* M, int largo)
{
    FILE* parch;
    int i;
    for(i=0; i<largo; i++)
    {
        parch=fopen("Web.html", "a+");
        if(parch==NULL)
        {
            printf("No se pudo crear\n");
            exit(1);
        }
        fprintf(parch, "<article class='col-md-4 article-intro'>");
        fprintf(parch, "<a href='#'>");
        fprintf(parch, "<img class='img-responsive img-rounded' src='%s'", (M+i)->link);
        fprintf(parch, "alt=''>");
        fprintf(parch, "</a>");
        fprintf(parch, "<h3>");
        fprintf(parch, "<a href='#'>%s</a>", (M+i)->titulo);
        fprintf(parch, "</h3>");
        fprintf(parch, "<ul>");
        fprintf(parch, "<li>Género:%s</li>", (M+i)->genero);
        fprintf(parch, "<li>Puntaje:%d</li>", (M+i)->puntaje);
        fprintf(parch, "<li>Duración:%d</li>", (M+i)->duracion);
        fprintf(parch, "</ul>");
        fprintf(parch, "<p>%s</p>", (M+i)->descripcion);
        fprintf(parch, "</article>");
    }
    fclose(parch);
}
