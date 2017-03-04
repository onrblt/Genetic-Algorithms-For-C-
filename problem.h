
#ifndef PROBLEM_H_
#define PROBLEM_H_

#include "chromosome.h"



class Problem
{
public:
	Problem(int MaxNum);
	~Problem();

	int GetMaxNum();

	void SetFunction(int (*FuncPtr)(Chromosome));

	int (*mFuncPtr)(Chromosome);



private:
	int mMaxNum;
	
	
	
};



#endif