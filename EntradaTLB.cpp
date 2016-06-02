#include "EntradaTLB.h"

EntradaTLB::EntradaTLB(int nmp, int npv)
{
  V = 1;
  R = 1;
  Npv = npv;
  Nmp = nmp;
}

EntradaTLB::EntradaTLB() {
  V = 0;
  R = 0;
}

void EntradaTLB::set_V(int v)
{
  V = v;
}
void EntradaTLB::set_R(int v)
{
  R = v;
}
void EntradaTLB::set_Nmp(unsigned int v)
{
  Nmp = v;
}
void EntradaTLB::set_Npv(unsigned int v)
{
  Npv = v;
}