
#include<iostream>
#include <vector>
#include<cstdlib>
#include"Particle.h"
#include <ctime>
#include "Random.h"
using namespace std;
Particle::Particle(){
}

Particle::Particle(FunctionBase* function, Swarm* swarm, vector<int> position){
	CostFunction = function;
	this->swarm = swarm;
	Position = position;

	// First time, pBestCost = initial cost and pBestPosition = initial position
	calculateCost();
	PBestCost = Cost;
	PBestPosition = Position;
}

void Particle::calculateCost(){
	Cost = CostFunction->getFx(Position);

}

Particle::~Particle(){
}

void Particle::UpdatePBest(){

	/*for(int i=0;i<20;i++){
		cout << PBestPosition.at(i)<< " ";
	}
	cout <<endl;*/
	if(Cost < PBestCost){
	//	cout<<"Yes"<<endl;
		PBestCost = Cost;
		PBestPosition = Position;	/// A copy of the current position the best position to make history
	}
	//for(int i=0;i<20;i++){
	//	cout << PBestPosition.at(i)<< " ";
	//}
	//cout <<endl;
	//system("pause");

}

void Particle::UpdatePosition(vector<int> bestPositionOfSwarm, double s1, double s2, double s3){

	vector < vector<int> > sequence1= detectSwapSequence(Position,PBestPosition);
	vector < vector<int> > sequence2= detectSwapSequence(Position,bestPositionOfSwarm);
	vector < vector<int> > sequence;
	srand(time(0));

	//Persional alignment;
	for(int i=0;i<sequence1.size();i++){
		if ( _rnd.NextDouble()>=s2){
			vector<int> temp = sequence1.at(i);
			sequence.push_back(temp);
		}
	}

	for(int i=0;i<sequence2.size();i++){
		if (_rnd.NextDouble() >=s3){
			vector<int> temp = sequence2.at(i);
			sequence.push_back(temp);

			//cout <<"TEst" <<i<<endl;
		}
	}

	/*///////////////////////////////////////////////////////////////////////////////////////
	cout <<"# of Swap: "<<sequence.size()<<endl;
	for(int i=0;i<sequence.size();i++){
		for(int j =0;j<2;j++){
			cout << sequence[i][j]<<" ";
		}
		cout <<endl;
	}
	system("pause");

	cout<<"Check that ????"<<endl;
	for (int i=0; i < sequence2.size();i++){
		for (int j =0;j<2;j++){
			cout<< sequence2[i][j]<< " ";
		}
		cout<<endl;
	}
	system("pause");

	vector<int>::iterator iter1;
	for (iter1 = Position.begin(); iter1 !=Position.end()-3; ++iter1){
			cout<<*iter1<<" ";
		}
		cout <<endl;
		system("pause");*/

	swapArray(Position,sequence);

	//
	//for (iter1 = Position.begin(); iter1 !=Position.end()-3; ++iter1){
	//		cout<<*iter1<<" ";
	//	}
	//	cout <<endl;
	//	system("pause");
}

vector<vector<int> >Particle:: detectSwapSequence(const vector<int> &S, const vector<int> &T){
	vector<vector<int> > result;
	vector<int> Source = S;
	vector<int> Target = T;
	for (int i =0;i<Target.size();i++){
		vector<int> temp(2,1);
		for(int j =0;j<Source.size();j++){
			if ((i!=j)&&(Target.at(i)== Source.at(j))){
				std::swap(Source.at(i),Source.at(j));
				temp.at(0)=i;
				temp.at(1)=j;
				result.push_back(temp);
				break;
			}
		}
	}
	return result;
}

void Particle::swapArray(vector<int> &Source, vector<vector<int> > Sequence){
	for (int i =0;i<Sequence.size();i++){
		std::swap(Source[Sequence[i][0]],Source[Sequence[i][1] ]);
	}
}

vector<int> Particle::getPBestPosition(){
	return PBestPosition;
}
double Particle::getPBestCost(){
	return PBestCost;
}
double Particle:: getCost(){
	return Cost;
}
vector<int> Particle::getPosition(){
	return Position;
}

