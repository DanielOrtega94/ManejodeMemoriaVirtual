#ifndef _ADTEntrada_
#define _ADTEntrada_ 

#include <cstdio>
#include <cstdlib>
#include <iostream>


using namespace std;

//clase virtual para el uso de polimorfismo

class Entrada {

public:
  char V;
  char R;
  virtual void set_V(int  v) = 0;
  virtual void set_R(int  v) = 0;
  virtual void set_Nmp(unsigned int v) = 0;
  virtual void set_Npv(unsigned int v) = 0;
};

#endif