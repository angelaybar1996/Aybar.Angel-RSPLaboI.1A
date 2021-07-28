#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "parser.h"



/**\brief Carga los datos de las bicicletas desde el archivo bicicletas.csv (modo texto).
 * \param path char* es el nombre del archivo
 * \param pArrayListBici LinkedList* el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBici)
{

	int retorno=-1;
	FILE* fpArchivo;
	char auxNombre[NOMBRE_TAM];
	char auxTipo[100];
	char auxId[100];
	char auxTiempo[100];

	if(pArrayListBici!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"r");
		if(fpArchivo==NULL)
        {
            printf("\nEl archivo no existe");
        }
		else
		{
			retorno=0;
			parser_BiciFromText(fpArchivo, pArrayListBici, auxId, auxNombre, auxTipo, auxTiempo);
		}
		fclose(fpArchivo);
	}
	return retorno;
}

/** \brief Carga los datos de los paises desde el archivo data.bin (modo binario).
 * \param path char* es el nombre del archivo
 * \param pArrayListPais LinkedList* el puntero de array de paises
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
 /*
int controller_loadFromBinary(char* path , LinkedList* pArrayListPais)
{
	int retorno=-1;
	FILE* fpArchivo;
	ePais* auxPais=NULL;

	if(pArrayListPais!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"rb");

		if(fpArchivo!=NULL)
		{
			retorno=0;
			parser_PaisFromBinary(fpArchivo,pArrayListPais,auxPais);

		}
		fclose(fpArchivo);
	}

	return retorno;
}
*/

/** \brief Alta de paises
 *
 * \param pArrayListPais LinkedList* el puntero de array de paises
 * \param pId, es el id inicial al dar del alta
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_addPais(LinkedList* pArrayListPais,int* pId)
{
	int retorno=-1;
	ePais* auxPais;
	char auxNombre[NOMBRE_TAM];
	float auxVac1dosis;
	float auxVac2dosis;
	float auxSinVacunar;

	if(pArrayListPais!=NULL && pId!=NULL)
	{
		if(!utn_getCadena(auxNombre,NOMBRE_TAM,"\nIngrese nombre:","\nError,nombre no valido",2) &&
		   !utn_getNumeroFlotante(&auxVac1dosis, "\nIngrese :", "\nError,horas no validas",1, 1000000, 2) &&
		   !utn_getNumeroFlotante(&auxSueldo, "\nIngrese Sueldo:", "\nError,sueldo no valido",1, 1000000, 2) &&
           !utn_getNumeroFlotante(&auxSueldo, "\nIngrese Sueldo:", "\nError,sueldo no valido",1, 1000000, 2))
		{
			auxEmpleado=employee_newParametros(*pId, auxNombre, auxHorasTrabajadas, auxSueldo);
			if(auxEmpleado!=NULL)
			{
				ll_add(pArrayListEmployee, auxEmpleado);
				 (*pId)++;
				 retorno=0;
			}
		}
	}

	return retorno;
}
*/
/** \brief Modifica datos de empleado
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \param auxId, es el id del empleado a ser modificados sus datos
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_editEmployee(LinkedList* pArrayListEmployee, int auxId)
{
	int retorno=-1;
	int indiceModificar;
	Employee* auxEmpleado;
	int buffer;
	char auxNombre[NOMBRE_TAM];
	float auxHoras;
	float auxSueldo;



	if(pArrayListEmployee!=NULL && auxId>=0)
	{
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado,&buffer);
			if(buffer==auxId)
			{
				indiceModificar=i;
				break;
			}
		}

		if(indiceModificar>=0)
		{
			if(!utn_getCadena(auxNombre,NOMBRE_TAM,"\nIngrese nombre:","\nError,nombre no valido",2) &&
			   !utn_getNumeroFlotante(&auxHoras, "\nIngrese horas trabajadas:", "\nError,horas  no valida",1, 1000000, 2) &&
			   !utn_getNumeroFlotante(&auxSueldo, "\nIngrese sueldo:", "\nError,sueldo  no valido",1, 1000000, 2) )
			{

				employee_setNombre(auxEmpleado, auxNombre);
				employee_setHorasTrabajadas(auxEmpleado, auxHoras);
				employee_setSueldo(auxEmpleado, auxSueldo);

			}
			ll_set(pArrayListEmployee, indiceModificar,(Employee*) auxEmpleado);
			retorno=0;
		}
	}
	return retorno;
}
*/
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \param auxId, es el id del empleado a ser dado de baja
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_removeEmployee(LinkedList* pArrayListEmployee, int auxId)
{
	int retorno=-1;
	int indiceBorrar;
	Employee* auxEmpleado;
	int buffer;
	if(pArrayListEmployee!=NULL && auxId>=0)
	{
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado,&buffer);
			if(buffer==auxId)
			{
				indiceBorrar=i;
				break;
			}
		}

		if(indiceBorrar>=0)
		{
			ll_remove(pArrayListEmployee, indiceBorrar);
		    retorno=0;
		}
	}

	return retorno;
}
*/

/** \brief Listar bicicletas
 *
 * \param pArrayListBici LinkedList* el puntero de array de bicicletas
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_ListBicicletas(LinkedList* pArrayListBici)
{
	int retorno=-1;
	int i;
	eBicicleta* auxBici;
	int auxId;
	char auxNombre[NOMBRE_TAM];
	char auxTipo[TIPO_TAM];
	float auxTiempo;

	if(pArrayListBici!=NULL)
	{
		printf("\n----------LISTA BICICLETAS-------------\n");
		for(i=0;i<ll_len(pArrayListBici);i++)
		{
			auxBici=(eBicicleta*)ll_get(pArrayListBici, i);

			if(!bici_getId(auxBici,&auxId) &&
			   !bici_getNombre(auxBici,auxNombre) &&
			   !bici_getTipo(auxBici,&auxTipo) &&
			   !bici_getTiempo(auxBici,&auxTiempo))
			{
				printf("ID: %d - Nombre: %s - Tipo: %s - Tiempo: %.2f\n",auxId,auxNombre,auxTipo,auxTiempo);
			}
		}
		retorno=0;
	}

	return retorno;
}

/** \brief Ordenar las bicicletas por tipos y si es del mismo tipo por tiempo
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_sortBici(LinkedList* pArrayListBici)
{
    int retorno=-1;
    int opcion;
    if(pArrayListBici!=NULL)
    {
        ll_sort(pArrayListBici, biciCmpTipoTiempo, 1);//ascendente

    	retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListBici)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	eBicicleta* auxBicicleta;

	int auxId;
	char auxNombre[NOMBRE_TAM];
	char auxTipo[TIPO_TAM];
	float auxTiempo;


	if(pArrayListBici!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"w");
		if(fpArchivo!=NULL)
		{
			retorno=0;
			for(i=0;i<ll_len(pArrayListBici);i++)
			{
				auxBicicleta=(eBicicleta*)ll_get(pArrayListBici,i);

				if(!bici_getId(auxBicicleta,&auxId) &&
				   !bici_getNombre(auxBicicleta, auxNombre) &&
				   !bici_getTipo(auxBicicleta,&auxTipo) &&
				   !bici_getTiempo(auxBicicleta, & auxTiempo))
				{
					fprintf(fpArchivo,"%d,%s,%s,%f\n",auxId,auxNombre,auxTipo,auxTiempo);
				}
			}
			fclose(fpArchivo);
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
 /*
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fpArchivo;
	Employee* auxEmpleado;


	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		fpArchivo=fopen(path,"wb");
		if(fpArchivo ==NULL)
		{
			printf("\nNo se pudo abrir el archivo");
		}
		else
		{
			for(int i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
				fwrite(auxEmpleado,sizeof(Employee),1,fpArchivo);
			}
		}
		fclose(fpArchivo);
		retorno=0;
	}
	return retorno;
}
*/


/** \brief Busca el id mas grande del pArrayListBici previamente cargado de un archivo
 *  y le suma 1 para que el siguiente id dado de alta sea continuo
 *
 * \param pArrayListBici LinkedList*  el puntero de array de bicicletas
 * \param id, es el id actual a ser actualizado
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int buscarMayorId(LinkedList* pArrayListBici,int* id)
{
    int retorno=-1;
    eBicicleta* auxBici=NULL;
    int mayor;
    if(pArrayListBici!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListBici);i++)
        {
            auxBici=(eBicicleta*)ll_get(pArrayListBici,i);
            if(i==0 || auxBici->id > mayor)
            {
                bici_getId(auxBici, &mayor);
            }
        }
        *id=mayor+1;

        retorno=0;
    }
    return retorno;
}

