import fileinput
from numpy import zeros

# Asume que encryption es tipo string y que no hay encriptaciones no permitidas

def memoized_N(i, chain, N):
    if i == 0:
        return 1
    elif i == 1 and (int(chain[0] + chain[1]) > 26 or \
        int(chain[1]) == 0):
        N[i] = 1
        return N[i]
    elif i == 1:
        N[i] = 2
        return N[i]
    else:
        if int(chain[i - 1] + chain[i]) > 26:
            if N[i - 1] == 0:
                N[i - 1] = memoized_N(i - 1, chain, N)
            return N[i - 1]
        elif int(chain[i]) == 0:
            if N[i - 2] == 0:
                N[i - 2] = memoized_N(i - 2, chain, N)
            return N[i - 2]
        else:
            if N[i - 1] == 0:
                N[i - 1] = memoized_N(i - 1, chain, N)
            if N[i - 2] == 0:
                N[i - 2] = memoized_N(i - 2, chain, N)
            return N[i - 1] + N[i - 2]

def num_decod(encryption):
    m = len(encryption)
    N = zeros(m, dtype = int)
    N[0] = 1
    
    return memoized_N(m - 1, encryption, N)

# Aqui empieza el programa

for line in fileinput.input():
    line = line[:len(line) - 1] # Quitar salto de linea
    if line != '0':
        print(num_decod(line))
