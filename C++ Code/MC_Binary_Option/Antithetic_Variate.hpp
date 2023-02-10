//
//  Antithetic_Variate.hpp
//  BinOption_ref_main19
//
//  Created by Jason on 21/04/2021.
//

#ifndef Antithetic_Variate_hpp
#define Antithetic_Variate_hpp

double MC_Antithetic_Variate( double& S0, double& E,double& r,double& V, double& T,
                             double payoff(double& S,double& E),long& N);

double payoff_call(double& ST, double& E);

double payoff_put (double& ST, double& E);

#endif /* Antithetic_Variate_hpp */
