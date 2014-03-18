/*** written by maluxing, 2014-3-18, Tue ***/
/*        problem discription
    Given an integer, convert it to a roman
    numeral.   Input is guaranteed to be within
    the range from 1 to 3999.
*/
#ifndef INTEGERTOROMAN_H_INCLUDED
#define INTEGERTOROMAN_H_INCLUDED
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string s;
        if(num <= 0)
            return s;
        dealRoman(s,num);
        return s;
    }
    void dealRoman(string & s,int num){
        while(num > 0){
            if(num >= 1000){
                s.push_back('M');
                num -= 1000;
            }
            else if(num / 900 == 1){
                s.push_back('C');
                s.push_back('M');
                num -= 900;
            }
            else if(num >= 500){
                s.push_back('D');
                num -= 500;
            }
            else if(num/400 == 1){
                s.push_back('C');
                s.push_back('D');
                num -= 400;
            }
            else if(num >= 100){
                s.push_back('C');
                num -= 100;
            }
            else if(num/90 == 1)
            {
                s.push_back('X');
                s.push_back('C');
                num -= 90;
            }
            else if(num >= 50){
                s.push_back('L');
                num -= 50;
            }
            else if(num/40 == 1){
                s.push_back('X');
                s.push_back('L');
                num -= 40;
            }
            else if(num >= 10){
                s.push_back('X');
                num -= 10;
            }
            else if(num == 9){
                s.push_back('I');
                s.push_back('X');
                num -= 9;
            }
            else if(num >= 5){
                s.push_back('V');
                num -= 5;
            }
            else if(num == 4){
                s.push_back('I');
                s.push_back('V');
                num -= 4;
            }
            else{
                s.push_back('I');
                num -= 1;
            }
        }
    }
};


#endif // INTEGERTOROMAN_H_INCLUDED
