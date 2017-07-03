#ifndef _SWARM_H
#define _SWARM_H

#include<vector>
#include<cstdlib>
#include "FunctionBase.h"
#include "Random.h"
using namespace std;

class Particle;
class Swarm {
	private:
		double Momentum;							//s1
		double TendencyToOwnBest;					//s2
		double TendencyToGlobalBest;				//s3
		int Size;
protected:
	Random _rnd;
public:
		vector<int> gBestPosition;
		double gBestCost;

		/// Particles
		vector<Particle*> Particles;

		Swarm();
		~Swarm();
		int getSwarmSize();
		void setSwarmSize(int size);
		double getS1();
		double getS2();
		double getS3();

		//------------------------------------------------------
		/// Init the swarm
		void InitSwarm(FunctionBase *function, int swarmSize,int demension, int interation);
		/// Execute one evolution step
		virtual void Iteration();

		vector<int> findMap(float *D, int start,vector<int> &mark, int dimension,int col, int E);


		vector<int> gen1Hop(const vector<int> &position, int col,int dimension, int pair);
		vector<int> getminPos(float *D, const vector<int> positions, const vector<int> position, vector<int> &mark, int col,int E, int c );
		int predictBest(float *D, const vector<int> min_positions, const vector<int> position, vector<int> &mark, int col,int E, int c , int dimension);
		void getGBest();
		float  getTotal(float *D, const vector<int> position, vector<int> &mark, int col,int E,const int &c,int u );
};

#endif
