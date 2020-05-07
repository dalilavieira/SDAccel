import os

#TODO: criar campo avisando se foi encotrada solucao

def le_arquivo(arq_nome):
	valores = []
	linhas = []
	is_find = False

	arquivo = open(arq_nome, 'r')
	for linha in arquivo:
		linhas.append(linha)
	
	for i in range(len(linhas)):
		#print(linhas[i])
		if not linhas[i].find("No solution"):
			is_find = True
			#print(linhas[i])
		try:
			lab,val = linhas[i].split(' = ')
			if is_find and not lab.find("Evaluation"):
				#print("treta")
				VAL = None
			else:
				VAL = int(val)	
				
			valores.append(VAL)

		except Exception as e:
			a = e

	arquivo.close()
	return valores




for _, _, arquivo in os.walk('.'):
    menorEval =99999999999
    menorEval_tempo =99999999999

    menorTempo =99999999999
    menorTempo_Eval =99999999999

    maiorTempo=0
    maiorTempo_Eval=0

    hop_menorEval =99999999999
    hop_menorEval_tempo =99999999999

    hop_menorTempo =99999999999
    hop_menorTempo_Eval =99999999999

    hop_maiorTempo=0
    hop_maiorTempo_Eval=0

 #   print(arquivo)
    for a in arquivo:
	try:
	    val = le_arquivo(a)
#	    print(a)
#	    print(val)
	    
	    #TODO: considerar apenas solucoes encontradas
	    if val[0] is not None and val[0] < menorEval:
			menorEval = val[0]
			menorEval_tempo = val[2]
			#print(menorEval) 
			
	    if val[2] < menorTempo:
			menorTempo = val[2]
			menorTempo_Eval = val[0]
			#print(menorTempo_Eval)
			
	    if val[2] > maiorTempo:		
			maiorTempo = val[2]		
			maiorTempo_Eval = val[0]
			#print(maiorTempo_Eval)


	    ##1-HOP
 	    if val[1] is not None and val[1] < hop_menorEval:
			hop_menorEval = val[1]
			hop_menorEval_tempo = val[2]
			#print(menorEval) 
			
	    if val[2] < hop_menorTempo:
			hop_menorTempo = val[2]
			hop_menorTempo_Eval = val[1]
			#print(menorTempo_Eval)
			
	    if val[2] > hop_maiorTempo:		
			hop_maiorTempo = val[2]		
			hop_maiorTempo_Eval = val[1]
			#print(maiorTempo_Eval)
#	for key in val:
#		print(key)

	except Exception as e:
		a = e

    print("Melhor solucao")
    print("   Evaluation = ", menorEval)
    print("   Ciclos = ", menorEval_tempo)

    print("Menor tempo")
    print("   Evaluation = ", menorTempo_Eval)
    print("   Ciclos = ", menorTempo)
		
    print("Maior tempo")
    print("   Evaluation = ", maiorTempo_Eval)
    print("   Ciclos = ", maiorTempo)
    print("")	

    print("          1-hop")
    print("Melhor solucao")
    print("   Evaluation 1-hop = ", hop_menorEval)
    print("   Ciclos = ", hop_menorEval_tempo)

    print("Menor tempo")
    print("   Evaluation 1-hop = ", hop_menorTempo_Eval)
    print("   Ciclos = ", hop_menorTempo)
		
    print("Maior tempo")
    print("   Evaluation 1-hop = ", hop_maiorTempo_Eval)
    print("   Ciclos = ", hop_maiorTempo)		
    print("")
    print("")
