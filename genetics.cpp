
#include <iostream>

#include <algorithm>

#include "genetics.h"


Genetics::Genetics()
{
	mPopulation= new std::vector<Chromosome>();
	mBuffer= new std::vector<Chromosome>();

}
Genetics::~Genetics()
{
	

	//mPopulation->clear();
	//mBuffer->clear();

	delete mPopulation;
	delete mBuffer;



	/*
	for(int i = 0; i < mBuffer.size(); i++)
	{
		if(mBuffer[i])
		{
			delete mBuffer[i];
			mBuffer[i] = NULL;
		}
	}
	*/

}

std::string RandValue(const int &MaxNum)
{
	
	std::string temp="";
	for(int i = 0; i < MaxNum; i++)
	{
		int R = rand()%2;
		if(R == 0)
			temp+='0';
		else
			temp+='1';
	}
	return temp;
}

void Genetics::Setup(Problem *problem,
		const int &PopSize,
		const int &MaxIter,
		const float &ElitRate,
		const float &MutRate
	)
{
	mProblem=problem;
	mPopSize=PopSize;
	mMaxIter=MaxIter;
	mElitRate=ElitRate;
	mMutRate=MutRate;




	for(int i = 0; i < mPopSize; i++)
	{
		Chromosome chr ;//= new Chromosome();
		chr.SetValue(RandValue(mProblem->GetMaxNum()));
		
		std::cout<<chr.GetValue() << "||" << chr.ToDecimal()<<std::endl;

		mPopulation->push_back(chr);

	}
	
	for(int i = 0; i < mPopSize; i++)
	{
		Chromosome chr2;//= new Chromosome();
		chr2.SetValue(mPopulation->at(i).GetValue());
		
		//std::cout<<chr2.GetValue() << "||" << chr2.ToDecimal()<<std::endl;

		mBuffer->push_back(chr2);

	}
	


	//mBuffer->resize(mPopSize);

}


bool FitnessSort(Chromosome x, Chromosome y) 
{ 
	return (x.GetFitness() < y.GetFitness()); 
}


void Genetics::PrintBest()
{ 
	std::cout << "Best: " << mPopulation->at(0).GetValue() << "||" << mPopulation->at(0).ToDecimal()<< " (" <<mPopulation->at(0).GetFitness() << ")" << std::endl;
}


void Genetics::Work()
{
	//int IterNum=0;
	int targetSize=mProblem->GetMaxNum();
	
	int elitSize = mPopSize * mElitRate;

	for(int it = 0 ; it <mMaxIter; it++)
	{
		//calc fitness

		for (int i=0; i<mPopSize; i++) {
			int fitness =mProblem->mFuncPtr(mPopulation->at(i));

			//for (int j=0; j<targetSize; j++) {
			//	fitness += abs(int(population[i].str[j] - target[j]));
			//}
		
			//population[i].fitness = fitness;
			
			mPopulation->at(i).SetFitness(fitness);

		}
		//sort by fitness
		std::sort(mPopulation->begin(), mPopulation->end(), FitnessSort);


		PrintBest();

		//Elitism

		for (int i=0; i<elitSize; i++) {
			mBuffer->at(i).SetValue(mPopulation->at(i).GetValue());
			mBuffer->at(i).SetFitness(mPopulation->at(i).GetFitness());
		}
		// Mating


		for (int i=elitSize; i<mPopSize; i++) {
			int i1 = rand() % (mPopSize / 2);
			int i2 = rand() % (mPopSize / 2);
			int spos = rand() % (targetSize-1)+1;

			//buffer[i].str = mPopulation[i1].str.substr(0, spos) + 
				//			mPopulation[i2].str.substr(spos, esize - spos);
	
			//mPopulation[0]->Mutate();
			mPopulation->at(i1).Crossover(mPopulation->at(i2),spos);

			if (rand() < RAND_MAX*mMutRate)
			{
				if(mBuffer)
					mBuffer->at(i).Mutate();
			}
		}

		
		//if (mPopulation->at(0).GetFitness() == 0) break;//Completed!


		// swap buffers
		//std::vector<Chromosome > *temp = mPopulation; mPopulation = mBuffer; mBuffer = temp;
		std::swap(mBuffer,mPopulation);
		std::cout<<"----end it----"<<std::endl;
	}


}

