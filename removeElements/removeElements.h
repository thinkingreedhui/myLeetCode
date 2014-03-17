#ifndef REMOVEELEMENTS_H_INCLUDED
#define REMOVEELEMENTS_H_INCLUDED
/*** problem discription  ***/
/*
 Given an array and a value, remove all instances
 of that value in place and return the new length.
 The order of elements can be changed. It doesn't
 matter what you leave beyond the new length.
*/
/*** written by maluxing,2014-3-17,Mon ***/
/***       O(n) time, O(1) space      ***/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int left = 0;
        int right = n-1;
        int temp = 0;
        while(left <= right){
            while( A[left] != elem && left < n)
                ++left;
            while( A[right] == elem && right >= 0)
                --right;
            if(left < right){
                temp = A[left];
                A[left++] = A[right];
                A[right++] = temp;
            }
        }
        return left;
    }
};


#endif // REMOVEELEMENTS_H_INCLUDED
