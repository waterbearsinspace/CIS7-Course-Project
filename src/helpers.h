
#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <iterator>
#include <cctype>

using namespace std;

// Display functions
void displayTitle();                                // Display name, title, and course section
void displayPhrases(map<string, string> phrases);   // Display stored phrases, if any

// Validity checkers
bool validString(string input);             // Checks if valid input (no numbers or punctuation)
bool validLen(int phrase, int key);         // Checks if key isn't too long

// Formatting functions
string toUpper(string input);               // Capitalization
string removeSpaces(string key);            // Removes spaces
string format(string phrase);               // Uses the above two and sections into 5 character chunks
string expand(string phrase, string key);   // Repeats key until same length as phrase

#endif /* HELPERS_H */
