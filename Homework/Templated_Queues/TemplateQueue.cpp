#include "TemplateQueue.h"

//Base constructor
template <class T> TemplateQueue<T>::TemplateQueue()
{
	queueType = new T[10];
	size = 10;
	count = 0;
}
template <class T> TemplateQueue<T>::TemplateQueue(int queueSize)
{
	queueType = new T[queueSize];
	size = queueSize; 
	count = 0;
	
}
/// <summary>
/// This is the copy constructor for the custom Template Queue class.
/// </summary>
/// <typeparam name="T">The data type that will be used for this class.</typeparam>
/// <param name="original">The original object that will be copied.</param>
template <class T> TemplateQueue<T>::TemplateQueue(const TemplateQueue& original)
{

	this->size = original.size;
	this->count = original.count;
	this.queueType = new T[this.size];
	for (int i = 0; i < this.count; i++)
	{
		this->queueType[i] = original.queueType[i];
	}
}



/// <summary>
/// This is the Template Queue destructor.
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T> TemplateQueue<T>::~TemplateQueue()
{
	delete[] queueType;
}

template <class T> void TemplateQueue<T>::Push(T obj)
{
	IncreaseCapacity();
	this->queueType[count] = obj;
	this.count++;
}
/// <summary>
/// This method removes the first element in the template queue.
/// </summary>
/// <typeparam name="T">The data type of the removed element.</typeparam>
template <class T> void TemplateQueue<T>::Pop()
{
	delete this->queueType[0];
	for (int i = 0; i < count - 1; i++)
	{
		this->queueType[i] = this->queueType[i + 1];
	}
	delete this->queueType[count];
	this->queueType[count] = nullptr;
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
	return this->count;
}
/// <summary>
/// This method enlarges the array used to store the template objects.
/// </summary>
/// <typeparam name="T">The template object type that array will store.</typeparam>
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
	if (this.count <= 0)
	{
		return true;
	}
	return false;
}