// metodo de euler - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double wx(double Ca,double vy,double vx,double m);
double wy(double Ca,double vy,double vx,double g,double m);

int main(){
	double t = 0, h = 0.0001, Ca = 0.0001, g = 9.8, v0 = 100, m = 0.01, tetha =  3.14159 * 30 / 180, x = 0, y = 0.3;
    double vx = v0 * cos(tetha), vy = v0 * sin(tetha);

    while(y > 0.0001){
        t = t + h;
        vx = vx + h*wx(Ca,vy,vx,m);
        vy = vy + h*wy(Ca,vy,vx,g,m);
        x = x + h*vx;
        y = y + h*vy;
    }
    printf("resulado = %f",x);
}

double wx(double Ca,double vy,double vx,double m){
    return -(1/m)*Ca*(sqrt(vx*vx + vy*vy)*vx);
}
double wy(double Ca,double vy,double vx,double g,double m){
    return -g - ((1./ m)*Ca*(sqrt(vx*vx + vy*vy)*vy));
}
