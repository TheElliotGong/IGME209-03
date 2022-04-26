// Templated_Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TemplateQueue.h"

int main()
{
    //Create some template queues on the stack.

    TemplateQueue<string> test = TemplateQueue<string>(8);
    test.Push("hey");
    test.Push("nice");
    test.Push("myself");
    test.Push("jam");
    std::cout << "Queue size: " << test.GetSize() << "\n";
    test.Print();
    test.Pop();
    test.Print();
    std::cout << "Queue size: " << test.GetSize() << "\n";

    //Call the copy assignment operator
    TemplateQueue<string> copy;
    copy = test;
    copy.Print();
    //Call the copy constructor
    TemplateQueue<string> other = copy;
    other.Push("bee");
    other.Print();
    cout << "First Queue empty?: " << boolalpha << test.IsEmpty() << endl;
    //Create a Template Queue on the heap.
    TemplateQueue<int>* heapQueue = new TemplateQueue<int>(5);
    cout << "Heap Queue empty?: " << boolalpha << heapQueue->IsEmpty() << endl;

    heapQueue->Push(7);
    heapQueue->Push(10);
    heapQueue->Push(29);
    heapQueue->Print();
    heapQueue->Pop();
    heapQueue->Print();
    
    heapQueue->~TemplateQueue();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
