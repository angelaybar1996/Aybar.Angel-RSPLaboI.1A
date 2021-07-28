#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Bicicletas.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBici);
//int controller_loadFromBinary(char* path , LinkedList* pArrayListPais);
//int controller_addPais(LinkedList* pArrayListPais,int* pId);
//int controller_editPais(LinkedList* pArrayListPais,int auxId);
//int controller_removePais(LinkedList* pArrayListPais,int auxId);
int controller_ListBicicletas(LinkedList* pArrayListBici);
int controller_sortBici(LinkedList* pArrayListBici);
int controller_saveAsText(char* path , LinkedList* pArrayListPais);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListPais);

//funcion para averiguar el mayor id de la lista cargada
//para luego al dar de alta sea con un id correspondiente
int buscarMayorId(LinkedList* pArrayListBici,int* id);

#endif /* CONTROLLER_H_ */







