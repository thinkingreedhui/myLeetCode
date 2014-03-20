#include <iostream>
#include "mergeTwoSortedList.h"
using namespace std;

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 =NULL;
    ListNode n0(-10);
    ListNode n1(-10);
    ListNode n2(-9);
    ListNode n3(-4);
    ListNode n4(1);
    ListNode n5(6);
    ListNode n6(6);
    ListNode n7(-7);
    //ListNode n3(-4);
    l1 = &n0;
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    l2 = &n7;

    Solution s;
    ListNode *l = s.mergeTwoLists(l1,l2);
    while(l!=NULL){
        cout<<l->val<<endl;
        l = l->next;
    }
    //cout <<flush<< c<< endl;
    return 0;
}
