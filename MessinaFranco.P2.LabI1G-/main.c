#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "time.h"
#include "input.h"
#include "controller.h"
#include "pelicula.h"
#include <ctype.h>

int main()
{
    srand(time(NULL));
    LinkedList* listPeliculas = ll_newLinkedList();
    char seguir = 'n';
    char pathCarga[25];
    char pathSave[25];

    do
    {
        switch(menuOpcion())
        {
        case 1:
            ingresarString("Ingresa el nombre del .csv a cargar. (movies.csv)\n",pathCarga);
            controller_loadFromText(pathCarga,listPeliculas);
            break;
        case 2:
            if(!ll_isEmpty(listPeliculas))
            {
                controller_MostrarPeliculas(listPeliculas);
            }
            else
            {
                printf("Debe cargar el archivo .csv para poder mostrar las peliculas\n");
            }
            break;
        case 3:
            if(!ll_isEmpty(listPeliculas))
            {
                listPeliculas = ll_map(listPeliculas,asignarRanking);
                if(listPeliculas != NULL)
                {
                    controller_MostrarPeliculas(listPeliculas);

                }
            }
            else
            {
                printf("Debe cargar el archivo .csv para poder mostrar las peliculas\n");
            }
            break;
        case 4:
            if(!ll_isEmpty(listPeliculas))
            {
                listPeliculas = ll_map(listPeliculas,asignarGenero);
                if(listPeliculas != NULL)
                {
                    controller_MostrarPeliculas(listPeliculas);

                }
            }
            else
            {
                printf("Debe cargar el archivo .csv para poder mostrar las peliculas\n");
            }
            break;
        case 5:
            if(!ll_isEmpty(listPeliculas))
            {
                switch(menuDeGeneros())
                {
                case 1:
                    controller_FiltroDrama(listPeliculas);
                    break;
                case 2:
                    controller_FiltroComedia(listPeliculas);
                    break;
                case 3:
                    controller_FiltroAccion(listPeliculas);
                    break;
                case 4:
                    controller_FiltroTerror(listPeliculas);
                    break;
                }
            }
            else
            {
                printf("Debe cargar el archivo .csv para poder mostrar las peliculas\n");
            }
            break;
        case 6:
            if(!ll_isEmpty(listPeliculas))
                {
                    controller_sortPeliculas(listPeliculas);
                    controller_MostrarPeliculas(listPeliculas);
                }
                else
                {
                    printf("Debe cargar el archivo .csv para poder mostrar las peliculas\n");
                }
            break;
        case 7:
            if(!ll_isEmpty(listPeliculas))
            {
                ingresarString("Ingresa el nombre del .csv a cargar.\n",pathSave);
                controller_saveAsText(pathSave, listPeliculas);
                printf("Guardado exitoso\n");
            }
            else
            {
                printf("Debe cargar el archivo .csv para poder guardar las peliculas\n");
            }
            break;
        case 8:
            printf("Quieres salir? s-n");
            fflush(stdin);
            scanf("%c",&seguir);
            seguir = tolower(seguir);
            if(seguir == 's')
            {

                printf("Salida con exito \n");
                ll_deleteLinkedList(listPeliculas);
            }
            break;
        }
        system("pause");
    }
    while(seguir != 's');
    return 0;
}
