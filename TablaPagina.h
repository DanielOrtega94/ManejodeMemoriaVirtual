#ifndef _TablaPagina_
#define _TablaPagina_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Entrada.h"
#include "EntradaTP.h"
#define LIBRE 0
#define OCUPADO 1


extern unsigned int get_pagina_virtual(unsigned int direccion_virtual);



using namespace std;

class TablaPagina
{
public:
    //arreglo de marcos libres, pero no se esta ocupando
    bool *marcos_libres;

    // Lleva la cuenta de los marcos de pagina desocupados
    int cantidad_marcos_disponibles;
    //Tamaño total de marcos de pagina disponibles,se usa para hacer lista circular
    int tamano_mp;
    // variable que recorre el arreglo de marcos de pagina
    int marco_actual;
    //  denota la posicion del puntero actual
    int puntero_LRU;
    //tamaño de la tabla de pagina
    int tamano;

    //contador para fallos de Tabla de pagina
    int contador_de_fallos;
    //arreglo de entradas
    EntradaTP *entrada;

    //contructor que recibe la cantidad de entradas de la tabla de pagina y la cantidad de mar
    TablaPagina(int cantidad, int cantidad_marcos_de_pagina);



    //construcctor dado por defecto
    TablaPagina();


    // Retorna el objeto entrada que se encuentra en la posición 'posicion' de esta tabla de pagina
    EntradaTP* get_entrada(int posicion);

//funcion que buscar la posicion de un marco libre, si no se encontre
    //retorna un 0
    //muestra los campos de la tabla
    void imprimir();
    // entrega puntero de posicion actual a tabla de pagina
    int circular();
    //entrega puntero de posicion acutal
    int circular_LRU();




};


#endif
