
#ifndef DECRYPTION_H
#define DECRYPTION_H

#include "helpers.h"

void decrypt(map<string, string> &phrases);     // Handles decryption

string getDecryptionPhrase();               // Gets valid decryption phrase
string getDecryptionKey(int length);        // Gets valid decryption key
string decrypt(string phrase, string key);  // Returns decrypted phrase

#endif /* DECRYPTION_H */
