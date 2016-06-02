#include <iostream>
#include "TLB.h"
#define ENTRADAS_TLB 4
#define SUCCESS 1


TLB ::TLB(int  entradas_tp)
{
  //entradas_tabla_de_pagina=entradas_tp;
  entradas = new EntradaTLB[ENTRADAS_TLB];
  int j = 0;
  for (j = 0; j < ENTRADAS_TLB; j++)
    entradas[j] = EntradaTLB();
}


int TLB ::LRU(int direccion_virtual)
{


  int nro_pagina = get_pagina_virtual(direccion_virtual);

  //si cae en algun caso deberiamos romper el for


//Caso A
  //diciendo q fue exitoso
  if (primer_caso(nro_pagina)) return SUCCESS;
  else if (segundo_caso(nro_pagina)) return SUCCESS;
//Caso C
//Debemos reemplazar un entrada de la Tp la entradas menos reciente
//debemos reemplazar en tablapagina



  return 0;
}

bool TLB::segundo_caso(int nro_pagina) {
  std::cout << "FUNCION SEGUNDOCASO" << std::endl;


  for (int i = 0; i < ENTRADAS_TLB; i++) {
    if (entradas[i].V == 0) {

      EntradaTP aux = tabla_pagina->get_entrada(nro_pagina);


// caso cuando v=1,
      if (aux.V == 1) {
        std::cout << "segundo caso, V = 1 en tabla de pagina" << std::endl;

        entradas[i].Nmp = aux.Nmp;
        aux.set_R(nro_pagina);
        entradas[i].V = 1;
        entradas[i].R = 1;
        entradas[i].Npv = nro_pagina;
        return true ;
      }


      if (aux.V == 0) {
        std::cout << "segundo caso, V = 0 en tabla de pagina" << std::endl;
        if (tabla_pagina->cantidad_marcos_disponibles != 0) {
          std::cout << "quedan marcos disponibles" << std::endl;
          tabla_pagina->cantidad_marcos_disponibles--;

          // Se actualiza la entrada en la tabla de pagina
          aux.Nmp = tabla_pagina->posicion_actual;
          aux.V = 1;
          aux.R = 1;
          // Se actualiza la entrada en la entrada libre de la TLB
          entradas[i].Nmp = tabla_pagina->posicion_actual;
          entradas[i].V = 1;
          entradas[i].R = 1;
          entradas[i].Npv = nro_pagina;
          //se cambia el puntero de la posicion actual
          tabla_pagina->posicion_actual++;
          return true ;

        }
        else {
          std::cout << "NO quedan marcos disponibles" << std::endl;
          return true;
        }
      }

    }
  }
  return false;
}



bool TLB::primer_caso(int nro_pagina) {
  std::cout << "FUNCION PRIMERCASO" << std::endl;

  for (int i = 0; i < ENTRADAS_TLB; i++) {

    if (nro_pagina == entradas[i].Npv && entradas[i].V == 1) {
      std::cout << "primer caso, V = 1 y npv = en tabla de pagina" << std::endl;
      entradas[i].set_R(1);
      tabla_pagina->get_entrada(nro_pagina).set_R(1);
      tabla_pagina->get_entrada(nro_pagina).set_V(1);
      return true;
    }
  }
  return false;
}



EntradaTLB* TLB ::at(int posicion)
{


  return 0;
}

//si es 0 es un miss y debe buscar
// si es un hit retorna un 1
void TLB ::buscar_direccion(int npv)
{

  if (entradas->V == 0) {
    //  for(int i =0; i< entradas_tabla_de_pagina;i++){
    //  if(npv==entradas[i]){
    /* no match for ‘operator==’ (operand types are ‘int’ and ‘Entrada’)
       if(npv==entradas[i]){*/


    // }
  }
}


void TLB ::set_tp(TablaPagina *tabla) {

  tabla_pagina = tabla;

}

void TLB ::buscar_npv(unsigned int direccion_virtual)
{
  /*
  for (int i = 0; i < ENTRADAS_TLB; i++)
    {
      //primero debemos analizar el valor del bit valido
      if (TLB_instrucciones[i].npv == get_pagina_virtual(direccion_virtual) && TLB_instrucciones[i].V == 1)
      // TODO: Comparar entrada i-ésima con la página asociada a la direccion virtual dada
      {
        TLB_instrucciones[i].R = 1;
        // TODO: marcar bit referencia
        return;
      }




      else{

      if(marcos_disponibles>0){
        marcos_disponibles--;
        //marcos_libres
      //debemos elegir un marco libre, asignarlo a la entrada y marcar el bit de validez como valido y
      //referencia como valido. Ademas actalizar la TLB con ese marco.

      }
  }
      if(marcos_disponibles=0){
        //debemos quitar con LRU un marco en la tabla de pagina,
        //asignar el marco, cambiar V y R, y actualizar la TLB

      }
      //buscamos
    }
    // Si se llega a este punto, la dirección virtual no se encuentra en la TLB
    // Hay que buscarla en la tabla de página.
    buscar_en_tabla_de_pagina(direccion_virtual);
    // TODO: actualizar TLB
  */
}
