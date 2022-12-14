
#ifndef VIGENERE_H
#define VIGENERE_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <iterator>
#include <cctype>

using namespace std;

void vigenere();
void displayPhrases();
void menu();
void encrypt();
void decrypt();
bool validString(string input);
string toUpper(string input);

#endif /* VIGENERE_H */
