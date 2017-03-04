#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_

#include <string>

//class Problem;

class Chromosome
{
public:
	Chromosome();
	~Chromosome();


	float GetFitness();
	std::string GetValue();

	
	void SetFitness(const float &fitness);
	void SetValue(const std::string &value);

	
	int ToDecimal();


	void Mutate();
	void Crossover(Chromosome &Other,const int &CrossoverPoint);

	
private:
	float mFitness;

	std::string mValue;



};



#endif