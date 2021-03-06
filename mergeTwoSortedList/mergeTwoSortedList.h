#ifndef MERGETWOSORTEDLIST_H_INCLUDED
#define MERGETWOSORTEDLIST_H_INCLUDED
#include<iostream>
using namespace std;
/*** written by maluxing, 2014-3-19,Wed ***/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define INT_MAX 2147483647
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dump(0);

        for(ListNode *result = &dump;l1 != NULL || l2 != NULL ;result = result->next){
            int val1 = (l1 == NULL) ? INT_MAX : l1->val;
            int val2 = (l2 == NULL) ? INT_MAX : l2->val;
            if(val1 < val2){
                result->next = l1;
                l1 = l1->next;
            }
            else{
                result->next = l2;
                l2 = l2->next;
            }
        }
        return dump.next;

    }
};
#endif // MERGETWOSORTEDLIST_H_INCLUDED
