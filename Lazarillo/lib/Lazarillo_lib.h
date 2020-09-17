#ifndef LAZARILLO_LIB_H_INCLUDED
#define LAZARILLO_LIB_H_INCLUDED

#define DERECHA 'd'
#define IZQUIERDA 'i'
#define FRENTE_DESDE_IZQUIERDA 'f'
#define FRENTE_DESDE_DERECHA 'F'
#define ADENTRO 'a'
#define FUERA 'A'
#define REPOSO 'r'
#define MOVIMIENTO 'm'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    float distancia;
    float motor_d;
    float motor_i;
    char obs;
    char rango_d;
    char estado;
}datos_t;
void Bienvenida(void);
datos_t Reposo(datos_t *val);
datos_t Movimiento(datos_t *val);
datos_t (*opciones)(datos_t *val);
//float Distancia(void);
datos_t Distancia(datos_t *val);
unsigned char Frente(void);
unsigned char Derecha(void);
unsigned char Izquierda(void);
unsigned char (*Analisis)(void);
void Giros(unsigned char o);
void Espera(int t);
int valor(char v[]);
char * getkey(char *v);

#endif // LAZARILLO_LIB_H_INCLUDED
