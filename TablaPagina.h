#ifndef _TablaPagina_ 
#define _TablaPagina_ 

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Tabla.h"
#include "Entrada.h"
#include "EntradaTP.h"



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
  int at(int posicion);
  void buscar_npv(unsigned int direccion_virtual);
  EntradaTP get_entrada(int posicion);

};


#endif