#pragma once
#include <iostream>
#include <type_traits>
using namespace std;

/*Author: Elliot Gong
* Purpose: Create a Template Queue class.
* Restrictions: Must have the defined methods and the Rule of 3.
* Date: 4/28/2022
*/

//Forward declared the class and the friend overload for the '<<' operator.
//template <class T> class TemplateQueue;
//template <class T> ostream& operator<<(ostream&, const TemplateQueue<T>&);


/// <summary>
/// This class will simulate a Queue that can take in a variety of data types. It will also contain many functions
/// that will help manage and manipulate the Queue entries.
/// </summary>
/// <typeparam name="T">The data type used by this Queue.</typeparam>
template <class T> class TemplateQueue
{
public:
	//Default constructor
	TemplateQueue();
	//Parameterized Constructor
	TemplateQueue(int queueSize);
	//Copy Constructor
	TemplateQueue(const TemplateQueue<T>& original);
	//Destructor
	~TemplateQueue();
	//Copy Assignment Operator
	TemplateQueue<T>& operator = (TemplateQueue<T>& other)
	{
		//Check we're not calling the copy assignment operator on itself.
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
		//Return the edited object.
		return *this;
	}
	//Necessary methods
	void Push(T obj);
	void Pop();
	void Print();
	void IncreaseCapacity();
	int GetSize();
	bool IsEmpty();
	//Friend overload of the << operator(attempted)
	//friend ostream& operator<<(ostream&, const TemplateQueue<T>&);
private:
	//Private field variables.

	//The 'Queue' that will hold the objects.
	T* queueType;
	//The current size of the Queue.
	int size;
	//How many objects are in the Queue.
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
template <class T> TemplateQueue<T>::TemplateQueue(const TemplateQueue<T>& original)
{
	//Copy over the original object's data and queue.
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
	if (!IsEmpty())
	{
		//Shift the objects down by one index.
		for (int i = 0; i < count - 1; i++)
		{
			queueType[i] = queueType[i + 1];
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
	//Print out the Queue's entries if it isn't empty.
	if (!IsEmpty())
	{
		for (int i = 0; i < GetSize(); i++)
		{
			//Once we reach the last element in the Queue, end the output line.
			if (i == count - 1)
			{
				cout << queueType[i] << endl;
			}
			//Otherwise, keep printing the Queue entries on the same line.
			else
			{
				cout << queueType[i] << ", ";
			}
		}
	}
	//Otherwise, return a simple notice.
	else
	{
		cout << "Nothing in the queue yet.";
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
			largerQueue[i] = queueType[i];
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
/*/// <summary>
/// This overrides the << operator when using our template class.
/// </summary>
/// <typeparam name="T">The data type used by this class</typeparam>
/// <param name="out">The ostream class object.</param>
/// <param name="obj">The Template Queue object.</param>
/// <returns>Returns the overloaded outstream of the Template Queue object.</returns>
template <class T> ostream& operator<<(ostream& out, const TemplateQueue<T>& obj)
{
	//Return all the Template Queue's data at once.
	for (T thing : obj.queueType)
	{
		out << thing << ", ";
	}
	out << endl;
	return out;
	//That way, if we have a Template Queue Object 'X', then 'cout << X;' will work.
}
*/
