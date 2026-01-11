#include "Encoder.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <iomanip>
using namespace std;

//ENCODERS

string Encoder::encodeBinary(const string& input) {
    stringstream res;
    for (char c : input) res << bitset<8>(c) << " ";
    string s = res.str();
    if (!s.empty()) s.pop_back(); 
    return s;
}

string Encoder::encodeHex(const string& input) {
    stringstream res;
    res << hex << uppercase << setfill('0');
    for (unsigned char c : input) res << setw(2) << (int)c << " ";
    string s = res.str();
    if (!s.empty()) s.pop_back();
    return s;
}

string Encoder::encodeBase64(const string& input) {
    static const string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string out;
    int val = 0, valb = -6;
    for (unsigned char c : input) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back(b[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) out.push_back(b[((val << 8) >> (valb + 8)) & 0x3F]);
    while (out.size() % 4) out.push_back('=');
    return out;
}

string Encoder::encodeURL(const string& input) {
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (char c : input) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
        } else {
            escaped << uppercase << '%' << setw(2) << int((unsigned char)c) << nouppercase;
        }
    }
    return escaped.str();
}