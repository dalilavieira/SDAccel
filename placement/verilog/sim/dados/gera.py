import math

def le_arquivo(vsorigem,vsdestino,arq_nome):
	linhas = []

	arquivo = open(arq_nome, 'r')
	for linha in arquivo:
		linhas.append(linha)
	
	n_v,n_a = linhas[0].split(' ')
	
	for i in range(2,len(linhas)-1):
		print(linhas[i])
		a,b = linhas[i].split(' ')
		A = int(a)
		B = int(b)
		vsorigem.append(A)
		vsdestino.append(B)

	arquivo.close()

def gera_exData(x,lista):
	arq_nome = "e"+x+"Data.txt"
	print(arq_nome)
	arquivo = open(arq_nome, 'w')
	
	for v in lista:
		arquivo.write(str(format(v, '01X'))+"\n")


	p = 0
	i  = 1
	while p < len(lista):
		p = pow(2,i)
		i += 1
		print(p)

	for i in range(p-len(lista)):
		arquivo.write("0\n")
	
	arquivo.close()

vsdestino = []
vsorigem = []
le_arquivo(vsorigem,vsdestino,"mac/mac.in")
gera_exData("a",vsorigem)
gera_exData("b",vsdestino)



