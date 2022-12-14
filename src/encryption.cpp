
#include "encryption.h"

void encrypt(map<string, string> &phrases) {
    bool done = false;
    
    while (!done) {        
        string phrase = getEncryptionPhrase();
        if (phrase == "") break;
        
        string key = getEncryptionKey(phrase.length());
        
        string encryptedPhrase = encrypt(phrase, key);
        phrases.insert(pair<string, string>(encryptedPhrase, key));
        
        cout << endl << endl;
        cout << phrase << " encrypted as " << encryptedPhrase 
                << " and saved!" << endl << endl;
    }
    
    cout << endl;
    cout << "Returning to menu..." << endl << endl;
}

string getEncryptionPhrase() {
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
        
    cout << "You've entered " << phrase;

    phrase = convert(phrase);
    
    cout << ", converted to " << phrase << endl;
    
    return phrase;
}

string getEncryptionKey(int length) {
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
        
    cout << "You've entered " << key;

    key = convert(key);
    
    cout << ", converted to " << key;
    
    return key;
}

string encrypt(string phrase, string key) {
    string encryptedPhrase = "";
    string expandedKey = expand(phrase, key);
    
    for (int i = 0; i < phrase.length(); i++) {
        if (isalpha(phrase[i]))
                encryptedPhrase += ((((phrase[i] - 65) + (expandedKey[i] - 65)) 
                        % 26) + 65);
    }
    
    encryptedPhrase = convert(encryptedPhrase);
    
    return encryptedPhrase;
}