#include <iostream>
#include <stdlib.h>
#include "mpi.h"

int main (int argc, char* argv[]){
	int id = 0;
        int max = 1;
	MPI::Init();
        id = MPI::COMM_WORLD.Get_rank();
        max = MPI::COMM_WORLD.Get_size();


	int randNumber;
	
	for (int i = 0 + id; i < 100; i += max){
		srand(12345 + i);
		std::cout << "Core: " << id << " Rep: " << i << " - Num: " << rand() << std::endl;
	}
	
	MPI::Finalize();
	return 0;
}