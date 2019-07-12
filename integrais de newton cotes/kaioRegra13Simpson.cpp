// regra do 1/3 de simpson - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

double funint ( double x );

int main (){
    double a = 0.0, b = 2.0, h, x, result;
    int m = 100;
    h = (b - a) / m;
    x = a;
    result = (h*funint(x)) / 3;
    x = x + h;
    for (int i = 1; i<m ; i++) {
        if (i % 2 != 0) 
            result = result + (h*4*funint(x)) / 3;
        else 
            result += (h*2*funint(x)) / 3;
        x = x + h;
    }
    result += (h*funint(b)) / 3;

    cout << "H: " << h << "\nRes: " << result;
}

double funint (double x){
    double y = exp(-1*cos(x))/sqrt(2*x + 4);
    return y;
}

