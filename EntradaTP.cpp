#include "EntradaTP.h"


EntradaTP::EntradaTP()
{
  //debe ser 1, ya que no considemoras el caso donde se invalide la entradas
  V = 0;
  R = 0;
}

EntradaTP::EntradaTP(int nmp)
{
  V = 1;
  R = 1;
  Nmp = nmp;
}
void EntradaTP::set_V(int v)
{
  V = v;
}
void EntradaTP::set_R(int v)
{
  R = v;
}
void EntradaTP::set_Nmp(unsigned int v)
{
  Nmp = v;
}
// Este metodo no deberia estar aqui..
void EntradaTP::set_Npv(unsigned int v)
{
  exit(EXIT_FAILURE);
}
