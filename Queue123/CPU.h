#pragma once

class CPU
{
	int powerCPU;//Мощность процессора

	CPU();
public:
	CPU(const int _power);

	bool isFree();//свободен ли процессор 

};


