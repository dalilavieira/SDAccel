#RUN ARF
import os
for i in range(102):
	print("RUNNING arf_{}".format(i))
	os.system("cp $i mibenchout/mibench_{}/eaData.txt _{}/ebData.txt dados/arf/".format(i,i))
	for j in range(100):
		os.system("./gera 6")
		os.system("iverilog random_placement_arf.v -o random_placement_arf.vvp")
		os.system("vvp random_placement_arf.vvp > arf/arf_{}/log_{}_{}.txt".format(i,i,j))
