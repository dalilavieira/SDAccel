#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int size_off = 62;
const int WALK = 4;
// horizontal and vertical first after diagonal - permutation 6 first
const int offset_x[WALK][size_off] = {
    {0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5},
    {0,-1, 0, 1, 0,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5},
    {0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5}, 
    {0,-1, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,-2, 1, 3, 3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5}
};
const int offset_y[WALK][size_off] = {
    {0, 1, 0,-1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0},
    {0, 0, 1, 0,-1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0},
    {0,-1, 0, 1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0},
    {0, 0, 0,-1, 1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2, 2, 3, 1,-1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0}
};

int main(int argc, char *argv[]){
	ofstream outX, outY;
	outX.open("offsetXData.txt");
	outY.open("offsetYData.txt");
	
	int n = atoi(argv[1]);
	
	srand(time(NULL));
	for (int i = 0; i < 62; i++){
		int k = rand() % WALK;
		
		if(offset_x[k][i] >= 0)
			outX << hex << uppercase << offset_x[k][i] << "\n";
		else
			outX << "FFFFFFFFFFFFFFFFFFFFFFFF" << hex << uppercase << offset_x[k][i] << "\n";
			
		if(offset_y[k][i] >= 0)
			outY << hex << uppercase << offset_y[k][i] << "\n";
		else
			outY << "FFFFFFFFFFFFFFFFFFFFFFFF" << hex << uppercase << offset_y[k][i] << "\n";
		
	}
	
	int val = rand() %n;
	
	if(val >= 0){
		outX << hex << uppercase << val << "\n";
		outY << hex << uppercase << val << "\n";
	}else{
		outX << "FFFFFFFFFFFFFFFFFFFFFFFF" << hex << uppercase << val << "\n";
		outY << "FFFFFFFFFFFFFFFFFFFFFFFF" << hex << uppercase << val << "\n";
	}
		
	outX.close();
	outY.close();

}
