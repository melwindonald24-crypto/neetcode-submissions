/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode*temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int delPos=len-n-1;
        if(delPos==0) return head->next;
        if(delPos<0) return NULL;
        temp=head;
        do{  
            temp=temp->next;
        }while(--delPos);

        ListNode*del=temp->next;
        temp->next=temp->next->next;
        del->next=NULL;
        return head;
;
    }
};
