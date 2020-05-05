import sys

if __name__ == "__main__":
    
    if len(sys.argv) > 1:
        path = sys.argv[1]
    else:
        print("python3 clean.py <path>\n")
        exit(0)
    
    arq = open(path, "r")

    count = 0
    vector = []
    for line in arq:
        line = line.replace("\n","").replace("     ","").split(" ")
        if count == 0:
            count += 1
            continue
        if line[0] == "WARNING:":
            continue
        if len(line) > 1 and line[0] == "No" and line[1] == "solution":
            break
        if len(line) == 1 and line[0] == '':
            continue
        
        for elem in line:
            if elem == '':
                continue
            vector.append(elem)
        
    if len(vector) > 1:
        for i in range(len(vector)):
            if i == 0:
                print(vector[i])
            else:
                print(vector[i], end=" ")
        print()
        
        