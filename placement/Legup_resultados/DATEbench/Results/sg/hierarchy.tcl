# main_top
# 	main
# 		__ieee754_pow_inst_0
# 			scalbn_inst_0
# 				copysign -> copysign (line 0 of ?)
# 				copysign -> copysign (line 0 of ?)
# 				copysign -> copysign (line 0 of ?)
# 		convBin_inst_0
# 			pow -> pow (line 10 of sg.c)
# 		convBin_inst_1
# 			pow -> pow (line 10 of sg.c)
add wave -hex -group "top" -group "ports"  {*}[lsort [find nets -ports [lindex [find instances -bydu top] 0]/*]]
add wave -hex -group "top" -group "main" -group "ports"  {*}[lsort [find nets -ports [lindex [find instances -r /main_inst] 0]/*]]
add wave -hex -group "main_top" -group "main" -group "__ieee754_pow_inst_0" -group "scalbn_inst_0" -group "copysign" -group "ports" {*}[lsort [find nets -ports [lindex [find instances -r /copysign_inst] 0]/*]]
add wave -hex -group "main_top" -group "main" -group "__ieee754_pow_inst_0" -group "scalbn_inst_0" -group "copysign" -group "ports" {*}[lsort [find nets -ports [lindex [find instances -r /copysign_inst] 0]/*]]
add wave -hex -group "main_top" -group "main" -group "__ieee754_pow_inst_0" -group "scalbn_inst_0" -group "copysign" -group "ports" {*}[lsort [find nets -ports [lindex [find instances -r /copysign_inst] 0]/*]]
add wave -hex -group "main_top" -group "main" -group "convBin_inst_0" -group "pow" -group "ports" {*}[lsort [find nets -ports [lindex [find instances -r /pow_inst] 0]/*]]
add wave -hex -group "main_top" -group "main" -group "convBin_inst_1" -group "pow" -group "ports" {*}[lsort [find nets -ports [lindex [find instances -r /pow_inst] 0]/*]]
