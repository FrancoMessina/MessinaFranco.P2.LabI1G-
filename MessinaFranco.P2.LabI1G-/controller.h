#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "linkedList.h"

int controller_loadFromText(char* path, LinkedList* pArrayListaPeliculas);
int controller_saveAsText(char* path, LinkedList* pArrayListaPeliculas);
int controller_MostrarPeliculas(LinkedList* pArrayListaPeliculas);
int controller_FiltroDrama(LinkedList* pArrayListaPeliculas);
int controller_FiltroComedia(LinkedList* pArrayListaPeliculas);
int controller_FiltroAccion(LinkedList* pArrayListaPeliculas);
int controller_FiltroTerror(LinkedList* pArrayListaPeliculas);
int controller_sortPeliculas(LinkedList* pArrayListaPeliculas);
#endif // CONTROLLER_H_INCLUDED
