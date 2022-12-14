
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
bool validLen(int phrase, int key);
string toUpper(string input);
string removeSpaces(string key);
string convert(string phrase);
string expand(string phrase, string key);

#endif /* HELPERS_H */
