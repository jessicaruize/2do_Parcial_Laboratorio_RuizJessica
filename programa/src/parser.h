
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "libro.h"
#include "Controller.h"


#define TAM_PARSE 10

int parser_eLibroFromText(FILE* pFile , LinkedList* pArrayListeLibro);

int parser_eLibroFromBinary(FILE* pFile , LinkedList* pArrayListeLibro);

int parser_eLibroSaveAsText(LinkedList* pArrayListeLibro, FILE* pFile);

int parser_eLibroSaveAsBinary(LinkedList* pArrayListeLibro, FILE* pFile);

#endif /* PARSER_H_ */
