
#include "helpers.h"

void displayPhrases(map<string, string> phrases) {
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

bool validLen(int phrase, int key) {
    if (phrase >= key) return true;
    else return false;
}

string expand(int length, string key) {
    string expandedKey = "";
    int pos = 0;
    
    for (int i = 0; i < length; i++) {
        expandedKey += key[pos];
        
        pos++;
        if (pos == key.length()) pos = 0;
    }
    
    return expandedKey;
}