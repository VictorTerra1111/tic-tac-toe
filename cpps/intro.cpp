#include <iostream>
#include <vector>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <cstdio>

#include "../hpps/intro.hpp"
#include "../hpps/menu.hpp"


char getch()
{
    termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
using namespace std;

vector<string> introduction_f()
{
    string name1, name2;
    vector<string> vec;

    int mode = 1;
    char input;

    // Mode selection screen
    while (true)
    {
        cout << "\033[2J\033[H" << flush;

        cout << "+=======================+\n";
        cout << "|     GAME MODE         |\n";
        cout << "+=======================+\n";

        if (mode == 1)
        {
            cout << "|    > Solo             |\n";
            cout << "|    - Multiplayer      |\n";
        }
        else
        {
            cout << "|    - Solo             |\n";
            cout << "|    > Multiplayer      |\n";
        }

        cout << "+=======================+\n";

        input = getch();

        if (input == 's' && mode == 1)
            mode = 2;
        else if (input == 'w' && mode == 2)
            mode = 1;
        else if (input == '\n' || input == '\r')
            break;
    }

    cout << "\033[2J\033[H" << flush;

    cout << "        HELLO!        " << endl;
    cout << "Let's play TIC TAC TOE\n" << endl;

    if (mode == 1) // Solo
    {
        cout << "Enter your name (You play as X): ";
        cin >> name1;
        name2 = "Computer";
    }
    else // Multiplayer
    {
        cout << "Player 1 name (X): ";
        cin >> name1;

        cout << "Player 2 name (O): ";
        cin >> name2;
    }

    cout << "\nLet's start!" << endl;

    vec.push_back(name1);
    vec.push_back(name2);

    return vec;
}