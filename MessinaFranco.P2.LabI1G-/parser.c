#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "parser.h"
#include "pelicula.h"
int parser_PeliculasFromText(FILE* pFile , LinkedList* pArrayListPelicula)
{
		ePelicula* pPelicula= NULL;
	    int cant;
	    char buffer[4][128];
	    int todoOk = 0;
	    if(pFile != NULL)
	    {
	    	 todoOk = 1;
	         cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//Lectura fantasma
	         do
	         {
	            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

	            if(cant < 4)
	            {
	                break;
	            }

	            pPelicula = pelicula_NewParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

	            if(pPelicula != NULL)
	            {
	                    ll_add(pArrayListPelicula,pPelicula);

	            }
	        }while(!feof(pFile));
	    }
	    else
	    {
	        printf("Error abriendo el archivo\n");
	    }
	    fclose(pFile);
	    return todoOk;
}
