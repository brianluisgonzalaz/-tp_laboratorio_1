#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menuAndInputs.h"



int initEmployees(eEmployee listaDeEmpleados[], int len)
{
    int i;
    int retorno;
    retorno = -1;
    for(i=0; i<len; i++)
    {
        listaDeEmpleados[i].isEmpty=TRUE;
        retorno = 0;
    }
    return retorno;
}

int addEmployee(eEmployee listaDeEmpleados[], int len)
{
    int indice;
    int empleadoCargado;
    char cargar;
    char opcion_continuar;

    empleadoCargado = -1;
    do
    {
        indice = indiceLibre(listaDeEmpleados, len);
        if(indice!=-1)
        {

            listaDeEmpleados[indice].id= idEmpleado(listaDeEmpleados, len);
            getValidarString("Ingrese su nombre: \n",listaDeEmpleados[indice].name, 50 );
            primerLetraMayuscula(listaDeEmpleados[indice].name);
            getValidarString("Ingrese su apellido: \n",listaDeEmpleados[indice].lastName, 50 );
            primerLetraMayuscula(listaDeEmpleados[indice].lastName);
            listaDeEmpleados[indice].salary = getValidarFloat("Ingrese su salario: \n",5000, 99999999);
            listaDeEmpleados[indice].sector = getValidarInt("Ingrese su sector: \n","Error, los sectores son entre",1,3);


            cargar = getRespuesta("Desea cargar este empleado?: \n");
            mostrarUnEmpleado(listaDeEmpleados[indice]);

            if(cargar!='s' && cargar!='S')
            {
                empleadoCargado = 2;

            }else
             {
                    listaDeEmpleados[indice].isEmpty=FALSE;
                    empleadoCargado = 1;
             }
        }else
        {

            return 0;
        }
        system("pause");
        system("cls");

        opcion_continuar = getRespuesta("Desea cargar otro empleado?: (S/N)\n");
    }while(opcion_continuar=='s'||opcion_continuar=='S');

    return empleadoCargado;
}

int findEmployeeById(eEmployee listaDeEmpleados[], int len)
{
    int i;
    int id;




    printf("Ingrese el ID a buscar: \n");
    scanf("%d",&id);

    for(i=0;i<len;i++)
    {
        if(listaDeEmpleados[i].id==id&&(listaDeEmpleados[i].isEmpty==FALSE))
        {
            id = i;
            break;
        }else
        {
            printf("No existe el id\n");

            break;
        }
    }
    return id;
}


int removeEmployee(eEmployee listaDeEmpleados[], int len, int id)
{
    int i;
    int empleadoEliminado;

    empleadoEliminado = -1;
    for(i=0;i<len;i++)
    {
        if((listaDeEmpleados[i].id==id)&&(listaDeEmpleados[i].isEmpty==FALSE))
        {
            listaDeEmpleados[i].isEmpty=TRUE;
            empleadoEliminado = 0;
            break;
        }
    }
    return empleadoEliminado;
}


int sortEmployees(eEmployee listaDeEmpleados[], int len, int order)
{
    int retorno = -1;
    eEmployee auxEmployee;
    int i;
    int j;

    if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(listaDeEmpleados[i].lastName,listaDeEmpleados[j].lastName)>0&& listaDeEmpleados[i].isEmpty == FALSE && listaDeEmpleados[j].isEmpty == FALSE)
                {
                    auxEmployee = listaDeEmpleados[i];
                    listaDeEmpleados[i] = listaDeEmpleados[j];
                    listaDeEmpleados[j] = auxEmployee;
                }else
                {
                    if(listaDeEmpleados[i].lastName == listaDeEmpleados[j].lastName && listaDeEmpleados[i].isEmpty == FALSE && listaDeEmpleados[j].isEmpty == FALSE)
                    {
                        if(listaDeEmpleados[i].sector > listaDeEmpleados[j].sector )
                        {
                            auxEmployee = listaDeEmpleados[i];
                            listaDeEmpleados[i] = listaDeEmpleados[j];
                            listaDeEmpleados[j] = auxEmployee;
                        }
                    }
                }
            }
        }
    retorno = 0;
    }
    else if(order == 0)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(listaDeEmpleados[i].lastName,listaDeEmpleados[j].lastName)<0 && listaDeEmpleados[i].isEmpty == FALSE && listaDeEmpleados[j].isEmpty == FALSE)
                {
                    auxEmployee = listaDeEmpleados[i];
                    listaDeEmpleados[i] = listaDeEmpleados[j];
                    listaDeEmpleados[j] = auxEmployee;
                }else
                {
                    if(listaDeEmpleados[i].sector == listaDeEmpleados[j].sector && listaDeEmpleados[j].sector && listaDeEmpleados[i].isEmpty == FALSE && listaDeEmpleados[j].isEmpty == FALSE)
                    {
                        if(listaDeEmpleados[i].sector < listaDeEmpleados[j].sector)
                        {
                            auxEmployee = listaDeEmpleados[i];
                            listaDeEmpleados[i] = listaDeEmpleados[j];
                            listaDeEmpleados[j] = auxEmployee;
                        }
                    }
                }
            }
        }
            retorno = 0;
    }

    return retorno;
}


void printEmployees(eEmployee listaDeEmpleados[], int length)
{
    int i;
    printf("  ID  \t\t\tNOMBRE\t\t\t\tApellido\t\tsalario  \t\t\tSector\n");
    for(i=0; i<length; i++)
    {
        if(listaDeEmpleados[i].isEmpty==FALSE)
        {
            mostrarUnEmpleado(listaDeEmpleados[i]);
        }else
        {
            break;
        }
    }
}





