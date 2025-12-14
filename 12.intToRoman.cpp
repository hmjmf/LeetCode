#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    std::string r = "IVXLCDM  ";

    string intToRomanPart(int num, int n) {
        if (num == 0 || n > 4) {
            return "";
        }

        int k = num % 10;
        int five_index = n * 2 + 1;
        char five = r[five_index];
        char ten = r[five_index + 1];
        char one = r[five_index - 1];

        std::string result = "";
        if (k == 9) {
            result += one;
            result += ten;
        } else if (k > 5) {
            result += five;
            for (int i = 0; i < k-5; i++) {
                result += one;
            }
        } else if (k == 5) {
            result += five;
        } else if (k == 4) {
            result += one;
            result += five;
        } else {
            for (int i = 0; i < k; i++) {
                result += one;
            }
        }
   
        // std::cout<< num << " " << k << " " << five  << ten << one  << " "  << result << std::endl;
        result = intToRomanPart(num / 10, n + 1) + result;
        return result;
    }

    
    string intToRoman(int num) {
        return intToRomanPart(num, 0);
    }
    
};


int main() {
    Solution s;
    std::cout << s.intToRoman(58) << std::endl;
}
