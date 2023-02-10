

//  Created by Jason on 21/04/2021.
//
#include <algorithm>
#include <cmath>
#include <iostream>
#include "MathLib.hpp"

using namespace std;

double payoff_call(double& ST, double& E){
    if (ST>=E) return 1;
    return 0;};

double payoff_put (double& ST, double& E) {
    if (ST<=E) return 1;
    return 0;};

long N;
double MC_Antithetic_Variate( double& S0, double& E,double& r,double& V, double& T,
                             double payoff(double& ST,double& E) ,long& N) {
    double Sum_Payoffs=0;
    for (int i=0; i<N; i++) {
        double S1 = S0 * exp((r - 0.5 * V*V)*T + V * sqrt(T) * Gauss());
        Sum_Payoffs += payoff(S1,E);
        double S2 = S0 * exp((r - 0.5 * V*V )*T + V * sqrt(T) * (-Gauss()));
        Sum_Payoffs += payoff(S2,E);
    };
    return exp(-r*T) * (Sum_Payoffs/(2*N));
};
