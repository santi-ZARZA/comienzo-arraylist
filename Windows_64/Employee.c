#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    printf("%d\t\t%s\t\t%s\t\t%d\n\n",this->id,this->name,this->lastName,this->isEmpty);
}


Employee* employee_new(int id,char* name,char* LastName,int isEmpty)
{

    Employee* returnAux = (Employee*) malloc(sizeof(Employee));

    if(returnAux != NULL)
    {
        returnAux->id = id;
        strcpy(returnAux->name,name);
        strcpy(returnAux->lastName,LastName);
        returnAux->isEmpty = isEmpty;
    }

    return returnAux;

}

void employee_delete(ArrayList* lista,Employee* this,int index)
{
    lista->remove(lista,index);
    free(this);

}

int employee_setId(Employee* this, int id)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->id = id;
        retorno = 1;
    }

    return retorno;

}

int employee_getId(Employee* this)
{
    int retorna= 0;

    if(this != NULL)
    {
        retorna = this->id;
    }

    return retorna;

}


