typedef struct ePersona
{
    char nombre[20];
    int edad;
    int dni;
    int estado;
}ePersona;
void inicializacion(ePersona x[], int TAM);
int buscarlibre(ePersona x[], int TAM);
void ingresarPersona(ePersona x[], int TAM);
void mostrarLista(ePersona x[], int TAM);
void ordenarZtoA(ePersona x[], int TAM);
void ordenarAtoZ(ePersona x[], int TAM);
void borrarPersona(ePersona x[], int TAM);
void graficoEdades(ePersona x[], int TAM);
