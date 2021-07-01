
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//******************************CARGAR DESDE LOS ARCHIVOS(TEXTO-BINARIO)******************************
int controller_loadFromText(char* path , LinkedList* pArrayListeLibro);
int controller_loadFromBinary(char* path , LinkedList* pArrayListeLibro);
//**********************************ALTA - MODIFICACION - BAJA(ABM)***********************************
int controller_addeLibro(LinkedList* pArrayListeLibro);
int controller_editeLibro(LinkedList* pArrayListeLibro);
int controller_removeeLibro(LinkedList* pArrayListeLibro);
//*****************************************LISTAR EMPLEADOS*******************************************
int controller_ListeLibro(LinkedList* pArrayListeLibro);
int controller_sorteLibro(LinkedList* pArrayListeLibro);
//*********************************GUARDAR EN ARCHIVOS (TEXTO-BINARIO)********************************
int controller_saveAsText(char* path , LinkedList* pArrayListeLibro);
int controller_saveAsBinary(char* path , LinkedList* pArrayListeLibro);
//****************************************************************************************************
int controller_buscarIdMaximo(LinkedList* pArrayListeLibro);
int controller_buscarPorId(LinkedList* pArrayListeLibro, int id);
int controller_mostrarTodos(LinkedList* pArrayListeLibro);
int controller_listaVacia(LinkedList* pArrayListeLibro);
//**************************************CONTROLAR ID***************************************************
int controller_saveLastID();
int controller_loadId();
int controller_saveID();

int controller_saveMap(LinkedList* pArrayListElibro);
int controller_sorteLibroAutoAscendente(LinkedList* pArrayListeLibro);
int eLibro_mapPrecio(void* pElemento);
int controller_map(LinkedList* pArrayListeLibro);

#endif /* CONTROLLER_H_ */
