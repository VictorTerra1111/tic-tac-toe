#include <iostream>
#include <string>
#include <vector>
#include "../hpps/win_logic.hpp"

using namespace std;

bool win_condition(const vector<int> &pos)
{
    vector<vector<int>> pos_wins{
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 5, 9}, {3, 5, 7}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}
    };

    for (long unsigned int j = 0; j < pos_wins.size(); j++)
    {
        int var_test = 0;
        for (int k = 0; k < 3; k++)
        {
            for (long unsigned int i = 0; i < pos.size(); i++)
            {
                if (pos[i] == pos_wins[j][k])
                {
                    var_test++;
                    break;
                }
            }
        }
        if (var_test == 3)
        {
            return true;
        }
    }
    return false;
}

int win_f(const vector<int> &x_pos, const vector<int> &o_pos)
{
    if (win_condition(x_pos) && !win_condition(o_pos))
        return 1;
    else if (win_condition(o_pos) && !win_condition(x_pos))
        return 2;
    else if (win_condition(x_pos) && win_condition(o_pos))
        return -1;
    else
        return 0;
}