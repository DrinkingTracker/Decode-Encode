#pragma once
#include <string>
// using namespace std; <= might be used in the future

class Decoder {
public:
    static std::string removeSpaces(const std::string& input);

    static std::string decodeBinary(const std::string& input);
    static std::string decodeHex(const std::string& input);
    static std::string decodeBase64(const std::string& input);
    static std::string decodeURL(const std::string& input);

};