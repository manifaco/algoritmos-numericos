#newton - kaio - 2019
#implementado em pyton pois nesse caso, torna-se mais simples

import numpy as num

def interpolacaoNewton(x,y,z):
    A = len(x)
    B = len(x)
    C = A
    Dely = y
    k = 0
    while(k<C):
        i = C - 1
        while(i>k):
            Dely[i] = (Dely[i] - Dely[i-1])/(x[i] - x[i-k-1])
            i = i-1
        k = k+1
    D = Dely[C-1]

    i = C-2
    while(i>=0):
        D = D*(z - x[i]) + Dely[i]
        i = i-1
    return D
print(interpolacaoNewton([0.100,0.600,0.800],[1.221,3.320,4.953],1))