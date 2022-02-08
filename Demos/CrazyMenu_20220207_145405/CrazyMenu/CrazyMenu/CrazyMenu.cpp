// CrazyMenu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void PrintMenu()
{
    cout << "Main Menu" << endl;
    cout << "--------------" << endl;
    cout << "1. Say Hello" << endl;
    cout << "2. Answer 5+5" << endl;
    cout << "Q. Quit" << endl;
}

void SayHello()
{
    cout << "Hello remote class" << endl << endl;
}
void Answer()
{
    cout << "the answer is 10" << endl << endl;
}



typedef void (*ActionPtr)();
typedef void (*ProgressPtr)(int percentage);

void PrintProgress(int percent)
{
    cout << "progress is " << percent << endl;
}

void ShowProgress(ProgressPtr callback)
{
    for (int i = 0; i <= 100; i+=10)
    {
        if (callback != nullptr)
            (*callback)(i);
    }
}

int main()
{
    typedef char PlayerAttribute;
    PlayerAttribute str;
    PlayerAttribute wis;
    char str2;

    char input = 0;
    do
    {
        PrintMenu();
        cin >> input;
        ActionPtr currentAction = nullptr;

        if (input == '1')
            currentAction = &SayHello;
        else if (input == '2')
            currentAction = &Answer;


        if (currentAction != nullptr)
            (*currentAction)();

    } while (input != 'Q');


    ShowProgress(&PrintProgress);

}
