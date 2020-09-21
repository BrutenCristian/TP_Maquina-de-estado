#include "lib_lazarillo.h"

int main()
{
    char ch;
    datos_t *var, valores;
    datos_t (*opciones[])(var)={Reposo,Movimiento};
    var=&valores;
    var->obs='0';
    var->estado=REPOSO;
    Bienvenida();
    while(1)
    {
            switch(valores.estado){
        case REPOSO :
           *var=Reposo(var);
            break;
        case MOVIMIENTO :
            *var=Movimiento(var);
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
