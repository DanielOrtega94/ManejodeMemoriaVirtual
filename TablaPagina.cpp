#include "TablaPagina.h"
#define LIBRE 0
#define OCUPADO 1

TablaPagina::TablaPagina()
{

}

// crea la tabla de pagina y agrega entradas por defecto
//v=0 y r=0 sin nmp definido
//
TablaPagina::TablaPagina(int cantidad, int cantidad_marcos_de_pagina)
{
    marco_actual = 0;
    puntero_LRU = 0;
    contador_de_fallos = 0;
    cantidad_marcos_disponibles  = cantidad_marcos_de_pagina;
    tamano = cantidad;
    tamano_mp = cantidad_marcos_de_pagina;
    entrada = new EntradaTP[cantidad];
    int k = 0;
    for (k = 0; k < cantidad; k++)
    {
        entrada[k] = EntradaTP();
    }
    marcos_libres = new bool[cantidad_marcos_de_pagina];
    for (unsigned int i = 0; i < cantidad_marcos_de_pagina; i++)
    {
        marcos_libres[i] = LIBRE;
    }

}


EntradaTP* TablaPagina::get_entrada(int posicion)
{

    if (posicion < tamano)

        return &entrada[posicion];
    else
        throw - 1;
}



void  TablaPagina::imprimir()
{

    for (int i = 0; i < tamano; i++)
    {
        std::cout << "i:%d V:%d R:%d Nmp:%d" << i << entrada[i].V << entrada[i].R << entrada[i].Nmp << endl;
    }

}

int TablaPagina::circular()
{
    return (marco_actual++) % tamano;
}
int TablaPagina::circular_LRU()
{
    return (puntero_LRU++) % tamano;
}
