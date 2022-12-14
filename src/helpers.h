
#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <iterator>
#include <cctype>

using namespace std;

void displayPhrases(map<string, string> phrases);
bool validString(string input);
string toUpper(string input);

bool validLen(int phrase, int key);



#endif /* HELPERS_H */
