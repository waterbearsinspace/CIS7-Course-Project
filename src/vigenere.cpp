
#include "vigenere.h"

using namespace std;

bool finished = false;

map<string, string> phrases;

void vigenere() {
    while (!finished) {
        menu();
    }
}

void displayPhrases() {
    cout << "Encrypted Phrases & Keys ----------" << endl;
    
    if (phrases.empty()) cout << "None... for now." << endl;
    
    else {
        map<string, string>::iterator i;
        
        int j = 1;
        
        for (i = phrases.begin(); i != phrases.end(); i++) {
            cout << "- P " << ((j > 9) ? " " : "") << j << ": " << i->first << endl;
            cout << "  K " << ((j > 9) ? " " : "") << j << ": " << i->second << endl;
            j++;
        }
    }
    
    cout << endl;
}

void menu() {
    displayPhrases();
    cout << "[#1] Encrypt " << endl;
    cout << "[#2] Decrypt " << endl;
    cout << "[#3] Exit " << endl << endl;
    
    cout << "Please enter a [#] to select an option: ";
    
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
    
    cout << endl;
    
    if (input == "1") {
        encrypt();
    }
    
    else if (input == "2") {
        decrypt();
    }
    
    else if (input == "3") {
        finished = true;
    }
}

void encrypt() {
    cin.ignore();
    bool done = false;;
    
    while (!done) {
        bool valid = false;
        
        string phrase = "";
        string key = "";
        
        cout << "Please enter a phrase to encrypt (letters only) or a blank line to quit: ";
        getline(cin, phrase);
        
        if (phrase.length() == 0) break;
        
        while (!valid) {
            if (!validString(phrase)) {
                cout << "Invalid entry, please try again: ";
                phrase = "";
                getline(cin, phrase);
            }
            else valid = true;
        }
        
        phrase = toUpper(phrase);
        
        cout << "You've entered " << phrase << endl;
        
        cout << "Please enter a key for this phrase: ";
        getline(cin, key);
        
        valid = false;
        
        while (!valid) {
            if (key.length() > phrase.length()) {
                cout << "Key too long, please try again: ";
                key = "";
                getline(cin, key);
            }
            
            else if ((!validString(key)) || (key.length() == 0)){
                cout << "Invalid entry, please try again: ";
                key = "";
                getline(cin, key);
            }
            
            else valid = true;
        }
        
        key = toUpper(key);
        cout << "You've entered " << key << endl << endl;
        
        phrases.insert(pair<string, string>(phrase, key));
        cout << "Encryption saved!" << endl << endl;
    }
    
    cout << endl;
    cout << "Returning to menu." << endl << endl;
}

void decrypt() {
    
}

bool validString(string input) {
    bool anyInvalid = false;
    
    for (int i = 0; i < input.length(); i++) {
        if ((!isalpha(input[i])) && (input[i] != ' ')) anyInvalid = true;
    }
    
    return !anyInvalid;
}

string toUpper(string input){
    string converted = "";
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) converted+= toupper(input[i]);
    }
    
    return converted;
}