#gradiente conjugado - kaio - 2019
#implementado em pyton pois nesse caso, torna-se mais simples

import numpy as num

def gradienteConjugado(A, B, erro):
    n = A.shape[0]  
    iter = 0
    x = num.zeros(n)
    r = B - num.dot(A,x)  
    s = r
    while num.linalg.norm(r) > erro: 
        q = num.dot(A,s)
        alpha = num.dot(s, r)/num.dot(s, q)
        x = x + alpha*s
        r = B - num.dot(A,x)
        beta = -num.dot(r, q)/num.dot(s, q)
        s = r + beta*s
        iter = iter + 1
    print("Interações: %d" %(iter)) #para verificar a eficiência do codigo
    return x
    

A = num.array([ [12.0, 3, -5], [1,5,3], [3,7,13] ])
B = num.array([1.0, 28, 76])
y = gradienteConjugado(A,B,0.001)
print(y)