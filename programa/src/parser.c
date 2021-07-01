#include "parser.h"
/** \brief Guarda los datos los datos de los pLibros desde el archivo modo texto a la lista de memoria dinamica.
 * \param File* pFile puntero al archivo.
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_eLibroFromText(FILE* pFile , LinkedList* pArrayListeLibro)
{
	int retorno = -1; //Error
	char idStr[TAM_OTROS];
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	char precio[TAM_OTROS];
	char editorialld[TAM_EDITORIAL];
	char aux[300];
	eLibro* pLibro;
	if(pFile != NULL && pArrayListeLibro != NULL)
	{
		if(!controller_listaVacia(pArrayListeLibro))
		{
			fscanf(pFile,"%s\n",aux);
			do
			{
				if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, titulo, autor, precio, editorialld)==5)
				{
					pLibro = eLibro_new();
					idStr[0]= '0';
					editorialld[strnlen(editorialld, sizeof(editorialld))-1] = '\n';
					if(pLibro != NULL)
					{
					//printf("%s %s %s %s %s\n",idStr, titulo, autor, precio, editorialld);
					pLibro = eLibro_newParametros(idStr, titulo, autor, precio, editorialld);
					eLibro_mostrarUno(pLibro);
					//printf("%d %s %s %f %s\n", pLibro->id, pLibro->titulo, pLibro->autor, pLibro->precio, pLibro->editorialld);
					//if(pLibro != NULL)
					//{
							if(!ll_add(pArrayListeLibro, pLibro))
							{
								//printf("%d %s %s %f %s\n", pLibro->id, pLibro->titulo, pLibro->autor, pLibro->precio, pLibro->editorialld);
								retorno=0;//Se guardo con exito
							}

					}
				}
			}while(!feof(pFile));
		}
	}
    return retorno;
}

/** \brief Guarda los datos los datos de los pLibros desde el archivo modo binario a la lista de memoria dinamica.
 * \param File* pFile puntero al archivo.
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_eLibroFromBinary(FILE* pFile , LinkedList* pArrayListeLibro)
{
	int retorno = -1; //Error
	eLibro* pLibro;
	if(pFile != NULL && pArrayListeLibro != NULL)
	{
		if(!controller_listaVacia(pArrayListeLibro))
		{
			do
			{
				pLibro = eLibro_new();
				if(fread(pLibro, sizeof(eLibro), 1, pFile) == 1 &&
				   !ll_add(pArrayListeLibro, pLibro))
				{
					retorno = 0;
				}
			}while(!feof(pFile));
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pLibros de la lista de memoria dinamica al archivo modo texto.
 * \param File* pFile puntero al archivo.
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_eLibroSaveAsText(LinkedList* pArrayListeLibro, FILE* pFile)
{
	int retorno = -1;
	int i;
	int cantidad;
	eLibro* pLibro;
	int id;
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	float precio;
	char editorial[TAM_EDITORIAL];
	if(pFile != NULL && pArrayListeLibro != NULL)
	{
		cantidad = ll_len(pArrayListeLibro);
		fprintf(pFile, "ID, Titulo, Autor, Precio, Editorialld\n");
		for(i=0; i<cantidad; i++)
		{
			pLibro = ll_get(pArrayListeLibro, i);
			if(!eLibro_getId(pLibro, &id) &&
			   !eLibro_getTitulo(pLibro, titulo) &&
			   !eLibro_getAutor(pLibro, autor) &&
			   !eLibro_getPrecio(pLibro, &precio) &&
			   !eLibro_getEditorialld(pLibro, editorial))
			{
				if(fprintf(pFile,"%d,%s,%s,%f,%s\n", id, titulo, autor, precio, editorial)<5)
				{
					retorno = -2; //copia defectuosa. intentar de nuevo
					break;
				}
			}
		}
		if(retorno != -2)
		{
			retorno = 0;//se guardo con exito.
		}
	}
	return retorno;
}
/** \brief Guarda los datos de los pLibros de la lista de memoria dinamica al archivo modo binario.
 * \param File* pFile puntero al archivo.
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int parser_eLibroSaveAsBinary(LinkedList* pArrayListeLibro, FILE* pFile)
{
	int retorno = -1;
	int cantidad;
	int cantidadImpresa;
	int i;
	eLibro* pLibro;
	if(pFile != NULL && pArrayListeLibro != NULL)
	{
		retorno = 0;
		cantidad = ll_len(pArrayListeLibro);
		for(i=0; i<cantidad; i++)
		{
			pLibro = ll_get(pArrayListeLibro, i);
			cantidadImpresa = fwrite(pLibro,sizeof(eLibro), 1, pFile);
			if (cantidadImpresa != 1)
			{
				retorno = -2; //copia defectuosa
				break;
			}
		}
	}

	return retorno;
}
