// quadratura gauss legendre - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double phi (x);

int main (){
	double res = gausslegendre (0, 1, 10); 
	printf("\n resultado = %F" , res); 
}

double phi (double x){
	double y = 4.0 / ( 1 + pow(x,2);
	return y;
}

double PesAbsGL(double n) // A = pesos, T abscissas, retornar
	double *A = (double*)calloc (1,sizeof(double)), *T = (double*)calloc (1,sizeof(double)) , vet [2]; // vet[0] armazenará A e vet[1] armazenará T, dps será retornado
	double m = floor(0.5 * (n + 1)); // o que é floor?
	
	for(int i=1; i<m ; i++){
		double z = cos (pi * (i - 0.25) / (n + 0.5));//verificar pi
		double z1 = 100 ;
		
		while ( abs ( z - z1 ) > 1.00e-15 ){ //erro000000 o que � abs em .m?
			double p1 = 1 ;
			double p2 = 0 ;
			
			for (int j = 1; j < n; j++){
				double p3 = p2;
				p2 = p1 ;
				p1 = ((2 * j - 1) * z * p2 - (j - 1) * p3) / j;
				j++;
			}

			double pp = n * (z * p1 - p2) / ((pow (z, 2)) - 1);
			z1 = z;
			z = z1 - (p1 / pp);
		}	
		T = (double*)realloc (T,sizeof(double));
		T[m + 1 - i] = z ;
		A = (double*)realloc (A,sizeof(double));
		A [m + 1 - i] = 2.0 / (( 1 - pow(z,2)) * pow(pp,2));

	}
	vet[0]=A;
	vet[1]=T;
	return vet;

endfunction

function integral = gausslegendre ( a, b, n )

	integral = 0.0 ;

	[ A T ] = PesAbsGL( n ) ;

	e1 = 0.5 .* ( b - a ) ;

	e2 = 0.5 .* ( a + b ) ;

	if ( mod ( n, 2 ) == 0 )
	
		c1 = 1.0 ;

		c2 = 0.5 ;

	else

		c1 = 0.0 ;

		c2 = 1.0 ;

	endif

	for i = 1 : n

		k = floor ( i - 0.5 .* ( n + 1 ) + sign ( i - 0.5 .* ( n + c1 ) ) .* c2 ) ;

		t = sign ( k ) .* T ( abs ( k ) ) ;

		x = e1 .* t + e2 ;

		y = phi( x ) ;

		c = A ( abs ( k ) ) ;

		integral = integral + c .* y ;

	endfor

	integral = e1 .* integral ;

endfunction
