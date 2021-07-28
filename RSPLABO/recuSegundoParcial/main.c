#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Bicicletas.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int opcion;
    char path[50];
    int nextId=0;
    int flag=0;
    int auxId;
    LinkedList* listaBicicletas = ll_newLinkedList();

    do{
    	if(utn_getNumero(&opcion,
			 "\n---------------------\n"
			 "BICICLETAS\n"
			 "---------------------\n"
			 "\n1. Cargar archivo"
			 "\n2. Imprimir lista"
			 "\n3. Asignar Tiempos"
			 "\n4. Filtrar por tipo"
			 "\n5. Mostrar posiciones"
			 "\n6. Guardar posiones"
			 "\n7. Salir\n\n"
			 "Ingrese opcion:",
			 "Opcion no valida",1,7,3)==0)
       {
			switch(opcion)
			{
				case 1:

                    printf("\nIngrese nombre del archivo(bicicletas.csv):");
                    fflush(stdin);
                    gets(path);
                    if(!controller_loadFromText(path,listaBicicletas))
                    {
                        buscarMayorId(listaBicicletas,&nextId);
                        printf("\nDatos cargados del archivo texto exitosamente");
                    }
                    flag=1;
				break;
				case 2:
				    if(flag!=0 )
					{
						controller_ListBicicletas(listaBicicletas);
					}
					else
					{
						printf("\nPrimero debe cargar los datos de las bicicletas");
					}
			    break;
				case 3:

			   break;
				case 4:

			   break;
				case 5:
					if(flag!=0 )
					{
						if(!controller_sortBici(listaBicicletas))
						{
							printf("\nOrdenamiento bicicletas exitosa");
						}
					}
					else
					{
						printf("\nPrimero debe cargar los datos de las bicicletas");
					}
					controller_ListBicicletas(listaBicicletas);

			   break;
				case 6:
                    if(flag!=0 )
					{
						if(!controller_saveAsText("bicicletas.csv",listaBicicletas))
						{
							printf("\nDatos guardados en archivo de texto exitosamente");
						}
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
			}
       }
    }while(opcion != 7);

     ll_deleteLinkedList(listaBicicletas);

    return 0;
}

