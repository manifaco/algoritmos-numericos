//Cholesky - kaio alan littike - 2019
#include <stdio.h>
#include <math.h>

int main () {
    float r, soma;
    int ordem = 3 ,i=0, k=0, j=0;

    float a[3][3] = {{4,2,-4},{2,10,4},{-4,4,9}};
    float g[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    
    while (i<3) {
        while (j<3) {
            printf("%.2f\t", a[i][j]);
        	j++;
		}
        printf("\n");
        i++;
    }
    
    while (k<ordem) {
        soma = 0;
        for (j=0 ; j<=k-1 ; j++) 
            soma = soma + pow(g[k][j],2);
            
        r = a[k][k] - soma;
        g[k][k] = sqrt(r);
        for (i=k+1 ; i<ordem ; i++) {
            soma = 0 ;
            for (j=0 ; j<=k-1 ; j++) 
                soma = soma + g[i][j]*g[k][j];
            g[i][k] = (a[i][k] - soma) / g[k][k];
        }
        k++;
    }

    printf("\n");
    for (i = 0 ; i<3 ; i++) {
        for (j=0 ; j<3 ; j++) 
            printf("%.3f\t", g[i][j]);
        printf("\n");
    }
}
