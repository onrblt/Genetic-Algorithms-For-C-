
#include <iostream>
#include "chromosome.h"

//#define BIG_NUMBER 99

Chromosome::Chromosome()//Problem * problem)
{
	mValue="";
	mFitness=0;
}

Chromosome::~Chromosome()
{

}


float Chromosome::GetFitness()
{
	return mFitness;
}

std::string Chromosome::GetValue()
{
	return mValue;
}

void Chromosome::SetFitness(const float &fitness)
{
	mFitness=fitness;

}
void Chromosome::SetValue(const std::string &value)
{
	mValue = value;

}


void Chromosome::Mutate()
{

	if(mValue.size()<=0)return;

	int ipos = (rand() % (int)mValue.size());
	//int delta = (rand() % 2) + (int)'0'; 

	std::cout<<"MutLoc="<<ipos<<std::endl;

	mValue[ipos] = (mValue[ipos]=='0')?'1':'0';

	
	
	std::cout<<"After="<<mValue<<std::endl;

}

void Chromosome::Crossover(Chromosome &Other,const int &CrossoverPoint)
{
	//int ipos = rand() % mValue.size();
	

	//std::string temp=mValue;
	//std::string tempOther = Other.GetValue();
	
	//std::cout<<"CrsLoc="<<CrossoverPoint<<std::endl;
	//std::cout<<"Before1="<<mValue<<std::endl;
	//std::cout<<"Before2="<<Other.mValue<<std::endl;

	std::string crd=mValue.substr(0,CrossoverPoint);
	std::string crd2=mValue.substr(CrossoverPoint,mValue.size()-CrossoverPoint);

	std::string crd3=Other.GetValue().substr(0,CrossoverPoint);
	std::string crd4=Other.GetValue().substr(CrossoverPoint,Other.GetValue().size()-CrossoverPoint);

	crd+=crd4;
	crd3+=crd2;

	SetValue(crd);
	Other.SetValue(crd3);

	
	//std::cout<<"After1="<<mValue<<std::endl;
	//std::cout<<"After2="<<Other.mValue<<std::endl;

}


int Chromosome::ToDecimal()
{
	
	int val = 0;
	int len = mValue.length();
	for(int i = 0; i < len ; i++)
	{
		if(mValue[i]=='0')
		{
			//Do nothing!

		}
		else if(mValue[i]=='1')
		{
			val += pow(2.0,len-i-1);

		}

	}

	return val;
}
