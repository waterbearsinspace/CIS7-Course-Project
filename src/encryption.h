
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "helpers.h"

void encrypt(map<string, string> &phrases);

string getPhrase();
string getKey(int length);

#endif /* ENCRYPTION_H */
