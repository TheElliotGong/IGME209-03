#include "TemplateQueue.h"

//Base constructor
template <class T> TemplateQueue<T>::TemplateQueue()
{
	this->queueType = new T[10];
	this.size = 10;
	this.count = 0;
}
template <class T> TemplateQueue<T>::TemplateQueue(int queueSize)
{
	this->queueType = new T[queueSize];
	this.size = queueSize; 
	this.count = 0;
	
}

template <class T> void TemplateQueue<T>::Push(T obj)
{
	IncreaseCapacity();
	this.count++;
}
template <class T> void TemplateQueue<T>::Pop()
{
	this.count--;
}

template <class T> void TemplateQueue<T>::Print()
{
	for (int i = 0; i < GetSize(); i++)
	{
		std::cout << queueType[i] << std::endl;
	}
}

template <class T> int TemplateQueue<T>::GetSize()
{
	return sizeof(this->queueType) / sizeof(this->queueType[0]);
}

template <class T> void TemplateQueue<T>::IncreaseCapacity()
{
	if (count == size)
	{
		//Create a new, larger queue that can hold more elements.
		T* largerQueue = new T[size + 10];
		//Copy elements of original 'queue' to the larger one.
		for (int i = 0; i < size; i++)
		{
			largerQueue[i] = queueType[i];
		}
		size *= 2;
		delete[] queueType;
		queueType = largerQueue;


	}
}
template <class T> bool TemplateQueue<T>::IsEmpty()
{
	if (this.size <= 0)
	{
		return true;
	}
	return false;
}