
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "helpers.h"

void encrypt(map<string, string> &phrases); // Handles encryption

string getEncryptionPhrase();               // Gets valid encryption phrase
string getEncryptionKey(int length);        // Gets valid encryption key
string encrypt(string phrase, string key);  // Returns encrypted phrase

#endif /* ENCRYPTION_H */
