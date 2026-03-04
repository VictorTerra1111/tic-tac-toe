#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include "../hpps/menu.hpp"

using namespace std;

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

int menu_f()
{
    int open_save = 0;
    cout << "+===================+" << endl;
    cout << "|    TIC TAC TOE    |" << endl;
    cout << "|    -----------    |" << endl;
    cout << "| by J. Victor T. P.|" << endl;
    cout << "|    -----------    |" << endl;
    cout << "|  Press any button |" << endl;
    cout << "+===================+" << endl;

    getch();
    open_save = load_options();
    return open_save;
}

int load_options()
{
    int mode = 1;
    char input;

    while (true)
    {
        // cout << "\033[2J\033[1;1H";

        cout << "+===================+\n";

        if (mode == 1)
        {
            cout << "|    > New Game     |\n";
            cout << "|    - Load Save    |\n";
        }
        else
        {
            cout << "|    - New Game     |\n";
            cout << "|    > Load Save    |\n";
        }

        cout << "+===================+\n";

        input = getch();

        if (input == 's' && mode == 1)
            mode = 2;
        else if (input == 'w' && mode == 2)
            mode = 1;
        else if (input == '\n' || input == '\r')
            break;
    }

    return mode;
}

int save_menu()
{
    int mode = 1;
    char input;

    cout << "+===================+\n";
    cout << "| > SLOT 1          |\n";
    cout << "| > SLOT 2          |\n";
    cout << "+===================+\n";

    while (true)
    {
        // cout << "\033[2J\033[1;1H";

        cout << "+===================+\n";

        if (mode == 1)
        {
            cout << "| > SLOT 1          |\n";
            cout << "| - SLOT 2          |\n";
        }
        else
        {
            cout << "| - SLOT 1          |\n";
            cout << "| > SLOT 2          |\n";
        }

        cout << "+===================+\n";

        input = getch();

        if (input == 's' && mode == 1)
            mode = 2;
        else if (input == 'w' && mode == 2)
            mode = 1;
        else if (input == '\n' || input == '\r')
            break;
    }

    return mode;
}