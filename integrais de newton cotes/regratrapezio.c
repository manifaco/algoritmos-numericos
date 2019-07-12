// regra do trapézio - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define a 0.0
#define b 2.0
#define m 100

double regraTrapezio ();
double funint (x);

int main (){
	double res = regraTrapezio (); 
	printf("\n resultado = %F" , res); 
}

double funint (double x){ //função a ser integrada
	double y = exp ((-1 * cos (x)) / (sqrt (2 * x + 4)));
	return y;
}

double regraTrapezio (){
	double integral;
	double h = (b - a) / m; 
	double x = a;
	integral = 0.5 * h * funint (x);
	x = x + h;
		
	for (int i = 1; i < (m - 1) ; i++){ 
		integral = integral + h * funint (x);
		x = x + h;
	}
	integral = integral + (0.5 * h * funint (x));
}
