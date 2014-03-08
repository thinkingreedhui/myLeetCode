#ifndef BUYSTOCK_H_INCLUDED
#define BUYSTOCK_H_INCLUDED
#include<vector>
using namespace std;
//written by maluxing
// 2014-3-4
class Solution { //use divide-conquer algorithm
public:
    int maxNum(vector<int> &A,int i,int j){
        int max = A[i];
        for(int k = i; k <= j; k++)
            if(A[k] > max)
                max = A[k];
        return max;
    }
    int minNum(vector<int> &A,int i,int j){
        int min = A[i];
        for(int k = i; k <= j; k++)
            if(A[k] < min)
                min = A[k];
        return min;
    }
    int max(int x1,int x2,int x3){
        if(x1 >= x2 && x1 >= x3)
            return x1;
        else if( x2 >= x1 && x2 >= x3)
            return x2;
        else
            return x3;
    }
    int maxProfits(vector<int> &prices,int i,int j){
        if(i == j)
            return 0;
        else{
            int profit1 = maxNum( (i+j)/2+1, j) - minNum(i, (i+j)/2 );
            int profit2 = maxProfits( i, (i+j)/2 );
            int profit3 = maxProfits( (i+j)/2 + 1, j);
            return max(profit1,profit2,profit3);
        }
    }
    int maxProfit(vector<int> &prices) {
        int profit = 0;;
        int size = prices.size();
        if(size < 2)
            return 0;
        return maxProfits(prices,0,size-1);
    }
};

#endif // BUYSTOCK_H_INCLUDED
