
#include "vigenere.h"

void vigenere() {
    std::map<string, string> phrases;
    
    bool finished = false;
    
    while (!finished) {
        displayPhrases(phrases);
        finished = true;
    }
    
}

void displayPhrases(std::map<string, string> phrases) {
    
    cout << "Encrypted Phrases & Keys ----------" << endl;
    
    if (phrases.empty()) cout << "None... for now." << endl;
    
    map<string, string>::iterator i;
    
    for (i = phrases.begin(); i != phrases.end(); i++) {
        cout << "Phrase:" << endl << i->first << endl;
        cout << "Key: " << i->second << endl;
    }
    
    cout << endl;
}