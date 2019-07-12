// eliminação de gauss com pivotação - kaio - 2019

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    int i=0, j=0, k=0, ordem;
    float m,s;

    printf("Ordem da matriz:\n");
    scanf("%d", & ordem);

    float x[ordem];
    float mat[ordem][ordem];
    float vet_const[ordem];

    printf("Preenchimento da matriz: \n");
    for (i=0; i<ordem; i++) {
        for (j=0 ; j<ordem ; j++) {
            printf("Elemento da linha %d, coluna %d :\n", i+1,j+1 );
            scanf("%f", &mat[i][j]);
            j++;
        }
    }
    printf("Vetor constante:\n");
    
    for (i=0; i<ordem; i++) {
        printf("Digite o valor:\n");
        scanf("%f", &vet_const[i]);
    }
    printf("\n");
    i = 0, j = 0;
    while (i < ordem) {
        j = 0;
        while (j < ordem) {
            printf("%.3f\t", mat[i][j]);
            j++;
        }
        printf("| %.3f", vet_const[i]);
        i++;
        printf("\n");
    }
    printf("\n");

    int indice;
    float max_val;
    float aux;
    for (k=0;k<ordem;k++) {
        indice = k;
        max_val = mat[k][k];
        for (i=k+1;i<ordem;i++) {
            if (max_val < mat[i][k]) {
                max_val = mat[i][k];
                indice = i;
            }
        }
        for (j=0;j<ordem;j++) {
            aux = mat[k][j];
            mat[k][j] = mat[indice][j];
            mat[indice][j] = aux;
        }
        aux = vet_const[k];
        vet_const[k] = vet_const[indice];
        vet_const[indice] = aux;
    }

    printf("\n");
    i = 0, j = 0;
    while (i < ordem) {
        j = 0;
        while (j < ordem) {
            printf("%.3f\t", mat[i][j]);
            j++;
        }
        printf("| %.3f", vet_const[i]);
        i++;
        printf("\n");
    }
    printf("\n");

    i = 0,j = 0,k = 0;
    while (k < ordem) {
        i = k + 1;
        while (i < ordem) {
            m = mat[i][k] / mat[k][k];
            mat[i][k] = 0.0;
            j = k + 1;
            while (j < ordem) {
                mat[i][j] = mat[i][j] - m*mat[k][j];
                j++;
            }
            vet_const[i] = vet_const[i] - m*vet_const[k];
            i++;
        }
        k++;
    }

    printf("\n");
    i = 0, j = 0;
    while (i < ordem) {
        j = 0;
        while (j < ordem) {
            printf("%.3f\t", mat[i][j]);
            j++;
        }
        printf("| %.3f", vet_const[i]);
        i++;
        printf("\n");
    }
    printf("\n");

    x[ordem-1] = vet_const[ordem-1] / mat[ordem-1][ordem-1];
    k = ordem - 2;
    while (k >= 0) {
        s = 0;
        j = k + 1;
        while (j < ordem) {
            s = s + mat[k][j]*x[j];
            j++;
        }
        x[k] = (vet_const[k] - s) / mat[k][k];
        k--;
    }
    printf("\nResultado: \n");
    i = 0;
    while (i < ordem) {
        printf("%.2f\n", x[i]);
        i++;
    }
    printf("\n");
}
