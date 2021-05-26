#include "TaskFlow.h"
#include <cstdlib>


TaskFlow::TaskFlow(const int n)
{
	taskintensity = n;
}

bool TaskFlow::isGeneration()
{
	return (rand() % 100) < taskintensity;
}
