
#include "encryption.h"

// Handles encryption
void encrypt(map<string, string> &phrases) {
    // Loop until user is done
    bool done = false;
    while (!done) {        
        // Get valid input, end loop if empty line
        string phrase = getEncryptionPhrase();
        if (phrase == "") break;
        
        // Get valid key
        string key = getEncryptionKey(phrase.length());
        
        // Use above two to generate encrypted key; store and echo
        string encryptedPhrase = encrypt(phrase, key);
        phrases.insert(pair<string, string>(encryptedPhrase, key));
        cout << endl << endl;
        cout << phrase << " encrypted as " << encryptedPhrase 
                << " and saved!" << endl << endl;
    }
    
    // Indicate return to menu
    cout << endl;
    cout << "Returning to menu..." << endl << endl;
}

// Gets valid encryption phrase
string getEncryptionPhrase() {
    // Request phrase to encrypt
    cout << "Please enter a phrase to encrypt (letters only) or a blank line to quit: ";
    
    // Get phrase to process
    string phrase = "";
    getline(cin, phrase);

    // Return empty string if user input nothing
    if (phrase.length() == 0) return "";
    
    // Keep asking for and getting input until valid
    bool valid = false;
    while (!valid) {
        if (!validString(phrase)) {
            cout << "Invalid entry, please try again: ";
            phrase = "";
            getline(cin, phrase);
        }
        else valid = true;
    }
        
    // Echo, uppercase, and remove spaces
    cout << "You've entered " << phrase;
    phrase = format(phrase);
    cout << ", converted to " << phrase << endl;
    
    // Return input
    return phrase;
}

// Gets valid encryption key
string getEncryptionKey(int length) {
    // Request key for encryption
    cout << "Please enter a key for this phrase: ";
    
    // Get key to process
    string key = "";
    getline(cin, key);

    // Keep asking for and getting input until valid
    bool valid = false;
    while (!valid) {
        // Invalid if too long
        if (!validLen(length, key.length())) {
            cout << "Key too long, please try again: ";
            key = "";
            getline(cin, key);
        }
        // Or if not all characters, or an empty line
        else if ((!validString(key)) || (key.length() == 0)){
            cout << "Invalid entry, please try again: ";
            key = "";
            getline(cin, key);
        }
        else valid = true;
    }
        
    // Echo, uppercase, and remove spaces
    cout << "You've entered " << key;
    key = format(key);
    cout << ", converted to " << key;
    
    // Return key
    return key;
}

// Returns encrypted phrase
string encrypt(string phrase, string key) {
    // Prepare empty string (for encrypted phrase) and key (to be same size as phrase)
    string encryptedPhrase = "";
    string expandedKey = expand(phrase, key);
    
    // Convert each letter of the phrase
    for (int i = 0; i < phrase.length(); i++) {
        if (isalpha(phrase[i]))
                encryptedPhrase += ((((phrase[i] - 65) + (expandedKey[i] - 65)) 
                        % 26) + 65);
    }
    
    // Properly format phrase
    encryptedPhrase = format(encryptedPhrase);
    
    // Return newly encrypted phrase
    return encryptedPhrase;
}