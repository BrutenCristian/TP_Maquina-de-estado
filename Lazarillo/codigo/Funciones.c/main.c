#include "Lazarillo_lib.h"

void Bienvenida(void)
{
    printf("\nBienvenido a esta emulacion del comportamiento de un lazarillo electronico.");
    printf("\nTodo el comportamiento sera emulado por el usuario.");
    system("pause");
    return;
}
datos_t Reposo(datos_t *val)
{
    char /*dist[]="Dist",*/ sensor[]="Sensor", td[]="Esp", sens;
    int t/*, i=0*/;
    unsigned char (*Analisis[])()={Frente,Derecha,Izquierda};
    //float dist_conf;
    //dist_conf=(float)valor(dist);
    sens=(char)valor(sensor);
    t=valor(td);
    /*do
    {
        val->distancia=Distancia();
        if(dist_conf<val->distancia)
        {
            printf("\nFuera del rango de distancia.");
            val->motor_d=0;
            val->motor_i=0;
            Espera(t/2);
            system("pause");
        }
    }while(dist_conf<val->distancia);
*/
 //   do
   // {
        val->motor_d=0;
        val->motor_i=0;
        for(int i=0;i<3;i++)
        {
            val->obs=(*Analisis[i])();
            if(val->obs=='1')
            {
                val->estado=MOVIMIENTO;
                break;
            }
        }
        if(val->obs=='0')
        {
            val->estado=REPOSO;
            printf("\nEsperando.");
            Espera(t);
        }
   // }while(val->obs!='1');
    return *val;
}
datos_t Movimiento(datos_t *val)
{
    char vel[]="Vel";
    float v;
    v=(float)valor(vel);
    val->motor_d=v;
    val->motor_i=v;
    printf("\nLos motores se mueven a %.2f rpm",v);
    printf("\nHay un obstaculo al frente?\n1-No\t0-Si\n");
    fflush(stdin);
    scanf("%c",&val->obs);
    if(val->obs=='1')
    {
        val->estado=REPOSO;
    }
    else
    {
        val->estado=MOVIMIENTO;
    }
    return *val;
}
/*float Distancia(void)
{
    float dist;
    printf("\n¿A que distancia se encuentra el lazarillo del usuario?\n");
    fflush(stdin);
    scanf("%f",&dist);
    return dist;
}*/
datos_t Distancia(datos_t *val)
{
    char dist[]="Dist", td[]="Esp";
    float dist_conf;
    int t;
    dist_conf=(float)valor(dist);
    t=valor(td);
    printf("\nA que distancia(en Cm) se encuentra el lazarillo del usuario? ");
    fflush(stdin);
    scanf("%f",&val->distancia);
    if(dist_conf<val->distancia)
    {
        val->rango_d=FUERA;
        printf("\nFuera del rango de distancia.");
        val->motor_d=0;
        val->motor_i=0;
        Espera(t/2);
        system("pause");
        return *val;
    }
    else
    {
        val->rango_d=ADENTRO;
        printf("\nDentro del rango de distancia.");
        system("pause");
        return *val;
    }
}
unsigned char Frente(void)
{
    char sens;
    printf("\n¿Hay un obstaculo al frente?\n1-No\t0-Si\n");
    fflush(stdin);
    scanf("%c",&sens);
    return (unsigned char)sens;
}
unsigned char Derecha(void)
{
    char obs;
    Giros(DERECHA);
    printf("\n¿Hay un obstaculo al frente?\n1-No\t0-Si\n");
    fflush(stdin);
    scanf("%c",&obs);
    if(obs=='0')
    {
        Giros(FRENTE_DESDE_DERECHA);
    }
    return (unsigned char)obs;
}
unsigned char Izquierda(void)
{
    char obs;
    Giros(IZQUIERDA);
    printf("\n¿Hay un obstaculo al frente?\n1-No\t0-Si\n");
    fflush(stdin);
    scanf("%c",&obs);
    if(obs=='0')
    {
        Giros(FRENTE_DESDE_IZQUIERDA);
    }
    return obs;
}
void Giros(unsigned char o)
{
    datos_t giro;
    char vel[]="Vel", tg[]="Tgiro";
    int v,t;
    v=valor(vel);
    t=valor(tg);
    switch(o)
    {
    case DERECHA://giro a la derecha
        giro.motor_d=(float)v*-1;
        giro.motor_i=(float)v;
        printf("\nEl lazarillo esta girando hacia la derecha.");
        Espera(t);
        giro.motor_d=0;
        giro.motor_i=0;
        printf("\nEl giro finalizo");
        system("pause");
        break;
    case FRENTE_DESDE_DERECHA://voy desde la derecha a la posicion inicial
        giro.motor_d=(float)v;
        giro.motor_i=(float)v*-1;
        printf("\nEl lazarillo esta volviendo a la posicion inicial desde la derecha.");
        Espera(t);
        giro.motor_d=0;
        giro.motor_i=0;
        printf("\nEl giro finalizo.");
        system("pause");
        break;
    case IZQUIERDA://giro desde la posicion inicial hacia la izquierda
        giro.motor_d=(float)v;
        giro.motor_i=(float)v*-1;
        printf("\nEl lazarillo esta girando desde la posicion inicial hacia la izquierda.");
        Espera(t);
        giro.motor_d=0;
        giro.motor_i=0;
        printf("\nEl giro finalizo.");
        system("pause");
        break;
    case FRENTE_DESDE_IZQUIERDA://giro desde la izquierda hacia la posicion inicial.
        giro.motor_d=(float)v*-1;
        giro.motor_i=(float)v;
        printf("\nEl lazarillo esta regresando a la posicion inicial desde el lado izquierdo.");
        Espera(t);
        giro.motor_d=0;
        giro.motor_i=0;
        printf("\nEl giro finalizo.");
        system("pause");
        break;
    }
    return;
}
void Espera(int t)
{
    clock_t ticks1 = clock(), ticks2 = ticks1;
       while ( ( ticks2/CLOCKS_PER_SEC - ticks1/CLOCKS_PER_SEC ) < t)
           ticks2 = clock();
           return;
}
int valor(char v[])
{
    FILE *conf;
    int i=0, val;
    char cadena[10], *p, *key, valor[5];
    if((conf=fopen("config.conf","rt"))==0)
    {
        printf("\nError al abrir el archivo de configuracion.");
        system("pause");
        return -1;
    }
    while(!feof(conf))
    {
        fgets(cadena,sizeof(cadena),conf);
        p=&cadena;
        for(int y=0;y<sizeof(v);y++)
        {
            if(*p!=v[0])
            {
                p++;
            }
        }
        if(*p==v[0])
        {
            break;
        }
    }
    key=getkey(p);
    while(*key!=' '&&*key!='\0')
    {
        valor[i]=*key;
        key++;
        i++;
    }
    val=atoi(valor);
    cadena[0]='\0';
    return val;
}
char * getkey(char *v)
{
    while(*v!=' '&&*v!='\0')
    {
        v++;
    }
    return (v+1);
}
