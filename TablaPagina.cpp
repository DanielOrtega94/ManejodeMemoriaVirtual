#include "TablaPagina.h"


  TablaPagina::TablaPagina(){
    
  }
  
  // crea la tabla de pagina y agrega entradas por defecto
  //v=0 y r=0 sin nmp definido
  TablaPagina::TablaPagina(int cantidad)
  {
    tamano=cantidad;
   entrada = new EntradaTP[cantidad];
    int k=0;
    for(k=0; k<cantidad; k++){
      EntradaTP *nueva = new EntradaTP();
      //entrada[k] = nueva;
      //entrada->push_back(nueva);
      printf("V:%c\n",nueva->V);
    }
    
  }


  int TablaPagina::LRU(int direccion_virtual)
  {
  
    return 0;
  }
  

  int TablaPagina::at(int posicion)
  { 
  	return 0;
  }


  void TablaPagina::buscar_npv(unsigned int direccion_virtual)
{/*
  //boramos argumento tipo de direccion, la idea era definir si era dato o instruccion
  //unsigned int numero_pagina_virtual = get_pagina_virtual(direccion_virtual);
  //if (tabla_de_pagina[numero_pagina_virtual].V == 1)/*TODO: testear si bit valido es 0
  //{
    //tabla_de_pagina[numero_pagina_virtual].R = 1;
    //buscar sitio en tlb, y copiar en ella
    //necesitamos la funcion q nos copie en TLB
    // TODO: buscar marco libre
    // 
  //}

  //else{

    if(marcos_disponibles>0){
      marcos_disponibles--;
      puntero_mp++;
      //resto 1 por el ++ anterior
      algoritmo_LRU(numero_pagina_virtual, puntero_mp-1);
      
      //marcos_libres
    //debemos elegir un marco libre, asignarlo a la entrada y marcar el bit de validez como valido y 
    //referencia como valido. Ademas actalizar la TLB con ese marco.

    }

    if(marcos_disponibles=0){
      // debemos iterar entradas_tabla_de_pagina veces
      //debemos quitar con LRU un marco en la tabla de pagina,
      //asignar el marco, cambiar V y R, y actualizar la TLB

    }
    //buscamos 
  }*/
}
/*

int TablaPagina:: valido(int npv)
{

  return entrada[npv].V;

}

int TablaPagina:: referenciado(int npv)
{

  return entrada[npv].R;

}*/

   EntradaTP TablaPagina::get_entrada(int posicion){

      if(posicion<tamano)
        //entrada[posicion].set_V(1);

       return entrada[posicion];
     // else 
      //  return NULL;
   }
