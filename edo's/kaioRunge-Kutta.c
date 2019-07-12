// runge-kutta - kaio alan littike - algoritmos numéricos - 2019/1

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

    while (y>0.0001){
 	k11 = h*wx(Ca,vy,vx,m,m1);
 	k12 = h*wy(Ca,vy,vx,g,m,m1);
 	k13 = h*vx;
 	k14 = h*vy;
	t0 = t0 + 0.5*h ;
 	k21 = h*wx(Ca,vy + 0.5*k12,vx + 0.5*k11,m,m1);
 	k22 = h*wy(Ca,vy + 0.5*k12,vx + 0.5*k11,g,m,m1);
 	k23 = h*(vx + 0.5*k11);
 	k24 = h*(vy + 0.5*k12);
 	k31 = h*wx(Ca,vy + 0.5*k22,vx + 0.5*k21,m,m1);
 	k32 = h*wy(Ca,vy + 0.5*k22,vx + 0.5*k21,g,m,m1);
 	k33 = h*(vx + 0.5*k21);
 	k34 = h*(vy + 0.5*k22);
	t0 = t0 + (0.5*h);
 	k41 = h*wx(Ca,vy + k32,vx + k31,m,m1);
 	k42 = h*wy(Ca,vy + k32,vx + k31,g,m,m1);
 	k43 = h*(vx + k31);
 	k44 = h*(vy + k32) ;
 	vx = vx + (1.0/6.0)*(1.0*k11 + 2.0*k21 + 2.0*k31 + 1.0*k41);
 	vy = vy + (1.0/6.0)*( 1.0*k12 + 2.0*k22 + 2.0*k32 + 1.0*k42);
 	x0 = x0 + (1.0/6.0)*(1.0*k13 + 2.0*k23 + 2.0*k33 + 1.0*k43);
 	y = y + (1.0/6.0)*( 1.0*k14 + 2.0*k24 + 2.0*k34 + 1.0*k44);
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
