#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "Particle.h"
#include "Swarm.h"


using namespace std;

int main(){
	cout<<"PSO start..."<<endl;
	//----------------------------------------------
	DVOPD fuction;
	int dimension = 32;	//Number of core
	//_----------------------------------------------
	// This properties is private for each application

	int swarmSize = 200;
	int iteration = 1000;
	Swarm swarm;
	swarm.InitSwarm(&fuction,swarmSize,dimension,iteration); // Init Swarm

	ofstream fileOut ("RESULT.txt", ios:: out);
	int i=0;
	while (i<=iteration) {
		/*
		//Print out to file /////////////////////////////////////////////////////
		fileOut <<"Iteration "<< i <<endl;

		for (int i =0;i<swarm.getSwarmSize();i++){
			vector <int> t = swarm.Particles[i]->getPosition();
			fileOut <<"Particle["<<i<<"] ";
			for (int j =0; j <dimension; j++){
				fileOut << t.at(j) <<"\t";
			}
			fileOut <<endl;
		}


		for (int j =0; j <dimension; j++){
			fileOut << swarm.gBestPosition.at(j) <<"\t";
			if ((j+1)%(int(sqrt(dimension))) ==0) fileOut <<endl;
		}
		fileOut <<"Best cost: "<<swarm.gBestCost<<endl;
		///////////////////////////////////////////////////////////////////////////
		*/
		swarm.Iteration();
		cout<<i<<"\t"<<swarm.gBestCost<<"\n"<<endl;

		if (i%200 ==0){
			swarm.InitSwarm(&fuction,swarmSize,dimension,iteration);
		}

		i++;
	}

	cout<<"Best Cost Are:"<<swarm.gBestCost<<"\n"<<endl;
	cout<<"Best Position Are:\n"<<endl;
	vector<int>::iterator iter;
	for (iter = swarm.gBestPosition.begin(); iter != swarm.gBestPosition.end(); ++iter){
		cout<<*iter<<" ";
	}

	cout<<endl;
	fileOut<<endl;
	fileOut.close();

	system("pause");
	return 0;
}
