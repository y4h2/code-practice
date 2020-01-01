/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {                
        for (int i = 0; i < int_dict.size(); i++) {
            if (int_dict[i] <= num)
                return roman_dict[i] + intToRoman(num - int_dict[i]);
        }
        return "";
    }
private:
    vector<int> int_dict {1000, 900, 500, 400, 100,
                          90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman_dict {"M", "CM", "D", "CD", 
                          "C", "XC", "L", "XL", "X", 
                          "IX", "V", "IV", "I"};
};

//线性解法
class Solution {
public:
    string intToRoman(int num) 
    { 
        string result = "";
        while(num > 0)
        {    
            for (int i = 0; i < int_dict.size(); i++) 
            {
                if (int_dict[i] <= num)
                {
                    num -= int_dict[i];
                    result += roman_dict[i];
                    break;
                }
            }
        }
        return result;
    }
private:
    vector<int> int_dict {1000, 900, 500, 400, 100,
                          90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman_dict {"M", "CM", "D", "CD", 
                          "C", "XC", "L", "XL", "X", 
                          "IX", "V", "IV", "I"};
};

//更快的解法


//map

class Solution {
public:
    string intToRoman(int num) 
    {
        map <int, char>::iterator i;
        
        
        for (i = stand.begin(); i <stand.end(); ++i)
        {
            if (num >= i->first
            {
                return i->second + intToRoman(num - i->first);
            }
        }
        
        return "";
    }
private:
    map <int, char> stand = 
        {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

};

