
#include "encryption.h"

void encrypt(map<string, string> &phrases) {
    cin.ignore();
    bool done = false;;
    
    while (!done) {        
        string phrase = getPhrase();
        if (phrase == "") break;
        
        cout << "You've entered " << phrase << endl;
        
        string key = getKey(phrase.length());

        key = toUpper(key);
        cout << "You've entered " << key;
        
        if (key.length() < phrase.length()) {
            key = expand(phrase.length(), key);
            cout << ", expanded to " << key;
        }
        
        cout << endl << endl;

        phrases.insert(pair<string, string>(phrase, key));
        cout << "Encryption saved!" << endl << endl;
    }
    
    cout << endl;
    cout << "Returning to menu." << endl << endl;
}

string getPhrase() {
    bool valid = false;
    string phrase = "";
    
    cout << "Please enter a phrase to encrypt (letters only) or a blank line to quit: ";
    
    getline(cin, phrase);

    if (phrase.length() == 0) return "";
    
    while (!valid) {
        if (!validString(phrase)) {
            cout << "Invalid entry, please try again: ";
            phrase = "";
            getline(cin, phrase);
        }
        else valid = true;
    }

    phrase = toUpper(phrase);
    
    return phrase;
}

string getKey(int length) {
    bool valid = false;
    string key = "";
    
    cout << "Please enter a key for this phrase: ";
    getline(cin, key);


    while (!valid) {
        if (!validLen(length, key.length())) {
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
    
    return key;
}

string encrypt(string phrase, string key) {
    
    return "";
}