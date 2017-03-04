
#ifndef GENETICS_H_
#define GENETICS_H_


#include <vector>





#include "problem.h"
#include "chromosome.h"


class Genetics
{
public:
	Genetics();
	~Genetics();


	void Setup(Problem *problem,
		const int &PopSize,
		const int &MaxIter,
		const float &ElitRate,
		const float &MutRate
	);


	void Work();


private:

	std::vector<Chromosome > *mPopulation;
	std::vector<Chromosome > *mBuffer;
	int mPopSize;
	int mMaxIter;
	float mElitRate;
	float mMutRate;

	Problem *mProblem;

	void SortByFitness();
	void PrintBest();

};



#endif