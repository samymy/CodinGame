#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
string      getBitCode(char bit) {
    
    return bit == '1' ? "0 " : "00 ";
}

string      getCode(string str) {

    string  code;
  
    char tmp = str[0] == 1 ? 0 : 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != tmp) {
            if (i)
                code += " ";
            tmp = str[i];
            code += getBitCode(str[i]);
        }
        code += "0";
    }
    
    return code;
}

string      getCharBinary(char c) {
    
    stringstream    char_binary;
    int             bit_idx = -1;
    
    while (++bit_idx < 7)
        char_binary << ((c >> (6 - bit_idx)) & 1);
    
    return char_binary.str();
}

string      getStrBinary(string str) {

    string  str_binary;
    
    for (auto c : str)
        str_binary += getCharBinary(c);
    
    return str_binary;
}
 
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << getCode(getStrBinary(MESSAGE)) << endl;
}
