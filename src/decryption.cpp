
#include "decryption.h"

void decrypt(map<string, string> &phrases) {
    bool done = false;
    
    while (!done) {     
        displayPhrases(phrases);
        
        string phrase = getDecryptionPhrase();
        if (phrase == "") break;
        
        string key = getDecryptionKey(phrase.length());
        
        string decryptedPhrase = decrypt(phrase, key);
        
        cout << endl << endl;
        cout << phrase << " decrypted as " << decryptedPhrase 
                << endl << endl;
    }
    
    cout << endl;
    cout << "Returning to menu..." << endl << endl;
}

string getDecryptionPhrase() {
    bool valid = false;
    string phrase = "";
    
    cout << "Please enter a phrase to decrypt (letters only) or a blank line to quit: ";
    
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

string getDecryptionKey(int length) {
    bool valid = false;
    string key = "";
    
    cout << "Please enter a key: ";
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
    
    return key;
}

string decrypt(string phrase, string key) {
    string decryptedPhrase = "";
    string expandedKey = expand(phrase, key);
    
    for (int i = 0; i < phrase.length(); i++) {
        if (isalpha(phrase[i]))
                decryptedPhrase += (((((phrase[i] - 65) - (expandedKey[i] - 65)) 
                        + 26) % 26) + 65);
    }
    
    decryptedPhrase = convert(decryptedPhrase);
    
    return decryptedPhrase;
}