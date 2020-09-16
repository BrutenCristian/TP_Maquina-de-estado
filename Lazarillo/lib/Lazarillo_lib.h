#ifndef LAZARILLO_LIB_H_INCLUDED
#define LAZARILLO_LIB_H_INCLUDED

#define DERECHA 'd'
#define IZQUIERDA 'i'
#define FRENTE_DESDE_IZQUIERDA 'f'
#define FRENTE_DESDE_DERECHA 'F'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
typedef struct
{
    float distancia;
    float motor_d;
    float motor_i;
    char obs;
}datos_t;
void Bienvenida(void);
datos_t Reposo(datos_t *val);
datos_t Movimiento(datos_t *val);
datos_t (*opciones)(datos_t *val);
float Distancia(void);
unsigned char Frente(void);
unsigned char Derecha(void);
unsigned char Izquierda(void);
unsigned char (*Analisis)(void);
void Giros(unsigned char o);
void Espera(int t);
int valor(char v[]);
char * getkey(char *v);

#endif // LAZARILLO_LIB_H_INCLUDED
