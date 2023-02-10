//
//  Control_Variate.cpp
//  BinOption_ref_main19
//
//  Created by Jason on 21/04/2021.
//

#include "Control_Variate.hpp"
#include "MathLib.hpp"
#include "Antithetic_Variate.hpp"
#include <cmath>
#include <iostream>

double Euler_Maruyama( double& S0, double& r,
                       double& V,double& T) {
return S0 * exp((r-0.5*V*V)*T + V * sqrt(T) * Gauss());
};

double MC_Control_Variate(double& S0, double& E, double& r,
                          double& V,  double& T,
                          double payoff(double& S0, double& E),long& N) {
    
    double Call_BSM = 0.532325;
    double Sum_Payoffs=0;
    double Sum_Payoffs_BSM=0;
    for (int i=0; i<N; i++) {
    double ST=Euler_Maruyama(S0,r,V,T);
    Sum_Payoffs += payoff(ST,E);
    Sum_Payoffs_BSM += payoff_call(ST,S0); // simulate at the money Black Scholes price
    };
    double Call_Sim = exp(-r*T) * (Sum_Payoffs/N);
    double Call_BSM_Sim = exp(-r*T) * (Sum_Payoffs_BSM/N);
    Call_Sim+= (Call_BSM - Call_BSM_Sim);
    return Call_Sim;
};










