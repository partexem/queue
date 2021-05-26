#include "CPU.h"
#include <cstdlib> 

bool CPU::isFree()
{
	return (rand() % 100) < powerCPU;//рандомим от 0 до 100 и проверяет выражение 
}
CPU::CPU(const int _power) : powerCPU(_power)
{

}

