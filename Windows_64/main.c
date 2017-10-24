#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int i;
    int* ids= (int*) malloc(sizeof(int)*3);
    int id = 0;

    ArrayList* lista = al_newArrayList();

    Employee* emple1;
    Employee* emple2;
    Employee* emple3;

    Employee* auxiliar;

    emple1 = employee_new(1,"juan","cruz",1);
    emple2 = employee_new(2,"alberto","perez",1);
    emple3 = employee_new(3,"matias","sacatumoco",1);

    lista->add(lista,emple1);
    lista->add(lista,emple2);
    lista->add(lista,emple3);

    printf("Imprimiendo los empleados jarcodeados con employee_print():\n\n");
    for(i=0; i<lista->len(lista) ; i++)
    {
        auxiliar = lista->get(lista,i);

        employee_print(auxiliar);
    }

    printf("\nObtiene el id por employee_getId():\n\n");
    for(i=0; i<lista->len(lista) ; i++)
    {
        auxiliar = lista->get(lista,i);

        *(ids+i) = employee_getId(auxiliar);

        printf("el ID del empleado es: %d\n\n",*(ids+i));
    }

     printf("Setea los IDs de los empleados por employee_setId(): \n\n");

    for(i=0; i<lista->len(lista) ; i++)
    {
        auxiliar = lista->get(lista,i);

        if(employee_setId(auxiliar,id))
        {
           employee_print(auxiliar);
        }
        else
        {
            printf("no se pudo realizar la operacion.\n");
        }


    }


    printf("\nQuita un empleado con employee_delete():\n\n");
    employee_delete(lista,emple2,1);
    for(i=0; i<lista->len(lista) ; i++)
    {
        auxiliar = lista->get(lista,i);

        employee_print(auxiliar);
    }

    return 0;
}
