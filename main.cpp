#include <iostream>
#include <string>
#include "Decoder.h"
#include "Encoder.h"

using namespace std;

void print_line() { cout << "---------------------------------------------------------------------------------------------\n"; }

int main() {
    int mode, type;
    string input_str;

    while (true) {
        cout << "\n=== Universal Tool ===\n";
        cout << "1. DECODER (Format -> Text)\n";
        cout << "2. ENCODER (Text -> Format)\n";
        cout << "3. Exit\n";
        cout << "Select Mode: ";
        
        if (!(cin >> mode)) {
            cin.clear(); cin.ignore(1000, '\n'); continue;
        }
        if (mode == 3) break;
        if (mode != 1 && mode != 2) { cout << "Invalid mode.\n"; continue; }

        cout << "\n--- Select Format ---\n";
        cout << "1. Binary   2. Hex\n";
        cout << "3. Base64   4. URL\n";
        cout << "Choice: ";
        
        if (!(cin >> type)) {
            cin.clear(); cin.ignore(1000, '\n'); continue;
        }
        cin.ignore(); // consume newline

        cout << "Enter string: ";
        getline(cin, input_str);

        print_line();
        cout << "Result: ";
        // Decode
        if (mode == 1) { 
            switch (type) {
                case 1: cout << Decoder::decodeBinary(input_str) << endl; break;
                case 2: cout << Decoder::decodeHex(input_str) << endl; break;
                case 3: cout << Decoder::decodeBase64(input_str) << endl; break;
                case 4: cout << Decoder::decodeURL(input_str) << endl; break;
                default: cout << "Invalid Type" << endl;
            }
        //Encode
        } else {
            switch (type) {
                case 1: cout << Encoder::encodeBinary(input_str) << endl; break;
                case 2: cout << Encoder::encodeHex(input_str) << endl; break;
                case 3: cout << Encoder::encodeBase64(input_str) << endl; break;
                case 4: cout << Encoder::encodeURL(input_str) << endl; break;
                default: cout << "Invalid Type" << endl;
            }
        }
        print_line();
    }
    return 0;
}