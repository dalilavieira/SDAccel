mkdir -p ./synthesis/
# create an sdc/xdc file with a 2ns clock period
echo "create_clock -period 5 -name clk [get_ports clk]" > ./synthesis/RoutCheb.sdc
# echo "create_clock -period 1 -name clk2x [get_ports clk2x]" >> ./synthesis/RoutCheb.sdc
# echo "create_clock -period 2 -name OSC_50_BANK2 [get_ports OSC_50_BANK2]" >> ./synthesis/RoutCheb.sdc
# these contraints only apply to Intel
echo "derive_pll_clocks" >> ./synthesis/RoutCheb.sdc
echo "derive_clock_uncertainty" >> ./synthesis/RoutCheb.sdc
cd ./synthesis/; quartus_sh \
  -t /usr/lib/legup-7.5/legup/examples/setup_proj.tcl \
  "Arria10" Arria10-PAC RoutCheb top 0 ; \
  cd ..
cd ./synthesis/; quartus_sh "--64bit" --flow compile top; cd ..
# Run each step separately, so that we don't run quartus_asm.
# Lanny: revert back to use quartus_sh otherwise quartus_map has to be changed to quartus_syn for Quartus Prime Pro.
# cd ./synthesis/; "quartus_map" "--64bit" top; cd ..
# cd ./synthesis/; "quartus_fit" "--64bit" top; cd ..
# cd ./synthesis/; "quartus_sta" "--64bit" top; cd ..
perl -I /usr/lib/legup-7.5/legup/examples/scripts \
  /usr/lib/legup-7.5/legup/examples/scripts/report_parsing/parse_simulation_synthesis_results_summary.pl \
  RoutCheb \
  __INTEL __"Arria10" __"10AX115N2F40E2LG" \
  simulation/transcript \
  ./synthesis/output_files/top.sta.rpt \
  ./synthesis/output_files/top.fit.summary \
  ./reports/summary.results.rpt
