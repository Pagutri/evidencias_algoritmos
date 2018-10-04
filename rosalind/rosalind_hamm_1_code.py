"""Programa que calcula el número de mutaciones puntuales (ditancia hammer) entre dos cadenas de ADN"""

data = open("rosalind_hamm.txt", "r")

s = data.read()

cadena_inicial = []
cadena_secundaria = []
cuenta1 = 0

for i in s: #Ciclo que lee la primera cadena y la guarda en una variable
	if i != "X":
		cadena_inicial.append(i)
		cuenta1 += 1
	else:
		break

cuenta2 = 0

for i in s: #Ciclo que lee la segunda cadena y la guarda en una variable
	if cuenta2 >= cuenta1 + 2:
		cadena_secundaria.append(i)
	cuenta2 += 1

hammer = 0

for i in range(len(cadena_inicial)):
	if cadena_inicial[i] != cadena_secundaria[i]:
		hammer += 1

cadena_inicial = ''.join(cadena_inicial) #Instrucciones que convierten las cadenas de listas a strings
cadena_secundaria = ''.join(cadena_secundaria)

print(cadena_inicial)
print(cadena_secundaria)
print(hammer)

hammer = str(hammer)

resp = open("resp_hamm.txt", "a")
resp.write(hammer)
resp.close()
data.close()