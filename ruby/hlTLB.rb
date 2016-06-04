#!usr/bin/ruby

load 'EntradaTLB.rb'
load 'TablaPagina.rb'

ENTRADAS_TLB = 4
SUCCESS = 1
FAILURE = 0

bits_offset = 0
def get_pagina_virtual(direccion_virtual)
	bits_offset = 0
end

class TLB

	def initialize(entradas_tp)
		@posicion_actual = 0
		@contador_de_fallos = 0
		@entradas = Array.new(ENTRADAS_TLB, EntradaTLB.new)
	end

	def LRU(direccion_virtual)
		nro_pagina = get_pagina_virtual(direccion_virtual)

		#Caso A
		if primer_caso(nro_pagina)
			return SUCCESS
		elsif segundo_caso(nro_pagina)
			return SUCCESS
		elsif tercer_caso(nro_pagina)
			return SUCCESS
		end
		return FAILURE
	end

	# no genera fallos de TLB ni Tabla de Pagina
	def primer_caso(nro_pagina)
		aux = @tabla_pagina.get_entrada(nro_pagina)

		# TODO
		for entrada_tlb in @entradas

			if nro_pagina == entrada_tlb.npv && entrada_tlb.v == 1
				puts "primer caso, V = 1 y npv = en tabla de pagina"
				entrada_tlb.set_R(1)
				aux.set_R(1)
				aux.set_V(1)
				puts "FUNCION PRIMER CASO"
				return true
			end
		end

		return false
	end

	def segundo_caso(nro_pagina)
		# TODO
		for entrada_tlb in @entradas

			if entrada_tlb.v == 0
				@contador_de_fallos += 1
				aux = @tabla_pagina.get_entrada(nro_pagina)

				# caso cuando v=1,
				if aux.v == 1
					puts "segundo caso, V = 1 en tabla de pagina"
					entrada_tlb[i].set_Nmp(aux.nmp)
					aux.set_R(1)
					entrada_tlb.set_V(1)
					entrada_tlb.set_R(1)
					entrada_tlb.set_Npv(nro_pagina)
					puts "FUNCION SEGUNDO CASO"
					return true
				end

				if aux.v == 0
					# TODO
					@tabla_pagina.incrementar_fallos()
					puts "segundo caso, V = 0 en tabla de pagina"

					if tabla_pagina.cantidad_marcos_disponibles != 0
						puts "quedan marcos disponibles"
						# TODO
						@tabla_pagina.decrementar_marcos_disponibles()

						# Se actualiza la entrada en la tabla de pagina
						aux.set_Nmp((tabla_pagina.marco_actual) % tabla_pagina.tamano)
						aux.set_V(1)
						aux.set_R(1)

						# Se actualiza la entrada en la entrada libre de la TLB
						entrada_tlb.set_Nmp(aux.nmp)
						entrada_tlb.set_V(1)
						entrada_tlb.set_R(1)
						entrada_tlb.set_Npv(nro_pagina)

						# se cambia el puntero de la posicion actual
						@tabla_pagina.incrementar_marco_actual()
						puts "FUNCION SEGUNDO CASO"
						return true
					end
					else
						# falta impplementer caso
						# Esta wea no existe!! :D
						puts "NO quedan marcos disponibles"
						puts "FUNCION SEGUNDO CASO" # este no deberia suceder
						return true
					end
				end
			end
		end
		#return false
	end

	def tercer_caso(nro_pagina)
		@contador_de_fallos += 1
		# no quedan entradas desocupadas en la TLB
		aux = @tabla_pagina.get_entrada(nro_pagina)
		# solamente para q entre
		# i, lo debemos cambiar por un puntero que recorra cirulamente la tlb
		lru_tlb = circular()
		lru_tp = (tabla_pagina.puntero_LRU) % tabla_pagina.tamano
		# caso Npv= y entradaTP.V=1

		if aux.v == 1 # && aux.R==0 # tabla de pagina tiene marco de pagina

			aux.set_R(1)
			@entradas[lru_tlb].set_Nmp(aux.nmp)
			@entradas[lru_tlb].set_V(1)
			@entradas[lru_tlb].set_R(1)
			@entradas[lru_tlb].set_Npv(nro_pagina)
			puts "FUNCION TERCER CASO"
			return true

		end

		@tabla_pagina.contador_de_fallos += 1

		if @tabla_pagina.cantidad_marcos_disponibles > 0
			aux.set_Nmp(tabla_pagina.marco_actual)
			aux.set_V(1)
			aux.set_R(1)
			@entradas[lru_tlb].set_Nmp(aux.nmp)
			@entradas[lru_tlb].set_V(1)
			@entradas[lru_tlb].set_R(1)
			@entradas[lru_tlb].set_Npv(nro_pagina)
			puts "FUNCION TERCER CASO"
			return true
		end

		# se busca una entrada que tenga bit valido 1 para quitarle el marco de pagina
		while @tabla_pagina.entrada[lru_tp].v == 0
			lru_tp = @tabla_pagina.circular_LRU()
		end

		# caso V=1 y R=1
		#invalidamos entraba en tabla de pagina
		# if (aux.V == 0 /*&& aux.R == 1*/) {
		aux.set_Nmp(@tabla_pagina.entrada[lru_tp].nmp)
		aux.set_V(1)
		aux.set_R(1)

		@entradas[lru_tlb].set_Nmp(aux.nmp)
		@entradas[lru_tlb].set_V(1)
		@entradas[lru_tlb].set_R(1)
		@entradas[lru_tlb].set_Npv(nro_pagina)

		@tabla_pagina.entrada[lru_tp].set_V(0)
		@tabla_pagina.entrada[lru_tp].set_R(1)
		puts "FUNCION TERCER CASO"
		return true


		# no deberia nunca retonar falso
		puts "RETORNA FALSO"
		return false
	end

	def set_tp(tabla)
		@tabla_pagina = tabla
	end

	def circular
		@posicion_actual += 1
		return @posicion_actual % ENTRADAS_TLB
	end
$end
