#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "EntradaTLB.h"
#include "EntradaTP.h"
#include "Entrada.h"
#include "TLB.h"
#include "TablaPagina.h"
#include "Tabla.h"

#define ENTRADAS_TLB 4
#define ITERACIONES 100000
#define INSTRUCCION 0
#define DATO 1
#define TAMANIO_DIRECCION_VIRTUAL_EN_BITS 32

using namespace std;

int contador_fallas;
int puntero_mp = 0;
unsigned int entradas_tabla_de_pagina = 0;
unsigned int cantidad_memoria_fisica_en_MB = 0;
unsigned int tamanio_pagina_en_KB = 0;
unsigned int cantidad_marcos_de_pagina = 0;
unsigned int bits_offset = 0;
unsigned int bits_npv = 0;
unsigned int bits_mp = 0;
unsigned int** marcos_de_pagina = NULL;
unsigned int PUROS_UNOS = ~(0 << (TAMANIO_DIRECCION_VIRTUAL_EN_BITS - 1));
unsigned int PUROS_CEROS = 0 << (TAMANIO_DIRECCION_VIRTUAL_EN_BITS - 1);

unsigned long long int calcular_marcos_de_pagina()
{
	return (cantidad_memoria_fisica_en_MB / tamanio_pagina_en_KB) * (1 << 10); // se multiplica por 2^10 para compensar la diferencia de unidades
}

unsigned int calcular_bits_offset()
{
	int retorno = 0;
	int aux = tamanio_pagina_en_KB;
	while (aux != 1)
	{
		aux /= 2;
		retorno++;
	}
	return retorno + 10; // mas diez porque está en KB
}

unsigned int calcular_bits_marco_pagina()
{
	int retorno = 0;
	int aux = cantidad_marcos_de_pagina;
	while (aux != 1)
	{
		aux /= 2;
		retorno++;
	}
	return retorno;
}

unsigned int get_offset(unsigned int direccion_virtual)
{
	return (~(PUROS_UNOS << bits_offset)) & direccion_virtual;
}

unsigned int get_pagina_virtual(unsigned int direccion_virtual)
{
	return direccion_virtual >> bits_offset;
}

int main(int argc, char const *argv[])
{

	unsigned char caracter_leido[2] = {'\0', '\0'}; // ocupo string en vez de char para que no lea whitespace
	unsigned int direccion_leida = 0x0;

	FILE* archivo_trace = fopen(argv[1], "r");

	if (archivo_trace == NULL) {
		perror("Error: ");
		exit(1);
	}

	printf("Ingrese la cantidad de memoria física (en MB): ");
	scanf("%d", &cantidad_memoria_fisica_en_MB);
	printf("Ingrese el tamaño de página (en KB): ");
	scanf("%d", &tamanio_pagina_en_KB);

	cantidad_marcos_de_pagina = calcular_marcos_de_pagina();
	bits_offset = calcular_bits_offset();
	bits_npv = TAMANIO_DIRECCION_VIRTUAL_EN_BITS - bits_offset;
	bits_mp = calcular_bits_marco_pagina();
	entradas_tabla_de_pagina = 1 << (bits_npv);

	// crea los objetos necesarios para emular la tarea
	TLB TLB_instrucciones(entradas_tabla_de_pagina);
	TLB TLB_datos(entradas_tabla_de_pagina);
	TablaPagina* tabla_de_pagina = new TablaPagina(entradas_tabla_de_pagina, cantidad_marcos_de_pagina);
	//marcos libres estara en 1 si esta disponible y 0 si no lo esta
	TLB_instrucciones.set_tp(tabla_de_pagina);
	TLB_datos.set_tp(tabla_de_pagina);
//seteamos todos los marcos de pagina como disponible en un principio


	printf("Tamaño entrada tlb: %lu\n", sizeof(EntradaTLB));
	printf("Tamaño entrada tp: %lu\n", sizeof(EntradaTP));

	printf("Memoria física en MB: %u\n", cantidad_memoria_fisica_en_MB);
	printf("Tamaño de página en KB: %u\n", tamanio_pagina_en_KB);
	printf("Entradas de la tabla de página (cantidad de páginas virtuales): %u\n", entradas_tabla_de_pagina);
	printf("Cantidad de marcos de página: %u\n", cantidad_marcos_de_pagina);
	printf("Número de marcos de página: %u\n", bits_npv);
	printf("Bits para offset: %u\n", bits_offset);
	printf("Bits para número de página virtual: %u\n", bits_npv);
	printf("Bits para número de marco de página: %u\n", bits_mp);

	//while (!feof(archivo_trace))
	for (int i = 0; i < ITERACIONES; i++)
	{
		fscanf(archivo_trace, "%s", caracter_leido);
		fscanf(archivo_trace, "%x", &direccion_leida);
		//printf("Caracter leído: %c\n", caracter_leido);
		printf("%s ", caracter_leido);
		printf("%x\n", direccion_leida);
		//printf("Dirección virtual: %x\n", direccion_leida);

		printf("offset: %x\n", get_offset(direccion_leida));
		printf("pagina virtual: %x\n", get_pagina_virtual(direccion_leida));

		//ejecuccion principal del programa
		// TODO: implementar  las funciones
		if (caracter_leido[0] == 'i')
		{
			
			printf("Se leyó una instrucción\n");
				TLB_instrucciones.LRU(direccion_leida);
		}
		else if (caracter_leido[0] == 'l')
		{
			//TLB_datos(get_pagina_virtual(direccion_leida));
			printf("Se leyó un load\n");
			TLB_datos.LRU(direccion_leida);
		}
		else if (caracter_leido[0] == 's')
		{
			// TLB_datos(get_pagina_virtual(direccion_leida));
			printf("Se leyó un store\n");
			TLB_datosLRU(direccion_leida);
		}
		else
		{
			printf("Algo terrible sucedió! Abandonen todas las esperanzas");
			exit(EXIT_FAILURE);
		}
	}


	return 0;
}
