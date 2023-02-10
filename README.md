# Binary Option Valuation in C++

This Project is to value binary option using Monte Carol simulation and BS model in C++

## 1. Introduction and Objectives

This task is to use the Monte Carlo (MC) scheme to price binary options under the risk-neutral density Q, in which the option value is expected value of the discounted payoff. The Monte Carlo simulation method is widely used to price a range of financial derivatives. The Monte Carlo has become an important approach to simulate one factor and multi-factor options. In general, this simulation is performed by approximating the stochastic differential equation (SDE) which models the underlying asset with regards to financial derivative products. It is of importance to give an overview of MC and and its main implementation tool is C++ because of its popularity in quantitative finance and Python is employed to be a complementary plotting in this task since C++ is a little tricky to visualization. 

### Theory Overviews

*Boyle (1977) employed Monte Carlo method to estimate option price for the first*

*time. He calculated a plain call option price in using MC.*


*### 1.1 Monte Carlo Method*

*To obtain the risk-neutral prices of financial derivatives, Monte Carlo simulation is a*

*practical algorithm. The math theorem behind this approach is the central limit*

*theorem. This indicates that the price computed by MC simulation is the risk-neutral*

*price. Furthermore, the standard error of the estimated asset price is in proportion to*

*one divided by the square of simulation number. Thus, to increase the accuracy of this*

*estimation by we increase the number of simulation scenarios. We can also use central*

*theorem to compute confidence bounds for the errors.*


*### 1.2 Euler-Maruyama Method*

*Euler-Maruyama approximation converge with strong order 0.5 under Libschitz and bounded growth conditions on the coefficient f anf g. And the this approximation if an Ito process converges with week order 1.0. Thus, week order of convergence is better than strong order of convergence in Euler. I will use this methods to initialized MC simulation.*

## 2. Findings and Conclusion:

This project implements Monte Carol simulation to compute binary option price using C++. The mathematics theorem behind MC is central limit theorem or the law of large number. The assumption of binary option pricing is Risk-Neutral under Q measure.
A continuous Euler-Maruyama scheme is employed to initialize MC simulation. And then I use option price under Black Scholes model as a benchmark to verify the outputs of MC scheme with the simulation number of 100,000. The absolute difference between MC and BS for call and put option are 0.001182 and 0.000421 respectively at time maturity. An interesting finding is that the price error is in proportion of simulation number and reducing the pricing error by one decimal requires around 100 times more simulations. To recure the variance, I use Antithetic variate approach to increase the efficiency of simulation. However, this method only makes the call price draw near to benchmark at the value of 0.00009 and makes the absolute difference to benchmark larger at the value of 0.000043 for put price. Thus, antithetic variate is not a very practical approach to improve simulation efficiency in this case, which is in line with the finding of Boyle (1977). Moreover, our finding suggests that to control BS call option as a variate is worse than a crude MC.

Alternatively, use other parameters as control variates and moment matching and so on can be used to improve Carol simulation efficiency. Further study can be Quasi-Monte Carlo scheme and Finite Difference method.
