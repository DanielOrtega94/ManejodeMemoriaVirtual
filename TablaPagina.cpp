#include "TablaPagina.h"
#define LIBRE 0
#define OCUPADO 1

TablaPagina::TablaPagina() {

}

// crea la tabla de pagina y agrega entradas por defecto
//v=0 y r=0 sin nmp definido
//
TablaPagina::TablaPagina(int cantidad, int cantidad_marcos_de_pagina)
{
  posicion_actual = 0;
  cantidad_marcos_disponibles  = cantidad_marcos_de_pagina;
  tamano = cantidad;
  tamano_mp = cantidad_marcos_de_pagina;
  entrada = new EntradaTP[cantidad];
  int k = 0;
  for (k = 0; k < cantidad; k++) {
    entrada[k] = EntradaTP();
  }
  marcos_libres = new bool[cantidad_marcos_de_pagina];
  for (unsigned int i = 0; i < cantidad_marcos_de_pagina; i++) {
    marcos_libres[i] = LIBRE;
  }

}

int TablaPagina::LRU(int direccion_virtual)
{

  int nro_pagina = get_pagina_virtual(direccion_virtual);

  if (entrada[nro_pagina].V == 1 && entrada[nro_pagina].R == 0) {

    entrada[nro_pagina].R = 1;
    //copiar entradaTP y npv en la TLB
    //respaldar en la posicion libre
  }

  else if (entrada[nro_pagina].V == 1 && entrada[nro_pagina].R == 1) {
//respaldar en la poscion menor recientemente usada


  }

  else if (entrada[nro_pagina].V == 0 ) {
//si hay MP disponibles, copiamos el nmp, copiar el nmp a la entrada de la TP
// y V=1 y R=1

//no hay MP disponibles, aplicamos LRU a la TP  y le quitamos el MP
//y V=1 y R=1, despues copiamos  la entrada en la TLB menos recientemente usada



  }

  return 0;
}


EntradaTP* TablaPagina::at(int posicion)
{
  return 0;
}


void TablaPagina::buscar_npv(unsigned int direccion_virtual)
{ /*
   //boramos argumento tipo de direccion, la idea era definir si era dato o instruccion
   //unsigned int numero_pagina_virtual = get_pagina_virtual(direccion_virtual);
   //if (tabla_de_pagina[numero_pagina_virtual].V == 1)// TODO: testear si bit valido es 0
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

EntradaTP* TablaPagina::get_entrada(int posicion) {

  if (posicion < tamano)

    return &entrada[posicion];
  else
    throw - 1;
}


// este me todo actualiza R
bool TablaPagina::primer_caso(int npv) {
  entrada[npv].R = 1;

}
//metodo debe busar un marco libre
bool TablaPagina::segundo_caso(int npv) {

}

void  TablaPagina::imprimir() {

for(int i =0;i<tamano;i++){
  std::cout<< "i:%d V:%d R:%d Nmp:%d" << i<< entrada[i].V << entrada[i].R << entrada[i].Nmp<< endl;
}

}

int TablaPagina::circular(){
  return (posicion_actual++)%tamano;
}