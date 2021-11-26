#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pelicula.h"
#include "input.h"


ePelicula* newPelicula()
{

	ePelicula* nuevaPelicula =  (ePelicula*)malloc(sizeof(ePelicula));
    if(nuevaPelicula != NULL )
    {
        nuevaPelicula->id_peli = 0;
        strcpy(nuevaPelicula->titulo," ");
        strcpy(nuevaPelicula->genero," ");
        nuevaPelicula->rating = 0;
    }
    return nuevaPelicula;
}
ePelicula* pelicula_NewParametros(char* idStr,char* tituloStr,char* generoStr,char* ratingStr)
{
	ePelicula* pPelicula = newPelicula();
	    if(pPelicula != NULL)
	    {
	        if(!(pelicula_setId(pPelicula,atoi(idStr))
                && pelicula_setTitulo(pPelicula,tituloStr)
                && pelicula_setGenero(pPelicula,generoStr)
                && pelicula_setRating(pPelicula,atof(ratingStr)))
            ){

	                free(pPelicula);
	                pPelicula = NULL;

	        }
	    }
	    return pPelicula;
}

int pelicula_setId(ePelicula* this,int id)
{

	int todoOk = 0;
	if(this != NULL && id > 0)
	{
		this->id_peli = id;
		todoOk = 1;
	}
	return todoOk;
}
int pelicula_getId(ePelicula* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL && id >= 0)
	{
		*id = this->id_peli;
		todoOk = 1;
	}
	return todoOk;
}
int pelicula_setTitulo(ePelicula* this,char* titulo)
{
    int todoOk = 0;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo,titulo);
        todoOk = 1;
    }
    return todoOk;
}
int pelicula_getTitulo(ePelicula* this,char* titulo)
{
    int todoOk = 0;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }
    return todoOk;
}


int pelicula_setGenero(ePelicula* this,char* genero)
{
    int todoOk = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero,genero);
        todoOk = 1;
    }
    return todoOk;
}
int pelicula_getGenero(ePelicula* this,char* genero)
{
    int todoOk = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }
    return todoOk;
}


int pelicula_setRating(ePelicula* this,float rating)
{

	int todoOk = 0;
	if(this != NULL)
	{
		this->rating = rating;
		todoOk = 1;
	}
	return todoOk;
}
int pelicula_getRating(ePelicula* this,float *rating)
{
	int todoOk = 0;
	if(this != NULL && rating != NULL)
	{
		*rating = this->rating;
		todoOk = 1;
	}
	return todoOk;
}


void pelicula_Delete(ePelicula* this)
{
	if(this!= NULL)
	{
		free(this);
	}

}
int pelicula_MostrarPelicula(ePelicula* unaPelicula)
{
    int id_peli;
    char titulo[50];
    char genero[50];
    float rating;
    int todoOk = 0;
    if(unaPelicula != NULL &&
       pelicula_getId(unaPelicula,&id_peli)
       && pelicula_getTitulo(unaPelicula,titulo)
       && pelicula_getGenero(unaPelicula,genero)
       && pelicula_getRating(unaPelicula,&rating)
            )
    {

        printf("%-15d%-16s %-20s%-.2f \n",id_peli,titulo,genero,rating);
        todoOk = 1;
    }
    return todoOk;
}
void* asignarRanking(void* pPelicula)
{
    ePelicula* aux = NULL;
    int minRanking = 10;
    int maxRanking = 100;
    float numero;
    if(pPelicula != NULL)
    {
        aux = (ePelicula*) pPelicula;
        numero = (float) (rand() % (maxRanking - minRanking + 1 ) + minRanking) / 10;
        aux->rating = numero;
    }
    return aux;
}
void* asignarGenero(void* pPelicula)
{
    ePelicula* aux = NULL;
    int minGenero = 1;
    int maxGenero = 4;
    int numero;
    if(pPelicula != NULL)
    {
        aux = (ePelicula*) pPelicula;
        numero = rand() % (maxGenero - minGenero + 1 ) + minGenero;
        switch(numero)
        {
        case 1:
            strcpy(aux->genero,"Drama");
            break;
        case 2:
            strcpy(aux->genero,"Comedia");
            break;
        case 3:
            strcpy(aux->genero,"Accion");
            break;
        case 4:
            strcpy(aux->genero,"Terror");
            break;
        }
    }
    return aux;
}
int pelicula_FiltrarDrama(void* pPelicula)
{
    int todoOk = 0;
	ePelicula* aux = NULL;
	aux = (ePelicula*)pPelicula;
	char generoDrama[20] = {"Drama"};
	if(aux != NULL)
	{
		if (strcmp(aux->genero, generoDrama) == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}
int pelicula_FiltrarComedia(void* pPelicula)
{
    int todoOk = 0;
    ePelicula* aux = NULL;
    aux = (ePelicula*)pPelicula;
    char generoComedia[20] = {"Comedia"};
    if(aux != NULL)
    {
        if (strcmp(aux->genero, generoComedia) == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int pelicula_FiltrarAccion(void* pPelicula)
{
    int todoOk = 0;
    ePelicula* aux = NULL;
    aux = (ePelicula*)pPelicula;
    char generoAccion[20] = {"Accion"};
    if(aux != NULL)
    {
        if (strcmp(aux->genero, generoAccion) == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int pelicula_FiltrarTerror(void* pPelicula)
{
    int todoOk = 0;
    ePelicula* aux = NULL;
    aux = (ePelicula*)pPelicula;
    char generoTerror[20] = {"Terror"};
    if(aux != NULL)
    {
        if (strcmp(aux->genero, generoTerror) == 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int pelicula_SortGeneroRating(void* pElementUno, void* pElementDos)
{
    int todoOk = 0;
    ePelicula* peliculaUno = NULL;
    ePelicula* peliculaDos = NULL;
    float ratingUno;
    float ratingDos;
    char generoUno[20];
    char generoDos[20];
    peliculaUno = (ePelicula*) pElementUno;
    peliculaDos = (ePelicula*) pElementDos;
    if(pElementUno != NULL && pElementDos != NULL)
    {
        pelicula_getGenero(peliculaUno, generoUno);
        pelicula_getGenero(peliculaDos, generoDos);
        pelicula_getRating(peliculaUno,&ratingUno);
        pelicula_getRating(peliculaDos,&ratingDos);
        if(strcmp(generoUno, generoDos) < 0 )
        {
            todoOk = 1;
        }
        else
        {
            if(strcmp(generoUno, generoDos) > 0)
            {
                todoOk = -1;
            }
            else
            {
                if(ratingUno > ratingDos)
                {
                    todoOk = 1;
                }
                else
                {
                    if(ratingUno < ratingDos)
                    {
                        todoOk = -1;
                    }

                }
            }

        }

    }
    return todoOk;
}
