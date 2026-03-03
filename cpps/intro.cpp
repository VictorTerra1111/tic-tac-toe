#include <iostream>
#include <vector>
#include <string>

#include "../hpps/intro.hpp"

using namespace std;

vector<string> introduction_f(){
    string name1, name2;
    vector<string> vec;
    char yn;

    cout << "        HELLO!        " << endl;
    cout << "Let\'s play TIC TAC TOE" << endl << endl;
    cout << "but first... What is your name? (The first player plays as X)" << endl;
    cin >> name1;
    
    cout << "Great, now... Is there a second player? (Y/N)" << endl;
    cin >> yn;
    if(yn == 'Y'){
        cout << "Great! Tell me your name:" << endl;
        cin >> name2;
    }
    else if(yn == 'N'){
        cout << "OK! Playing against the machine then...";
        name2 = "Computer";
    }
    else{
        cout << "that\'s not a valid answer. You are playing against the computer now" << endl;
        name2 = "Computer";

    }
    cout << "Let\'s start!" << endl;

    vec.push_back(name1);
    vec.push_back(name2);

    return vec;
}
