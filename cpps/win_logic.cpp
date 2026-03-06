#include <iostream>
#include <string>
#include <vector>
#include "../hpps/win_logic.hpp"

using namespace std;

bool win_condition(const vector<int> &pos)
{
    vector<vector<int>> pos_wins{
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 5, 9}, {3, 5, 7}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

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

int draw_f(vector<int> vec1, vector<int> vec2)
{
    int count = 0;
    int slot_missing;
    for (long unsigned int j = 0; j < 4; j++)
    {
        count = count + vec1[j] + vec2[j];
    }
    slot_missing = 45 - count;

    vec1.push_back(slot_missing);
    vec2.push_back(slot_missing);

    if (win_condition(vec1) && !win_condition(vec2))
        return 1;
    else if (win_condition(vec2) && !win_condition(vec1))
        return 2;
    return -1;
}

int win_f(const vector<int> &x_pos, const vector<int> &o_pos)
{
    int draw_test = 0;
    if (win_condition(x_pos) && !win_condition(o_pos))
        return 1;
    else if (win_condition(o_pos) && !win_condition(x_pos))
        return 2;
    else if (x_pos.size() == 4 && o_pos.size() == 4)
    {
        draw_test = draw_f(x_pos, o_pos);
        if (draw_test == 1)
            return 1;
        if (draw_test == 2)
            return 2;
        if (draw_test == -1)
            return -1;
    }
    return 0;
}
