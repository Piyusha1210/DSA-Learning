#include <bits/stdc++.h>
using namespace std;

// #define queSolved 2

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/ 
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL, *temp = NULL;
        int s, f = 0;

        while (l1 || l2 || f == 1)
        {
            s = 0;
            if (l1)
            {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                s += l2->val;
                l2 = l2->next;
            }
            if (f == 1)
            {
                s += 1;
            }
            f = s / 10;

            ListNode *n = new ListNode(s % 10);
            if (head == NULL)
            {
                head = n;
                temp = n;
            }
            else
            {
                temp->next = n;
                temp = temp->next;
            }
        }
        return head;
    }
};

// 2 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL, *temp = NULL, *n;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                n = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                n = new ListNode(list2->val);
                list2 = list2->next;
            }
            if (head == NULL)
            {
                temp = n;
                head = temp;
            }
            else
            {
                temp->next = n;
                temp = temp->next;
            }
        }
        if (list1)
        {
            if (head == NULL)
                head = list1;
            else
                temp->next = list1;
        }
        if (list2)
        {
            if (head == NULL)
                head = list2;
            else
                temp->next = list2;
        }
        return head;
    }
};

// 3 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* temp=head;
        ListNode* newhead=NULL,*back=NULL;
        while(temp != NULL)
        {
            if(temp->val == val)
            {
                temp = temp->next;
                continue;
            }
            else
            {                
                if(newhead == NULL)
                {
                    newhead = temp;
                    back = temp;
                    
                }
                else
                {
                    back->next = temp;
                    back = back->next;
                }
                temp = temp->next;
            }
        }
        if(back)
        {
            back->next = NULL;
        }
        return newhead;
        
    }
};

// 4 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead=NULL,*temp=head;
        ListNode* t;
        
        while(head)
        {
            t = head;
            head = head->next;
            t->next = newhead;
            newhead = t;
        }
        return newhead;
    }
};