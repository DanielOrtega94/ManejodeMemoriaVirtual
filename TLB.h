#ifndef _TLB_
#define _TLB_ 

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Entrada.h"
#include "Tabla.h"
#include "EntradaTLB.h"
#include "TablaPagina.h"
#pragma once


extern unsigned int bits_offset;
extern unsigned int get_pagina_virtual(unsigned int direccion_virtual);

class TLB : public Tabla {

  public:
  TablaPagina *tabla_pagina;
	EntradaTLB *entradas;
  int entradas_tabla_de_pagina;
//construcctor donde recibe las entradas de tabla de pagina
  TLB(int entradas_tablas_de_pagina);
  
  int LRU(int direccion_virtual);
  int at(int posicion);
  int buscar_direccion(int npv);
  void buscar_npv(unsigned int direccion_virtual);
  void set_tp(TablaPagina *tabla);
 
};

#endif