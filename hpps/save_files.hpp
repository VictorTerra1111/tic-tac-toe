#ifndef SAVE_FILES_HPP
#define SAVE_FILES_HPP

#include <string>

using namespace std;

void file_save(const int slot, const string name1, const string name2, const int wins1, const int wins2, const int draws);

vector<pair<string,int>> find_save(const int slot);

#endif
