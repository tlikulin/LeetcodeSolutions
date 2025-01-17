#include <string>

class Solution {
public:
    int conv(char c) {
                switch(c) {
                    case 'I':
                        return 1;
                    case 'V':
                        return 5;
                    case 'X':
                        return 10;
                    case 'L':
                        return 50;
                    case 'C':
                        return 100;
                    case 'D':
                        return 500;
                    case 'M':
                        return 1000;
                    default:
                        return 0;
                }
    }
    int romanToInt(std::string s) {
        
    
        int output = 0;
        for (int i = 0; i < s.size() - 1; i++){
            if (conv(s[i]) < conv(s[i+1])) {
                output -= conv(s[i]);
            } else {
                output += conv(s[i]);
            }
        }
        output += conv(s[s.size() - 1]);
        return output;
    }
};