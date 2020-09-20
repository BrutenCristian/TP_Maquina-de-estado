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
    Distancia(var);
    while(1)
    {
        while(valores.rango_d==FUERA)
        {
            Distancia(var);
        }
            switch(valores.estado){
        case REPOSO :
           *var=Reposo(var);
            break;
        case MOVIMIENTO :
            *var=Movimiento(var);
            Distancia(var);
            break;
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
    }
}
