#include "CPU.h"
#include <cstdlib> 

bool CPU::isFree()
{
	return (rand() % 100) < powerCPU;//�������� �� 0 �� 100 � ��������� ��������� 
}
CPU::CPU(const int _power) : powerCPU(_power)
{

}

