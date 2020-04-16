#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    float a;
    float b;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int factorialA;
    int factorialB;

    int flagA;
    int flagB;

    flagA = 0;
    flagB = 0;

    do
    {
        if(flagA==0)
        {
            printf("1. Ingresar 1er operando (A=x)\n");
        }else
        {
            printf("1. Ingresar 1er operando (A=%.3f)\n",a);
        }

        if(flagB==0)
        {
            printf("2. Ingresar 2do operando (B=y)\n");
        }else
        {
            printf("2. Ingresar 2do operando (B=%.3f)\n",b);
        }


        printf("3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
                printf("Ingrese primer operando: \n");
                scanf("%f",&a);
                flagA = 1;
                break;
        case 2: printf("Ingrese el segundo operando: \n");
                scanf("%f",&b);
                flagB = 1;
                break;
        case 3: printf("Calculando suma de %.3f+%.3f\n",a,b);
                printf("Calculando resta de %.3f-%.3f\n",a,b);
                printf("Calculando division de %.3f/%.3f\n",a,b);
                printf("Calculando multiplicacion de %.3f*%.3f\n",a,b);
                printf("Calculando factorial de %.3f!\n",a);
                printf("Calculando factorial de %.3f!\n",b);
                break;
        case 4: suma = funcionSuma(a,b);
                printf("El resultado de %.3f+%.3f es: %.3f\n",a,b,suma);
                resta = funcionResta(a,b);
                printf("El resultado de %.3f-%.3f es: %.3f\n",a,b,resta);
                if(b==0)
                {
                    printf("No es posible dividir por cero\n");
                }
                else
                {
                    division = funcionDivision(a,b);
                    printf("El resultado de %.3f/%.3f es: %.3f\n",a,b,division);
                }
                multiplicacion = funcionMultiplicacion(a,b);
                printf("El resultado de %.3f*%.3f es: %.3f\n",a,b,multiplicacion);
                if(a>=0)
                {
                  factorialA = funcionFactorial(a);
                  printf("El factorial de %.3f es: %d\n",a,factorialA);
                }else
                {
                    printf("No es posible factorizar un numero negativo\n");
                }
                if(b>=0)
                {
                    factorialB = funcionFactorial(b);
                    printf("El factorial de %.3f es: %d\n",b,factorialB);

                }else
                {
                    printf("No es posible factorizar un numero negativo\n");
                }



            break;

        case 5:

            break;

        default:
                printf("No ingreso una opcion valida\n");
                break;
        }
      system("pause");
      system("cls");
    }while(opcion!=5);
    return 0;
}
