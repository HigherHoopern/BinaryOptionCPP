#include <iostream>
#include "BinaryOption.hpp"
#include "BSModel.hpp"
#include "MCSimulation.hpp"
#include "Antithetic_Variate.hpp"
#include "Control_Variate.hpp"
using namespace std;

int main()
{
   double S0=100.0, r=0.05, V=0.2;
   MCSimulation MCS(S0,r,V);

   double T=1.0, E=100.0;
   int M=1;
   BinaryCall Call(T,E,M);

   long N=100000;
    
    cout << "Number of Simulations: " << N << endl;
    cout << "Stock Price:     " << S0 << endl;
    cout << "Strike Price:    " << E << endl;
    cout << "Risk-Free Rate:  " << r << endl;
    cout << "Volatility:      " << V << endl;
    cout << "Time_Inverval:   " << M << endl ;
    cout << "Time_to_Expiry:  " << T << endl << endl;
    
    BSModel BSM;
    cout << "Black Scholes Binary Call Value = "
        << BSM.CallOption(S0, E, r, T, V) << endl;
    
    cout << "Black Scholes Binary Put Value  =  "
        << BSM.PutOption(S0, E, r, T, V) << endl<<endl;
    
    cout << "Monte Catol Binary Call Value   =  "
        << Call.MCPricer(MCS,N) << endl <<
    "Pricing Error = " << Call.PError << endl;
    
    BinaryPut Put(T,E,M);
    cout << "Monte Catol Binary Put  Value   =  "
         << Put.MCPricer(MCS,N) << endl<<endl;
    
    
    cout << "Antithetic_Variate call price   =  "
    << MC_Antithetic_Variate(S0,E,r,V,T,payoff_call,N) << endl;
    cout << "Antithetic_Variate put price    =  "
    << MC_Antithetic_Variate(S0,E,r,V,T,payoff_put,N)<< endl<<endl;
    
    
    std::cout << "Control_Variate call option price = " << MC_Control_Variate(S0,E,r,V,T,payoff_call,N) <<std::endl;
    std::cout << "Control_Variate put option price  = " << MC_Control_Variate(S0,E,r,V,T,payoff_put,N)<<std::endl;

   return 0;
}
