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

int addEmployee(eEmployee listaDeEmpleados[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int indice;
    int retorno;
    retorno = -1;
    indice = indiceLibre(listaDeEmpleados,len);
    if(indice!=-1)
    {
        listaDeEmpleados[indice].id = id;
        strcpy(listaDeEmpleados[indice].name,name);
        strcpy(listaDeEmpleados[indice].lastName,lastName);
        listaDeEmpleados[indice].salary = salary;
        listaDeEmpleados[indice].sector = sector;
        retorno = indice;

    }
    return retorno;
}

int findEmployeeById(eEmployee listaDeEmpleados[], int len)
{
    int i;
    int id;
    int idDelEmpleado;



    printf("Ingrese el ID a buscar: \n");
    scanf("%d",&id);

    for(i=0;i<len;i++)
    {
        if((listaDeEmpleados[i].id==id)&&(listaDeEmpleados[i].isEmpty==FALSE))
        {
            idDelEmpleado=id;
            break;
        }else
        {
            printf("No existe el id\n");
            idDelEmpleado = -1;
            break;
        }
    }
    return idDelEmpleado;
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





