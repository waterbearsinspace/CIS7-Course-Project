
#include "helpers.h"

void displayPhrases(map<string, string> phrases) {
    cout << "Encrypted Phrases & Keys ----------" << endl;
    
    if (phrases.empty()) cout << "None... for now." << endl;
    
    else {
        map<string, string>::iterator i;
        
        for (i = phrases.begin(); i != phrases.end(); i++) {
            cout << "- P " << ": " << i->first << endl;
            cout << "  K " << ": " << i->second << endl;
        }
    }
    
    cout << endl;
}

bool validString(string input) {
    bool anyInvalid = false;
    bool atLeastOne = false;
    
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) atLeastOne = true;
        if ((!isalpha(input[i])) && (input[i] != ' ')) {
            anyInvalid = true;
        }
    }
    
    return (atLeastOne && !anyInvalid);
}

bool validLen(int phrase, int key) {
    if (phrase >= key) return true;
    else return false;
}

string toUpper(string input){
    string converted = "";
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) converted+= toupper(input[i]);
        else if (input[i] == ' ') converted += ' ';
    }
    
    return converted;
}

string removeSpaces(string key) {
    string noSpaces = "";
    for (int i = 0; i < key.length(); i++) {
        if (isalpha(key[i])) noSpaces += key[i];
    }
    
    return noSpaces;
}

string convert(string phrase) {
    string oldPhrase = removeSpaces(toUpper(phrase));
    
    string converted = "";
    
    for (int i = 0; i < phrase.length(); i++) {
        if (((i != 0) && (i % 5 == 0)) && (i != phrase.length() - 1))
                converted += " ";
        converted += oldPhrase[i];
    }
    
    return converted;
}

string expand(string phrase, string key) {
    string expandedKey = "";
    int pos = 0;
    
    for (int i = 0; i < phrase.length(); i++) {        
        if (phrase[i] == ' ') expandedKey += ' ';
        else {
            expandedKey += key[pos];
            pos++;
            if (pos == key.length()) pos = 0;
        }
    }
    
    return expandedKey;
}