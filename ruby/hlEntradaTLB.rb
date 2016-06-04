#!usr/bin/ruby

load 'Entrada.rb'

class EntradaTLB < Entrada
	def initialize(nmp=0, npv=0, v=0, r=0)
		@v = v
		@r = r
		@npv = npv
		@nmp = nmp
	end
end

# entrada = EntradaTLB.new(3, 5, 4, 1)
# puts "#{entrada.v}, #{entrada.r}, #{entrada.npv}, #{entrada.nmp}"
