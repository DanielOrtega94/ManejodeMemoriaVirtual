#!usr/bin/ruby

load 'EntradaTP.rb'
class TablaPagina

	def initialize(cantidad, cantidad_marcos_de_pagina)
		@marco_actual = 0
		@puntero_LRU = 0
		@contador_de_fallos = 0
		@cantidad_marcos_disponibles = cantidad_marcos_de_pagina
		@tamano = cantidad
		@tamano_mp = cantidad_marcos_de_pagina
		@entrada = Array.new(cantidad, EntradaTP.new)

		#esta wea no se ocupa
		@marcos_libres = Array.new(cantidad_marcos_de_pagina, false)
	end
	def get_entrada(posicion)
		if @posicion < @tamano
			return @entrada[posicion]
		else
			puts "indice fuera de rango"
		end
	end

	def imprimir
		@entrada.each{|x| puts "V: #{x.v}, R: #{x.r}, Nmp:#{x.nmp}"}
	end

	def circular
		@marco_actual += 1
		return @marco_actual % @tamano
	end
	def circular_LRU
		@puntero_LRU += 1
		return @puntero_LRU % @tamano
	end

end

tabla = TablaPagina.new(32, 16)
tabla.imprimir
