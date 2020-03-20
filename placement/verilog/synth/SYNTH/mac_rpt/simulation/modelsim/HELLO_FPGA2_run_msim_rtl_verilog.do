transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/dalila/CDC/LESC/CAE/Josue/SDAccel/SYNTH/Synth {/home/dalila/CDC/LESC/CAE/Josue/SDAccel/SYNTH/Synth/HELLO_FPGA2.v}

