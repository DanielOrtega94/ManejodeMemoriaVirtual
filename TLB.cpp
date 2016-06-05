#include <iostream>
#include "TLB.h"
#define ENTRADAS_TLB 4
#define SUCCESS 1


/*
No se dara segunda oportunidad al quitar un marco en la tabla de pagina
*/

TLB ::TLB(int  entradas_tp)
{
    //entradas_tabla_de_pagina=entradas_tp;
    posicion_actual = 0;
    contador_de_fallos = 0;
    entradas = new EntradaTLB[ENTRADAS_TLB];
    int j = 0;
    for (j = 0; j < ENTRADAS_TLB; j++)
        entradas[j] = EntradaTLB();


}


int TLB ::LRU(int direccion_virtual)
{


    int nro_pagina = get_pagina_virtual(direccion_virtual);

//Caso A
    //diciendo q fue exitoso
    if (primer_caso(nro_pagina)) return SUCCESS;
    else if (segundo_caso(nro_pagina)) return SUCCESS;
    else if (tercer_caso(nro_pagina)) return SUCCESS;
//Caso C
//Debemos reemplazar un entrada de la Tp la entradas menos reciente
//debemos reemplazar en tablapagina



    return 0;
}
//no genera fallos de TLB ni Tabla de Pagina
bool TLB::primer_caso(int nro_pagina)
{
    EntradaTP* aux = tabla_pagina->get_entrada(nro_pagina);
    for (int i = 0; i < ENTRADAS_TLB; i++)
    {

        if (nro_pagina == entradas[i].Npv && entradas[i].V == 1)
        {

            //std::cout << "primer caso, V = 1 y npv = en tabla de pagina" << std::endl;
            entradas[i].set_R(1);

            aux->R = 1;
            aux->V = 1;
            //std::cout << "FUNCION PRIMERCASO" << std::endl;
            return true;
        }
    }
    return false;
}

bool TLB::segundo_caso(int nro_pagina)
{


    for (int i = 0; i < ENTRADAS_TLB; i++)
    {
        if (entradas[i].V == 0)
        {
            contador_de_fallos++;
            EntradaTP* aux = tabla_pagina->get_entrada(nro_pagina);


// caso cuando v=1,
            //la pagina, ya tiene un marco de pagina asociado, entonces, solo actualizamos el bit Valido en 1 y copia a la TLB
            //fallo en TLB
            //no Hay fallo en TP
            if (aux->V == 1)
            {

                // std::cout << "segundo caso, V = 1 en tabla de pagina" << std::endl;
                entradas[i].Nmp = aux->Nmp;
                aux->set_R(1);
                entradas[i].V = 1;
                entradas[i].R = 1;
                entradas[i].Npv = nro_pagina;
                //std::cout << "FUNCION SEGUNDO  CASO" << std::endl;

                return true;
            }

            //fallo en TLB
            //fallo en TP
            if (aux->V == 0)
            {

                tabla_pagina->contador_de_fallos++;
                //std::cout << "segundo caso, V = 0 en tabla de pagina" << std::endl;
                if (tabla_pagina->cantidad_marcos_disponibles != 0)
                {
                    // std::cout << "quedan marcos disponibles" << std::endl;
                    tabla_pagina->cantidad_marcos_disponibles--;

                    // Se actualiza la entrada en la tabla de pagina
                    aux->Nmp = (tabla_pagina->marco_actual) % tabla_pagina->tamano;
                    aux->V = 1;
                    aux->R = 1;
                    // Se actualiza la entrada en la entrada libre de la TLB
                    entradas[i].Nmp = aux->Nmp;
                    entradas[i].V = 1;
                    entradas[i].R = 1;
                    entradas[i].Npv = nro_pagina;
                    //se cambia el puntero de la posicion actual
                    tabla_pagina->marco_actual++;
                    // std::cout << "FUNCION SEGUNDO  CASO" << std::endl;
                    return true ;

                }

                else
                {
                    // Esta wea no existe!! :D
                    // std::cout << "NO quedan marcos disponibles" << std::endl;
                    // std::cout << "CUARTO" << std::endl; // este no deberia suceder
                    return true;
                }
            }

        }
    }
    return false;
}



bool TLB::tercer_caso(int nro_pagina)
{

// no quedan entradas desocupadas en la TLB
    contador_de_fallos++; // contado de fallos de la tlb
    EntradaTP* aux = tabla_pagina->get_entrada(nro_pagina);
    //solamente para q entre
    //i, lo debemos cambiar por un puntero que recorra cirulamente la tlb
    int lru_tlb = circular();
    int lru_tp = (tabla_pagina->puntero_LRU) % tabla_pagina->tamano;
    //caso Npv= y entradaTP.V=1

    // este es el caso en que la pagina virtual esta mapeada a la memoria fisica pero no esta en la TLB
    if (aux->V == 1 /*&& aux->R==0*/)   // tabla de pagina tiene marco de pagina
    {

        aux->R = 1;
        entradas[lru_tlb].Nmp = aux->Nmp;
        entradas[lru_tlb].V = 1;
        entradas[lru_tlb].R = 1;
        entradas[lru_tlb].Npv = nro_pagina;
        // std::cout << "FUNCION TERCER CASO" << std::endl;
        return true;

    }
    tabla_pagina->contador_de_fallos++;//contador de fallos de la Tabla de pagina

    if(tabla_pagina->cantidad_marcos_disponibles > 0)
    {
        aux->Nmp = tabla_pagina->marco_actual;
        aux->V = 1;
        aux->R = 1;
        entradas[lru_tlb].Nmp = aux->Nmp;
        entradas[lru_tlb].V = 1;
        entradas[lru_tlb].R = 1;
        entradas[lru_tlb].Npv = nro_pagina;
        //std::cout << "FUNCION TERCER CASO" << std::endl;
        return true;
    }
    int contador_penca=0;
    // se busca una entrada que tenga bit valido 1 para quitarle el marco de pagina
    while (tabla_pagina->entrada[lru_tp].V == 0 || tabla_pagina->entrada[lru_tp].R == 1)
    {
        contador_penca++;
        lru_tp = tabla_pagina->circular_LRU();
        // cada avance no cuenta como fallo
        //consideramos como un fallo de pagina, cuando se reemplaza

    }
// cout << "contador_penca"<< contador_penca <<endl;
    // caso V=1 y R=1
    //invalidamos entraba en tabla de pagina
    aux->Nmp = tabla_pagina->entrada[lru_tp].Nmp;
    aux->V = 1;
    aux->R = 1;

    entradas[lru_tlb].Nmp = aux->Nmp;
    entradas[lru_tlb].V = 1;
    entradas[lru_tlb].R = 1;
    entradas[lru_tlb].Npv = nro_pagina;

    tabla_pagina->entrada[lru_tp].V = 0;
    tabla_pagina->entrada[lru_tp].R = 1;
//  std::cout << "FUNCION TERCER CASO" << std::endl;
    return true ;

// no deberia nunca retonar falso
    //std::cout << "RETORNA FALSO" << std::endl;
    return false;
}

int TLB::circular()
{
    return (posicion_actual++) % 4; // 4 entradas en la TLB
}

void TLB ::set_tp(TablaPagina *tabla)
{

    tabla_pagina = tabla;

}
