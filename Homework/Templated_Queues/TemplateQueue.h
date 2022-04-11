#pragma once
#include <iostream>

template <class T> class TemplateQueue
{
public:
	TemplateQueue();
	TemplateQueue(int queueSize);
	~TemplateQueue();
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

