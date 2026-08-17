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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp=head;
        if(head==NULL || head->next==NULL) return ;

        while(temp)
        {
            st.push(temp);
            temp=temp->next;
        }
        temp=head;
        int n=st.size();
        int i=n/2;

        while(i--)
        {
            ListNode*backNode=st.top();
            st.pop();
            backNode->next=temp->next;
            temp->next=backNode;
            temp=temp->next->next;
        }
        temp->next=NULL;

    }
};
