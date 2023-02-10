#ifndef BinaryOption_hpp
#define BinaryOption_hpp
#include "MCSimulation.hpp"

class BinaryOption
{
public:
      double T;
      double Price;
      double PError;
      int M;
      double MCPricer(MCSimulation MCS, long N);
      virtual double Payoff(PricePath& S)=0;
};

class BinaryCall: public BinaryOption
{
   public:
      double E;
      BinaryCall(double T_, double E_, int M_)
            {T=T_; E=E_; M=M_;}
      double Payoff(PricePath& S);
};


class BinaryPut: public BinaryOption
{
   public:
      double E;
      BinaryPut(double T_, double E_, int M_)
            {T=T_; E=E_; M=M_;}
      double Payoff(PricePath& S);
};

#endif
