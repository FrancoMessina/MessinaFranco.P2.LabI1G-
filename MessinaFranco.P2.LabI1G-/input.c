#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ingresarString(char mensaje[], char dato[])
{
	int todoOk = 0;

	    if(mensaje != NULL && dato !=NULL)
	    {
	        printf("%s", mensaje);
	        fflush(stdin);
	        gets(dato);

	        todoOk = 1;
	    }

	    return todoOk;
}
int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);

    scanf("%d",&numeroIngresado);

    return numeroIngresado;

}
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior)
{
    int todoOk = 0;
    if(valor >= limiteInferior && valor <= limiteSuperior )
    {
        todoOk = 1;
    }
    return todoOk;
}
int stringPrimerLetraMayuscula(char string[])
{
    int todoOk = 0;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);
        while(string[i] != '\0')
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

            i++;
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarLargoString(char string[], int min , int max)
{
	int todoOk = 0;
	if(string != NULL)
	{

		if(strlen(string) < min || strlen(string) > max)
		{
			todoOk = 1;
		}

	}
	return todoOk;

}

int verificarSiContieneNumero(char list[])
{
    int todoOk = 0;
    if(list!= NULL)
    {
    	for (int i = 0; i < strlen(list); i++)
    	{
    		if(!(isalpha(list[i])) && list[i] != ' ')
    		{
    			todoOk = 1;
    			break;
    		}
    	}

    }

    return todoOk;
}
int menuOpcion()
{
    printf("-------------------------------\n");
	printf("  *** PELICULAS ***\n\n");
	printf("-------------------------------\n");
	int opcion;
	system("cls");
	printf("[1]CARGAR ARCHIVO MOVIES.CSV (Modo Texto)\n");
	printf("[2]IMPRIMIR LISTA\n");
	printf("[3]ASIGNAR RATING\n");
	printf("[4]ASIGNAR GENERO\n");
	printf("[5]FILTRAR POR GENERO \n");
	printf("[6]ORDENAR PELICULAS \n");
	printf("[7]GUARDAR PELICULAS \n");
	printf("[8]SALIR\n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
int menuDeGeneros()
{
    int opcion;

    system("cls");
    printf("                *** Menu de generos para filtrar y generar un archivo ***                     \n");
    printf("----------------------------------------------------------------------\n");
    printf("[1]DRAMA\n");
	printf("[2]COMEDIA\n");
	printf("[3]ACCION\n");
	printf("[4]TERROR\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
