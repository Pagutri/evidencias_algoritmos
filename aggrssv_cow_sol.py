import fileinput

def get_min_dist(locations, cows):
    locations.sort()
    n = len(locations)
    lo = locations[1] - locations[0] # Distancia mínima entre casetas
    hi = locations[n - 1] - locations[0] # Distancia máxima entre casetas
    print(lo, hi)
    
    while lo + 1 < hi:
        x = lo + (hi - lo) // 2
        alloc_cows = 1
        current_loc = locations[0]
        
        for i in range(1, len(locations)):
            if locations[i] - current_loc >= x:
                # Puedo poner vaca
                alloc_cows += 1
                current_loc = locations[i]

        if alloc_cows >= cows:
            lo = x
        else:
            hi = x - 1

    return hi


stalls = []

for line in fileinput.input():
    if fileinput.isfirstline():
        test_cases = int(line)
    elif ' ' in line:
        info = line.split()
        num_stalls = int(info[0])
        num_cows = int(info[1])
    else:
        stalls.append(int(line))
        
    if len(stalls) == num_stalls:
        print(get_min_dist(stalls, num_cows))
        pos_stalls = []


