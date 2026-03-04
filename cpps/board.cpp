#include <iostream>
#include <vector>
#include <string>
#include "../hpps/board.hpp"

using namespace std;

bool vector_find(const vector<int>& vec, int value){
    for(long unsigned int i = 0; i < vec.size(); i++){
        if(vec[i] == value){
            return true;
        }
    }

    return false;
}

bool draw_board(const vector<int>& x_pos, const vector<int>& o_pos){
    int place_count = 0;
    string what_to_show;
    
    cout << "+---+-+---+-+---+" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            place_count++;
            if(vector_find(x_pos, place_count)){
                what_to_show = "X";
            } 
            else if(vector_find(o_pos, place_count)){
                what_to_show = "O";
            } 
            else {
                what_to_show = to_string(place_count);
            }
            cout << "| " << what_to_show << " | ";
        }
        cout << endl << "+---+-+---+-+---+" << endl;

    }
    return true;
}
