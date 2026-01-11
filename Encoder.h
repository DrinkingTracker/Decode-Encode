#pragma once 
#include <string>
// using namespace std; <= might be used in the future

class Encoder {
public:
    
    static std::string encodeBinary(const std::string& input);
    static std::string encodeHex(const std::string& input);
    static std::string encodeBase64(const std::string& input);
    static std::string encodeURL(const std::string& input);

};