#ifndef ROMANTOINTEGER_H_INCLUDED
#define ROMANTOINTEGER_H_INCLUDED
#include<string>
#include<unordered_map>
using namespace std;
/*** written by maluxing , 2014-3-16 ***/
/*** this is an inefficient method ***/
class Solution {
public:
    int selectPos(int pos1,int pos2){
        if(pos1 < 0 || pos2 < 0)
            return  max(pos1,pos2);
        else
            return min(pos1,pos2);
    }
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        unsigned int len = s.size();
        unordered_map<string, int> m;
        //string strArray[9];
        if(s[0] == 'I' || s[0] == 'V'){ //The number is one digit
            string strArray[9] = {"I","II" ,"III", "IV","V",
                "VI","VII","VIII", "IX"};
            for(int i = 0;i < 9; ++i)
                m[strArray[i]] = i;
           return m[s] + 1;
        }
        else if(s[0] == 'X' || s[0] == 'L'){ // The int is two digits
            string strArray[9] = {"X","XX" ,"XXX", "XL","L",
                "LX","LXX","LXXX", "XC"};
            int pos1 = s.find('I');
            int pos2 = s.find('V');
            if( pos1== s.npos && pos2 == s.npos){
                for(int i = 0;i < 9; ++i)
                    m[strArray[i]] = i;
                return 10*(m[s] + 1);
            }
            else {
                int pos = selectPos(pos1,pos2);
                string tens = s.substr(0,pos);
                string ones = s.substr(pos,len - pos);
                return romanToInt(tens) + romanToInt(ones);
            }

        }
        else if(s[0] == 'C' || s[0] == 'D'){
            string strArray[9] = {"C","CC" ,"CCC", "CD","D",
                "DC","DCC","DCCC", "CM"};
            int pos1 = s.find('X');
            int pos2 = s.find('L');
            int pos3 = s.find('I');
            if(pos3 != -1 && pos3 < pos1)
                pos1 = pos2 = -1;
            int pos;
            if(pos1 == -1 && pos2 == -1){ //there is no tens digit
                pos1 = s.find('I');
                pos2 = s.find('V');
                if(pos1 == -1 && pos2 == -1)
                {
                    for(int i = 0;i < 9; ++i)
                    m[strArray[i]] = i;
                    return 100*(m[s] + 1);
                }
                pos =selectPos(pos1,pos2);
                string hundreds = s.substr(0,pos);
                string tens = s.substr(pos,len - pos);
                return romanToInt(hundreds) + romanToInt(tens);
            }
            else{
                pos =selectPos(pos1,pos2);
                string hundreds = s.substr(0,pos);
                string tens = s.substr(pos,len - pos);
                return romanToInt(hundreds) + romanToInt(tens);
            }
        }
        else{
            unsigned int mCount = 0;
            for(; mCount < len; ++mCount)
                if(s[mCount] != 'M')
                    break;
            return 1000 * mCount + romanToInt(s.substr(mCount,len - mCount));

        }
    }

};

#endif // ROMANTOINTEGER_H_INCLUDED
