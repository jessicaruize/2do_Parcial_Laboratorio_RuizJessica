/*
 * Menu.c
 *
 *  Created on: 11 jun. 2021
 *      Author: jessica
 */
#include "Menu.h"
/** \brief Menu que devuelve por parametro la respuesta de las opciones dadas.
 * \param  int* respuesta. Puntero que devuelve la opcion elegida
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int menu_principal(int* respuesta)
{
	int retorno = -1;
	if(respuesta != NULL)
	{
		puts("MENU:");
		puts("1. Leer un archivo con los datos de libros.");
		puts("2. Ordenar la lista generada en el ítem anterior, según el criterio de  ordenamiento “Autor” de manera ascendente.");
		puts("3. Imprimir por pantalla todos los datos de los libros.");
		puts("4. realizar descuentos a los precios según se detalla: * Planeta: 20% (si el monto es mayor o igual a $300) * SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)");
		puts("5. Generar el archivo de salida: mapeado.csv.");
		puts("6. Salir.");
		if(!utn_pedirEntero(respuesta, "Ingrese una opción.", "Error.", 1, 6, 2, 1))
		{
			retorno = 0;
		}
		else
		{
			puts("Ingreso un número errroneo.");
		}
	}
	return retorno;
}
/** \brief Menu que devuelve por parametro la respuesta de las opciones dadas.
 * \param  int* respuesta. Puntero que devuelve la opcion elegida
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int menu_edit(int* respuesta)
{
	int retorno = -1;
	puts("\nEDITAR: \n1_Titulo.\n2_Autor.\n3_Precio. \n4_editorial\n5_Salir");
	if(!utn_pedirEntero(respuesta, "Ingrese el número correspondiente al dato que desea editar: ", "Error", 1, 5, 2, 1))
	{
		retorno = 0;
	}
	return retorno;
}
/** \brief Menu que devuelve por parametro la respuesta de las opciones dadas.
 * \param  int* opcion. Puntero que devuelve la opcion elegida
 * \param int* criterio. Puntero que devuelve el criterio de ordenamiento elegido.
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int menu_sort(int* opcion, int* criterio)
{
	int retorno = -1;
	if(opcion != NULL && criterio != NULL)
	{
		retorno = -2; //Error al ingresar los datos.
		puts("\nORDENAR:\n1_ID\n2_Titulo\n3_Autor\n4_Precio\n5_Editorial\n6_Salir");
		if(!utn_pedirEntero(opcion, "Ingrese el número correspondiente al modo de ordenamiento", "Error", 1, 6, 2, 1))
		{
			if(*opcion > 0 && *opcion < 6)
			{
				puts("\nOrdenad de forma: \n1_Ascendente.\n0_Descendente.");
				if(!utn_pedirEntero(criterio, "Ingrese el numero correspondiente al criterio de ordenamiento.", "Error", 0, 1, 2, 1))
				{
					puts("Aguarde por favor...");
					retorno = 0;
				}
			}
			else
			{
				if(*opcion == 6)
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/** \brief Menu que devuelve por parametro la respuesta de las opciones dadas.
 * \param  int* opcion. Puntero que devuelve la opcion elegida
 * \return  retorno. ( 0 ) si se realizo correctamente.
 * 					 ( -1 ) error.
 */
int menu_listNotEmpty(int* opcion)
{
	int retorno = -1;
	if(opcion != NULL)
	{
		puts("La lista ya tiene guardados los empleados mostrados."
			"\n1_Mantener los datos de la lista junto con los del archivo."
			"\n2_Borrar los elementos que se encuentran en la lista y cargar unicamente los del archivo."
			"\n3 Borrar algunos elementos.");
		if(!utn_pedirEntero(opcion, "Ingrese el número correspondiente a la acción que desea.", "Error.", 1, 3, 2, 1))
		{
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief advierte q va a salir. pregunta si esta seguro.
 * \return int  -1 error. 0 no salir. 1 salir
 */
int menu_salir()
{
	int retorno = -1;
	int respuesta;
	puts("Tenga a bien guardar los cambios antes de salir.");
	respuesta = utn_verificar("¿Desea salir? ", "Error, ingrese [s/n]\n", 2);
	if(respuesta == 1)
	{
		retorno = 0;// no salir
	}
	else
	{
		retorno = 1; //salir
	}
	return retorno;
}

int menu_Editoriales(int* opcion)
{
	int retorno = -1;
	if(opcion != NULL)
	{
		puts("Lista de editoriales: \n"
			"1. PLANETA.\n2. SIGLO XXI EDITORES.\n3. PEARSON.\n"
			"4. MINOTAURO.\n5. SALAMANDRA.\n6. PENGUIN BOOKS.\n");
		if(!utn_pedirEntero(opcion, "ingrese el número correspondiente a la editorial: ", "Error", 0, 6, 2, 1))
		{
			retorno = 0;
		}
	}
	return retorno;
}

