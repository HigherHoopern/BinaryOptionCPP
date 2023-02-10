#include "MCSimulation.hpp"
#include "MathLib.hpp"
#include <cmath>

void MCSimulation::GenPricePath(double T, int M, PricePath& S)
{
   double St = S0;
   for(int i=0; i<M; i++)
   {
      S[i]= St*exp((r-0.5*V*V)*(T/M) +V*sqrt(T/M)*Gauss());
      St=S[i];
   }
}
