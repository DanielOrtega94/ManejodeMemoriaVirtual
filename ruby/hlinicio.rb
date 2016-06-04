#!usr/bin/ruby
# coding:utf-8

load 'EntradaTLB.rb'
load 'EntradaTP.rb'
load 'TLB.rb'
load 'TablaPagina.rb'

ENTRADAS_TLB = 4
ITERACIONES = 100000
INSTRUCCION = 0
DATO = 1
TAMANIO_DIRECCION_VIRTUAL_EN_BITS = 32
PUROS_UNOS = 0xffffffff

contador_fallas = 0
puntero_mp = 0
entradas_tabla_de_pagina = 0
cantidad_memoria_fisica_en_MB = 0
tamanio_pagina_en_KB = 0
cantidad_marcos_de_pagina = 0
bits_offset = 0
bits_npv = 0
bits_mp = 0
marcos_de_pagina = nil
# PUROS_CEROS = 0 << (TAMANIO_DIRECCION_VIRTUAL_EN_BITS - 1)

def calcular_marcos_de_pagina()
	return (cantidad_memoria_fisica_en_MB/tamanio_pagina_en_KB) * (1 << 10) # se multiplica por 2^10 para compensar la diferencia de unidades
end

def calcular_bits_offset()
	retorno = 0
	aux = tamanio_pagina_en_KB

	while aux != 1
		aux /= 2
		retorno += 1
	end

	return retorno + 10 # mas diez porque está en KB
end

def calcular_bits_marco_pagina()
	retorno = 0
	aux = cantidad_marcos_de_pagina

	while aux != 1
		aux /= 2
		retorno += 1
	end

	return retorno
end

def get_offset(direccion_virtual)
	return (~(PUROS_UNOS << bits_offset)) & direccion_virtual
end

def get_pagina_virtual(direccion_virtual)
	return direccion_virtual >> bits_offset
end


# unsigned char caracter_leido[2] = {'\0', '\0'} // ocupo string en vez de char para que no lea whitespace
# unsigned int direccion_leida = 0x0
# TODO: abrir el archivo
#FILE* archivo_trace = fopen(argv[1], "r")
archivo_trace = nil

if archivo_trace == nil
	puts "Error!!"
	exit(1)
end

puts "Ingrese la cantidad de memoria física (en MB):"
# TODO: implementar la lectura
# scanf("%d", &cantidad_memoria_fisica_en_MB)
puts "Ingrese el tamaño de página (en KB): "
# TODO: implementar la lectura
# scanf("%d", &tamanio_pagina_en_KB)

cantidad_marcos_de_pagina = calcular_marcos_de_pagina()
bits_offset = calcular_bits_offset()
bits_npv = TAMANIO_DIRECCION_VIRTUAL_EN_BITS - bits_offset
bits_mp = calcular_bits_marco_pagina()
entradas_tabla_de_pagina = 1 << (bits_npv)

# crea los objetos necesarios para emular la tarea
tlb_instrucciones = TLB.new(entradas_tabla_de_pagina)
tlb_datos = TLB.new(entradas_tabla_de_pagina)
tabla_de_pagina = TablaPagina.new(entradas_tabla_de_pagina, cantidad_marcos_de_pagina)
# marcos libres estara en 1 si esta disponible y 0 si no lo esta
TLB_instrucciones.set_tp(tabla_de_pagina)
TLB_datos.set_tp(tabla_de_pagina)
# seteamos todos los marcos de pagina como disponible en un principio

# TODO: buscar equivalente a sizeof
puts "Tamaño entrada tlb:" # sizeof(EntradaTLB)
puts "Tamaño entrada tp: " # sizeof(EntradaTP)
puts "Memoria física en MB: #{cantidad_memoria_fisica_en_MB}"
puts "Tamaño de página en KB: #{tamanio_pagina_en_KB}"
puts "Entradas de la tabla de página (cantidad de páginas virtuales): #{entradas_tabla_de_pagina}"
puts "Cantidad de marcos de página: #{cantidad_marcos_de_pagina}"
puts "Número de marcos de página: #{bits_npv}"
puts "Bits para offset: #{bits_offset}"
puts "Bits para número de página virtual: #{bits_npv}"
puts "Bits para número de marco de página: #{bits_mp}"

# while (!feof(archivo_trace))
for i in 0...ITERACIONES
	# TODO: implementar lectura
	fscanf(archivo_trace, "%s", caracter_leido)
	fscanf(archivo_trace, "%x", &direccion_leida)
	puts "Caracter leído: #{caracter_leido}"
	puts "#{caracter_leido}"
	puts "#{direccion_leida}"
	puts "Dirección virtual: #{direccion_leida}"

	puts "offset: #{get_offset(direccion_leida)}"
	puts "pagina virtual: #{get_pagina_virtual(direccion_leida)}"

	#ejecuccion principal del programa
	if caracter_leido == 'i'
		puts "Se leyó una instrucción"
		TLB_instrucciones.LRU(direccion_leida)
	elsif caracter_leido == 'l'
		# TLB_datos(get_pagina_virtual(direccion_leida))
		puts "Se leyó un load"
		TLB_datos.LRU(direccion_leida)
	elsif caracter_leido == 's'
		# TLB_datos(get_pagina_virtual(direccion_leida))
		puts "Se leyó un store"
		TLB_datos.LRU(direccion_leida)
	else
		puts "Algo terrible sucedió! Abandonen todas las esperanzas"
		exit(-1)
	end
end

puts "fallos: TLB:  datos: #{TLB_datos.contador_de_fallos}\ninstrucciones: #{TLB_instrucciones.contador_de_fallos}"
puts "fallos Tabla Pagina: #{tabla_de_pagina.contador_de_fallos}"
