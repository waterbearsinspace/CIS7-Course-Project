
#include "vigenere.h"

using namespace std;

bool finished = false;

map<string, string> phrases;

// Contains the program loop
void vigenere() {
    // Recall the menu until the user is finished
    while (!finished) {
        menu();
    }
}

// Handles menu and calling other sections
void menu() {
    // Show the title
    displayTitle();
    
    // Display the saved phrases and keys if any
    displayPhrases(phrases);
    
    // Display choices and ask for user's
    cout << "[#1] Encrypt " << endl;
    cout << "[#2] Decrypt " << endl;
    cout << "[#3] Exit " << endl << endl;
    cout << "Please enter a [#] to select an option: ";
    string input = getSelection();
    
    cout << endl;
    
    // Redirect to corresponding choice
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

// Process user selection, making sure to receive valid
string getSelection() {
    string input = "";
    bool valid = false;
    
    getline(cin, input);
    
    while (!valid) {
        if ((input != "1") && (input != "2") && (input != "3")) {
            cout << "Invalid input, please try again: ";
            getline(cin, input);
        }
        else {
            valid = true;
        }
    }
    
    return input;
}