#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv){
	int menor = 945763;
        int maior = 2147483633;
	ofstream out;
	out.open("Main.v");
	
	srand(time(NULL));

        out << "`include \"placement.v\"" << endl;
        out << endl;
        out << "module test;" << endl;
        out << " 	 reg clk;" << endl;
        out << "	 reg reset, rst;" << endl;
        out << "         reg loads = 0;" << endl;
        out << "        reg [31:0] seed = " << rand()%(maior-menor+1) + menor << ";" << endl;
        out << " 	 initial begin" << endl;
        out << "	 	 $dumpfile(\"placement.vcd\");" << endl;
        out << "	 	 $dumpvars;" << endl;
        out << "	 	 clk = 0;" << endl;
        out << "	 	 reset = 0;" << endl;
        out << "	 	 #1 reset = 1;" << endl;
        out << "	 	 #23 reset = 0;" << endl;
        out << "		 #0 rst = 1;"  << endl;
        out << "		 #0 loads = 1;" << endl;
        out << "		 #2 loads = 0;" << endl;
        out << "	 	 //#50 rst = 0;" << endl;
        out << "                //#140 $finish;" << endl;
        out << "	 end" << endl;
        out << "	 always #1 clk = !clk;" << endl;
        out << "	 wire out;" << endl;
        out << "	 placement p1 (out, clk, reset, loads, rst, seed);" << endl;
        out << "endmodule" << endl;

	
	out.close();

}
