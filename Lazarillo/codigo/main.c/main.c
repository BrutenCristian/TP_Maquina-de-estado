#include "Lazarillo_lib.h"

int main()
{
    int enc,i=0;
    datos_t *var, valores;
    datos_t (*opciones[])(var)={Reposo,Movimiento};
    var=&valores;
    var->obs='0';
    Bienvenida();
    do
    {
        while(i<2)
        {
            *var=(*opciones[i])(var);
            i++;
        }
        printf("\nDesea dejar el lazarillo prendido?\n1-No\t0-Si\n");
        fflush(stdin);
        scanf("%d",&enc);
        i=0;
    }while(enc!=1);
}
