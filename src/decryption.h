
#ifndef DECRYPTION_H
#define DECRYPTION_H

#include "helpers.h"

void decrypt(map<string, string> &phrases);

string getDecryptionPhrase();
string getDecryptionKey(int length);
string decrypt(string phrase, string key);

#endif /* DECRYPTION_H */
