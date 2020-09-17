#include "lib_lazarillo.h"

int main()
{
    //int i=0;
    char ch;
    datos_t *var, valores;
    datos_t (*opciones[])(var)={Reposo,Movimiento};
    var=&valores;
    var->obs='0';
    var->estado=REPOSO;
    Bienvenida();
    Distancia(var);//pregunta anticipada
    do
    {
        while(valores.rango_d==FUERA)
        {
            Distancia(var);
        }
        if(var->estado==REPOSO)
        {
            (*opciones[0])(var);
        }
        else
        {
            (*opciones[1])(var);
            Distancia(var);
        }
        printf("\nSi desea apagar el lazarillo presione esc.");
        if(kbhit)
        {
            ch=getch();
            if((int)ch==27)
            {
                break;
            }
    }
    }while(valores.rango_d==ADENTRO);
   /* while(1)
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
    }*/

}
