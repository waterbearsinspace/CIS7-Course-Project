
#include <iostream>
#include <iomanip>
#include "vigenere.h"

using namespace std;

int main(int argc, char** argv) {
    
    cout << "  Welcome to Nick Viste's..." << endl;
    
    cout << "           _                                    ___ _       _               " << endl
            << "    /\\   /(_) __ _  ___ _ __   ___ _ __ ___    / __(_)_ __ | |__   ___ _ __ " << endl
            << "    \\ \\ / / |/ _` |/ _ \\ '_ \\ / _ \\ '__/ _ \\  / /  | | '_ \\| '_ \\ / _ \\ '__|" << endl
            << "     \\ V /| | (_| |  __/ | | |  __/ | |  __/ / /___| | |_) | | | |  __/ |   " << endl
            << "      \\_/ |_|\\__, |\\___|_| |_|\\___|_|  \\___| \\____/|_| .__/|_| |_|\\___|_|   " << endl
            << "             |___/                                   |_|                    " << endl
            << endl;
    
    cout << right << setw(77) << "from CIS-7-28606 Fall 2022" << endl << endl;
    
    vigenere();
    
    cout << "  Thank you for using my Vigenere Cipher. Have a nice rest of your day ☺" << endl;
    
    return 0;
}