#include "genetics.h"



Problem::Problem(int MaxNum)
{
	mMaxNum=MaxNum;
}
Problem::~Problem()
{

}

int Problem::GetMaxNum()
{
	return mMaxNum;
}

void Problem::SetFunction(int (*FuncPtr)(Chromosome))
{
	mFuncPtr = FuncPtr;


}

