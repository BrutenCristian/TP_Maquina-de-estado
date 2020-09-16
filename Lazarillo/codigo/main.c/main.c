#include "Lazarillo_lib.h"

int main()
{
    int enc,i=0;
    datos_t *var, valores;
    datos_t (*opciones[])(var)={Reposo,Movimiento};
    var=&valores;
    var->obs='0';
    Bienvenida();
       while(1)
    {
        (*opciones[i])(var);
        i++;
        printf("\nSi desea apagar el lazarillo presione esc.");
        if(kbhit)
        {
            ch=getch();
            if((int)ch==27)
            {
                break;
            }
        }
        if(i==2)
        {
            i=0;
        }
    }
}
