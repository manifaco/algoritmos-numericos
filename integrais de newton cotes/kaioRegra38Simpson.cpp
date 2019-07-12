// regra do 3/8 de simpson - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

double funint(double x);

int main () {
    double a = 0.0, b = 2.0, h, x, result;
    int m = 120;
    h = (b - a) / m;
    x = a;
    result = (3 * h * funint(x)) / 8;
    x = x + h;
    for (int i = 1;i<m;i++) {
        if (i % 3 == 0) 
            result = result + (3 * h * 2 * funint(x)) / 8;
        else 
            result = result + (3 * h * 3 * funint(x)) / 8;
        x = x + h;
    }
    result = result + (3 * h * funint(b)) / 8;

    cout << "H: " << h << "\nRes: " << result;
}

double funint(double x) {
    double y = exp(-1*cos(x)) / sqrt(2*x + 4);
    return y;
}
