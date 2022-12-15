
#include "decryption.h"

// Handles decryption
void decrypt(map<string, string> &phrases) {
    // Loop until user is done
    bool done = false;
    while (!done) {
        // Display the saved phrases and keys if any
        displayPhrases(phrases);
        
        // Get valid input, end loop if empty line
        string phrase = getDecryptionPhrase();
        if (phrase == "") break;
        
        // Get valid key
        string key = getDecryptionKey(phrase.length());
        
        // Use above two to generate encrypted key then echo
        string decryptedPhrase = decrypt(phrase, key);
        cout << endl << endl;
        cout << phrase << " decrypted as " << decryptedPhrase 
                << endl << endl;
    }
    
    // Indicate return to menu
    cout << endl;
    cout << "Returning to menu..." << endl << endl;
}

// Gets valid decryption phrase
string getDecryptionPhrase() {
    // Request phrase to encrypt
    cout << "Please enter a phrase to decrypt (letters only) or a blank line to quit: ";
    
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
string getDecryptionKey(int length) {
    // Request key for encryption
    cout << "Please enter a key: ";
    
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
    
    // Return key
    return key;
}

// Returns encrypted phrase
string decrypt(string phrase, string key) {
    // Prepare empty string (for encrypted phrase) and key (to be same size as phrase)
    string decryptedPhrase = "";
    string expandedKey = expand(phrase, key);
    
    // Convert each letter of the phrase
    for (int i = 0; i < phrase.length(); i++) {
        if (isalpha(phrase[i]))
                decryptedPhrase += (((((phrase[i] - 65) - (expandedKey[i] - 65)) 
                        + 26) % 26) + 65);
    }
    
    // Properly format phrase
    decryptedPhrase = format(decryptedPhrase);
    
    // Return newly encrypted phrase
    return decryptedPhrase;
}