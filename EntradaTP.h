#ifndef _ENTRADATP_
#define _ENTRADATP_
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Entrada.h"

#define ENTRADAS_TLB 4
#define ITERACIONES 10
#define INSTRUCCION 0
#define DATO 1
#define TAMANIO_DIRECCION_VIRTUAL_EN_BITS 32



class EntradaTP : public Entrada
{
public:
  unsigned int V;
	unsigned int R;
	unsigned int Nmp;
  

  EntradaTP(); 
  EntradaTP(int nmp);
  void set_V(char v);
  void set_Nmp(unsigned int v);
  void set_R(char v);
  //Este metodo no deberia estar aqui...
  void set_Npv(unsigned int v);
};

#endif