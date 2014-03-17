#ifndef ROMANTOINTEGER_H_INCLUDED
#define ROMANTOINTEGER_H_INCLUDED
#include<string>
#include<unordered_map>
using namespace std;
/*** written by maluxing , 2014-3-16 ***/
/*** this is an inefficient method ***/
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map <char,int> mapToNum1;
        mapToNum1.insert(make_pair('I', 1));
        mapToNum1.insert(make_pair('V', 5));
        mapToNum1.insert(make_pair('X', 10));
        mapToNum1.insert(make_pair('L', 50));
        mapToNum1.insert(make_pair('C', 100));
        mapToNum1.insert(make_pair('D', 500));
        mapToNum1.insert(make_pair('M', 1000));
        unordered_map<char,int> mapToNum2;
        mapToNum2.insert(make_pair('I',-1));
        mapToNum2.insert(make_pair('X',-10));
        mapToNum2.insert(make_pair('C',-100));
        int len = s.size();
        bool flag = false;
        for(int i = len-1; i >= 0; --i){
            flag = (s[i] == 'I' && result >= 5) || (s[i] == 'X' && result >= 50)
                    || (s[i] == 'C' && result >= 500);
            if(flag)
                result += mapToNum2[s[i]];
            else
                result += mapToNum1[s[i]];
        }

        return result;
    }
};

#endif // ROMANTOINTEGER_H_INCLUDED
