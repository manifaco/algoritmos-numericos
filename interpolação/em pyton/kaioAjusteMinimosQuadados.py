#ajuste Minimos Quadrados - kaio - 2019
#implementado em pyton pois nesse caso, torna-se mais simples

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt

#principal
def ajusteMinimosQuadrados(n, erro):
    media = 0
    desvio = 0.1
    s = np.random.normal(media, desvio, n)
    x = np.arange(0, n * erro, erro)
    y = np.zeros([n])
    for i in range(n):
        y[i] = ((x[i]**2 + x[i] +1) + s[i]) 
    return x, y

x, y = ajusteMinimosQuadrados(10, 0.1)
print(x)
print(y)

#plot
def main_plot():
    plt.scatter(x, y, s=10)
    plt.title("")
    plt.autoscale(tight=True)
    plt.grid(True, linestyle='-', color='0.75')
main_plot()
def sin_plot():
    fx = sp.linspace(0., 1., num=100)
    f = np.sin(2 * np.pi * fx)
    plt.plot(fx, (fx**2 + fx + 1 ),'C1', linewidth=2)
    plt.grid(True, linestyle='-', color='0.75')
sin_plot()
plt.show()