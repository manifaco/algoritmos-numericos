//interpolação de lagrange - kaio alan littike - 2019

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define lin 3
#define col 3

double iLagrange();

int main (){
	double x [lin] = {0.100, 0.600, 0.800};
	double y [col] = {1.221, 3.320, 4.953};
	double z = 0.200;
	double resul;
	resul = iLagrange(x,y,z);
	printf ("\n resultado = %f /n", resul);
}
//função
double iLagrange ( double x [lin], double y [col], double z ){
	int m = lin;
	double r = 0 ;
	int i,j;
	
	for (i=1 ; i<=m ; i++){
		double c = 1 ;
		double d = 1 ;
		for (j=1 ; j<=m ; j++){
			if (i != j){
				c = c * (z - x [j]);
				d = d * (x [i] - x [j]); 
			}
		}
		r = r + (y[i] *(c / d));
	}
	return r;
}

