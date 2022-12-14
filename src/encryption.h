
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "helpers.h"

void encrypt(map<string, string> &phrases);

string getEncryptionPhrase();
string getEncryptionKey(int length);
string encrypt(string phrase, string key);

#endif /* ENCRYPTION_H */
