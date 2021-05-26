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

	cout << "Введите размер очереди \n";
	cin >> value;
	Queue myQueue(value);

	cout << "Введите мощность процессора от 0 до 100 \n";
	cin >> value;
	CPU myCPU(value);

	cout << "Введите интенсивность потока задач от 0 до 100 \n";
	cin >> value;
	TaskFlow myTaskFlow(value);

	cout << "Кол-во тактов \n";
	cin >> value;
	for (int takt = 1; takt <= value; takt++) //value - период моделирования 
	{
		cout << takt << " такт" << endl;
		if (myTaskFlow.isGeneration())
		{
			cout << "Задача была сгенерирована";

			if (!myQueue.isFull())
			{
				myQueue.addElement(id++);
				cout << ", добавлена в очередь." << endl;
			}
			else
			{
				ignor++;
				cout << " и проигнорирована." << endl;
			}

		}
		else
		{
			cout << "Задача не сгенерирована." << endl;
		}
		if (myCPU.isFree() || isFirstTask)
		{
			cout << "Процессор ";
			if (!myQueue.isEmpty())
			{
				isFirstTask = false;
				myQueue.getElement();
				cout<< " выполняет задачу " << current++ << endl;
			}
			else
			{
				dinamo++;
				cout << "простаивает." << endl;
			}
		}
		else
		{
			cout << "Процессор занят выполнением предыдущей задачи." << endl;

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


	cout << "\nПроцент проигнорированных задач равен " << protsent << endl;
	cout << "Процент простоя процессора " << prostprotsent << endl;
	cout << "Среднее время выполнения задачи " << srtime << endl;



	system("pause");
	return 0;


}
