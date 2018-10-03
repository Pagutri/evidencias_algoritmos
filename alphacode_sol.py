import fileinput
from numpy import zeros

# Esta es la funcion que encuentra el numero de decodificaciones posibles
# Asume que encryption es tipo string

def num_decod(encryption):
    m = len(encryption)
    N = []
    
    if m == 1 or (m == 2 and (int(encryption[0] + encryption[1]) > 26 or \
        int(encryption[1]) == 0)):
        return 1
    elif m == 2:
        return 2
    else:
        N.append(1)
        
        if int(encryption[0] + encryption[1]) > 26 or int(encryption[1]) == 0:
            N.append(1)
        else:
            N.append(2)
        
        for i in range(2, m):
            if int(encryption[i - 1] + encryption[i]) > 26 or \
               int(encryption[i - 1] + encryption[i]) <= 10:
                N.append(N[i - 1])
            else:
                N.append(N[i - 1] + N[i - 2])
            
            if int(encryption[i]) == 0 and int(encryption[i - 2] + encryption[i - 1]) <= 26:
                if i > 2:
                    N[i] -= N[i - 3]
                    N[i - 1] = N[i]
                else:
                    N[i - 1] -= N[i - 2]
                    N[i] = N[i - 1]
    
    print(N)
    return N[m - 1]

# Aqui empieza el programa

for line in fileinput.input():
    line = line[:len(line) - 1] # Quitar salto de linea
    if line != '0':
        print(num_decod(line))
