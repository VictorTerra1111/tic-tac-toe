#include <iostream>
#include <vector>
#include <string>

#include "../hpps/board.hpp"
#include "../hpps/save_files.hpp"
#include "../hpps/intro.hpp"
#include "../hpps/win_logic.hpp"
#include "../hpps/menu.hpp"

using namespace std;

int main()
{
    int w1 = 0, w2 = 0, ds = 0;
    int dec1, dec2;
    // store player names returned by introduction
    vector<string> name_save = introduction_f();
    bool loop = true, p1 = true;
    vector<int> xs;
    vector<int> os;

    if (name_save.size() < 2)
    {
        cerr << "NAMING ERROR\n";
        return 1;
    }

    while (loop)
    {
        draw_board(xs, os);

        if (p1)
        {
            cout << "Choose in which position do you want to place your marker " << name_save[0] << endl;
            cin >> dec1;
            if (dec1 < 1 || dec1 > 9)
            {
                cout << "invalid, only 1 - 9 numbers are possible" << endl;
                continue;
            }
            else if (vector_find(xs, dec1) || vector_find(os, dec1))
            {
                cout << "Already used!" << endl;
                continue;
            }
            else
            {
                xs.push_back(dec1);
                draw_board(xs, os);
                p1 = false;
                // note: p1 already set to false above
            }
        }

        else
        {
            if (name_save[1] == "Computer")
          
                     {
                cout << "The computer is deciding where to play..." << endl;
                dec2 = 10;
                os.push_back(dec2);
                draw_board(xs, os);
                p1 = true;
            }
            else
            {
                cout << "Choose in which position do you want to place your marker " << name_save[1] << endl;
                cin >> dec2;
                if (dec2 < 1 || dec2 > 9)
                {
                    cout << "invalid, only 1 - 9 numbers are possible" << endl;
                    continue;
                }
                else if (vector_find(xs, dec2) || vector_find(os, dec2))
                {
                    cout << "Already used!" << endl;
                    continue;
                }
                else
                {
                    os.push_back(dec2);
                    draw_board(xs, os);
                }
                p1 = true;
            }
        }

        if (win_f(xs, os) == 1)
        {
            w1++;
            cout << "Player 1 wins!" << endl;
            break;
        }
        else if (win_f(xs, os) == 2)
        {
            w2++;
            cout << "Player 2 wins!" << endl;

            break;
        }
        else if (win_f(xs, os) == -1)
        {
            ds++;
            cout << "It\'s a draw!" << endl;

            break;
        }
    }

    file_save(1, name_save[0], name_save[1], w1, w2, ds);

    xs.clear();
    os.clear();

    return 0;
}