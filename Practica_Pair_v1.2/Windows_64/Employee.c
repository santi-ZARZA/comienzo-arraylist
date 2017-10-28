#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno = 0;
    Employee* auxiliar;
    Employee* auxiliar2;

        if(pEmployeeA != NULL && pEmployeeB != NULL)
        {
            auxiliar = (Employee*) pEmployeeA;
            auxiliar2 = (Employee*) pEmployeeB;

            if(strcmp(auxiliar->name,auxiliar2->name) > 0)
            {
                retorno = 1;
            }
        }

    return retorno;
}


void employee_print(Employee* this)
{
    printf("%d\t\t%s\t\t%s\t\t%d\n\n",this->id,this->name,this->lastName,this->isEmpty);
}


Employee* employee_new(void)
{
    Employee* returnAux = (Employee*) malloc(sizeof(Employee));

    return returnAux;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


