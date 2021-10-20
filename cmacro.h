#include <iostream>
#include <fstream>
#include <string>
#include <map> /* map of macros */
#include <vector>
#include <algorithm>
#include <sstream>

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}


// bool isUpper(const std::string& s) {
//     return std::all_of(s.begin(), s.end(), [](unsigned char c){ return std::isupper(c); });
// }
std::vector<std::string>split(std::string str, char delim) {
    std::stringstream ss(str);
    std::string mallocr;
    std::vector<std::string>stff{};
    while (getline(ss, mallocr, delim)) {
        stff.push_back(mallocr);
    }
    return stff;
}

std::map<std::string, std::vector<std::string>>CMac_compile(const std::string& codes) {

    std::map <std::string, std::vector<std::string>> stuff{};

    std::vector<std::string>stats = split(codes, ';');
    std::string code = trim(codes);

    if (code[0] == 'd') {
        if (code[1] == 'n') {
            if (code[2] == 'l') {
                
            }
        }
    }
    else if (code[0] == '/') {
        if (code[1] == '/') {
            
        } else {
            std::cout << "Random token '/' found (random-token)" << std::endl;\
            return {{"Error", {"random-token"}}};
        }
    }

    std::string     MName;
    std::string     MData;
    std::vector<std::string>    MArgs{};
    std::stringstream       CodeStream(code);
    getline(CodeStream, MName, '(');
    MName = trim(MName);
    getline(CodeStream, MData, ')');
    MData = trim(MData);

    std::vector <std::string> data = split(MData, ',');

    for (uint i = 0 ; i < data.size() ; ++ i) {
        data[i] = trim(data[i]);
    }
    return {
        {MName, data} 
    };
}
