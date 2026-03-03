#include <iostream>
#include <vector>
#include <string>

#include "../hpps/board.hpp"
#include "../hpps/save_files.hpp"
#include "../hpps/intro.hpp"

using namespace std;

int main()
{
    int w1 = 0, w2 = 0, ds = 0;
    int dec1, dec2;
    vector<string> name_save;
    bool loop = true, p1 = true;
    vector<int> xs;
    vector<int> os;
    name_save = introduction_f();

    while (loop)
    {
        draw_board(xs, os);

        if (p1)
        {
            cout << "Choose in which position do you want to place your marker " << name_save[0] << endl;
            cin >> dec1;
            // validate range and availability
            if (dec1 < 1 || dec1 > 9) {
                cout << "invalid, only 1 - 9 numbers are possible" << endl;
                continue;      // re-start loop instead of exiting
            }
            if (vector_find(xs, dec1) || vector_find(os, dec1)) {
                cout << "Already used!" << endl;
                continue;
            }
            xs.push_back(dec1);
            draw_board(xs, os);
            p1 = false;
        }

        else
        {
            if (name_save[1] == "Computer")
            {
                cout << "The computer is deciding where to play..." << endl;
                dec2 = 10;
                os.push_back(dec2);
                p1 = true;
            }
            else
            {
                cout << "Choose in which position do you want to place your marker " << name_save[1] << endl;
                cin >> dec2;
                if (dec2 < 1 || dec2 > 9) {
                    cout << "invalid, only 1 - 9 numbers are possible" << endl;
                    continue;
                }
                if (vector_find(xs, dec2) || vector_find(os, dec2)) {
                    cout << "Already used!" << endl;
                    continue;
                }
                os.push_back(dec2);
                draw_board(xs, os);
                p1 = true;
            }
        }
    }

    file_save(name_save[0], name_save[1], w1, w2, ds);

    xs.clear();
    os.clear();

    return 0;
}