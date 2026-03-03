#include <iostream>
#include <vector>

#include "../hpps/board.hpp"
#include "../hpps/save_files.hpp"

using namespace std;

int main(){

    vector<int> xs = {1, 2, 3};
    vector<int> os = {1, 2, 3};
    
    draw_board(xs, os);

    return 0;
}