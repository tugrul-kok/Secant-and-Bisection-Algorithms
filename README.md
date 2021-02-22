# Secant-and-Bisection-Algorithms
Secant and bisection algorithms are implemented in order to solve 𝑓(𝑥)=0 for any given homogenous polynomial f.

This program takes the coefficients of the function, initial guesses and the tolerance value as command line arguments and return the resulting values of x as well as the numbers of iterations for each method. Both methods first implemented separately. Then a hybrid method is used where it start with bisection methods for the first two iterations and then continue with secant method for the rest of the iterations. This program prints out the number of iterations required for each of the 3 methods (i.e., bisection, secant, and hybrid).

n+1 command line inputs for the coefficients of 𝑓(𝑥)= 𝑎𝑛 * 𝑥^n + 𝑎𝑛−1 * 𝑥^𝑛−1 +⋯+ 𝑎1 * 𝑥 +𝑎0 in the order from 𝑎𝑛 to 𝑎0.
3 more command line inputs for the initial guesses 𝑥0, 𝑥1 (𝑥1>𝑥0) and the tolerance value 𝑡𝑜𝑙.

Example:
The command line arguments are:
2 2 -7 1 -7 1.5 1.8 0.001
This program solves 2𝑥^4 + 2𝑥^3− 7𝑥^2 + 𝑥 −7 = 0 and find a root close to 1.67.
