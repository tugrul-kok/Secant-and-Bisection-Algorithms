#include <iostream>
#include <string>//need to use string to get file names.
#include <stdlib.h> //need to use abs() when calculating condition number and ordering pivots.
#include <vector> 
#include <cmath>
#define N (argc - 4)
using namespace std; 

double power(double number, int exponent){// this function gets a power of a number. Used to calculate x^n values in the next function.
	double value = 1;// if exponent is 0, returns 1.
    while (exponent != 0) {
        value *= number;
        --exponent;
    }
return value;}

double FofX(double x, double *coef, int n){//This function calculates F(x) value of the polynom for any given x.
	double value = 0;
	for(int i=0; i<n; i++)
		value += coef[i]*power(x,i);
	
	return value;
}

int sign(double value){//This function returns 1 if the value is positive, -1 if the value is negative, 0 if the value is 0.
	return (0 < value) - (value < 0);
}

double bisectionIteration(double *a, double *b,double tolerance, double *coef, int n){//This function does only one iteration for bisection method
		double m = ( *a + *b)/2; //equal to : a + (b-a)/2
		if(sign(FofX(*a,coef,n)) == sign(FofX(m,coef,n)))
			*a=m;
		else
			*b=m;
		return m;
}

double bisection(double a, double b,double tolerance, double *coef, int n, int *counter){//This function does bisection iterations until get a value in tolerance area
		double m=0;																		//returns root, sets counter.
		int count = 0;
		while ((b-a)>tolerance){
			count++;
			m = bisectionIteration(&a,&b,tolerance,coef,n);}
			
		*counter = count;
		
return m;}

double secant(double a, double b, double tolerance, double *coef, int n, int *counter){//This function applies secant method and return root while seting counter.
	int count=0;
	double temp;
	while(abs(b-a)>tolerance){
		count++;
		temp = b;
		b = b - FofX(b, coef, n)*(b-a) /(FofX(b, coef, n)-FofX(a, coef, n));
		a = temp;}
		
	*counter=count;
	return b;
}

int main(int argc, char *argv[]){
	
		double *coef;// this array stores coefficients of the polynom
	coef = new double[N];//N is defined as argc - 4 
	
	for(int i=0; i<N; i++)// coefficients are set in this loop
		coef[N-i-1]= atof(argv[i+1]); // coef[k] holds the coefficient for x^k.
	
	double tolerance = atof(argv[N + 3]);
	double guess1 = atof(argv[N + 1]);
	double guess2 = atof(argv[N + 2]);

	int counterForBisection = 0, counterForSecant = 0, counterForHybrid = 0;//Counters are declared.

	//Next part prints the related values 
	cout<<"Root from bisection : "<<bisection(guess1, guess2, tolerance, coef, N, &counterForBisection)<<endl;
	cout<<"Bisection iteration time: "<<counterForBisection<<endl;	
	cout<<"Root from secant : "<<secant(guess1,guess2,tolerance, coef, N, &counterForSecant )<<endl;
	cout<<"Secant iteration time: "<<counterForSecant<<endl;

	// next part does hybrid part and also print
	bisectionIteration(&guess1,&guess2,tolerance,coef,N);
	bisectionIteration(&guess1,&guess2,tolerance,coef,N);
	cout<<"Root from hybrid: "<< secant(guess1,guess2,tolerance, coef, N, &counterForHybrid )<<endl;
	cout<<"Hybrid iteration time: "<<counterForHybrid + 2<<endl;//2 added for bisection iterations
	
return 0;}
