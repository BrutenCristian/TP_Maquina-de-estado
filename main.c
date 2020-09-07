#include <stdio.h>
#include <stdlib.h>

int main()
{
   int dist, estado=0,obs;
   char mov;
   Bienvenida();
   printf("\nEsta en el rango de distancia?\n1-si\t0-no");
   fflush(stdin);
   scanf("%d",&dist);
   if(d==0)
   {
       do{
       swith(estado)
       {
       case 0://frente
        obs=Analizo();//devuelve 0 si no hay obstaculo, 1 si lo hay
        break;
       case 1://devuelve 0 si no hay obstaculo, 1 si lo hay
        mov=Giro();//devuelve d si giro a la derecha, sino e
        obs=Analizo();
        break;
       case 2://devuelve 0 si hay obstaculo, 1 si lo hay
        mov=Giro();//devuelve i si giro a la izquierda, sino e
        obs=Analizo();
        break;
       case 3:
        delay();
        break;
       }
       if(obs!=0)
       {
           estado++;
       }
       if(estado==4)
       {
           estado=0;
       }
       }while(obs!=0);//con el 0 no hay obstaculo
       mov=Avanza();//devuelve a si avanza, sino e
   }
}
