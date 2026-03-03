#include <iostream>
#include <string>
#include <fstream>

#include "../hpps/save_files.hpp"

using namespace std;

void file_save(const string name1, const string name2, const int wins1, const int wins2, const int draws){
    ofstream file("save_file.txt");
    
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
