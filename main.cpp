
//#include <vld.h>

#pragma warning(disable:4786)		// disable debug warning

#include <iostream>					// for cout etc.
#include <vector>					// for vector class
#include <string>					// for string class
#include <time.h>					// for random seed
#include <math.h>					// for abs()
#include <conio.h>

#include "genetics.h"

static int func(Chromosome chrmsm)
{
	//biggest square
	//return (chrmsm.ToDecimal()*chrmsm.ToDecimal());
	return chrmsm.ToDecimal()*chrmsm.ToDecimal()+15*(-chrmsm.ToDecimal());

}


int main()
{
	srand(unsigned(time(NULL)));

	Problem* prb=new Problem(5);
	prb->SetFunction(func);


	Genetics genetics;
	genetics.Setup(prb,10,10,0.25f,0.1f);
	
	genetics.Work();

	delete prb;
	prb=0;

	printf("OK!");
	getch();


	return 0;
}
