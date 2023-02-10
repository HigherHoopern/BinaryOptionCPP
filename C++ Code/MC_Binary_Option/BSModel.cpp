//
//
//  Created by Jason on 20/04/2021.
//

#include "BSModel.hpp"
#include "MathLib.hpp"
#include <cmath>
// define a class named BS_Model to verify the result of Monte Carol simulations
// BS_Model class is based on Black-Scholes model;

    // compute binary call option value
    double BSModel::CallOption(double& S, double& E, double& r, double& T, double& V){
        double d2;
        d2 = log (S/E) + (r - 0.5*V*V)*T/V*sqrt(T);
        return exp(-r*T)*NormalCDF(d2);
    }
    // compute binary put option value
    double BSModel::PutOption(double& S, double& E, double& r, double& T, double& V){
        double d2;
        d2 = log (S/E) + (r - 0.5*V*V)*T/V*sqrt(T);
        return exp(-r*T)* (1 - NormalCDF(d2));
    }

