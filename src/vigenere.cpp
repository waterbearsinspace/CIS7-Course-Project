
#include "vigenere.h"

using namespace std;

bool finished = false;

map<string, string> phrases;

void vigenere() {
    while (!finished) {
        menu();
    }
}

void menu() {
    displayPhrases(phrases);
    cout << "[#1] Encrypt " << endl;
    cout << "[#2] Decrypt " << endl;
    cout << "[#3] Exit " << endl << endl;
    
    cout << "Please enter a [#] to select an option: ";
    
    string input = getSelection();
    
    cout << endl;
    
    if (input == "1") {
        encrypt(phrases);
    }
    
    else if (input == "2") {
        decrypt(phrases);
    }
    
    else if (input == "3") {
        finished = true;
    }
}

string getSelection() {
    string input = "";
    bool valid = false;
    
    cin >> input;
    
    while (!valid) {
        if ((input != "1") && (input != "2") && (input != "3")) {
            cout << "Invalid input, please try again: ";
            cin >> input;
        }
        else {
            valid = true;
        }
    }
    
    return input;
}