//interpolação de Newton - kaio alan littike - 2019

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define lin 3
#define col 3

double iNewton();

int main (){
	double x [lin] = {0.100, 0.600, 0.800};
	double y [col] = {1.221, 3.320, 4.953};
	double z = 0.200;
	double resul;
	double Dely [col] = {0.0, 0.0, 0.0};
	resul = iNewton(x,y,z,Dely); 
	printf ("\n resultado = %10.8f \n", resul);
	return 1;
}

//função
double iNewton (double x [lin], double y [col], double z, double Dely [col] )
{
	int m = lin ;
	int k,i, aux;
	double r;
	
	
	for(aux=0;aux<col;aux++)//atribuir um vetor ao outro
		Dely[aux]=y[aux];
		
	for(aux=0;aux<lin;aux++)//printar
		printf("\n %f", x[aux]);
	
	for (k=1 ; k<=(m - 1) ; k++){
		for (i = m; i>=(k + 1); i--){
			Dely [i] = (Dely [i] - Dely [i - 1]) / (x [i] - x [i - k]);
			//printf("\n %f", Dely[i]);
		}
	}

	r = Dely [m];
	printf ("Passei daqui!") ; 

	for (i = (m - 1) ; (i >= 1) ; i--)
		r = (r * (z - x [i])) + Dely [i];
	printf ("Passei daqui!") ; 
	printf ("\n %f \n", r ) ;
	return r;
}
