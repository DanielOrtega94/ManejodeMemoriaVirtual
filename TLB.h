#ifndef _TLB_
#define _TLB_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Entrada.h"
#include "Tabla.h"
#include "EntradaTLB.h"
#include "TablaPagina.h"
#include "EntradaTP.h"
#pragma once


extern unsigned int bits_offset;
extern unsigned int get_pagina_virtual(unsigned int direccion_virtual);

class TLB : public Tabla {

public:

// Puntero a tabla de pagina que se crea en el main
  TablaPagina *tabla_pagina;

  // PPuntero a un arreglo de EntradasTLB
  EntradaTLB *entradas;

  // cantidad de entradas que contendra la tabla de pagina
  //int entradas_tabla_de_pagina;

//construcctor donde recibe las entradas de tabla de pagina
  TLB(int entradas_tablas_de_pagina);

  //
  int LRU(int direccion_virtual);

  // retorna un puntero al a entrada en la posición i-esma
  EntradaTLB* at(int posicion);


  void buscar_direccion(int npv);

// referido al primer caso, sin necesidad de entrar a LRU
  bool primer_caso(int nro);
//va a buscar entradas con V=0
  bool segundo_caso(int nro);
  void buscar_npv(unsigned int direccion_virtual);
  void set_tp(TablaPagina *tabla);

};

#endif