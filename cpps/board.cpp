#include <iostream>
#include <vector>
#include "../hpps/board.hpp"

using namespace std;

bool draw_board(const std::vector<int>& x_pos, const std::vector<int>& o_pos){
    int place_count = 0;
    string what_to_show = " ";
    
    cout << "+---+-+---+-+---+" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "| " << what_to_show << " | ";
            place_count++;
        }
        cout << endl << "+---+-+---+-+---+" << endl;

    }
    cout << place_count;
    return true;
}
