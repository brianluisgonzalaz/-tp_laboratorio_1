#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menuAndInputs.h"

void menu (eEmployee listaDeEmpleados[], int len)
{

    int opcion;
    int subOpcion;
    int opcionOrdenar;
    int empleadoCargado;

    empleadoCargado = 0;

    do
    {
        printf("1.Alta empleado\n2.Modificar datos\n3.Baja empleados\n4 Informes lista de empleados.\n5.Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                    switch(cargarEmpleado(listaDeEmpleados, len))
                    {
                    case -1:
                            printf("Error, no se puedo realizar la carga");
                    break;
                    case 0:
                            printf("Empleado cargado exitosamente\n");
                            empleadoCargado = 1;
                    break;
                    case 1:
                            printf("El usuario cancelo el alta\n");
                            empleadoCargado = 1;
                    break;
                    }
            printf("\n");
            break;

            case 2:
                        if(empleadoCargado==1)
                        {
                           menuModificacion(listaDeEmpleados,len);
                        }else
                        {
                            printf("No hay empleados cargados para modificar\n");
                        }

            break;

            case 3:

                    if(empleadoCargado==1)
                    {
                        switch(bajaEmpleados(listaDeEmpleados, T))
                        {
                        case -1:
                                printf("Error, no se puedo eliminar el empleado\n");
                        break;
                        case 0:
                                printf("Empleado eliminado exitosamente\n");

                        break;
                        case 1:
                                printf("El usuario cancelo la operacion\n");

                        break;
                        }
                    }else
                    {
                       printf("No hay empleados cargados para eliminar\n");
                    }

            break;

            case 4:
                    if(empleadoCargado ==1)
                    {
                       opcionOrdenar = getValidarInt("Ingrese: \n1 para ordenar por apellido y sector\n2 Para ordenar por salario\n","Error, las opciones validas son",1,2);
                       switch(opcionOrdenar)
                       {
                           case 1:
                                subOpcion=getValidarInt("0.Ordenar en orden asendente\n1.Ordenar en orden descendente\n","Error, las opciones validas son",0,1);
                                if(subOpcion==0)
                                {
                                    sortEmployees(listaDeEmpleados,len,0);
                                    printEmployees(listaDeEmpleados,T);
                                }else
                                {
                                    sortEmployees(listaDeEmpleados,len,1);
                                    printEmployees(listaDeEmpleados,T);
                                }

                        break;
                        case 2:
                                ordenarPorSalario(listaDeEmpleados,len);
                                printEmployees(listaDeEmpleados,T);
                        break;
                       }
                    }else
                       {
                            printf("No hay empleados cargados para mostrar\n");
                       }


            break;

            case 5:
                    printf("Esta saliendo del programa \n");
            break;
            default:
                    printf("opcion no valida \n");
            break;
        }
        system("pause");
        system("cls");
    }while(opcion!=5);
}

void menuModificacion (eEmployee listaDeEmpleados[], int len)
{
    int opcion; // guardara la opcion del menu ingresada por el usuario que desencadenara un switch
    int id; // guardara el indice del ID a modificar previamente ingresado por el usuario
    int i;
    eEmployee auxEmpleado;
    printEmployees(listaDeEmpleados,len);

    id = findEmployeeById(listaDeEmpleados,len);
    for(i=0;i<len;i++)
    {
            if (id==listaDeEmpleados[i].id&&listaDeEmpleados[i].isEmpty==FALSE)
        {
            do{
        system("pause");
        system("cls");
        printf("Usted esta en el menu Modificar Empleado\n\n");

        opcion = getValidarInt("1.Modificar nombre\n2.Modificar apellido\n3.Modificar salario\n4.Modificar sector\n5.Volver al menu anterior.\n\n\n","Las opciones validas son entre", 1, 5);
        switch (opcion)
        {
           case 1:
                system("cls");
                getValidarString("su nombre: \n",auxEmpleado.name, 50 );
                if (getRespuesta("Desea cambiar su nombre? (S/N)")=='s'|| getRespuesta("Desea cambiar su nombre (S/N)")=='S')
                {
                   strcpy(listaDeEmpleados[i].name, auxEmpleado.name);
                   primerLetraMayuscula(listaDeEmpleados[i].name);
                }
                break;
            case 2:
                system("cls");
                getValidarString("su apellido: \n",auxEmpleado.name, 50 );
                if (getRespuesta("Desea cambiar su apellido (S/N)")=='s'|| getRespuesta("Desea cambiar su apellido (S/N)")=='S')
                {
                   strcpy(listaDeEmpleados[i].lastName, auxEmpleado.lastName);
                   primerLetraMayuscula(listaDeEmpleados[i].lastName);
                }
                break;
            case 3:
                system("cls");
                auxEmpleado.salary=getValidarFloat("su salario: \n", 0, 50000);
                if (getRespuesta("Desea modificar su salario (S/N)")=='s'|| getRespuesta("Desea modificar su salario (S/N)")=='S')
                {
                   listaDeEmpleados[i].salary=auxEmpleado.salary;
                }
                break;
            case 4:
                system("cls");
                auxEmpleado.sector = getValidarInt("Ingrese su sector: \n","Error, los sectores son entre",1,3);
                if (getRespuesta("Desea desea modificar su sector de trabajo (S/N)")=='s'|| getRespuesta("Desea desea modificar su sector de trabajo (S/N)")=='S')
                {
                   listaDeEmpleados[i].sector = auxEmpleado.sector;
                }
                break;
            case 5:
                printf("\nVolviendo al menu anterior...\n\n");
                break;
            default:
                printf("\nNo ingreso una opcion valida!\n\n");
                break;
        }
        }while (opcion!=5);
        break;
        }else
        {
            printf("No existe el id ingresado:\n");
            break;
        }
    }
}

int indiceLibre(eEmployee listaDeEmpleados[], int len)
{
    int i;
    int indice;

    indice = -1;

    for(i=0; i<len; i++)
    {
        if(listaDeEmpleados[i].isEmpty==TRUE)
        {
            indice = i;
            break;
        }

    }
    return indice;
}
int idEmpleado(eEmployee listaDeEmpleados[], int len)
{
    int i;
    int id;

    id = -1;

    for(i=0; i<len; i++)
    {
        if(listaDeEmpleados[i].isEmpty==TRUE)
        {
            id = i+1;
            break;
        }

    }
    return id;
}

int cargarEmpleado(eEmployee listaDeEmpleados[],int len)
{
    int id;
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
    int lugar;
    int retorno;
    char cargar;
    char opcion_continuar;

    retorno = -1;

    do
    {
        id= idEmpleado(listaDeEmpleados,len);
        getValidarString("Ingrese su nombre: \n",nombre,50);
        primerLetraMayuscula(nombre);
        getValidarString("Ingrese su apellido: \n",apellido,50);
        primerLetraMayuscula(apellido);
        salario = getValidarFloat("Ingrese su salario: \n",5000,999999);
        sector = getValidarInt("Ingrese su sector: \n","Error, los sectores son entre",1,3);

        lugar = addEmployee(listaDeEmpleados,len,id,nombre,apellido,salario,sector);

        if(lugar!=-1)
        {
            mostrarUnEmpleado(listaDeEmpleados[id-1]);
            cargar = getRespuesta("Desea cargar este empleado?: (S/N)\n");


            if(cargar!='s' && cargar!='S')
            {
                listaDeEmpleados[lugar].isEmpty=TRUE;
                retorno = 1;

            }else
             {
                listaDeEmpleados[lugar].isEmpty=FALSE;
                retorno = 0;
             }
        }
        system("pause");
        system("cls");
        opcion_continuar = getRespuesta("Desea cargar otro empleado?: (S/N)\n");
    }while(opcion_continuar=='s'||opcion_continuar=='S');

    return retorno;
}
int empleadosCargados(eEmployee listaDeEmpleados[],int len)
{
        int i;
        int cargados;

        cargados = 0;

        for(i=0;i<len;i++)
        {
            if(listaDeEmpleados[i].isEmpty==FALSE)
            {
                cargados=cargados+1;
            }
        }
    return cargados;
}

void mostrarUnEmpleado(eEmployee unEmpleado)
{
        printf("%2d",unEmpleado.id);
        printf("%30s",unEmpleado.name);
        printf("%30s",unEmpleado.lastName);
        printf("%30.2f",unEmpleado.salary);
        printf("%20d\n",unEmpleado.sector);
}

int bajaEmpleados(eEmployee listaDeEmpleados[],int len)
{
    int i;
    int id;
    int retorno;
    char respuesta;
    char continuar;

    retorno = -1;

    do
    {
        printEmployees(listaDeEmpleados,len);
        id = getValidarInt("Ingrese el id que desea borrar: \n","Error, los ID disponibles son entre",0,len);

    for(i=0;i<len;i++)
    {
        if(id==listaDeEmpleados[i].id&&listaDeEmpleados[i].isEmpty==FALSE)
        {
            mostrarUnEmpleado(listaDeEmpleados[i]);
            respuesta = getRespuesta("Desea eliminar este empleado?: (S/N) \n");

            if(respuesta=='S' || respuesta == 's')
            {
                retorno = removeEmployee(listaDeEmpleados,len,id);
            }else
            {
                retorno = 1;
            }


            break;
        }else
        {
            printf("No existe el id\n");
            break;
        }

    }

    continuar = getRespuesta("Desea eliminar otro empleado? (S/N)\n");
    system("cls");
    }while((continuar=='s'||continuar=='S')&& (listaDeEmpleados[i].isEmpty==FALSE));
    return retorno;
}
char getRespuesta(char mensaje [])
{
    char auxChar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxChar);
    auxChar=tolower(auxChar);
    while(auxChar<'a'|| auxChar>'z')
    {
        printf("No es una letra\nIngrese una opcion valida por favor: \n");
        scanf("%c",&auxChar);
    }
    return auxChar;
}
void ordenarPorSalario (eEmployee listaDeEmpleados[], int len)
{
    int i; // variable de control del for
    int cantidadEmpleados;

    cantidadEmpleados=empleadosCargados(listaDeEmpleados,len);

    float salarioTotal; //guardara el salario total de todos los empleados que retornara la funcion emplouee_salaryAcum
    float salarioPromedio; //guardara el salario promedio
    salarioTotal = salarioAcumulado(listaDeEmpleados, len);
    salarioPromedio = salarioTotal / cantidadEmpleados;
    printf("\n El salario promedio es: %.2f\n\n", salarioPromedio);
    printf("Los empleados que lo superan son: \n\n");
    for (i=0;i<len;i++)
    {
        if (listaDeEmpleados[i].salary > salarioPromedio && listaDeEmpleados[i].isEmpty == FALSE)
        {
            printf("%s %s\n\n",listaDeEmpleados[i].name, listaDeEmpleados[i].lastName);
        }
    }
}
float salarioAcumulado (eEmployee listaDeEmpleados[], int len)
{
    int i; // variable de control del for
    float salarioAcumuladoEmpleados=0; //guardara el salario total de todos los empleados
    for (i=0;i<len; i++)
    {
        if (listaDeEmpleados[i].isEmpty==FALSE)
        {
            salarioAcumuladoEmpleados+= listaDeEmpleados[i].salary;
        }
    }
    printf("\n\nLa suma total de los salarios es: %.2f\n", salarioAcumuladoEmpleados);
    return salarioAcumuladoEmpleados;
}

int getInt(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    return numero;
}
float getFloat(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);
    return numero;
}
char getChar(char mensaje[], char respuesta)
{
    char letra;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&letra);
    letra = tolower(letra);
    respuesta = letra;
    return respuesta;
}
void getString(char mensaje[], char texto[])
{
    char cadena[200];
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",cadena);
    strcpy(texto, cadena);
}
void getSexo(char mensaje[], char sexo)
{
    char letra;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&letra);
    letra = toupper(letra);
    sexo = letra;
}
int esNumero(char cadena[])
{
    int i; //indice para revisar el string
    int flag=1; //bandera que permite saber si solo posee numeros
    i=0;
    while (cadena[i]!='\0')
    {
        if (cadena[i]<'0'||cadena[i]>'9')
        {
            flag=-1;
        }
    i++;
    }
return flag;
}
int getCadenaNumeros(char mensaje[], char numeros[])
{
    char auxInt[200];
    int flag;
    flag=-1;
    getString(mensaje, auxInt);
    if (esNumero(auxInt)==1)
    {
        strcpy(numeros,auxInt);
        flag=1;
    }
return flag;
}

int getValidarInt(char mensaje[], char mensajeError[], int masBajo, int masAlto)
{
    char auxCadena[200]; //guardara un string de numeros
    int auxInt; //permite pasar el string de numeros a int para poder compararlo con maximos y minimos
    int finalInt; //int en caso de validarse

    getCadenaNumeros(mensaje, auxCadena);
    auxInt = atoi(auxCadena);

    while (auxInt < masBajo || auxInt > masAlto)
    {
        printf("%s %d y %d\n\n",mensajeError, masBajo, masAlto);
        getCadenaNumeros(mensaje, auxCadena);
        auxInt = atoi(auxCadena);
    }
    finalInt = auxInt;

return finalInt;
}
int esNumeroFlotante(char cadena[])
{
    int i; //indice que permite revisar el string de floats
    int flag=1; //bandera que permite saber si tiene solo numeros y puntos
    i=0;
    while (cadena[i]!='\0')
    {
        if ((cadena[i]<'0'||cadena[i]>'9') && cadena[i]!='.')
        {
            flag=-1;
        }
    i++;
    }
return flag;
}



int getCadenaNumerosFlotantes(char mensaje[], char salida[])
{
    char auxCadena[200]; //guardara un string de flotantes
    int flag; //bandera que permite saber si el string es un numero flotante
    flag=-1;
    getString(mensaje, auxCadena);
    if (esNumeroFlotante(auxCadena)==1)
    {
        strcpy(salida, auxCadena);
        flag=1;
    }
return flag;
}

float getValidarFloat(char mensaje[], float masBajo, float masAlto)
{
    char auxCadena[200]; //guardara un string de floats
    float auxFloat; //permite pasar el string de floats a float para poder compararlo con maximos y minimos
    float finalFloat;

    getCadenaNumerosFlotantes(mensaje, auxCadena);
    auxFloat = atof(auxCadena);

    while (auxFloat < masBajo || auxFloat > masAlto)
    {
        printf("Recuerde que solo puede ingresar un numero entre %.2f y %.2f\n\n", masBajo, masAlto);
        getCadenaNumerosFlotantes(mensaje, auxCadena);
        auxFloat = atof(auxCadena);
    }
    finalFloat = auxFloat;

return finalFloat;

}
int esCadenaSoloLetras(char cadena[])
{
    int i; //indice para revisar el string
    int flag=1; //bandera que permite saber si solo posee letras y espacios
    i=0;
    while (cadena[i]!='\0')
    {
        if ((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z') && cadena[i]!=' ')
        {
            flag=-1;
        }
    i++;
    }
return flag;
}
int getCadenaSoloLetras(char mensaje[], char salida[])
{
    char auxCadena[200]; //guarda un string
    int flag; //bandera que permite saber si el string contiene solo letras
    flag=-1;
    getString(mensaje, auxCadena);
    if (esCadenaSoloLetras(auxCadena)==1)
    {
        strcpy(salida, auxCadena);
        flag=1;
    }
return flag;
}

void getValidarString (char mensaje[], char salida[], int tamCadena)
{
   while (getCadenaSoloLetras(mensaje, salida)==-1 || (strlen(salida)>tamCadena) || salida[0]==' ')
    {
        printf("Por favor, %s. \n\n", mensaje);
    }
}

void primerLetraMayuscula(char nombre[])
{
    strlwr(nombre);

    nombre[0] = toupper(nombre[0]);
    int i=0;

    while(nombre[i]!='\0')
    {

        if(nombre[i]==' ')
        {
            nombre[i+1]= toupper (nombre[i+1]);

        }
        i++;
    }
}
void cadenaEnMayuscula (char letras[])
{
    int i; //variable de control que permite revisar el string

    for (i=0; letras[i] != '\0'; i++)
    {
    letras[i] = toupper(letras[i]);
    }
}

void cadenaEnMinuscula (char letras[])
{
    int i; // variable de control que permite revisar el string

    for (i=0; letras[i] != '\0'; i++)
    {
        letras[i] = tolower(letras[i]);
    }
}
