#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int aux;
    Employee* empleados;
   char name[2000], lastName[2000], id[2000],isEmpty[2000];

    if(pArrayListEmployee != NULL)
    {
        pFile = fopen("data.csv","r");

        if(pFile != NULL)
        {
            while(!(feof(pFile)))
            {
                fscanf(pFile," %[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,isEmpty);

               empleados = employee_new();

               empleados->id  = atoi(id);
               strcpy(empleados->name,name);
               strcpy(empleados->lastName,lastName);
                if(strcmp(isEmpty,"true") == 0)
                {
                    empleados->isEmpty = 1;
                }
                else
                {
                    empleados->isEmpty = 0;
                }


               pArrayListEmployee->add(pArrayListEmployee,empleados);
            }
        }
    }
    return 0;
}
