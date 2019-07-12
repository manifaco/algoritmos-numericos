#lagrange - kaio - 2019
#implementado em pyton pois nesse caso, torna-se mais simples

import numpy as num

def interpolacaoLagrange(x,y,z): 
    a = len(x)
    b = 0
    for i in num.arange(a):
        e = 1
        f = 1
        for j in num.arange(a):
            if (i!=j):
                e = e*(z - x[j])
                f = f*(x[i] - x[j])
        b += y[i]*(e/f)
    return b
print(interpolacaoLagrange([0.100,0.600,0.800],[1.221,3.320,4.953],1))