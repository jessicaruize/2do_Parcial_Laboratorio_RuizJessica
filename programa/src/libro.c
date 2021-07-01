/*
 * libro.c
 *
 *  Created on: 25 jun. 2021
 *      Author: jessica
 */

#include "libro.h"

/** \brief crea un nuevo libro en memoria dinamica.
 * \return int retorna la direccion del libro si es que se creo o NULL.
 */
eLibro* eLibro_new()
{
	eLibro* libro;
	libro = (eLibro*)malloc(sizeof(eLibro));
	return libro;
}
/** \brief crea un libro y lo carga con los parametros..
 * \param char* idStr id a cargar en el libro.
 * \param   char* tituloStr titulo a cargar en el libro.
 * param   char* autorStr horas trabajadas a cargar en el libro
 * param   char* sueldoStr sueldo a cargar en el libro
 * \return   retorna la direccion del libro si es que se creo o NULL..
 */
eLibro* eLibro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* editorialldStr)
{
	eLibro* libro;
	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && editorialldStr != NULL)
	{
		libro = eLibro_new();
		if(libro != NULL)
		{
			//printf("%s %s %s %s %s\n", idStr, tituloStr, autorStr, editorialldStr, precioStr);
			eLibro_set(libro, atoi(idStr), tituloStr, autorStr, editorialldStr, atof(precioStr));
			//printf("%d %s %s %s %f\n", id, tituloStr, autorStr, editorialldStr, precio);
			//eLibro_mostrarUno(libro);
		}
	}
	return libro;
}
//*********************************************************************************************************************************************
/** \brief carga al libro el id pasado por parametro.
 * \param   int id. ID a ser cargado en el libro
 * \param   eLibro* this. Direccion del libro a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_setId(eLibro* this, int id)
{
	int retorno = -1;
	if(this != NULL && id > -1)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene el id del libro pasado por parametro.
 * \param   int* id. ID a obtener.
 * \param   eLibro* this. Direccion del libro de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_getId(eLibro* this, int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	//printf("id %d", *id);
	return retorno;
}
/** \brief carga al libro el titulo pasado por parametro.
 * \param   char* titulo. titulo a ser cargado en el libro
 * \param   eLibro* this. Direccion del libro a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_setTitulo(eLibro* this, char* titulo)
{
	int retorno = -1;
	if(this != NULL && titulo != NULL && strnlen(titulo, TAM_TITULO) > 0)
	{
		strncpy(this->titulo, titulo, TAM_TITULO);
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene el titulo del libro pasado por parametro.
 * \param   char* titulo. titulo a obtener.
 * \param   eLibro* this. Direccion del libro de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_getTitulo(eLibro* this, char* titulo)
{
	int retorno = -1;
	if(this != NULL && titulo != NULL)
	{
		retorno = 0;
		strncpy(titulo, this->titulo, TAM_TITULO);
	}
	return retorno;
}
/** \brief carga al libro el autor pasado por parametro.
 * \param   char* autor. autor a ser cargado en el libro
 * \param   eLibro* this. Direccion del libro a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_setAutor(eLibro* this, char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL && strnlen(autor, TAM_AUTOR) > 0)
	{
		strncpy(this->autor, autor, TAM_AUTOR);
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene el autor del libro pasado por parametro.
 * \param   char* autor. autor a obtener.
 * \param   eLibro* this. Direccion del libro de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_getAutor(eLibro* this, char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		retorno = 0;
		strncpy(autor, this->autor, TAM_AUTOR);
	}
	return retorno;
}

/** \brief carga al libro el precio pasado por parametro.
 * \param   int precio. precio a ser cargado en el libro
 * \param   eLibro* this. Direccion del libro a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_setPrecio(eLibro* this, float precio)
{
	int retorno = -1;
	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene el precio del libro pasado por parametro.
 * \param   int* precio. precio a obtener.
 * \param   eLibro* this. Direccion del libro de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_getPrecio(eLibro* this, float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

/** \brief carga al libro el editorialld pasado por parametro.
 * \param   int editorialld. editorialld a ser cargado en el libro
 * \param   eLibro* this. Direccion del libro a cargar.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_setEditorialld(eLibro* this, char* editorialld)
{
	int retorno = -1;
	if(this != NULL && editorialld != NULL)
	{
		strncpy(this->editorialld, editorialld, TAM_EDITORIAL);
		retorno = 0;
	}
	return retorno;
}
/** \brief obtiene el editorialld del libro pasado por parametro.
 * \param   int* editorialld. editorialld a obtener.
 * \param   eLibro* this. Direccion del libro de donde se obtiene el dato.
 * \return   retorno. ( 0 ) si salio bien.
 * 						 ( -1 ) en caso de error.
 */
int eLibro_getEditorialld(eLibro* this, char* editorialld)
{
	int retorno = -1;
	if(this != NULL && editorialld != NULL)
	{
		strncpy(editorialld, this->editorialld, TAM_EDITORIAL);
		retorno = 0;
	}
	return retorno;
}
//*********************************************************************************************************************************************
/** \brief compara los titulos de los libros recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los titulos son iguales.
 * 					 ( 1 ) si titulo1 es mayor a titulo2.
 * 					 ( -1 ) si titulo2 es mayor a titulo1.
 * 					 (-2) error.
 */
int eLibro_compareByTitulo(void* elemento1, void* elemento2)
{
	int comparacion = -2;
	int aux;
	eLibro* libro1;
	eLibro* libro2;
	char titulo1[TAM_TITULO];
	char titulo2[TAM_TITULO];
	if(elemento1 != NULL && elemento2 != NULL)
	{
		libro1 = (eLibro*)elemento1;
		libro2 = (eLibro*)elemento2;
		eLibro_getTitulo(libro1, titulo1);
		eLibro_getTitulo(libro2, titulo2);
		aux = strncmp(titulo1, titulo2, TAM_TITULO);
		comparacion = 0;
		if(aux > 0)
		{
			comparacion = 1;
		}
		else
		{
			if(aux < 0)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}

/** \brief compara los autores de los libros recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los autors son iguales.
 * 					 ( 1 ) si autor1 es mayor a autor2.
 * 					 ( -1 ) si autor2 es mayor a autor1.
 * 					 (-2) error.
 */
int eLibro_compareByAutor(void* elemento1, void* elemento2)
{
	int comparacion = -2;
	int aux;
	eLibro* libro1;
	eLibro* libro2;
	char autor1[TAM_AUTOR];
	char autor2[TAM_AUTOR];
	if(elemento1 != NULL && elemento2 != NULL)
	{
		libro1 = (eLibro*)elemento1;
		libro2 = (eLibro*)elemento2;
		eLibro_getAutor(libro1, autor1);
		eLibro_getAutor(libro2, autor2);
		aux = strncmp(autor1, autor2, TAM_AUTOR);
		comparacion = 0;
		if(aux > 0)
		{
			comparacion = 1;
		}
		else
		{
			if(aux < 0)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}

/** \brief compara los id de los libros recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los id's son iguales.
 * 					 ( 1 ) si id1 es mayor a id2.
 * 					 ( -1 ) si id2 es mayor a id1.
 * 					 (-2) error.
 */
int eLibro_compareById(void* elemento1, void* elemento2)
{
	int comparacion = -2; //error
	eLibro* libro1;
	eLibro* libro2;
	int id1;
	int id2;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		libro1 = (eLibro*)elemento1;
		libro2 = (eLibro*)elemento2;
		eLibro_getId(libro1, &id1);
		eLibro_getId(libro2, &id2);
		comparacion = 0;
		if(id1>id2)
		{
			comparacion = 1; // id 1 mayor
		}
		else
		{
			if(id2>id1)
			{
				comparacion = -1; //id2 mayor
			}
		}
	}
	return comparacion;
}
/** \brief compara las editoriales de los libros recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los editorialld son iguales.
 * 					 ( 1 ) si editorialld1 es mayor a editorialld2.
 * 					 ( -1 ) si editorialld2 es mayor a editorialld1.
 * 					 (-2) error.
 */
int eLibro_compareByEditorialld(void* elemento1, void* elemento2)
{
	int comparacion = -2; //error
	eLibro* libro1;
	eLibro* libro2;
	char editorialld1[TAM_EDITORIAL];
	char editorialld2[TAM_EDITORIAL];

	if(elemento1 != NULL && elemento2 != NULL)
	{
		libro1 = (eLibro*)elemento1;
		libro2 = (eLibro*)elemento2;
		eLibro_getEditorialld(libro1, editorialld1);
		eLibro_getEditorialld(libro2, editorialld2);
		comparacion = 0;
		if(strncmp(editorialld1, editorialld2, TAM_EDITORIAL))
		{
			comparacion = 1; // editorialld 1 mayor
		}
		else
		{
			if(editorialld2>editorialld1)
			{
				comparacion = -1; //editorialld2 mayor
			}
		}
	}
	return comparacion;
}
/** \brief compara los precios de los elementos recibidos.
 * \param  void* elemento1 primer elemento a comparar.
 * \param  void* elemento2 elemento a comparar con el primer elemento.
 * \return  retorno. ( 0 ) si los precios son iguales.
 * 					 ( 1 ) si precio1 es mayor a precio2.
 * 					 ( -1 ) si precio2 es mayor a precio1.
 * 					 (-2) error.
 */
int eLibro_compareByPrecio(void* elemento1, void* elemento2)
{
	int comparacion = -2; //error
	eLibro* libro1;
	eLibro* libro2;
	float precio1;
	float precio2;

	if(elemento1 != NULL && elemento2 != NULL)
	{
		libro1 = (eLibro*)elemento1;
		libro2 = (eLibro*)elemento2;
		eLibro_getPrecio(libro1, &precio1);
		eLibro_getPrecio(libro2, &precio2);
		comparacion = 0;
		if(precio1>precio2)
		{
			comparacion = 1; // precio 1 mayor
		}
		else
		{
			if(precio2>precio1)
			{
				comparacion = -1; //precio 2 mayor
			}
		}
	}
	return comparacion;
}
//*********************************************************************************************************************************************
/** \brief Muesta un libro.
 * \param  eLibro* libro.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_mostrarUno(eLibro* libro)
{
	int retorno = -1;
	int id;
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	char editorialld[TAM_EDITORIAL];
	float precio;
	if(!eLibro_getId(libro, &id) &&
	   !eLibro_getTitulo(libro, titulo) &&
	   !eLibro_getAutor(libro, autor) &&
	   !eLibro_getEditorialld(libro, editorialld) &&
	   !eLibro_getPrecio(libro, &precio))
	{
		printf("%5d %55s  %35s %10.1f$ %30s\n", id, titulo, autor, precio, editorialld);
		retorno = 0;
	}
	return retorno;
}

/** \brief Carga al libro con los datos recibidos.
 * \param  eLibro* libro. puntero al libro a cargar.
 * \param int id. ID a cargar en el campo id del libro.
 * \param char* nombre. nombre a cargar en el campo nombre del libro.
 * \param int horasTrabajadas. horas trabajadas a cargar en el campo horasTrabajadas del libro.
 * \param int sueldo. sueldo a cargar en el campo sueldo del libro.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_set(eLibro* libro, int id, char* titulo, char* autor, char* editorialld, float precio)
{
	int retorno = -1;
	//printf("%d %s %s %s %f\n", id, titulo, autor, editorialld, precio);
	if(libro != NULL && titulo != NULL && autor != NULL && id > 0 && editorialld != NULL && precio > 0)
	{
		if(!eLibro_setTitulo(libro, titulo) &&
		   !eLibro_setId(libro, id) &&
		   !eLibro_setAutor(libro, autor) &&
		   !eLibro_setEditorialld(libro, editorialld) &&
		   !eLibro_setPrecio(libro, precio))
		{

			retorno = 0;
		}
	}
	return retorno;
}
/** \brief Carga un libro con los datos pedidos al usuario.
 * \param  eLibro* libro. puntero al libro a cargar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_cargarDatos(eLibro* libro)
{
	int retorno = -1;
	char titulo[TAM_TITULO];
	char autor[TAM_AUTOR];
	char editorialld[TAM_EDITORIAL];
	float precio;
	int id;
	if(libro != NULL)
	{

		eLibro_getId(libro, &id);
		if(!utn_pedirCadena(titulo, TAM_TITULO, "Ingrese el titulo del libro: ", "Error.", 2) &&
		   !utn_pedirCadena(autor, TAM_AUTOR, "Ingrese el autor.", "Error.", 2) &&
		   !utn_pedirCadena(editorialld, TAM_EDITORIAL, "Ingrese la editorial: ", "Error.\n", 2) &&
		   !utn_pedirFlotante(&precio, "Ingrese el precio", "Error.\n", 0, 0, 2, 0))
		{
			eLibro_set(libro, id, titulo, autor, editorialld, precio);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Edita nombre un libro con los datos pedidos al usuario.
 * \param  eLibro* libro.puntero al libro a editar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_editTitulo(eLibro* libro)
{
	int retorno = -1;
	char titulo[TAM_TITULO];
	if (libro != NULL &&
		!utn_pedirCadena(titulo, TAM_TITULO, "Ingrese el título: ", "Error.\n", 2) &&
		!utn_verificar("¿Desea guardar los cambios? ", "Error, ingrese [s/n]\n", 2) &&
		!eLibro_setTitulo(libro, titulo))
		{
			retorno = 0;
		}
	return retorno;
}
/** \brief Edita nombre un libro con los datos pedidos al usuario.
 * \param  eLibro* libro.puntero al libro a editar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_editAutor(eLibro* libro)
{
	int retorno = -1;
	char autor[TAM_AUTOR];
	if (libro != NULL &&
		!utn_pedirCadena(autor, TAM_AUTOR, "Ingrese el autor: ", "Error.\n", 2) &&
		!utn_verificar("¿Desea guardar los cambios? ", "Error, ingrese [s/n]\n", 2) &&
		!eLibro_setAutor(libro, autor))
		{
			retorno = 0;
		}
	return retorno;
}
/** \brief Edita hs. trabajadas un libro con los datos pedidos al usuario.
 * \param  eLibro* libro. puntero al libro a editar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_editPrecio(eLibro* libro)
{
	int retorno = -1;
	float precio;
	if (libro != NULL &&
	    !utn_pedirFlotante(&precio, "Ingrese precio: ", "Error\n", 0, 0, 2, 0) && precio > 0 &&
		!utn_verificar("¿Desea guardar los cambios? ", "Error, ingrese [s/n]\n", 2) &&
		!eLibro_setPrecio(libro, precio))
		{
			retorno = 0;
		}
	return retorno;
}
/** \brief Edita salario un libro con los datos pedidos al usuario.
 * \param  eLibro* libro. puntero al libro a editar
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_editEditorialld(eLibro* libro)
{
	int retorno = -1;
	char editorial[TAM_EDITORIAL];
	if (libro != NULL &&
	    !utn_pedirCadena(editorial, TAM_EDITORIAL, "Ingrese la editorial: ", "Error.\n", 2) &&
		!utn_verificar("¿Desea guardar los cambios? ", "Error, ingrese [s/n]\n", 2) &&
		!eLibro_setEditorialld(libro, editorial))
		{
			retorno = 0;
		}
	return retorno;
}
/** \brief pregunta si desea editar algun dato.
 * \param  eLibro* libro. puntero al libro a mostrar
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_saveEdit(eLibro* libro)
{
	int retorno = -1;
	int respuesta;
	if (libro != NULL)
	{
		puts("El libro elegido se guardara con estos datos: ");
		puts("\n   ID\t\t\t\t\t\t     TITULO\t\t\t\t    AUTOR\tPRECIO\t\t\t   EDITORIAL\n");
		eLibro_mostrarUno(libro);
		puts("\n");
		respuesta = utn_verificar("¿Desea cambiar algún dato? ", "Error, ingrese [s/n]\n", 2);
		if(!respuesta)
		{
			retorno = 1; // seguir editando
		}
		else
		{
			if(respuesta == 1)
			{
				retorno = 0; //se guardan los datos como estan.
			}
		}
	}
	return retorno;
}
/** \brief edita al libro
 * \param  eLibro* libro. puntero al libro a editar
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_editeLibro(eLibro* libro)
{
	int retorno = -1;
	int respuesta;
	int seguir;
	if(libro != NULL)
	{
		do
		{//hacer get.
			puts("\nlibro seleccionado: ");
			puts("\n   ID\t\t\t\t\t\t     TITULO\t\t\t\t    AUTOR\tPRECIO\t\t\t   EDITORIAL\n");
			eLibro_mostrarUno(libro);
			if(!menu_edit(&respuesta))
			{
				switch(respuesta)
				{
					case 1:
						if (!eLibro_editTitulo(libro))
						{
							retorno = 0;
						}
						break;
					case 2:
						if (!eLibro_editAutor(libro))
						{
							retorno = 0;
						}
						break;
					case 3:
						if (!eLibro_editPrecio(libro))
						{
							retorno = 0;
						}
						else
						{
							puts("Error\n");
						}
						break;
					case 4:
						if (!eLibro_editEditorialld(libro))
						{
							retorno = 0;
						}
						break;
					case 5:
						seguir = eLibro_saveEdit(libro);
						if(seguir == 1)
						{
							respuesta = 1; //Seguir editando.
						}
						else
						{
							if(!seguir)
							{
								retorno = 0;
							}
						}
						break;
				}
			}
		}while(respuesta != 5);
	}
    return retorno;
}
/** \brief elimina al libro.
 * \param  eLibro* libro. puntero al libro a eliminar.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int eLibro_delete(eLibro* this)
{
	int retorno =-1;
	if(this != NULL)
	{
		free(this);
		this = NULL;
		retorno = 0;
	}
	return retorno;
}



//0 ok ....-1 error.
int eLibro_mapPrecio(void* pElemento)
{
	int retorno = -1;
	float precio;
	char editorial[TAM_EDITORIAL];
	int auxSiglo;
	int auxPlaneta;
	eLibro* pLibro;
	pLibro = pElemento;
	if(pElemento != NULL && !eLibro_getEditorialld(pLibro, editorial) && !eLibro_getPrecio(pLibro, &precio))
	{
		retorno = 0;
		auxSiglo = strncmp("SIGLO XXI EDITORES", editorial, TAM_EDITORIAL);
		auxPlaneta = strncmp("Planeta", editorial, TAM_EDITORIAL);
		//printf("editorial: %s SIGLO XXI EDITORES: %d - precio : %f\n",editorial, auxSiglo, precio);
		//printf("editorial: %s Planeta: %d - precio : %f\n",editorial, auxPlaneta, precio);
		if(strncmp("Planeta", editorial, TAM_EDITORIAL) == auxPlaneta && precio >=300)
		{
			//printf("editorial: %s SIGLO XXI EDITORES: %d - precio : %f\n",editorial, aux, precio);
			precio = precio - (precio * 0.2);
			retorno = eLibro_setPrecio(pElemento, precio);
		}
		if(strncmp("SIGLO XXI EDITORES", editorial, TAM_EDITORIAL) == auxSiglo && precio <= 200)
		{
			precio = precio - (precio * 0.1);
			retorno = eLibro_setPrecio(pLibro, precio);
		}
	}
	return retorno;
}
