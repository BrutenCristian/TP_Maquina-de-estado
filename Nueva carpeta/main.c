#include <stdio.h>
#include <stdlib.h>

int main()
{
   int dist, estado=0,obs,on,p,e;
   char mov;
   Bienvenida();
   dist=Distancia();
   do
   {
   if(d==0)
   {
       do{
       swith(estado)
       {
       case 0://frente
        obs=Analizo_Frente();//devuelve 0 si no hay obstaculo, 1 si lo hay
        break;
       case 1://devuelve 0 si no hay obstaculo, 1 si lo hay
        obs=Analizo_Derecha();
        break;
       case 2://devuelve 0 si hay obstaculo, 1 si lo hay
        obs=Analizo_Izquierda();
        break;
       case 3:
        e=delay();
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
   else
   {
       p=delay();
   }
   printf("\nDesea apagar el lazarillo?\n1-no\t0-si");
   fflush(stdin);
   scanf("%d",&on);
   }while(on!=0);
}
