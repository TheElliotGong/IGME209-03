#pragma once
#include <iostream>

template <class T> class TemplateQueue
{
public:
	TemplateQueue();
	TemplateQueue(int queueSize);
	TemplateQueue(const TemplateQueue& original);
	~TemplateQueue();
	TemplateQueue<T>& operator = (TemplateQueue<T>& other)
	{
		//Check we're not calling this on itself.
		if (this != other)
		{
			size = other.size;
			count = other.count;
			delete[] queueType;
			this->queueType = new T[this.size];
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

