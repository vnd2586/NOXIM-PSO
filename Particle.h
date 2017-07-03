

#ifndef _PARTICLE_H
#define _PARTICLE_H

#include <vector>
#include "FunctionBase.h"
#include "Swarm.h"
#include "Random.h"

class Particle{
private:
	vector<int> Position;//Position of core in Topo graph
	vector<int> PBestPosition;
	double PBestCost;
	double Cost;
	FunctionBase* CostFunction;
protected:
	Random _rnd;
public:
	Swarm *swarm;

	Particle();
	Particle(FunctionBase* function, Swarm* swarm, vector<int> position);
	~Particle();

	void calculateCost();
	void UpdatePBest();
	void UpdatePosition(vector<int> bestPositionOfSwarm, double m, double c1, double c2);

	vector<vector<int> > detectSwapSequence(const vector<int> &S, const vector<int> &T);

	void swapArray(vector<int> &Source, vector<vector<int> > Sequence);

	double  getCost();
	vector<int> getPosition();
	double getPBestCost();

	vector<int> getPBestPosition();

};
#endif
