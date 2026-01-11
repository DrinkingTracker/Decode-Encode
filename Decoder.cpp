#include "Decoder.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

// --- Helper ---
string Decoder::removeSpaces(const string& input) {
    string output = input;
    output.erase(remove_if(output.begin(), output.end(), ::isspace), output.end());
    return output;
}

//DECODERS

string Decoder::decodeBinary(const string& input) {
    string clean = removeSpaces(input);
    stringstream output;
    if (clean.length() % 8 != 0) return "Error: Length not multiple of 8";
    
    for (size_t i = 0; i < clean.length(); i += 8) {
        try {
            output << (char)bitset<8>(clean.substr(i, 8)).to_ulong();
        } catch (...) { return "Error: Invalid binary"; }
    }
    return output.str();
}

string Decoder::decodeHex(const string& input) {
    string clean = removeSpaces(input);
    string output;
    if (clean.length() % 2 != 0) return "Error: Length not even";
    
    for (size_t i = 0; i < clean.length(); i += 2) {
        try {
            output += (char)stoul(clean.substr(i, 2), nullptr, 16);
        } catch (...) { return "Error: Invalid hex"; }
    }
    return output;
}

string Decoder::decodeBase64(const string &in) {
    string out;
    vector<int> T(256, -1);
    static const string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    for (int i = 0; i < 64; i++) T[b[i]] = i;

    int val = 0, valb = -8;
    for (unsigned char c : in) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}

string Decoder::decodeURL(const string& str) {
    string ret;
    int ii;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != '%') {
            if (str[i] == '+') ret += ' ';
            else ret += str[i];
        } else {
            if (i + 2 < str.length() && sscanf(str.substr(i + 1, 2).c_str(), "%x", &ii)) {
                ret += (char)ii;
                i += 2;
            } else return "Error: Invalid URL";
        }
    }
    return ret;
}

