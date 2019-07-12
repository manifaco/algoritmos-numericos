#gauss Legendre - kaio - 2019
#implementado em pyton pois nesse caso, torna-se mais simples

import numpy as num
from math import *

def pesAbsGaussLegendre(n):
    T = []
    A = []
    m = num.floor((n + 1) * 0.5)
    for i in num.arange(m+1):
        z = cos(num.pi * (i - 0.25) / (n + 0.5))
        z1 = 100

        while(abs(z - z1) > 1.00e-15):
            p1 = 1
            p2 = 0
            
            for j in range(n+1):
                if(j != 0):
                    p3 = p2
                    p2 = p1
                    p1 = ((2 * j - 1) * z * p2 - (j - 1) * p3) / j 
            
            pp = n * (z * p1 - p2) / (z**2 - 1)
            z1 = z
            z = z1 - (p1 / pp)
        
        k = int(m + 1 - i)
        T.append(z)
        A.append(2.0 / ((1 - z**2) * pp**2))
        
    return T, A

def gaussLegendre(a, b, n):
    integral = 0
    T, A = pesAbsGaussLegendre(n)
    e1 = (b - a) * 0.5
    e2 = (a + b) * 0.5
    if n % 2 == 0:
        c1 = 1.0
        c2 = 0.5
    else:
        c1 = 0.0
        c2 = 1.0
    
    for i in range(n+1):
        if i != 0:
            k = num.floor(i - 0.5 * (n + 1) + num.sign(i - 0.5 * (n + c1)) * c2) 
            t = num.sign(k) * T[abs(int(k))]
            x = e1 * t + e2
            y = f(x)
            c = A[abs(int(k))]
            integral = integral + c * y
    
    integral = e1 * integral
    return integral

def f(x):
    return 4 / (1 + x**2)

print(gaussLegendre(0, 1, 10))
