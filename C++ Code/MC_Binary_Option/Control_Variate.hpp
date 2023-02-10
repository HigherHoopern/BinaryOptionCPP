//
//  Control_Variate.hpp
//  BinOption_ref_main19
//
//  Created by Jason on 21/04/2021.
//

#ifndef Control_Variate_hpp
#define Control_Variate_hpp


double Euler_Maruyama( double& S0, double& r,double& V,double& T);

double MC_Control_Variate(double& S0, double& E, double& r,double& V,
                          double& T,double payoff(double& S, double& E),long& N);

#endif /* Control_Variate_hpp */
