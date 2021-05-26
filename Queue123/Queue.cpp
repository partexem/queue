#include "Queue.h"


Queue::Queue(const int _size) : size(_size), pHead(0), pTail(0), counter(0)

{
	this->array = new int[size];//выделение памяти
}


Queue::~Queue()
{
	if (array)
	{
		delete[] array;//освобождение памяти 
	}
}


int Queue::nextIndex(int index)
{
	return (index + 1) % size;
}


void Queue::addElement(const int element)
{
	array[pTail] = element;
	pTail = nextIndex(pTail);
	counter += 1;
}


int Queue::getElement()
{
	int element = array[pHead];
	pHead = nextIndex(pHead);
	counter -= 1;
	return element;
}


bool Queue::isEmpty()
{
	return counter == 0;
}


bool Queue::isFull()
{
	return counter == size;
}
