// Templated_Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <vector>
#include "TemplateQueue.h"

/*Author: Elliot Gong
* Purpose: Test out the Template Queue class by creating several objects and calling their methods.
* Restrictions: Must test all the methods as well as the Rule of 3.
* Date: 4/28/2022
*/
int main()
{
    vector<float> beta(3);
    //beta.push_back(3);
    std::cin >> beta[0] >> beta[1] >> beta[2];
    for (int i = beta.size() - 1; i >= 0; i--)
    {
        std::cout << beta[i] << " ";
    }
    //Create some template queues on the stack.
    TemplateQueue<string> test = TemplateQueue<string>(8);
    //Push some strings to the queue.
    test.Push("hey");
    test.Push("nice");
    test.Push("myself");
    test.Push("jam");
    //Call the GetSize method to print out the # of objects in the Queue.
    std::cout << "First Stack Queue size: " << test.GetSize() << "\n";
    //Call the Print and Pop methods.
    test.Print();
    test.Pop();
    test.Print();
    //Call the GetSize method on the first object again.
    cout << "First Stack Queue size: " << test.GetSize() << "\n";
    //Call the copy assignment operator
    TemplateQueue<string> copy;
    copy = test;
    copy.Print();
    //Call the copy constructor
    TemplateQueue<string> other = copy;
    other.Pop();
    other.Push("hill");
    other.Push("bee");
    other.Print();
    //Call the IsEmpty method on the first object.
    cout << "First Queue empty?: " << boolalpha << test.IsEmpty() << endl;
    //Create a Template Queue on the heap using a pointer.
    TemplateQueue<int>* heapQueue = new TemplateQueue<int>(5);
    //call the IsEmpty method on the heap/pointer object.
    cout << "Heap Queue empty?: " << boolalpha << heapQueue->IsEmpty() << endl;
    //Call the Push, Pop, and Print methods on the Pointer Queue.
    heapQueue->Push(7);
    heapQueue->Push(15);
    heapQueue->Push(29);
    heapQueue->Print();
    heapQueue->Pop();
    heapQueue->Print();
    //Print out the Pointer Queue's size and pop the remaining objects.
    cout << "Heap Queue size: " << heapQueue->GetSize() << "\n";
    heapQueue->Pop();
    heapQueue->Pop();
    //Check if the Pointer Queue is empty.
    cout << "Heap Queue empty?: " << boolalpha << heapQueue->IsEmpty() << endl;
    //Call the destructor on the Pointer Queue since it's on the heap.
    heapQueue->~TemplateQueue();
    return 0;
}
