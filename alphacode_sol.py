import fileinput

# Esta es la funcion que encuentra el numero de decodificaciones posibles
# Asume que encryption es tipo string

def num_decod(encryption):
    m = len(encryption)
    encryption = encryption[:m - 1] # Quitar el salto de linea
    m -= 1
    N = []
    
    if m == 1 or (m == 2 and int(encryption[0] + encryption[1]) > 26):
        return 1
    elif m == 2 and int(encryption[0] + encryption[1]) <= 26:
        return 2
    else:
        N.append(1)
        
        if int(encryption[0] + encryption[1]) > 26:
            N.append(1)
        else:
            N.append(2)
        
        for i in range(2, m):
            if int(encryption[i - 1] + encryption[i]) > 26:
                N.append(N[i - 1])
            else:
                N.append(N[i - 1] + N[i - 2])
    
    return N[m - 1]

# Aqui empieza el programa

for line in fileinput.input():
    if line != '0':
        print(num_decod(line))
