
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "libro.h"
#include "parser.h"
#include "pedir_valores.h"
#include "Menu.h"
#include "Controller.h"
static int idIncremental;
//******************************CARGAR DESDE LOS ARCHIVOS(TEXTO-BINARIO)******************************
/** \brief Carga los datos de los libros desde el archivo modo texto.
 *
 * \param path char* nombre del archivo
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int retorna (0) si los datos fueron cargados con exito.
 * 					   (-1) en caso de error.
 * 					   (-2) si la operacion fue cancelada.
 * 					   (-3) si no se pude abrir el archivo o no existe.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeLibro)
{
	int retorno = -1;//Error.
	FILE* pFile;
	int continuar = 1;
	if(path != NULL && pArrayListeLibro != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			continuar = parser_eLibroFromText(pFile, pArrayListeLibro);
			if(!continuar)
			{
				retorno = 0; //datos cargados con exito.
			}
			else
			{
				if(continuar == -2)
				{
					retorno = -2; // Operacion cancelada.
				}
			}
			fclose(pFile);
		}
		else
		{
			retorno = -3; //Error al abrir el archivo
		}
	}
	return retorno;
}

/** \brief Carga los datos de los libros desde archivo modo binario.
 *
 * \param path char* nombre del archivo
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int retorna (0) si los datos fueron cargados con exito.
 * 					   (-1) en caso de error.
 * 					   (-2) si la operacion fue cancelada.
 * 					   (-3) si no se pude abrir el archivo o no existe.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListeLibro)
{
	int retorno = -1;//Error.
	FILE* pFile;
	int continuar = 1;
	if(path != NULL && pArrayListeLibro != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			continuar = parser_eLibroFromBinary(pFile, pArrayListeLibro);
			if(!continuar)
			{
				retorno = 0; //datos cargados con exito.
			}
			else
			{
				if(continuar == -2)
				{
					retorno = -2; // Operacion cancelada.
				}
			}
			fclose(pFile);
		}
		else
		{
			retorno = -3; //Error al abrir el archivo
		}
	}
	return retorno;
}
//**********************************ALTA - MODIFICACION - BAJA(ABM)***********************************
/** \brief Alta de libros
 * \param pArrayListeLibro LinkedList*  puntero a la lista.
 * \return int (0) operacion realizada con exito.
 * 			   (-1) error al realizar la operación.
 * 			   (-2) operacion cancelada.
 */
int controller_addeLibro(LinkedList* pArrayListeLibro)
{
	int retorno = -1; //Error
	eLibro* libro;
	if(pArrayListeLibro != NULL)
	{
		libro = eLibro_new();
		if(libro != NULL)
		{
			idIncremental ++;
			if(!eLibro_setId(libro, idIncremental) &&
			   !eLibro_cargarDatos(libro))
			{
				if(!utn_verificar("¿Desea guardar los datos? ", "Error, ingrese [s/n].\n", 2))
				{
					if(!ll_add(pArrayListeLibro, libro))
					{
						retorno = 0; // salio bien.
						puts("libro cargado: ");
						puts("\n   ID\t\t\t\t\t\t     TITULO\t\t\t\t    AUTOR\tPRECIO\t\t\t   EDITORIAL\n");
						eLibro_mostrarUno(libro);
						puts("");
					}
				}
				else
				{
					retorno = -2;//operación cancelada.
				}
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de libro
 * \param pArrayListeLibro LinkedList*  puntero a la lista.
 * \return int. (0) operacion realizada con exito.
 * 				(-1) Error al realizar la operación.
 * 				(-2) ID invalido.
 * 				(-3) ID mal ingresado.
 * 				(-4) No hay elementos para editar.
 */
int controller_editeLibro(LinkedList* pArrayListeLibro)
{
	int retorno = -1; //Error.
	int id;
	int indice;
	eLibro* libro;
	if(pArrayListeLibro != NULL)
	{
		if(!ll_isEmpty(pArrayListeLibro))
		{
			ll_sort(pArrayListeLibro, eLibro_compareByTitulo, 1);
			controller_mostrarTodos(pArrayListeLibro);
			if(!utn_pedirEntero(&id, "Ingrese el ID del libro que desea editar: ", "Error\n", 0, 0, 2, 0))
			{
				indice = controller_buscarPorId(pArrayListeLibro, id);
				if(indice > -1)
				{
					libro = ll_get(pArrayListeLibro, indice);
					if(!eLibro_editeLibro(libro))
					{
						retorno = 0;
						puts("libro guardado: \n");
						puts("\n   ID\t\t\t\t\t\t     TITULO\t\t\t\t    AUTOR\tPRECIO\t\t\t   EDITORIAL\n");
						eLibro_mostrarUno(libro);
						puts("");
					}
				}
				else
				{
					if(indice == -2)
					{
						retorno = -2; //id invalido.
					}
				}
			}
			else
			{
				retorno = -3; // dato mal ingresado
			}
		}
		else
		{
			retorno = -4;// No hay elementos para editar.
		}
	}
    return retorno;
}

/** \brief elimina libro
 * \param pArrayListeLibro LinkedList*  puntero a la lista.
 * \return int. (0) operacion realizada con exito.
 * 				(-1) Error al realizar la operación.
 * 				(-2) operacion cancelada.
 * 				(-3) ID no existe.
 * 				(-4) ID mal ingresado.
 * 				(-5) No hay elementos para eliminar.
 */
int controller_removeeLibro(LinkedList* pArrayListeLibro)
{
	int retorno = -1; //Error.
	int id;
	int indice;
	eLibro* libro;
	if(pArrayListeLibro != NULL)
	{
		if(!ll_isEmpty(pArrayListeLibro))
		{
			ll_sort(pArrayListeLibro, eLibro_compareByTitulo, 1);
			controller_mostrarTodos(pArrayListeLibro);
			if(!utn_pedirEntero(&id, "Ingrese el ID del libro que desea eliminar: ", "Error.\n", 0, 0, 2, 0))
			{
				indice = controller_buscarPorId(pArrayListeLibro, id);
				if(indice > -1)
				{

					libro = ll_get(pArrayListeLibro, indice);
					puts("libro a eliminar: ");
					puts("\n   ID\t\t\t\t\t\t     TITULO\t\t\t\t    AUTOR\tPRECIO\t\t\t   EDITORIAL\n");
					eLibro_mostrarUno(libro);
					puts("");
					if(!utn_verificar("¿Desea confirmar la operación? ", "Error, ingrese [s/n]\n", 2))
					{
						if(!ll_remove(pArrayListeLibro, indice) &&
						   !eLibro_delete(libro))
						{
							retorno = 0;//libro eliminado
						}
					}
					else
					{
						ll_push(pArrayListeLibro, indice, libro);
						retorno = -2; //operacion cancelada
					}
				}
				else
				{
					if(indice == -2)
					{
						retorno = -3; //ID no existe.
					}
				}
			}
			else
			{
				retorno = -4;//ID mal ingresado.
			}
		}
		else
		{
			retorno = -5; // no hay libro el la lista para eliminar.
		}
	}
    return retorno;
}
//*****************************************LISTAR libroS*******************************************
/** \brief Listar libros
 * \param pArrayListeLibro LinkedList* puntero a la lista
 * \return int. (0) operacion realizada con exito.
 * 				(1) No hay elementos para listar.
 * 				(-1) Error
 */
int controller_ListeLibro(LinkedList* pArrayListeLibro)
{
	int retorno = -1; // error
	if(pArrayListeLibro != NULL)
	{
		retorno = controller_mostrarTodos(pArrayListeLibro);
	}
    return retorno;
}

/** \brief Ordenar libros
 * \param pArrayListeLibro LinkedList* puntero a la lista
 * \return int  (0) Operacion realizada con exito.
 * 				(-1) Error.
 * 				(-2) error al ingresar las opciones del menu.
 * 				(-3) lista vacia.
 */
int controller_sorteLibro(LinkedList* pArrayListeLibro)
{
	int retorno = -1;
	int opcion;
	int criterio;
	int respuesta;
	if(pArrayListeLibro != NULL)
	{
		respuesta = ll_isEmpty(pArrayListeLibro);
		if(!respuesta)
		{
			do
			{
				respuesta = menu_sort(&opcion, &criterio);
				if(!respuesta)
				{

					switch(opcion)
					{
						case 1:
							retorno =ll_sort(pArrayListeLibro, eLibro_compareById, criterio);
						break;
						case 2:
							retorno = ll_sort(pArrayListeLibro, eLibro_compareByTitulo, criterio);
							break;
						case 3:
							retorno = ll_sort(pArrayListeLibro, eLibro_compareByAutor, criterio);
						break;
						case 4:
							retorno = ll_sort(pArrayListeLibro, eLibro_compareByPrecio, criterio);
						break;
						case 5:
							retorno = ll_sort(pArrayListeLibro, eLibro_compareByEditorialld, criterio);
						break;
						case 6:
							retorno = 0;
							break;
					}
					if(opcion != 6)
					{
						controller_mostrarTodos(pArrayListeLibro);
					}
				}
				else
				{
					if(respuesta == -2)
					{
						retorno = -2; //error al ingreesar las opciones del menu.
					}
				}
			}while(opcion != 6);
		}
		else
		{
			if(respuesta == 1)
			{
				retorno = -3; //lista vacia.
			}
		}
	}
    return retorno;
}
//*********************************GUARDAR EN ARCHIVOS (TEXTO-BINARIO)********************************
/** \brief Guarda los datos de los libros en el archivo modo texto.
 * \param path char* nombre del archivo
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int  (0) operacion realizada con exito.
 * 				(-1) error
 * 				(-2) copia defectuosa.
 * 				(-3) operacion cancelada.
 * 				(-4) lista vacia.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeLibro)
{
	int retorno = -1; //Error.
	FILE* pFile;
	if(path != NULL && pArrayListeLibro != NULL)
	{
		if(!ll_isEmpty(pArrayListeLibro))
		{
			ll_sort(pArrayListeLibro, eLibro_compareById, 1);
			puts("\n\n***************************************************************INICIO DE LA LISTA************************************************************");
			puts("\tlibros en la lista: ");
			controller_mostrarTodos(pArrayListeLibro);
			puts("\n\n****************************************************************FIN DE LA LISTA***************************************************************");
			if(!utn_verificar("¿Esta seguro de guardar la lista mostrada en el archivo de texto? ", "Error , ingrese [s/n]\n", 2))
			{
				pFile = fopen(path,"w");
				retorno = parser_eLibroSaveAsText(pArrayListeLibro, pFile); // 0 ok - -2 copia defectuosa - -1error
				fclose(pFile);
			}
			else
			{
				retorno = -3; //operacion cancelada
			}
		}
		else
		{
			retorno = -4; // lista vacia.
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los libros en el archivo modo binario.
 * \param path char* nombre del archivo
 * \param pArrayListeLibro LinkedList* puntero a la lista
 * \return int  (0) operacion realizada con exito.
 * 				(-1) error
 * 				(-2) copia defectuosa.
 * 				(-3) operacion cancelada.
 * 				(-4) lista vacia.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListeLibro)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListeLibro != NULL)
	{
		if(!ll_isEmpty(pArrayListeLibro))
		{
			ll_sort(pArrayListeLibro, eLibro_compareByTitulo, 1);
			puts("\n\n***************************************************************INICIO DE LA LISTA*************************************************************");
			puts("\tlibros en la lista: ");
			controller_mostrarTodos(pArrayListeLibro);
			puts("\n\n****************************************************************FIN DE LA LISTA***************************************************************");
			if(!utn_verificar("¿Esta seguro de guardar la lista mostrada en el archivo binario? ", "Error, ingrese [s/n]\n", 2))
			{
				pFile = fopen(path,"wb");
				if(pFile != NULL)
				{
					retorno = parser_eLibroSaveAsBinary(pArrayListeLibro, pFile); // 0 ok - -2 copia defectuosa - -1 error
					fclose(pFile);
				}
			}
			else
			{
				retorno = -3; //operacion cancelada
			}
		}
		else
		{
			retorno = -4; // lista vacia.
		}
	}
    return retorno;
}
//****************************************************************************************************
/** \brief devuelve el indice del elemento buscandolo por el id.
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int  (>-1) si devuelve el indice.
 * 				(-1) error
 * 				(-2) no se encontro el ID.
 */
int controller_buscarPorId(LinkedList* pArrayListeLibro, int id)
{
	int retorno = -1;
	int i;
	eLibro* libro;
	int cantidad;
	int idlibro;
	if(pArrayListeLibro != NULL)
	{
		cantidad = ll_len(pArrayListeLibro);
		for(i=0; i<cantidad; i++)
		{
			libro = ll_get(pArrayListeLibro, i);
			eLibro_getId(libro, &idlibro);
			if(idlibro == id)
			{
				retorno = i;//mayor que -1 si lo  encontro; retorna el indice.
				break;
			}
			else
			{
				retorno = -2;//no se encontro  ID;
			}
		}
	}
	return retorno;
}
/** \brief devuelve el id maximo encontrado en la lista.
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int  (-1) error.
 * 				(>-1) si devuelve el id maximo.
 * 				(-1) error
 * 				(-2) no se encontro el ID.
 */
int controller_buscarIdMaximo(LinkedList* pArrayListeLibro)
{
	int i;
	eLibro* libro;
	int bandera = 0;
	int idMax = -1;
	int cantidad;
	int id;
	if(pArrayListeLibro != NULL)
	{
		cantidad = ll_len(pArrayListeLibro);
		for(i=0; i<cantidad; i++)
		{
			libro = ll_get(pArrayListeLibro, i);
			eLibro_getId(libro, &id);
			if(bandera == 0 || id > idMax)
			{
				bandera = -1;
				idMax = id;
			}
		}
	}
	return idMax;
}
/** \brief lista todos los elementos de la lista.
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int (-1) error.
 * 				(0) operación realizada con exito
 * 				(1) no hay elementos para lista
 */
int controller_mostrarTodos(LinkedList* pArrayListeLibro)
{
	int retorno = -1;
	int cantidad;
	int i;
	eLibro* libro;
	if(pArrayListeLibro != NULL)
	{
		if(!ll_isEmpty(pArrayListeLibro))
		{
			puts("\n\n***************************************************************INICIO DE LA LISTA*************************************************************");
			cantidad= ll_len(pArrayListeLibro);
			puts("\n   ID\t\t\t\t\t\t     TITULO\t\t\t\t    AUTOR\tPRECIO\t\t\t   EDITORIAL\n");
			for(i=0; i<cantidad; i++)
			{
				libro = ll_get(pArrayListeLibro, i);
				eLibro_mostrarUno(libro);
			}
			printf("\n\tCantidad libros: %d\n", cantidad);
			puts("\n\n****************************************************************FIN DE LA LISTA***************************************************************");
			retorno = 0;
		}
		else
		{
			retorno = 1; //no hay elementos para listar.
		}
	}
	return retorno;
}
/** \brief Corrobora si la lista esta vacia y si no lo esta realiza la opcion elegida por el usuario (borrarla o mantenerla).
 * \param pArrayListeLibro LinkedList* puntero a la lista.
 * \return int  (-1) error
 * 				(0) operacion realizada con exito.
 */
int controller_listaVacia(LinkedList* pArrayListeLibro)
{
	int retorno = -1; //error.
	int opcion;
	int cantidadElementos;
	int i = 0;
	eLibro* libro;
	if(pArrayListeLibro != NULL)
	{
		if(!ll_isEmpty(pArrayListeLibro))//devuelve 1 lista vacia- 0 si no esta vacia
		{
			puts("\n\n***************************************************************INICIO DE LA LISTA*************************************************************");
			controller_mostrarTodos(pArrayListeLibro);
			puts("\n\n****************************************************************FIN DE LA LISTA***************************************************************");
			if(!menu_listNotEmpty(&opcion))
			{
				switch(opcion)
				{
					case 1:
						retorno = 0;
					break;
					case 2:
						cantidadElementos = ll_len(pArrayListeLibro);
						for(i=cantidadElementos; i>-1; i--)
						{
							libro = ll_get(pArrayListeLibro, i);
							if(libro != NULL && !ll_remove(pArrayListeLibro, i) &&
							 !eLibro_delete(libro))
							{
								retorno = 0;
							}
						}
					break;
					case 3:
						do{
							if(!controller_removeeLibro(pArrayListeLibro))
							{
								if(utn_verificar("¿Desea eliminar otro libro?", "Error.\n", 2) == 1)
								{
									i = 1;
								}
							}
							else
							{
								puts("Ocurrio un error o no hay más libros para eliminar.");
								i=1;
							}
						}while(!i);
						retorno = 0;
					break;
				}
			}
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}
//**************************************CONTROLAR ID***************************************************
/** \brief escribe un archivo en modo binario el ultimo id
 * \param numero. numero que va a ser escrito en el archivo
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int controller_saveLastID(int numero)
{
	int retorno = -1;
	int* idMax;
	FILE* pFile;
	idMax = (int*)malloc(sizeof(int));
	pFile = fopen("ultimoID.bin", "wb");
	if(pFile != NULL && idMax != NULL)
	{
		*idMax = numero;
		fwrite(idMax, sizeof(int), 1, pFile);
		fclose(pFile);
		retorno = 0;
	}
	free(idMax);
	return retorno;
}
/** \brief lee un archivo en modo binario que guarda el ultimo id y se lo copia a idIncremental.
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int controller_loadId()
{
	int retorno = -1;
	int* idMax;
	FILE* pFile;
	idMax = (int*)malloc(sizeof(int));
	pFile = fopen("ultimoID.bin", "rb");
	if(pFile != NULL && idMax != NULL)
	{
		fread(idMax, sizeof(int), 1, pFile);
		fclose(pFile);
		idIncremental = *idMax;
		free(idMax);
		retorno = 0;
	}
	return retorno;
}
/** \brief escribe en un archivo en modo binario el ultimo id
 * \return int (-1) error.
 * 			   (0) operacion realizada con exito.
 */
int controller_saveID()
{
	int retorno = -1;
	int* idMax;
	FILE* pFile;
	idMax = (int*)malloc(sizeof(int));
	*idMax = idIncremental;
	pFile = fopen("ultimoID.bin", "wb");
	if(pFile != NULL && idMax != NULL)
	{
		fwrite(idMax, sizeof(int), 1, pFile);
		fclose(pFile);
		free(idMax);
		retorno = 0;
	}
	return retorno;
}









/** \brief Ordenar libros
 * \param pArrayListeLibro LinkedList* puntero a la lista
 * \return int  (0) Operacion realizada con exito.
 * 				(-1) Error.
 * 				(-2) error al ingresar las opciones del menu.
 * 				(-3) lista vacia.
 */
int controller_sorteLibroAutoAscendente(LinkedList* pArrayListeLibro)
{
	int retorno = -1;
	if(pArrayListeLibro != NULL)
	{
			retorno = ll_sort(pArrayListeLibro, eLibro_compareByAutor, 1);
			if(!retorno)
			{
				retorno = controller_mostrarTodos(pArrayListeLibro);
			}
	}
    return retorno;
}

int controller_map(LinkedList* pArrayListeLibro)
{
	int retorno = -1;
	if(pArrayListeLibro != NULL)
	{
		retorno = 1; //lista vacia.
		if(!ll_isEmpty(pArrayListeLibro))
		{
			if(!ll_map(pArrayListeLibro, eLibro_mapPrecio)) //0 ok
			{
				controller_mostrarTodos(pArrayListeLibro);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_saveMap(LinkedList* pArrayListElibro)
{
	int retorno = 0;
	if(pArrayListElibro != NULL)
	{
		retorno = controller_saveAsText("mapeado.csv", pArrayListElibro);
	}
	return retorno;
}
