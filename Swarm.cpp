#include "Swarm.h"
#include "FunctionBase.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Particle.h"
#include <ctime>

using namespace std;


int index(const vector<int> &position, int value){
	for (int i =0;i < position.size();i++){
		if (value == position.at(i)){
			return float(i);
		}
	}
}

void swapArray(vector<int> &Source, vector<vector<int> > Sequence){
	for (int i =0;i<Sequence.size();i++){
		std::swap(Source[Sequence[i][0] ],Source[Sequence[i][1] ]);
	}
}

Swarm::Swarm(){
	Momentum =1.0;
	TendencyToOwnBest = 0.34;
	TendencyToGlobalBest =0.72;
	gBestCost = 10e+10;
}
Swarm::~Swarm(){
	vector<Particle*>::iterator iter;
	for (iter = Particles.begin(); iter != Particles.end(); ++iter){
		delete *iter;
	}
}

void Swarm::InitSwarm(FunctionBase *function, int swarmSize,int dimension, int iteration){
	setSwarmSize(swarmSize);
	vector<Particle*> particles;
	particles.reserve(swarmSize);
	std::srand(time(0));
	vector<vector<int> > sequence;
	vector<int> position ;
	for(int i =0;i <dimension;i++){
			position.push_back(i+1);
	}


	for (int i=0; i < swarmSize-dimension; i++){
		for (int i =0;i<dimension;i++){
			vector<int>temp;
			temp.push_back(_rnd.NextInt() %dimension);
			temp.push_back(_rnd.NextInt()%dimension);
			sequence.push_back(temp);
		}
		swapArray(position,sequence);
		particles.push_back(new Particle(function,this,position));
	}


/*This following code will initial with deterministic mapping of N Particles N = number of router */
	for(int i = 0;i<dimension;i++){
		vector<int> core_mark(dimension,0);
		int E;	// # of edge
		int col;
		float* D= function->getData(E, col);
		position = findMap(D, i,core_mark, dimension, col, E);
		particles.push_back(new Particle(function,this,position));
	}
	this->Particles = particles;
	getGBest();
}

bool existUnmapped(const vector<int> &test){
	for (int i =0;i<test.size();i++){
		if (test.at(i) == 0) return true; //has Unmapped
	}
	return false;
}

vector<int> Swarm:: findMap(float *D, int start,vector<int> &mark, int dimension,int col, int E){

	vector<int> position(dimension,-1);
	int c1, c2,core;
	c1 = *(D+0);
	c2 = *(D+1);
	float cost1=0, cost2 =0;
	for (int i =0;i<E;i++){
		if (c1 == *(D+6*i) ) cost1 += *(D+6*i+2);
		if (c1 == *(D+6*i+1)) cost1 += *(D+6*i+2);

		if (c2 == *(D+6*i) ) cost2 += *(D+6*i+2);
		if (c2 == *(D+6*i+1)) cost2 += *(D+6*i+2);

	}
	if (cost1>cost2) {
		core = c1;
	}else{
		core = c2;
	}
	position[start] = core;
	mark[core-1] = 1;

	while(existUnmapped(mark)){

		vector<int> positions, min_positions;
		int c, pair;
		//find valid c1 and c2
		for (int i =0;i<E;i++){
			c1 = *(D+i*6+0);	c2 = *(D+i*6+1);
			if ((mark[c1-1]==1)&&(mark[c2-1]!=1)){
				c = c2;
				pair = c1;
				break;
			}else if ((mark[c2-1]==1)&&(mark[c1-1]!=1)){
				c = c1;
				pair = c2;
				break;
			}
		}

		positions = gen1Hop(position,col,dimension,pair);
		min_positions = getminPos(D,positions, position, mark,col, E,c );
//check _ok
//if (min_positions.size()==0) cout <<"Loi mapping"<<endl;

		if (min_positions.size()==1){
		//	cout <<"Yes-Simple"<<endl;
			core = min_positions.at(0);
		}else{
		//	cout <<"Yes -predict: "<<endl;
			core = predictBest(D,min_positions, position,mark, col, E, c , dimension);
		//	cout <<"Done-predict"<<endl;
		}

		//cout <<" \nvi tri tiep theo map: "<<core<<" boi " << c<<endl;
		position[core] = c;
		mark[c-1] = 1;
	}
//cout <<"done:\n";
//system("pause");
//for(int i =0;i<position.size();i++){
//	cout <<position.at(i)<< "  ";
//}
//cout<< endl;
	return position;
}


// Execute one evolution step
void Swarm::Iteration(){
	double s1 = getS1();
	double s2 = getS2();
	double s3 = getS3();

	//getSwarmSize()
	for (int i = 0; i < getSwarmSize(); i++) {
		Particles[i]->UpdatePosition(gBestPosition,s1,s2,s3);
		Particles.at(i)->calculateCost(); // Calculate fitness
		Particles.at(i)->UpdatePBest(); // Update pBest
	}

	//Update gBestCost and its position
	getGBest();
}


void Swarm:: getGBest(){
	double cost;
	for (int i =0; i < getSwarmSize(); i++){
		cost = Particles[i]->getPBestCost();

		/*for(int i=0;i<20;i++){
			cout << gBestPosition.at(i)<< " ";
		}
		cout <<endl;
		*/

		if (cost<gBestCost){
			gBestCost = cost;
			gBestPosition = Particles[i] ->getPBestPosition();
		}

		//for(int i=0;i<20;i++){
		//	cout << gBestPosition.at(i)<< " ";
		//}
		//cout <<endl;
		//system("pause");
	}
}


void Swarm::setSwarmSize(int size){
	Size = size;
}
int Swarm::getSwarmSize(){
	return Size;
}

double Swarm::getS1(){
	return Momentum;
}
double Swarm::getS2(){
	return TendencyToOwnBest;
}
double Swarm:: getS3(){
	return TendencyToGlobalBest;
}



vector<int> Swarm:: gen1Hop(const vector<int> &position, int col,int dimension, int pair){
	vector<int> result;

	int i = index(position,pair);
			int x = int(i/col);
			int y = int(i%col);
			if (x == 0){
				if (y==0 ){
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else if(y ==(col-1)){
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else {
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}
			}else if (x ==(dimension/col-1)){
				if (y==0 ){
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
				}else if(y ==(col-1)){
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
				}else {

					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
				}

			}else {
				if (y==0 ){
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else if(y ==(col-1)){
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else {
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}
			}

		if (result.size() != 0){
			return result;
		}else{







	for(int i =0; i<dimension;i++){
		if (position.at(i) != -1){
			int x = int(i/col);
			int y = int(i%col);
			if (x == 0){
				if (y==0 ){
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else if(y ==(col-1)){
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else {
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}
			}else if (x ==(dimension/col-1)){
				if (y==0 ){
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
				}else if(y ==(col-1)){
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
				}else {

					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
				}

			}else {
				if (y==0 ){
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else if(y ==(col-1)){
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}else {
					if(position.at(i-1) ==-1)	result.push_back(i-1);
					if(position.at(i+1) ==-1)	result.push_back(i+1);
					if(position.at(i-col) ==-1)	result.push_back(i-col);
					if(position.at(i+col) ==-1)	result.push_back(i+col);
				}
			}
		}
	}
	vector<int> pos;
	pos.push_back(result.at(0));
	for (int i =1;i<result.size();i++){
		bool flag = true;
		for(int j =0;j<pos.size();j++){
			if(pos.at(j) == result.at(i)){
				flag = false;
				break;
			}
		}
		if (flag) pos.push_back(result.at(i));
	}


	return pos;
	}
	}
///////////////////////////////////////////////////////////////


vector<int> Swarm:: getminPos(float *D, const vector<int> positions, const vector<int> position, vector<int> &mark, int col,int E, int c ){
	vector <int> cost;
	vector <int> result;
	int _cost =0, min =10e+9;

	for(int u_next =0;u_next<positions.size();u_next++){
		_cost = 0;
		int router= positions.at(u_next);
		vector<int> temp_Posn = position;
		temp_Posn[router] = c;
		mark[c-1] =1;

		for (int i =0;i<E;i++){
			int c1 = *(D+i*6+0),	c2 = *(D+i*6+1);
			if((mark[c1-1]==1)&&(mark[c2-1] ==1)){
				///cout <<"Yes\t"<<c1<<"\t"<<c2<<endl; system("pause");
				int u1 = index(temp_Posn,c1);
				int u2 = index(temp_Posn,c2);
				///cout <<"\t"<<u1<<"\t"<<u2<<endl;
				int hop = abs(u1/col -u1%col) + abs(u2/col -u2%col);
				_cost += *(D + i*6 + 2) * hop;
			}
		}

		if(min>_cost){
			min = _cost;
		}
		cost.push_back(_cost);
		mark[c-1]= 0;
	}
	for (int i =0;i <positions.size(); i++){
		if (cost.at(i)==min) result.push_back(positions.at(i));
	}
	return result;
}

int Swarm :: predictBest(float *D, const vector<int> min_positions, const vector<int> position, vector<int> &mark, int col,int E, int c , int dimension){
	int p;
	float _cost;
	int min_cost = 10e+9;


	for(int u_next =0;u_next<min_positions.size();u_next++){
		vector<int> temp_Posn = position;
		int router= min_positions.at(u_next);	//ok
		temp_Posn[router] = c;
		mark[c-1] =1;

		//vector<int> temp_mark = mark;
	/*cout <<"Core: "<<c<<" vao "<<router<<endl;system("pause");
	for(int i =0;i<16;i++){
		cout<<temp_Posn.at(i)<<" ";
	}
	cout<<endl;*/
		//check _ok
		while(existUnmapped(mark)){

			vector<int> _positions, _min_positions;
			int _c, _pair;
			for (int i = 0;i<E;i++){
				int c1 = *(D+i*6+0);	int c2 = *(D+i*6+1);
				if ((mark[c1-1]==1)&&(mark[c2-1]!=1)){
					_c = c2;	_pair = c1;	break;
				}else if ((mark[c2-1]==1)&&(mark[c1-1]!=1)){
					_c = c1;	_pair = c2;	break;
				}
			}
			_positions = gen1Hop(temp_Posn,col,dimension,_pair);//check ok
			_min_positions = getminPos(D,_positions, temp_Posn, mark,col, E,_c);
		//cout<<"minsize "<<_min_positions.size()<<endl;
			int r = _min_positions.at(0);
			//cout <<"next_core: "<<_c<<" vao vi tri "<<r<<" voi vnvnn"<<endl;
			temp_Posn[r] = _c;
			mark[_c-1] = 1;


			_cost = getTotal(D, temp_Posn, mark, col, E, _c, r );

//cout <<"next_core: "<<_c<<" vao vi tri "<<r<<" voi "<<_cost<<endl;
//for(int i =0;i<16;i++){
//		cout<<temp_Posn.at(i)<<" ";
//}
//cout<<endl;

			mark[_c-1]=0;
			if (min_cost>_cost){
				//std:: cout<<"Yes. router "<<router<<endl;
				min_cost = _cost;
				p =  router;
			}
			break;
		}
		mark[c-1] =0;
	}

	return p;
}


float Swarm:: getTotal(float *D, const vector<int> position, vector<int> &mark, int col,int E, const int &c,int u ){
	float _cost = 0;
	vector<int> temp_Posn = position;
	temp_Posn[u] = c;
	mark[c-1] =1;
	for (int i =0;i<E;i++){
		int c1 = *(D+i*6+0),	c2 = *(D+i*6+1);
		if((mark[c1-1]==1)&&(mark[c2-1] ==1)){
			int u1 = index(position,c1);
			int u2 = index(position,c2);
			int hop = abs(u1/col -u1%col) + abs(u2/col -u2%col);
			_cost += *(D + i*6 + 2) * hop;
		}
	}
	mark [c-1] =0;
	return _cost;
}
