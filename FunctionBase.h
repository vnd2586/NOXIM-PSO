
#pragma once

#include <vector>
#include <cmath>

using namespace std;
// Cost function
class FunctionBase {

public:
	FunctionBase();
	virtual float getFx(const vector<int> &position)=0;
	virtual float* getData(int &E, int &col) =0;

	void genToPo(const vector<int> &position,int N, int col, float Data[][6]);
	float index(const vector<int> &position, float value);
	float genHopCount(const int &value1,const int &value2,int col); //must convert to int
	//float getFx(const vector<int> &position,int N,int col);

	void sortGraph(float Data[][6],int E);

	~FunctionBase();
};

/*----------PIP-------------------------*/
class PIP : public FunctionBase{
private:
	float Data[8][6];
	int E;
	int col;		//colum of topology ie: 3x3 mesh
public:
	PIP();
	~PIP();
	float getFx(const vector<int> &position);
};


/*----------DVOPD-------------------------*/
class DVOPD : public FunctionBase{
private:
	float Data[44][6];
	int E;
	int col;		//colum of topology ie: 3x3 mesh
public:
	DVOPD();
	~DVOPD();
	float getFx(const vector<int> &position);
	float* getData(int &E, int &col);
};


/*----------VOPD-------------------------*/
class VOPD : public FunctionBase{
private:
	float Data[21][6];
	int E;
	int col;

public:
	VOPD();
	~VOPD();
	float* getData(int &E, int &col);
	float getFx(const vector<int> &position);
};
