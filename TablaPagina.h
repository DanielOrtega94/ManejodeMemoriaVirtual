#ifndef _TablaPagina_ 
#define _TablaPagina_ 

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Tabla.h"
#include "Entrada.h"
#include "EntradaTP.h"
#include <vector>


using namespace std;

class TablaPagina : public Tabla
{
  public:
  vector<EntradaTP*> *entrada;
 // EntradaTP *entrada;
  //contructor que recibe la cantidad de entradas de la tabla de pagina 
  TablaPagina(int cantidad);
  //construcctor dado por defecto
  TablaPagina();
  int LRU(int direccion_virtual);
  int at(int posicion);
  void buscar_npv(unsigned int direccion_virtual);
  //int valido(int npv);
  //int referenciado(int npv);
  EntradaTP get_entrada(int posicion);

};


#endif