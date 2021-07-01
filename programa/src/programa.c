/*
 ============================================================================
 Name        : programa.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "libro.h"
#include "Menu.h"

int main()
{
	LinkedList* listaEmpleados;
	int opcion;
	int respuesta;
	int banderamap = 0;
	char archivo[TAM_ARCHIVO];
	listaEmpleados = ll_newLinkedList();
	//**************CARGA EL ARCHIVO ultimoID.bin CON EL ULTIMO ID QUE SE ENCUENTA EN EL ARCHIVO data.csv*********************
	//int numero;
	//numero = 30;
	//controller_saveLastID(numero);
	//************************************************************************************************************************
	controller_loadId();
	do{
		if(!menu_principal(&opcion))
		{
			switch(opcion)
			{
				case 1:
					if(!utn_pedirAlfanumerico(archivo, TAM_ARCHIVO, "Ingrese el nombre del archivo de texto: ", "Error.", 2))
					{
						strncat(archivo, ".csv", TAM_ARCHIVO);
						respuesta = controller_loadFromText(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -3:
								puts("Error al abrir el archivo, asegurese que exista.");
								break;
							case -2:
								puts("Operación cancelada.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Operación realizada con exito.");
								break;
						}
					}
					break;
				case 2:
					respuesta = controller_sorteLibroAutoAscendente(listaEmpleados);
					switch(respuesta)
					{
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Operación realizada con exito.");
							break;
						case 1:
							puts("No hay empleados para mostrar.");
							break;
					}
				break;
				case 3:
					respuesta = controller_ListeLibro(listaEmpleados);
					switch(respuesta)
					{
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Operación realizada con exito.");
							break;
						case 1:
							puts("No hay empleados para mostrar.");
							break;
					}
				break;
				case 4:
					respuesta = controller_map(listaEmpleados);
					switch(respuesta)
					{
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Operación realizada con exito.");
							banderamap = 1;
							break;
						case 1:
							puts("No hay empleados para mostrar.");
							break;
					}
				break;
				case 5:
					if(banderamap)
					{
						puts("Aguarde por favor...");
						respuesta = controller_saveMap(listaEmpleados);
						switch (respuesta)
						{
							case -4:
								puts("Lista vacia. No se guardara nada.");
								break;
							case -3:
								puts("Operacion cancelada.");
								break;
							case -2:
								puts("Copia defectuosa. intente nuevamente.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Empleados cargados en el archivos de texto con exito.");
								break;
						}
					}
					else
					{
						puts("primero tiene que elegir la opción 4");
					}
						break;
				case 6:
					respuesta = menu_salir();
					if(!respuesta)
					{
						opcion = 1;
					}
					else
					{
						if(respuesta == -1)
						{
							opcion = 1;
							puts("Error al responder. Intente nuevamente.");
						}
					}
					puts("Gracias");
				break;
			}
		}
	}while(opcion != 6);
	controller_saveID();
	ll_deleteLinkedList(listaEmpleados);
    return 0;
}//FIN MAIN

/*
 * 				case 1:
					if(!utn_pedirAlfanumerico(archivo, TAM_ARCHIVO, "Ingrese el nombre del archivo de texto: ", "Error.", 2))
					{
						strncat(archivo, ".csv", TAM_ARCHIVO);
						respuesta = controller_loadFromText(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -3:
								puts("Error al abrir el archivo, asegurese que exista.");
								break;
							case -2:
								puts("Operación cancelada.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Operación realizada con exito.");
								break;
						}
					}
					break;
				case 2:
					if(!utn_pedirAlfanumerico(archivo, TAM_ARCHIVO, "Ingrese el nombre del archivo binario: ", "Error.", 2))
					{
						strncat(archivo, ".bin", TAM_ARCHIVO);
						respuesta = controller_loadFromBinary(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -3:
								puts("Error al abrir el archivo, asegurese que exista.");
								break;
							case -2:
								puts("Operación cancelada.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Operación realizada con exito.");
								break;
						}
					}
				break;
				case 3:
					respuesta = controller_addeLibro(listaEmpleados);
					switch (respuesta)
					{
						case -2:
							puts("Operación cancelada.");
							break;
						case -1:
							puts("Error al realizar la operación.");
							break;
						case 0:
							puts("Operación realizada con exito.");
							break;
					}
				break;
				case 4:
					puts("Aguarde por favor...");
					respuesta = controller_editeLibro(listaEmpleados);
					switch(respuesta)
					{
						case -4:
							puts("No hay elementos para editar.");
							break;
						case (-3 || -2):
							puts("ID invalido.");
							break;
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Operación exitosa.");
							break;
					}
				break;
				case 5:
					puts("Aguarde por favor...");
					respuesta = controller_removeeLibro(listaEmpleados);
					switch(respuesta)
					{
						case -5:
							puts("No hay empleados el la lista para eliminar.");
							break;
						case (-3 || -4):
							puts("ID no existe.");
							break;
						case -2:
							puts("Operación cancelada.");
							break;
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Empleado eliminado.");
							break;
					}
				break;
				case 6:
					respuesta = controller_ListeLibro(listaEmpleados);
					switch(respuesta)
					{
						case -1:
							puts("Error al procesar la operación.");
							break;
						case 0:
							puts("Fin de la lista.");
							break;
						case 1:
							puts("No hay empleados para mostrar.");
							break;
					}
				break;
				case 7:
					respuesta = controller_sorteLibro(listaEmpleados);
					switch (respuesta)
					{
						case -3:
							puts("Lista vacia.");
							break;
						case -2:
							puts("Error al ingresar las opciones del menu.");
							break;
						case -1:
							puts("Error al realizar la operación.");
							break;
						case 0:
							puts("");
							break;
					}
				break;
				case 8:
					if(!utn_pedirAlfanumerico(archivo, TAM_ARCHIVO, "Ingrese el nombre del archivo de texto: ", "Error.", 2))
					{
						strncat(archivo, ".csv", TAM_ARCHIVO);
						puts("Aguarde por favor...");
						respuesta = controller_saveAsText(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -4:
								puts("Lista vacia. No se guardara nada.");
								break;
							case -3:
								puts("Operacion cancelada.");
								break;
							case -2:
								puts("Copia defectuosa. intente nuevamente.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Empleados cargados en el archivos de texto con exito.");
								break;
						}
					}
				break;
				case 9:
					if(!utn_pedirAlfanumerico(archivo, TAM_ARCHIVO, "Ingrese el nombre del archivo binario: ", "Error.", 2))
					{
						strncat(archivo, ".bin", TAM_ARCHIVO);
						puts("Aguarde por favor...");
						respuesta = controller_saveAsBinary(archivo, listaEmpleados);
						switch (respuesta)
						{
							case -4:
								puts("Lista vacia. No se guardara nada.");
								break;
							case -3:
								puts("Operacion cancelada.");
								break;
							case -2:
								puts("Copia defectuosa. intente nuevamente.");
								break;
							case -1:
								puts("Error al realizar la operación.");
								break;
							case 0:
								puts("Empleados cargados en el archivos binario con exito.");
								break;
						}
					}
				break;
				case 10:
					respuesta = menu_salir();
					if(!respuesta)
					{
						opcion = 1;
					}
					else
					{
						if(respuesta == -1)
						{
							opcion = 1;
							puts("Error al responder. Intente nuevamente.");
						}
					}
					puts("Gracias");
				break;
 * */
