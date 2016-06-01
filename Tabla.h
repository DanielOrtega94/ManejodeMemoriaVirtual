#ifndef _TAbla_
#define _TAbla_ 


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Entrada.h"



class Tabla {

  public:
  // Obtiene la entrada menos recientemente usada
  virtual int LRU(int direccion) = 0;
  // obtiene la entrada en la posicion i
  virtual Entrada* at(int i) = 0;
  virtual void buscar_npv(unsigned int direccion_virtual)=0;
};

#endif