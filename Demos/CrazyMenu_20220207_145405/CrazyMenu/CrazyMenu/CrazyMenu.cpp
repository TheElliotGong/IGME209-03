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


//Define new data types of pointers that point to void functions. One has no parameters, while the
//other takes an int param.
typedef void (*ActionPtr)();
typedef void (*ProgressPtr)(int percentage);

//Declare a void function that takes an int param.
void PrintProgress(int percent)
{
    cout << "progress is " << percent << endl;
}

//Declare a function that calls one of the custom data types.
void ShowProgress(ProgressPtr callback)
{
    for (int i = 0; i <= 100; i+=10)
    {
        //If pointer function isn't null, call it using the int parameter.
        if (callback != nullptr)
            (*callback)(i);
    }
}

int main()
{
    //Create custom char data types.
    typedef char PlayerAttribute;
    PlayerAttribute str;
    PlayerAttribute wis;
    char str2;

    char input = 0;
    do
    {
        PrintMenu();
        cin >> input;
        //Define a custom pointer type that points to a void function.
        ActionPtr currentAction = nullptr;
        //Have the pointer point to the specific function based on input.
        if (input == '1')
            currentAction = &SayHello;
        else if (input == '2')
            currentAction = &Answer;

        //Call the function via the pointer.
        if (currentAction != nullptr)
            (*currentAction)();

    } while (input != 'Q');

    //use the address of a function as a field for the custom pointer function.
    ShowProgress(&PrintProgress);

}
