#ifndef _TablaPagina_ 
#define _TablaPagina_ 

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Tabla.h"
#include "Entrada.h"
#include "EntradaTP.h"



extern unsigned int get_pagina_virtual(unsigned int direccion_virtual);



using namespace std;

class TablaPagina : public Tabla
{
  public:
  //tamaño de la tabla de pagina
  int tamano;
  //arreglo de entradas
  EntradaTP *entrada;
  //contructor que recibe la cantidad de entradas de la tabla de pagina 
  TablaPagina(int cantidad);
  //construcctor dado por defecto
  TablaPagina();
  int LRU(int direccion_virtual);
  EntradaTP* at(int posicion);
  void buscar_npv(unsigned int direccion_virtual);
  EntradaTP get_entrada(int posicion);

//se refiere al caso  V=1 y R=1 
  bool primer_caso(int npv);
  //se refiere al caso V=0
  bool segundo_caso(int npv);

};


#endif