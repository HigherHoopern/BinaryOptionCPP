#include "BinaryOption.hpp"
#include <cmath>

double BinaryOption::MCPricer(MCSimulation MCS, long N)
{
   double Avg=0.0, HT=0.0;
   PricePath S(M);
   for(long i=0; i<N; i++)
   {
      MCS.GenPricePath(T,M,S);
      Avg = (i*Avg + Payoff(S))/(i+1);
      HT=(i*HT + pow(Payoff(S), 2))/(i+1);
   }
   PError = exp(-MCS.r*T)/sqrt(N-1)*sqrt(HT-Avg*Avg);
   return Price = exp(-MCS.r*T)*Avg;
}

double BinaryCall::Payoff(PricePath& S)
{
   double ST=0.0;
   for (int i=0; i<M; i++)
       ST=(i*ST+S[i])/(i+1);
   if (ST>E)
       return 1;
   return 0;
}


double BinaryPut::Payoff(PricePath& S)
{
   double ST=0.0;
   for (int i=0; i<M; i++)
       ST=(i*ST+S[i])/(i+1.0);
   if (ST<E)
       return 1;
   return 0;
}


