#ifndef LAZARILLO_H_INCLUDED
#define LAZARILLO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

void Funcionamiento(void);
int Distancia(void);
void Giros(int o);

void Velocidad(int);
int Analizo(void);
int (*Estados)(void);
void Bienvenida(void);
int valor_conf(char V[]);
char * getkey(char *key);

void Bienvenida(void)
{
    printf("\nBienvenido a esta emulacion de un lazarillo robotico.");
    system("pause");
    system("cls");
    return;
}
char * getkey(char *key)
{
    char i=0;
    while(*(key+i) !=' ')
    {
       // printf("\n%c",*(key+i));
        i++;
    }
    *(key+i)='\0';
    return key+i+1;
}
int valor_conf(char V[])
{
    FILE *conf;
    char cadena[55],*key,*val,i=0;
    int valor;
    if((conf=fopen("config.conf","rt"))==NULL)
    {
        printf("\nError al abrir el archivo de configuracion.");
        system("pause");
        return -1;
    }
    fgets(&cadena,55,conf);
    key=cadena;
    while(*(key+i)!=V[0])
    {
        i++;
    }
    key=key+i;
    if(*key!=' ' && *key!='NULL')
    {
        val=getkey(key);
    }
    valor=atoi(val);
    return valor;
}
void Funcionamiento(void)
{
    int d,sensor,vel,md,mi;
    char V[]="vel";
    int (*Estados[])()={Analizo,Distancia};
    d=(*Estados[1])();
    while(d==0)
    {
        sensor=(*Estados[0])();
        if(sensor==0)
        {
          vel=valor_conf(V);
          md=vel;
          mi=vel;
          printf("\nEl lazarillo se mueve a: %d",vel);
        }
    }
    return;
}
int Distancia(void)
{
    int dist, maximo;
    char V[]="Dist";
    printf("\nDistancia entre usted y el lazarillo: ");
    fflush(stdin);
    scanf("%d",&dist);
    maximo=valor_conf(V);
    if(maximo<dist)
    {
        printf("\nFuera de rango.");
        system("pause");
        return -1;
    }
    else
    {
        printf("\nDentro del rango.");
        system("pause");
        return 0;
    }
}
int Analizo(void)
{
    int op=0,estado,frente,iz,der,sensor=0,t;
    char V[]="Sensor";
    char v[]="Esp";
    estado=valor_conf(V);
    do
    {
        printf("\nHay un obstaculo al frente?\n0->No\t1->Si\n");
        fflush(stdin);
        scanf("%d",&frente);

        if(frente==estado)
        {
            return 0;
        }
        op=1;
        Giros(op);
        printf("\nHay un obstaculo al nuevo frente?\n0-No\t1-Si\n");
        fflush(stdin);
        scanf("%d",&der);
        if(der==estado)
        {
            return 0;
        }
        op=2;
        Giros(2);
        printf("\nHay un obstaculo al nuevo frente?\n0-No\t1-Si\n");
        fflush(stdin);
        scanf("%d",&iz);
        if(iz==estado)
        {
            return 0;
        }
        t=valor_conf(v);
        Sleep(t*1000);
    }while(sensor!=0);
}
void Giros(int o)
{
    int vel,t,Motor_derecho,Motor_izquierdo;
    char V[]="Vel";
    char v[]="Tgiro";
    vel=valor_conf(V);
    t=valor_conf(v);
    if(o=1)
    {
        Motor_derecho=-1*vel;
        Motor_izquierdo=vel;
        Sleep(t*1000);
        printf("\nEl lazarillo giro hacia la derecha.");
        system("pause");
        return;
    }
    else
    {
        Motor_derecho=vel;
        Motor_izquierdo=-1*vel;
        Sleep(t*1000);
        printf("\nEl lazarillo giro hacia la izquierda.");
        system("pause");
        return;
    }
}

#endif // LAZARILLO_H_INCLUDED
