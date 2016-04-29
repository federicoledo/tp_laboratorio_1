typedef struct ePersona
{
    char nombre[20];
    int edad;
    int dni;
    int estado;
}ePersona;

/** \brief Funcion que inicializa todos los valores del vector
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return void No devuelve nada
 *
 */
void inicializacion(ePersona x[], int TAM)
{
    int i;
    for(i=0; i<TAM; i++)
        {
            x[i].estado=-1;
            x[i].dni=-1;
        }
}
/** \brief Funcion que buscar el primer indice disponible para guardar un usuario
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return int Devuelve el indice del vector donde se va a guardar el siguiente usuario
 *
 */
int buscarlibre(ePersona x[], int TAM)
{
    int i, aux=-1;
    for(i=0; i<TAM; i++)
        {
            if(x[i].estado==-1)
            {
                aux=i;
                x[i].estado=1;
                break;
            }
        }
    return aux;
}
/** \brief Funcion que agrega una nueva persona
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return void No devuelve nada
 *
 */
void ingresarPersona(ePersona x[], int TAM)
{
    printf("\nIngrese el nombre\t");
    fflush(stdin);
    gets(x[TAM].nombre);
    printf("\nIngrese el dni\t");
    scanf("%d", &x[TAM].dni);
    printf("\nIngrese la edad\t");
    scanf("%d", &x[TAM].edad);
    x[TAM].estado=1;
    int i;
    for(i=0; i<TAM; i++)
        {
            if((x[i].dni)==(x[TAM].dni))
                {
                    printf("Es la misma persona\n");
                    x[i].estado=-1;
                }
        }
}
/** \brief Funcion que muestra la lista de usuarios ingresados hasta el momento
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return void No devuelve nada
 *
 */
void mostrarLista(ePersona x[], int TAM)
{
    int i;
    for(i=0; i<TAM; i++)
        {
            if(x[i].estado>0)
                {
                    printf("El nombre es %s, su dni es %d y su edad es %d\n", x[i].nombre, x[i].dni, x[i].edad);
                }
        }
}
/** \brief Funcion que ordena alfabeticamente(Z-A) los usuarios ingresados
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return void No devuelve nada
 *
 */
void ordenarZtoA(ePersona x[], int TAM)
{
    int i, j;
    ePersona aux;
    aux.estado=1;
    for(i=0; i<TAM; i++)
        {
            if(x[i].estado>0&&x[i].dni>0)
                {
                    for(i=0; i<TAM-1; i++)
                        {
                            for(j=i+1; j<TAM; j++)
                                {
                                    if((stricmp(x[i].nombre, x[j].nombre))<0)
                                        {
                                            aux=x[i];
                                            x[i]=x[j];
                                            x[j]=aux;
                                        }
                                }
                        }
                }
        }
}
/** \brief Funcion que ordena alfabeticamente(A-Z) los usuarios ingresados hasta el momento
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return void No devuelve nada
 *
 */
void ordenarAtoZ(ePersona x[], int TAM)
{
    int i, j;
    ePersona aux;
    for(i=0; i<TAM; i++)
        {
            if(x[i].dni>0)
                {
                    for(i=0; i<TAM-1; i++)
                        {
                            for(j=i+1; j<TAM; j++)
                                {
                                    if((stricmp(x[i].nombre, x[j].nombre))>0)
                                        {
                                            aux=x[i];
                                            x[i]=x[j];
                                            x[j]=aux;
                                        }
                                }
                        }
                }
        }
}
/** \brief Funcion que borra una persona
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return void No devuelve nada
 *
 */
void borrarPersona(ePersona x[], int TAM)
{
    int i, borrar;
    for(i=0; i<TAM; i++)
    {
        if(x[i].estado<0)
        {
            printf("No hay personas cargadas\n");
            break;
        }
        else
        {
            printf("\nIngrese el numero de la persona que desea borrar\n");
            for(i=0; i<TAM; i++)
                {
                    if(x[i].estado>0)
                        {
                            printf("%d.%s\n",i, x[i].nombre);
                        }
                }
            fflush(stdin);
            scanf("%d", &borrar);
            for(i=0; i<TAM; i++)
            {
                if(i==borrar)
                    {
                        x[i].estado=-1;
                        printf("La operacion ha ocurrido con exito\n");
                        break;
                    }
                if(i==TAM&&i!=borrar)
                    {
                        printf("Ha ocurrido un error\n");
                    }
            }
        }
    }
}
/** \brief Funcion que muestra el grafico de edades
 *
 * \param x[] ePersona Vector de tipo ePersona
 * \param TAM int Cantidad de elementos que puede tener el vector
 * \return void No devuelve nada
 *
 */
void graficoEdades(ePersona x[], int TAM)
{
    int i, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;
    for(i=0; i<TAM; i++)
    {
        if(x[i].estado>0)
        {
            if(x[i].edad<18)
            {
                hasta18++;
            }
            else
            {
                if(x[i].edad>35)
                {
                    mayorDe35++;
                }
                else
                    {
                        de19a35++;
                    }
            }
        }
    }
        if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
        {
            mayor = hasta18;
        }
        else
        {
            if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
            {
                mayor = de19a35;
            }
            else{
            mayor = mayorDe35;
            }
        }
        for(i=mayor; i>0; i--)
        {
            if(i<20)
            {
                printf("%02d|",i);
            }
            else
                printf("%02d|",i);
            if(i<= hasta18)
            {
                printf("*");
            }
            if(i<= de19a35)
            {
                flag=1;
                printf("\t*");
            }
            if(i<= mayorDe35)
            {
                if(flag==0)
                    printf("\t\t*");
                if(flag==1)
                    printf("\t*");
            }
            printf("\n");
        }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
}

