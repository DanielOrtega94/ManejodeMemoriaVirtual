#include "EntradaTP.h"


EntradaTP::EntradaTP()
  {
    V = 0;	
    R = 0;
  }

  EntradaTP::EntradaTP(int nmp)
  {
    V = 1;
    R = 1;
    Nmp = nmp;
  }
  void EntradaTP::set_V(char v)
  {
    V=v;
  }
  void EntradaTP::set_R(char v)
  {
    R=v;
  }
  void EntradaTP::set_Nmp(unsigned int v)
  {
     Nmp=v;
  }
  // Este metodo no deberia estar aqui..
 void EntradaTP::set_Npv(unsigned int v)
  {
    cout << "no puede setear Nmp, porque es una entrada en TP" <<endl;
  }
 