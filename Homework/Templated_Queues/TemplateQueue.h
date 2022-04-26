#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T> class TemplateQueue
{
public:
	//Default constructor
	TemplateQueue();
	//Parameterized Constructor
	TemplateQueue(int queueSize);
	//Copy Constructor
	TemplateQueue(const TemplateQueue& original);
	//Destructor
	~TemplateQueue();
	//Copy Assignment Operator
	TemplateQueue<T>& operator = (TemplateQueue<T>& other)
	{
		//Check we're not calling this on itself.
		if (this != &other)
		{
			//Copy the data from the original object into this one.
			this->size = other.size;
			this->count = other.count;
			delete[] this->queueType;
			this->queueType = new T[this->size];
			for (int i = 0; i < this->count; i++)
			{
				this->queueType[i] = other.queueType[i];
			}
		}
		return *this;
	}
	//Necessary methods
	void Push(T obj);
	void Pop();
	void Print();
	void IncreaseCapacity();
	int GetSize();
	bool IsEmpty();
private:
	T* queueType;
	int size;
	int count;
};

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
	size = original.size;
	count = original.count;
	queueType = new T[size];
	for (int i = 0; i < count; i++)
	{
		queueType[i] = original.queueType[i];
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
	queueType[count] = obj;
	count++;
}
/// <summary>
/// This method removes the first element in the template queue.
/// </summary>
/// <typeparam name="T">The data type of the removed element.</typeparam>
template <class T> void TemplateQueue<T>::Pop()
{
	//Move up all the elements up one.
	for (int i = 0; i < count - 1; i++)
	{
		this->queueType[i] = queueType[i + 1];
	}
	//"Delete" the last element and decrement the # of elements in the queue.
	queueType[count - 1] = -1;
	count--;
}
/// <summary>
/// This prints out all the elements in the template queue.
/// </summary>
/// <typeparam name="T">The data type shared by the elements.</typeparam>
template <class T> void TemplateQueue<T>::Print()
{
	for (int i = 0; i < GetSize(); i++)
	{
		std::cout << queueType[i] << ", ";
	}
	std::cout << "\n";
}
/// <summary>
/// This method returns the size of the template queue.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template <class T> int TemplateQueue<T>::GetSize()
{
	return count;
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
		for (int i = 0; i < count; i++)
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
	if (count == 0)
	{
		return true;
	}
	return false;
}