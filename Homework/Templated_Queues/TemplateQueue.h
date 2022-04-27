#pragma once
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

/*Author: Elliot Gong
* Purpose: Create a Template Queue class.
* Restrictions: Must have the defined methods and the Rule of 3.
* Date: 4/26/2022
*/

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
	//Private field variables.
	T* queueType;
	int size;
	int count;
};
/// <summary>
/// This is the default Template Queue Constructor
/// </summary>
/// <typeparam name="T">The data type that will be used for this class.</typeparam>
template <class T> TemplateQueue<T>::TemplateQueue()
{
	queueType = new T[10];
	size = 10;
	count = 0;
}
/// <summary>
/// This is the parameterized Template Queue Constructor
/// </summary>
/// <typeparam name="T">The data type that will be used for this class.</typeparam>
/// <param name="queueSize">The initial size of the queue.</param>
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
	//Copy over the original object's data and queue.
	size = original.size;
	count = original.count;
	queueType = new T[size];
	for (int i = 0; i < count; i++)
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
	//Deallocate the memory used to store the objects in the queue.
	delete[] queueType;
}
/// <summary>
/// This method adds an object of type T to the end of the Queue.
/// </summary>
/// <typeparam name="T">The datatype used by the Queue and the object parameter.</typeparam>
/// <param name="obj">The object to be added to the Queue.</param>
template <class T> void TemplateQueue<T>::Push(T obj)
{
	//Call the increase capacity method, and add the new object to the next index
	//and increment the count variable.
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
	//Only pop if there are objects in the queue.
	if (count > 0)
	{
		//Shift the objects down by one index.
		for (int i = 0; i < count - 1; i++)
		{
			this->queueType[i] = queueType[i + 1];
		}
		//"Delete" the last element and decrement the count variable.
		queueType[count - 1] = -1;
		count--;
	}
}
/// <summary>
/// This prints out all the elements in the template queue.
/// </summary>
/// <typeparam name="T">The data type shared by the elements.</typeparam>
template <class T> void TemplateQueue<T>::Print()
{
	//Print out the elements in the Queue.
	if (count > 0)
	{
		
			for (int i = 0; i < GetSize(); i++)
			{
				if (i == count - 1)
				{
					cout << queueType[i] << endl;
				}
				else
				{
					cout << queueType[i] << ", ";
				}
			}

		
	}
	
}
/// <summary>
/// This method returns the size of the Queue.
/// </summary>
/// <typeparam name="T">The datatype used by the Queue.</typeparam>
/// <returns>Returns the # of objects in the Queue.</returns>
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
	//Checks if the Queue has run out of space.
	if (count == size)
	{
		//Create a new, larger queue that can hold more elements.
		T* largerQueue = new T[size + 10];
		//Copy elements of original 'queue' to the larger one.
		for (int i = 0; i < count; i++)
		{
			largerQueue[i] = this->queueType[i];
		}
		//Increment the size by 10, delete the old queue, and set it to the new one.
		size += 10;
		delete[] queueType;
		queueType = largerQueue;
	}
}
/// <summary>
/// This method checks if the Queue is empty.
/// </summary>
/// <typeparam name="T">The datatype used by the Queue.</typeparam>
/// <returns>Returns a bool value checking if the Queue is empty.</returns>
template <class T> bool TemplateQueue<T>::IsEmpty()
{
	//If there's nothing in the Queue, return true.
	if (count == 0)
	{
		return true;
	}
	//Otherwise, return false.
	else
	{
		return false;
	}
}