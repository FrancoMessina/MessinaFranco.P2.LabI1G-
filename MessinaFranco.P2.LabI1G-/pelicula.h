#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
typedef struct{
    int id_peli;
    char titulo[60];
    char genero[60];
    float rating;
}ePelicula;


#endif // PELICULA_H_INCLUDED
//Nueva pelicula
ePelicula* newPelicula();
ePelicula* pelicula_NewParametros(char* idStr,char* tituloStr,char* generoStr,char* ratingStr);

//Borrar pelicula
void pelicula_Delete(ePelicula* this);
//Getter
int pelicula_setId(ePelicula* this,int id);
int pelicula_getId(ePelicula* this,int* id);

int pelicula_setTitulo(ePelicula* this,char* titulo);
int pelicula_getTitulo(ePelicula* this,char* titulo);

int pelicula_setGenero(ePelicula* this,char* genero);
int pelicula_getGenero(ePelicula* this,char* genero);


int pelicula_setRating(ePelicula* this,float rating);
int pelicula_getRating(ePelicula* this,float* rating);
//List
int pelicula_MostrarPelicula(ePelicula* unaPelicula);
//Voy a usar para map
void* asignarRanking(void* pPelicula);
void* asignarGenero(void* pPelicula);
//Filtrar por genero
int pelicula_FiltrarDrama(void* pPelicula);
int pelicula_FiltrarComedia(void* pPelicula);
int pelicula_FiltrarAccion(void* pPelicula);
int pelicula_FiltrarTerror(void* pPelicula);
//Sort
int pelicula_SortGeneroRating(void* pElementUno, void* pElementDos);
