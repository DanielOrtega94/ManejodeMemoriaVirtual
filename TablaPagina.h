#ifndef _TablaPagina_
#define _TablaPagina_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Tabla.h"
#include "Entrada.h"
#include "EntradaTP.h"
#define LIBRE 0
#define OCUPADO 1


extern unsigned int get_pagina_virtual(unsigned int direccion_virtual);



using namespace std;

class TablaPagina : public Tabla
{
public:
  //arreglo de marcos libres, pero no se esta ocupando
  bool *marcos_libres;

  // Lleva la cuenta de los marcos de pagina desocupados
  int cantidad_marcos_disponibles;
  //Tamaño total de marcos de pagina disponibles,se usa para hacer lista circular
  int tamano_mp;
  // variable que recorre el arreglo de marcos de pagina
  int posicion_actual;
  //tamaño de la tabla de pagina
  int tamano;
  //arreglo de entradas
  EntradaTP *entrada;

  //contructor que recibe la cantidad de entradas de la tabla de pagina y la cantidad de mar
  TablaPagina(int cantidad, int cantidad_marcos_de_pagina);

  //contructor que recibe la cantidad de entradas de la tabla de pagina
  TablaPagina(int cantidad);

  //construcctor dado por defecto
  TablaPagina();
  int LRU(int direccion_virtual);
  EntradaTP* at(int posicion);
  void buscar_npv(unsigned int direccion_virtual);

  // Retorna el objeto entrada que se encuentra en la posición 'posicion' de esta tabla de pagina
  EntradaTP* get_entrada(int posicion);

//se refiere al caso  V=1 y R=1
  bool primer_caso(int npv);
  //se refiere al caso V=0
  bool segundo_caso(int npv);
//funcion que buscar la posicion de un marco libre, si no se encontre
  //retorna un 0
  //muestra los campos de la tabla
  void imprimir();

  int circular();



};


#endif
