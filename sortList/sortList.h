#ifndef SORTLIST_H_INCLUDED
#define SORTLIST_H_INCLUDED

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
    public:

    ListNode *sortList(ListNode *head)
    {
        int len = getLen(head);
        mergeSort(head,len);
        return head;
    }
    int getLen(ListNode *head)
    {
        int len = 0;
        ListNode *p = head;
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        return len;
    }
    void mergeSort(ListNode *s, int len)
    {
        if(len <= 1)
            return ;
        else
        {
            mergeSort(s,len/2);
            ListNode * mid = s;
            for(int i = 0; i < len/2; ++i)
                mid = mid->next;
            mergeSort(mid,len - len/2);
            s = merge(s,mid);
        }

    }

    ListNode * merge(ListNode * ptr1,ListNode *ptr2) //将两个递增有序的链表合并
    {

        ListNode *tempPtr1 = NULL;
        if(ptr1 != NULL && ptr2 != NULL )
        {
            if(ptr1->val < ptr2->val)
                tempPtr1 = ptr1;
            else
                tempPtr1 = ptr2;
        }
        else if(ptr1 == NULL)  //有一个链表为空的话直接返回非空的链表头
            return ptr2;
        else
            return ptr2;

        ListNode *newList = NULL;

        while(ptr1 != NULL && ptr2 != NULL)  // 此处代码可以更简练
        {

            if(ptr1->val < ptr2->val)
             {
                 if(newList == NULL)
                    newList = ptr1;
                 else
                 {
                     newList->next = ptr1;
                     newList = ptr1;
                 }
                 ptr1 = ptr1->next;
             }
             else
             {
                 if(newList == NULL)
                    newList = ptr2;
                 else
                 {
                     newList->next = ptr2;
                     newList = ptr2;
                 }
                 ptr2 = ptr2->next;
             }
        }
        if(ptr1 != NULL)
            newList->next = ptr1;
        if(ptr2 != NULL)
            newList->next = ptr2;
        return tempPtr1;
    }
};

#endif // SORTLIST_H_INCLUDED
