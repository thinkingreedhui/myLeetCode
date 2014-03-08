#include <iostream>
#include "sortList.h"
using namespace std;

void printList(ListNode *head);
int main()
{
    ListNode n1(1);
    ListNode n2(3);
    ListNode n3(2);
    ListNode n4(4);
    ListNode *head = NULL;
    ListNode *mid =NULL;
    head = &n1;
    head->next = &n2;

    mid = &n3;
    mid->next = &n4;

    Solution test;

    test.merge(head,mid);
    printList(head);
    return 0;
}

void printList(ListNode *head)
{
    ListNode *p = head;
    while(p != NULL)
    {
        cout<<p->val<<'\t';
        p = p->next;
    }
    cout<<endl;
}
