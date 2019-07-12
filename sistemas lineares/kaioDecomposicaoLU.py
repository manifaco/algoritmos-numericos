#decomposição LU - kaio alan Littike - 2019
#implementado em pyton pois nesse caso, torna-se mais simples
import numpy as np


def decompLU(A):
    U = np.copy(A)
    n = np.shape(U)[0]
    L = np.eye(n)
    for j in np.arange(n - 1):
        for i in np.arange(j + 1, n):
            L[i, j] = U[i, j] / U[j, j]
            for k in np.arange(j + 1, n):
                U[i, k] = U[i, k] - L[i, j] * U[j, k]
            U[i, j] = 0

    return L, U


#matriz a
A = [[1.0, 1.0, 0, 3.0], [2.0, 1.0, -1.0, 1.0], [3.0, -1.0, -1.0, 2.0],
     [-1.0, 2.0, 3.0, -1.0]]

b = [4.0, 1.0, -3.0, 4.0]

y, x = decompLU(A)

sol_y = np.linalg.solve(y, b)
sol_x = np.linalg.solve(x, sol_y)

print("\n Matriz A")
print(A)
print("\n Matriz L")
print(y)
print("\n Matriz U")
print(x)
print("\n resultados de y")
print(sol_y)
print("\n resultados de X")
print(sol_x)
