#ifndef _ENTRADATLB_
#define _ENTRADATLB_
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Entrada.h"



class EntradaTLB : public Entrada
{
public:
  unsigned int V;
	unsigned int R;
	unsigned int Npv;
	unsigned int Nmp;

  EntradaTLB(int nmp, int npv);
  EntradaTLB();
  void set_V(char v);
  void set_Npv(unsigned int v);
  void set_Nmp(unsigned int v);
  void set_R(char v);
};

#endif