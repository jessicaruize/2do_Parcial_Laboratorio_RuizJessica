/*
 * libro.h
 *
 *  Created on: 25 jun. 2021
 *      Author: jessica
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <stdlib.h>
#include "pedir_valores.h"
#include "Menu.h"

#define TAM_TITULO 100
#define TAM_AUTOR 20
#define TAM_EDITORIAL 30
#define TAM_OTROS 10
#define TAM_ARCHIVO 25

//EDITORIALES
#define  PLANETA 1
#define  SIGLO_XXI_EDITORES 2
#define  PEARSON 3
#define  MINOTAURO 4
#define  SALAMANDRA 5
#define  PENGUIN_BOOKS 6



typedef struct
{
	int id;
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	float precio;
	char editorialld[TAM_EDITORIAL];
}eLibro;


eLibro* eLibro_new();
eLibro* eLibro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialldStr);


int eLibro_delete(eLibro* this);

int eLibro_setId(eLibro* this, int id);
int eLibro_getId(eLibro* this, int* id);

int eLibro_setTitulo(eLibro* this, char* titulo);
int eLibro_getTitulo(eLibro* this, char* titulo);

int eLibro_setAutor(eLibro* this, char* autor);
int eLibro_getAutor(eLibro* this, char* autor);

int eLibro_setPrecio(eLibro* this, float precio);
int eLibro_getPrecio(eLibro* this, float* precio);

int eLibro_setEditorialld(eLibro* this, char* editorialld);
int eLibro_getEditorialld(eLibro* this, char* editorialld);


int eLibro_compareByTitulo(void* elemento1, void* elemento2);
int eLibro_compareById(void* elemento1, void* elemento2);
int eLibro_compareByAutor(void* elemento1, void* elemento2);
int eLibro_compareByPrecio(void* elemento1, void* elemento2);
int eLibro_compareByEditorialld(void* elemento1, void* elemento2);

int eLibro_mostrarUno(eLibro* libro);
int eLibro_mostrarEditorial(eLibro* libro);
int eLibro_set(eLibro* libro, int id, char* titulo, char* autor, char* editorialld, float precio);
int eLibro_cargarDatos(eLibro* libro);


int eLibro_editTitulo(eLibro* libro);
int eLibro_editAutor(eLibro* libro);
int eLibro_editPrecio(eLibro* libro);
int eLibro_editEditorialld(eLibro* libro);
int eLibro_saveEdit(eLibro* libro);
int eLibro_editeLibro(eLibro* libro);

int eLibro_mapPrecio(void* pElemento);





#endif /* LIBRO_H_ */
