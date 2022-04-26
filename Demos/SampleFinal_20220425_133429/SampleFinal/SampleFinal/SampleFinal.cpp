// SampleFinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <fstream>

using namespace std;

class Player
{
private:
    string name;
    string weapon;
public:
    Player(string n, string w)
    {
        name = n;
        weapon = w;
    }
    string ToString()
    {
        string buffer = "Player " + name + " has a " + weapon;
        return buffer;
    }
};


void ReadData(string filename, vector<string>& list)
{
    ifstream file(filename);
    list.clear();
    while(!file.eof())
    { 
        string data;
        file >> data;
        list.push_back(data);
    }
}

int main()
{
    cout << "Final Exam Sample\n";

    vector<string> names;
    vector<string> weapons;
    vector<Player> players;
    ofstream output("PlayersAndWeapons.txt");

    // read the file
    // ReadData("Players.txt", names);
    // ReadData("Weapons.txt", weapons);
    thread playerThread(ReadData,"Players.txt", ref(names));
    thread weaponThread(ReadData,"Weapons.txt", ref(weapons));
    
    playerThread.join();
    weaponThread.join();

    for (size_t i = 0; i < names.size(); i++)
    {
        players.push_back(Player(names[i], weapons[i]));
    }

    // output to console and file
    for (size_t i = 0; i < players.size(); i++)
    {
        cout << players[i].ToString() << endl;
        output << players[i].ToString() << endl;
    }

    output.close();

    /*
done -	Read the files
done -	Synchronize the threads

done-	Match up the player name with their weapon
done-	Create a class called Player
done o	Player will have a string variable for name
done o	Player will have a string variable for weapon
done -	Create a Vector that will store all 10 instances of Player, one for each combination of player/ weapon
done-	Iterate through the vector (any way you like) and output the following:
done-	Output the combined name and weapon to:
done	The console
done	AND an output file called “PlayersAndWeapons.txt”
done-	The format of the output will be similar to this:
donePlayer 1 (player name) has a (weapon name)
donePlayer 2 (player name) has a (weapon name)
donePlaydoneer 3 (player name) has a (weapon name)
done…
donePlayer 10 (player name) has a (weapon name)

Make sure you properly clean up ALL resources/ variables
    */


}

