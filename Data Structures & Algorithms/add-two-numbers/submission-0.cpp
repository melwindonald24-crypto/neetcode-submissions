/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode*temp1=l1;
        ListNode *temp2=l2;
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*head=dummy;
        while(temp1 && temp2)
        {
            int res=temp1->val+temp2->val+carry;
            ListNode*new_ListNode=new ListNode(res%10);
            dummy->next=new_ListNode;
            dummy=dummy->next;
            carry=res/10;
            temp1=temp1->next;
            temp2=temp2->next;

        }
        while(temp1)
        {
            int res=temp1->val+carry;
            ListNode*new_ListNode=new ListNode(res%10);
            dummy->next=new_ListNode;
            dummy=dummy->next;
            carry=res/10;
            temp1=temp1->next;
        }
        while(temp2)
        {
            int res=temp2->val+carry;
            ListNode*new_ListNode=new ListNode(res%10);
            dummy->next=new_ListNode;
            dummy=dummy->next;
            carry=res/10;
            temp2=temp2->next;
        }
        if(carry==1)
        {
            ListNode* new_node=new ListNode(1);
            dummy->next=new_node;
            dummy=dummy->next;
        }
        return head->next;
         
        
    }
};
