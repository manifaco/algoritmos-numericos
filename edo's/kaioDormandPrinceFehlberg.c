// dormand Prince fehlberg - kaio alan littike - algoritmos numéricos - 2019/1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double wx(double Ca,double vy,double vx,double m,double m1);
double wy(double Ca,double vy,double vx,double g,double m,double m1);

int main(){
    double k1[7],k2[7],k3[7],k4[7], A[7][7], B4[7], B5[7][1];
    double t0 = 0, v0 = 100, g = 9.8, k1_=0,k2_=0,k3_=0,k4_=0;
    double tetha =  3.14159 * 30 / 180, h = 0.001, m = 0.01, x0 = 0;
    double y = 0.3, Ca = 0.0001, m1 = pow(18.68,-6);
    double vx = v0 * cos(tetha), vy = v0 * sin(tetha);
    int i=0,j=0;
    A[0][0] = 0.0;
    A[1][0] = 1.0/5;
    A[2][0] = 3.0/40;
    A[2][1] = 9.0/40;
    A[3][0] = 44.0/45;
    A[3][1] = -56.0/15;
    A[3][2] = 32.0/9;
    A[4][0] = 19372.0/6561;
    A[4][1] = -25360.0/2187;
    A[4][2] = 64448.0/6561;
    A[4][3] = -212.0/729;
    A[5][0] = 9017.0/3168;
    A[5][1] = -355.0/33;
    A[5][2] = 46732.0/5247;
    A[5][3] = 49.0/176;
    A[5][4] = -5103.0/18656;
    A[6][0] = 35.0/384;
    A[6][1] = 0;
    A[6][2] = 500.0/1113;
    A[6][3] = 125.0/192;
    A[6][4] = -2187.0/6784;
    A[6][5] = 11.0/84;
    B4[0] = 5179.0/57600;
    B4[1] = 0.0;
    B4[2] = 7571.0/16695;
    B4[3] = 393.0/640;
    B4[4] = -92097.0/339200;
    B4[5] = 187.0/2100;
    B4[6] = 1.0/40;

    for (i = 0;i<7;i++) {
        k1[i] = 0;
        k2[i] = 0;
        k2[i] = 0;
        k2[i] = 0;
    }
    k1[0] = h*wx(Ca,vy,vx,m,m1);
    k2[0] = h*wy(Ca,vy,vx,g,m,m1);
    k3[0] = h*vx;
    k4[0] = h*vy;

    while (y>0.0001) {

        for (j = 0;j<6;j++) {
            k1_= 0,k2_ = 0;
            for (i = 0;i<=j;i++) {
                k1_ = k1_ + k1[i] * A[j+1][i];
                k2_ = k2_ + k2[i] * A[j+1][i];
            }
            k1[j+1] = wx(Ca, vy + h*k2_,vx + h*k1_,m,m1);
            k2[j+1] = wy(Ca, vy + h*k2_,vx + h*k1_,g,m,m1);
            k3[j+1] = vx + h*k1_;
            k4[j+1] = vy + h*k2_;
        }

        k1_ = 0,k2_ = 0, k3_ = 0,k4_ = 0;
        for (i = 0;i<7;i++) {
            k1_ = k1_ + k1[i]*B4[i];
            k2_ = k2_ + k2[i]*B4[i];
            k3_ = k3_ + k3[i]*B4[i];
            k4_ = k4_ + k4[i]*B4[i];
        }


        vx = vx + h *k1_;
        vy = vy + h * k2_;
        x0  =  x0 + h * k3_;
        y  =  y + h * k4_;
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

