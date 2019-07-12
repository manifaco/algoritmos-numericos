// regra do trapézio - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

double funint(double x);

int main () {
    double a = 0.0, b = 2.0, h, x, result;
    int m = 100;
    h = (b - a) / m;
    x = a;
    result = 0.5 * h * funint(x);
    x = x + h;
    for (int i=1;i<m;i++) {
        result = result + (h * funint(x));
        x = x + h;
    }
    result = result + (0.5 * h * funint(b));

    cout << "H: " << h << "\nRes: " << result;
}

double funint(double x) {
    double y = exp(-1*cos(x)) / sqrt(2*x + 4);
    return y;
}
