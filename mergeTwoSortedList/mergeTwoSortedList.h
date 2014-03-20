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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode dump(0);
        ListNode *result = &dump;
        ListNode *temp = result;
        while(l1 != NULL && l2 != NULL)
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }

        if(l1 != NULL){
            temp->next = l1;
            return result->next;
        }
        else{
            temp->next = l2;
            return result->next;
        }


    }
};
#endif // MERGETWOSORTEDLIST_H_INCLUDED
