import math
import sys

def le_arquivo(vsorigem,vsdestino,arq_nome):
	linhas = []

	arquivo = open(arq_nome, 'r')
	for linha in arquivo:
		linhas.append(linha)
	
	n_v,n_a = linhas[0].split(' ')
	
	for i in range(2,len(linhas)-1):
		#print(linhas[i])
		try:
			a,b = linhas[i].split(' ')
			A = int(a)
			B = int(b)
			vsorigem.append(A)
			vsdestino.append(B)	
		except Exception as e:
			print(e)

	arquivo.close()
	return int(n_v)

def gera_exData(x,lista):
	arq_nome = sys.argv[1]+"e"+x+"Data.txt"
	#print(arq_nome)
	arquivo = open(arq_nome, 'w')
	
	for v in lista:
		arquivo.write(str(format(v, '01X'))+"\n")

	p = 0
	i  = 1
	while p < len(lista):
		p = pow(2,i)
		i += 1
		#print(p)

	for i in range(p-len(lista)):
		arquivo.write("0\n")
	
	arquivo.close()

	return p

def gera_gridData(p):
	arquivo = open("gridData.txt", 'w')
	val = int(math.sqrt(p))

	for j in range(val):
		for i in range(val):
			arquivo.write("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF")
			if i != val-1:
				arquivo.write(" ")
			else:
				arquivo.write("\n")

	arquivo.close()

def gera_posData(p,n_v):
	arquivo = open("posData.txt", 'w')

	for i in range(n_v):
		arquivo.write("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n")

	for i in range(p-n_v):
		arquivo.write("0\n");


if len(sys.argv) > 1:
    file = sys.argv[1]+".dot"
    print(file)

    vsdestino = []
    vsorigem = []
    n_v = le_arquivo(vsorigem,vsdestino,file)
    p = gera_exData("a",vsorigem,sys.argv[1])
    p = gera_exData("b",vsdestino,sys.argv[1])
    #gera_gridData(p)
    #print("n v ",n_v)
    #gera_posData(p,n_v)
else:
    print("python3 dot_to_list_several.py <name.dot> <name>\n")
    exit(0)
    





