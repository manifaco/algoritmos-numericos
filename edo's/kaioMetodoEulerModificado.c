// metodo de euler modificado - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double wx(double Ca,double vy,double vx,double m,double m1);
double wy(double Ca,double vy,double vx,double g,double m,double m1);

int main(){
    double k11, k12, k13,k14,k21,k22,k23,k24,k31,k32,k33,k34,k41,k42,k43,k44;
    double m = 0.01, Ca = 0.0001, m1 = pow(18.68,-6), g = 9.8, t0 = 0, h = 0.001;
    double x0 = 0, y = 0.3, v0 = 100, tetha =  3.14159 * 30 / 180;
    double vx = v0 * cos(tetha), vy = v0 * sin(tetha);

    while(y>0.0001){
        k11 = wx(Ca,vy,vx,m,m1);
        k12 = wy(Ca,vy,vx,g,m,m1);
        k13 = vx;
        k14 = vy;
        t0 = t0 + 0.5*h;
        k21 = wx(Ca,vy + 0.5*h*k12,vx + 0.5*h*k11,m,m1);
        k22 = wy(Ca,vy + 0.5*h*k12,vx + 0.5*h*k11,g,m,m1);
        k23 = vx + 0.5*h*k11;
        k24 = vy + 0.5*h*k12;
        t0 = t0 + 0.5*h;
        k31 = wx(Ca,vy + 0.5*h*k22,vx + 0.5*h*k21,m,m1);
        k32 = wy(Ca,vy + 0.5*h*k22,vx + 0.5*h*k21,g,m,m1);
        k33 = vx + 0.5*h*k21;
        k34 = vy + 0.5*h*k22;
        vx = vx + h*(0.25*k11 + 0.5*k21 + 0.25*k31);
        vy = vy + h*(0.25*k12 + 0.5*k22 + 0.25*k32);
        x0 = x0 + h*(0.25*k13 + 0.5*k23 + 0.25*k33);
        y = y + h*(0.25*k14 + 0.5*k24 + 0.25*k34);
    }
    printf("resultado %f",x0);
}

double wx(double Ca,double vy,double vx,double m,double m1){
    double v = sqrt(vx*vx + vy*vy)*vx;
    return -(1/m)*Ca*v - m1*vx;
}

double wy(double Ca,double vy,double vx,double g,double m,double m1){
    double v = sqrt(vx*vx + vy*vy)*vy;
    return -g - ((1./ m)*Ca*v - m1*vy);
}
