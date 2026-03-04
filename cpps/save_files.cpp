#include <iostream>
#include <string>
#include <fstream>

#include "../hpps/save_files.hpp"

using namespace std;

void file_save(const int slot, const string name1, const string name2, const int wins1, const int wins2, const int draws){
    
    ofstream file;

    if(slot == 1){
        file.open("save_file_slot1.txt");

    }
    else{
        file.open("save_file_slot2.txt");
    }    
    if(file.is_open()){
        cout <<" saving game..." << endl;
        file << name1 << " " << wins1 << endl;
        file << name2 << " " << wins2 << endl;
        file << "Draws " << draws << endl;
        file.close();
        cout << "game has been saved" << endl;

    } else {
        cout << "Unable to save current game :(" << endl;
    }
}

void find_save(const int slot)
{
    ifstream file;

    if (slot == 1)
        file.open("save_file_slot1.txt");
    else
        file.open("save_file_slot2.txt");

    if (file.is_open())
    {
        string line;

        cout << "Loading save...\n\n";

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    else
    {
        cout << "No save file found.\n";
    }
}
