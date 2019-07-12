// regra do 3/8 de simpson - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define a 0.0
#define b 2.0
#define m 100

double regrasimpson38 ();
double funint (x);

int main (){
	double res = regrasimpson38 (); 
	printf("\n resultado = %F" , res); 
}

double funint (double x){
	double y = exp (-1 * cos (x)) / (sqrt (2 * x + 4));
	return y;
}

double regrasimpson38 (){
	double integral;
	double h = (b - a) / m; 
	double x = a;
	integral = (3.0 / 8.0) * h * funint (x);
	x = x + h;
	
	for (int i = 1 ; i < (m - 1) ; i++){ 
		if ((i%3) == 0)
			integral = integral + (3.0 / 8.0) * h * 2.0 * funint (x);
		else 
			integral = integral + (3.0 / 8.0) * h * 3.0 * funint (x);	
		x = x + h;
	}
	
	integral = integral + (3.0 / 8.0) * h * funint (b); 
	return integral;
}
