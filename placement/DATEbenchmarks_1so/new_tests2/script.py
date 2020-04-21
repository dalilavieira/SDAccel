import os
BENCHMARKS=['chebyshev', 'mibench', 'poly5', 'poly6', 'poly8', 'qspline', 'sgfilter']#, 'cosine', 'filter'
n=[5,6,8,12,10,9,7]#,9,12
#os.system("g++ gera.cpp -o gera")
for i in range(len(BENCHMARKS)):
	for j in range(102):
		os.system("cp $i {}/{}_{}/eaData.txt {}/{}_{}/ebData.txt dados/{}/".format(BENCHMARKS[i],BENCHMARKS[i],j,BENCHMARKS[i],BENCHMARKS[i],j,BENCHMARKS[i]))
		for k in range(10):
			print("RUNNING {}_{}_{}".format(BENCHMARKS[i], j, k))
			os.system("./gera {}".format(n[i]))
			os.system("iverilog random_placement_{}.v -o random_placement_{}.vvp".format(BENCHMARKS[i], BENCHMARKS[i]))
			os.system("vvp random_placement_{}.vvp > {}/{}_{}/log_{}.txt".format(BENCHMARKS[i], BENCHMARKS[i], BENCHMARKS[i], j, k))