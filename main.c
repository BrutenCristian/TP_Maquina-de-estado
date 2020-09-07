#include <stdio.h>
#include <stdlib.h>

int main()
{
   int dist, estado=0,obs;
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
        Giro();
        obs=Analizo();
        break;
       case 2://devuelve 0 si hay obstaculo, 1 si lo hay
        Giro();
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
       Avanza();
   }
}
