/* 
 * Title: randnum.cpp
 * Author: Alec Bennett
 * Description: Random number generation distributed across MPI tasks
 */

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
		/* 
 		 * Each task gets a different random number, but it is consistently generated
		 * no matter how many tasks are used, thus can be reproduced
		 */
		srand(12345 + i);
		std::cout << "Core: " << id << " Rep: " << i << " - Num: " << rand() << std::endl;
	}
	
	MPI::Finalize();
	return 0;
}
