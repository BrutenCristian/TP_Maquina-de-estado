#include <stdio.h>
#include <stdlib.h>
#include "Lazarillo.h"
int main()
{
    int estado;
    Bienvenida();
    do
    {
        Funcionamiento();
        printf("\nDesea que el lazarillo permanezca prendido?");
        printf("1-Encendido\t2-Apagado");
        fflush(stdin);
        scanf("%d",&estado);
    }while(estado!=2);
}
