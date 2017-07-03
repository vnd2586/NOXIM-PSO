
#include "FunctionBase.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

FunctionBase::FunctionBase(){
};

FunctionBase::~FunctionBase(){
};

void FunctionBase:: genToPo(const vector<int> &position,int N, int col, float Data[][6]){
	for (int i=0;i<N;i++){
		Data[i][3]= index(position,Data[i][0]);
		Data[i][4]= index(position,Data[i][1]);
		Data[i][5]= genHopCount(Data[i][3],Data[i][4],col);
	}
}

float FunctionBase::index(const vector<int> &position, float value){
	for (int i =0;i < position.size();i++){
		if (value == float(position.at(i)) ){
			return float(i);
		}
	}
}

float FunctionBase:: genHopCount(const int &value1,const int &value2, int col){
	int remain1, remain2,quotient1, quotient2;
	remain1 = value1%col;	remain2 = value2%col;
	quotient1 = value1/col; quotient2 = value2/col;
	return float (abs(remain1-remain2) + abs(quotient1-quotient2));
}


void FunctionBase::sortGraph(float Data[][6],int E){
	for (int i=0; i<E-1; i++){
		int k = i;
		for (int j =i+1; j<E; j++){
			if (Data[k][2] < Data[j][2]) k = j;
		}
		std::swap(Data[k][2],Data[i][2]);
		std::swap(Data[k][1],Data[i][1]);
		std::swap(Data[k][0],Data[i][0]);
	}
}


/*************************************Done_Basic**************************************/
/*----------PIP-------------------------*/
PIP::PIP(){
	E = 8;
	col = 3;
	Data[0][0] =1;		Data[0][1] =5;		Data[0][2] =64;
	Data[1][0] =2;		Data[1][1] =1;		Data[1][2] =128;
	Data[2][0] =2;		Data[2][1] =3;		Data[2][2] =64;
	Data[3][0] =3;		Data[3][1] =4;		Data[3][2] =64;
	Data[4][0] =4;		Data[4][1] =7;		Data[4][2] =64;
	Data[5][0] =5;		Data[5][1] =6;		Data[5][2] =64;
	Data[6][0] =6;		Data[6][1] =7;		Data[6][2] =64;
	Data[7][0] =7;		Data[7][1] =8;		Data[7][2] =64;
	sortGraph(Data,E);
}

PIP::~PIP(){
}

float PIP::getFx(const vector<int> &position){
	float result = 0;
	genToPo(position,E,col,Data);
	for (int i =0;i<E;i++){
		result += Data[i][2]*Data[i][5];
	}
	return result;
}

/*----------------END_PIP------------------------------------------*/

/*----------DVOPD-------------------------*/
DVOPD::DVOPD(){
	E = 44; col = 8;
	Data[0][0] =1;		Data[0][1] =2;		Data[0][2] =70;
	Data[1][0] =2;		Data[1][1] =3;		Data[1][2] =362;
	Data[2][0] =3;		Data[2][1] =4;		Data[2][2] =362;
	Data[3][0] =4;		Data[3][1] =5;		Data[3][2] =362;
	Data[4][0] =4;		Data[4][1] =15;		Data[4][2] =49;
	Data[5][0] =5;		Data[5][1] =6;		Data[5][2] =357;
	Data[6][0] =6;		Data[6][1] =7;		Data[6][2] =353;
	Data[7][0] =7;		Data[7][1] =8;		Data[7][2] =300;
	Data[8][0] =8;		Data[8][1] =9;		Data[8][2] =313;
	Data[9][0] =8;		Data[9][1] =10;		Data[9][2] =500;
	Data[10][0] =9;		Data[10][1] =10;		Data[10][2] =313;
	Data[11][0] =10;		Data[11][1] =9;		Data[11][2] =94;
	Data[12][0] =11;		Data[12][1] =9;		Data[12][2] =16;
	Data[13][0] =11;		Data[13][1] =6;		Data[13][2] =16;
	Data[14][0] =11;		Data[14][1] =12;		Data[14][2] =16;
	Data[15][0] =11;		Data[15][1] =32;		Data[15][2] =540;
	Data[16][0] =12;		Data[16][1] =13;		Data[16][2] =157;
	Data[17][0] =13;		Data[17][1] =14;		Data[17][2] =16;
	Data[18][0] =14;		Data[18][1] =11;		Data[18][2] =16;
	Data[19][0] =14;		Data[19][1] =12;		Data[19][2] =16;
	Data[20][0] =15;		Data[20][1] =5;		Data[20][2] =27;
	Data[21][0] =16;		Data[21][1] =17;		Data[21][2] =70;
	Data[22][0] =17;		Data[22][1] =18;		Data[22][2] =362;
	Data[23][0] =18;		Data[23][1] =19;		Data[23][2] =362;
	Data[24][0] =19;		Data[24][1] =20;		Data[24][2] =362;
	Data[25][0] =19;		Data[25][1] =30;		Data[25][2] =49;
	Data[26][0] =20;		Data[26][1] =21;		Data[26][2] =357;
	Data[27][0] =21;		Data[27][1] =22;		Data[27][2] =353;
	Data[28][0] =22;		Data[28][1] =23;		Data[28][2] =300;
	Data[29][0] =23;		Data[29][1] =24;		Data[29][2] =313;
	Data[30][0] =23;		Data[30][1] =25;		Data[30][2] =500;
	Data[31][0] =24;		Data[31][1] =25;		Data[31][2] =313;
	Data[32][0] =25;		Data[32][1] =24;		Data[32][2] =94;
	Data[33][0] =26;		Data[33][1] =24;		Data[33][2] =16;
	Data[34][0] =26;		Data[34][1] =27;		Data[34][2] =16;
	Data[35][0] =26;		Data[35][1] =21;		Data[35][2] =16;
	Data[36][0] =26;		Data[36][1] =32;		Data[36][2] =540;
	Data[37][0] =27;		Data[37][1] =28;		Data[37][2] =157;
	Data[38][0] =28;		Data[38][1] =29;		Data[38][2] =16;
	Data[39][0] =29;		Data[39][1] =26;		Data[39][2] =16;
	Data[40][0] =29;		Data[40][1] =27;		Data[40][2] =16;
	Data[41][0] =30;		Data[41][1] =20;		Data[41][2] =27;
	Data[42][0] =31;		Data[42][1] =1;		Data[42][2] =126;
	Data[43][0] =31;		Data[43][1] =16;		Data[43][2] =126;
	sortGraph(Data,E);
}

float DVOPD::getFx(const vector<int> &position){
	float result = 0;
	genToPo(position,E,col,Data);
	for (int i =0;i<E;i++){
		result += Data[i][2]*Data[i][5];
	}
	return result;
}
float* DVOPD:: getData(int &E, int &col){
	E = this->E;
	col = this->col;
	return Data[0];
}

DVOPD::~DVOPD(){

}
/*----------------END_DVOPD------------------------------------------*/

/*----------VOPD-------------------------*/
VOPD::VOPD(){
	E = 21; col = 4;
	Data[0][0] =1;		Data[0][1] =2;		Data[0][2] =70;
	Data[1][0] =2;		Data[1][1] =3;		Data[1][2] =362;
	Data[2][0] =3;		Data[2][1] =4;		Data[2][2] =362;
	Data[3][0] =4;		Data[3][1] =5;		Data[3][2] =362;
	Data[4][0] =4;		Data[4][1] =16;		Data[4][2] =49;
	Data[5][0] =5;		Data[5][1] =6;		Data[5][2] =357;
	Data[6][0] =6;		Data[6][1] =7;		Data[6][2] =353;
	Data[7][0] =7;		Data[7][1] =8;		Data[7][2] =300;
	Data[8][0] =8;		Data[8][1] =9;		Data[8][2] =313;
	Data[9][0] =8;		Data[9][1] =10;		Data[9][2] =500;
	Data[10][0] =9;		Data[10][1] =10;		Data[10][2] =313;
	Data[11][0] =10;		Data[11][1] =9;		Data[11][2] =94;
	Data[12][0] =11;		Data[12][1] =12;		Data[12][2] =16;
	Data[13][0] =12;		Data[13][1] =6;		Data[13][2] =16;
	Data[14][0] =12;		Data[14][1] =9;		Data[14][2] =16;
	Data[15][0] =12;		Data[15][1] =13;		Data[15][2] =16;
	Data[16][0] =13;		Data[16][1] =14;		Data[16][2] =157;
	Data[17][0] =14;		Data[17][1] =15;		Data[17][2] =16;
	Data[18][0] =15;		Data[18][1] =11;		Data[18][2] =16;
	Data[19][0] =15;		Data[19][1] =13;		Data[19][2] =16;
	Data[20][0] =16;		Data[20][1] =5;		Data[20][2] =27;

	sortGraph(Data,E);
}

float VOPD::getFx(const vector<int> &position){
	float result = 0;
	genToPo(position,E,col,Data);
	for (int i =0;i<E;i++){
		result += Data[i][2]*Data[i][5];
	}
	return result;
}

float* VOPD:: getData(int &E, int &col){
	E = this->E;
	col = this->col;
	return Data[0];
}


VOPD::~VOPD(){

}

