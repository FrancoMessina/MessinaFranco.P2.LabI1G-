#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "parser.h"
#include "input.h"
#include "controller.h"
#include "pelicula.h"
int controller_loadFromText(char* path, LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    FILE* pFile;

    if (path != NULL && pArrayListaPeliculas != NULL)
    {
        system("cls");
        printf("Cargar los datos de los peliculas desde el archivo movies.csv (modo texto).\n");

        pFile = fopen( path, "r");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if (parser_PeliculasFromText(pFile, pArrayListaPeliculas))
            {
                printf( "Carga de archivo de texto exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
int controller_saveAsText(char* path, LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    FILE* pFile;
    int id;
    char titulo[50];
    char genero[50];
    float rating;
    ePelicula* auxPelicula = NULL;
    int tam;
    if (path != NULL && pArrayListaPeliculas != NULL)
    {
        pFile = fopen(path, "w");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }

        fprintf(pFile, "id_peli,titulo,genero,rating\n");
        tam =  ll_len(pArrayListaPeliculas);
        for (int i = 0; i < tam ; i++)
        {
            auxPelicula = ll_get(pArrayListaPeliculas, i);
            if (
                pelicula_getId(auxPelicula,&id)
                && pelicula_getTitulo(auxPelicula,titulo)
                && pelicula_getGenero(auxPelicula,genero)
                && pelicula_getRating(auxPelicula,&rating)
               )
            {
                fprintf(pFile, "%d,%s,%s,%.1f\n", id, titulo, genero, rating);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
int controller_MostrarPeliculas(LinkedList* pArrayListaPeliculas)
{
    ePelicula* pPelicula = NULL;
    int todoOk = 0;
    int tam;

    if(pArrayListaPeliculas != NULL)
    {
        tam =  ll_len(pArrayListaPeliculas);
        system("cls");
        printf("                     ***Lista de Peliculas  ***\n");
        printf("--------------------------------------------------------------------------\n");
        printf(" ID             TITULO                  GENERO                          RATING               \n");
        printf("---------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            pPelicula = ll_get(pArrayListaPeliculas,i);
            pelicula_MostrarPelicula(pPelicula);

        }
        todoOk =1;
    }
    return todoOk;
}
int controller_FiltroDrama(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, pelicula_FiltrarDrama);
        if(controller_MostrarPeliculas(listaFiltrada))
        {
            controller_saveAsText("peliculasDrama.csv", listaFiltrada);
            printf("Archivo generado exitosamente \n");
        }

        todoOk = 1;
    }
    return todoOk;
}
int controller_FiltroComedia(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, pelicula_FiltrarComedia);
        if(controller_MostrarPeliculas(listaFiltrada))
        {
            controller_saveAsText("peliculasComedia.csv", listaFiltrada);
            printf("Archivo generado exitosamente \n");
        }

        todoOk = 1;
    }
    return todoOk;
}
int controller_FiltroAccion(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, pelicula_FiltrarAccion);
        if(controller_MostrarPeliculas(listaFiltrada))
        {
            controller_saveAsText("peliculasAccion.csv", listaFiltrada);
            printf("Archivo generado exitosamente \n");
        }

        todoOk = 1;
    }
    return todoOk;
}
int controller_FiltroTerror(LinkedList* pArrayListaPeliculas)
{
    int todoOk = 0;
    LinkedList* listaFiltrada = NULL;

    if(pArrayListaPeliculas != NULL)
    {
        listaFiltrada = ll_filter(pArrayListaPeliculas, pelicula_FiltrarTerror);
        if(controller_MostrarPeliculas(listaFiltrada))
        {
            controller_saveAsText("peliculasTerror.csv", listaFiltrada);
            printf("Archivo generado exitosamente \n");
        }

        todoOk = 1;
    }
    return todoOk;
}
int controller_sortPeliculas(LinkedList* pArrayListaPeliculas)
{
	int todoOk = 0;
	int criterio = 0; // En el enunciado se pide el criterio descendente hardcodeo.

	if(pArrayListaPeliculas != NULL)
	{
		if(ll_isEmpty(pArrayListaPeliculas) == 0)
		{
			ll_sort(pArrayListaPeliculas, pelicula_SortGeneroRating, criterio);
			todoOk = 1;
		}
	}
    return todoOk;
}
