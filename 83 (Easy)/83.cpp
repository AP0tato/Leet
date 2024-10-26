#include <iostream>
#include "ListNode.cpp"

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *curr = head->next, *tmp = head;
        while(curr!=NULL)
        {
            if(curr->val==tmp->val) curr=curr->next;
            else 
            {
                tmp->next=curr;
                tmp=curr;
                curr=tmp->next;
            }
        }
        tmp->next=NULL;
        return head;
    }
};