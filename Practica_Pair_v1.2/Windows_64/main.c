#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
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
    FILE* archivo;
    ArrayList* lista = al_newArrayList();
    Employee* auxiliar;
    Employee* agrega;

    int contando = 50;
    int i;
    char opcion;
    char seguir = 's';
    char menu[]= "    Menu:\n1. Parse del archivo data.csv\n2. Listar Empleados\n3. Ordenar por nombre\n4. Agregar un elemento\n5. Elimina un elemento\n6. Listar Empleados (Desde/Hasta)";


    do
    {
        system("cls");
        puts(menu);
        printf("\ningrese la opcion deseada: ");
        fflush(stdin);
        opcion = tolower(getch());

        switch(opcion)
        {
            case '1':
                parserEmployee(archivo,lista);
                break;
            case '2':
                system("cls");
                    for(i=0; i<lista->len(lista) ; i++)
                    {
                        auxiliar = (Employee*) lista->get(lista,i);
                        employee_print(auxiliar);
                    }
                system("pause");
                break;
            case '3':
                lista->sort(lista,employee_compare,1);
                break;
            case '4':
                agrega = employee_new();
                agrega->id = 7000;
                strcpy(agrega->name,"zzzzzz");
                strcpy(agrega->lastName,"zzzzzz");
                agrega->isEmpty = 1;

                lista->add(lista,agrega);
                break;
            case '5':
                employee_delete(agrega);
                i = lista->indexOf(lista,agrega);
                lista->remove(lista,i);
                break;
            case '6':
                contando = 51;
                system("cls");
                printf("empleados 0 hasta el 50:\n\n");
                    for(i=1; i<contando ; i++)
                    {
                        auxiliar = (Employee*) lista->get(lista,i);
                        employee_print(auxiliar);
                    }
                    system("pause");
                break;
            case '7':
                seguir = 'n';
                break;
        }

    }while(seguir == 's');

    return 0;
}
