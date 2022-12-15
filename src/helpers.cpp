
#include "helpers.h"

// Display name, title, and course section
void displayTitle() {
    // Display name
    cout << "Welcome to Nick Viste's..." << endl;
    
    // Title
    cout << "         _                                    ___ _       _               " << endl
            << "  /\\   /(_) __ _  ___ _ __   ___ _ __ ___    / __(_)_ __ | |__   ___ _ __ " << endl
            << "  \\ \\ / / |/ _` |/ _ \\ '_ \\ / _ \\ '__/ _ \\  / /  | | '_ \\| '_ \\ / _ \\ '__|" << endl
            << "   \\ V /| | (_| |  __/ | | |  __/ | |  __/ / /___| | |_) | | | |  __/ |   " << endl
            << "    \\_/ |_|\\__, |\\___|_| |_|\\___|_|  \\___| \\____/|_| .__/|_| |_|\\___|_|   " << endl
            << "           |___/                                   |_|                    " << endl
            << endl;
    
    // And course section
    cout << right << setw(75) << "from CIS-7-28606 Fall 2022" << endl << endl;
}

// Display stored phrases, if any
void displayPhrases(map<string, string> phrases) {
    // Header
    cout << "Encrypted Phrases & Keys ----------" << endl;
    
    // Indicate if empty
    if (phrases.empty()) cout << "None... for now." << endl;
    // Print every phrase and key combo
    else {
        map<string, string>::iterator i;
        
        for (i = phrases.begin(); i != phrases.end(); i++) {
            cout << "- P " << ": " << i->first << endl;
            cout << "  K " << ": " << i->second << endl;
        }
    }
    
    cout << endl;
}



// Checks if valid input (no numbers or punctuation)
bool validString(string input) {
    // Keep track of if there are any invalid chars and at least one valid char
    bool anyInvalid = false;
    bool atLeastOne = false;
    
    // Check if any invalids, then check if at least one valid
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) atLeastOne = true;
        if ((!isalpha(input[i])) && (input[i] != ' ')) {
            anyInvalid = true;
        }
    }
    
    // Return result (if at least one valid and if there were NOT any invalids)
    return (atLeastOne && !anyInvalid);
}

// Checks if key isn't too long
bool validLen(int phrase, int key) {
    if (phrase >= key) return true;
    else return false;
}



// Capitalization
string toUpper(string input){
    string converted = "";
    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) converted+= toupper(input[i]);
        else if (input[i] == ' ') converted += ' ';
    }
    
    return converted;
}

// Removes spaces
string removeSpaces(string key) {
    string noSpaces = "";
    for (int i = 0; i < key.length(); i++) {
        if (isalpha(key[i])) noSpaces += key[i];
    }
    
    return noSpaces;
}

// Uses the above two and sections into 5 character chunks
string format(string phrase) {
    string oldPhrase = removeSpaces(toUpper(phrase));
    string converted = "";
    
    // Add space every 5 characters
    for (int i = 0; i < phrase.length(); i++) {
        if (((i != 0) && (i % 5 == 0)) && (i != phrase.length() - 1))
                converted += " ";
        converted += oldPhrase[i];
    }
    
    return converted;
}

// Repeats key until same length as phrase
string expand(string phrase, string key) {
    string expandedKey = "";
    int pos = 0;
    
    // Repeat key, ignoring spaces, until correct length
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