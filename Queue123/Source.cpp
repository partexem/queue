#include <iostream>
#include <ctime>

#include "CPU.h"
#include "Queue.h"
#include "TaskFlow.h"

int main() {

	using namespace std;
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	int value;
	int id = 1;
	int ignor = 0;
	int dinamo = 0;
	bool isFirstTask = true;
	int taskInQueue = 1;

	int current = 1;

	cout << "������� ������ ������� \n";
	cin >> value;
	Queue myQueue(value);

	cout << "������� �������� ���������� �� 0 �� 100 \n";
	cin >> value;
	CPU myCPU(value);

	cout << "������� ������������� ������ ����� �� 0 �� 100 \n";
	cin >> value;
	TaskFlow myTaskFlow(value);

	cout << "���-�� ������ \n";
	cin >> value;
	for (int takt = 1; takt <= value; takt++) //value - ������ ������������� 
	{
		cout << takt << " ����" << endl;
		if (myTaskFlow.isGeneration())
		{
			cout << "������ ���� �������������";

			if (!myQueue.isFull())
			{
				myQueue.addElement(id++);
				cout << ", ��������� � �������." << endl;
			}
			else
			{
				ignor++;
				cout << " � ���������������." << endl;
			}

		}
		else
		{
			cout << "������ �� �������������." << endl;
		}
		if (myCPU.isFree() || isFirstTask)
		{
			cout << "��������� ";
			if (!myQueue.isEmpty())
			{
				isFirstTask = false;
				myQueue.getElement();
				cout<< " ��������� ������ " << current++ << endl;
			}
			else
			{
				dinamo++;
				cout << "�����������." << endl;
			}
		}
		else
		{
			cout << "��������� ����� ����������� ���������� ������." << endl;

		}


	}

	while (!myQueue.isEmpty())
	{
		myQueue.getElement();
		taskInQueue++;
	}

	float protsent = 0;
	protsent = ((float)ignor / (id + ignor)) * 100;

	float prostprotsent = 0;
	prostprotsent = ((float)dinamo / value) * 100;

	float srtime = 0;
	if (id - taskInQueue > 0)
		srtime = ((float)(value - dinamo) / (id - taskInQueue));
	else
		srtime = 0;


	cout << "\n������� ����������������� ����� ����� " << protsent << endl;
	cout << "������� ������� ���������� " << prostprotsent << endl;
	cout << "������� ����� ���������� ������ " << srtime << endl;



	system("pause");
	return 0;


}
