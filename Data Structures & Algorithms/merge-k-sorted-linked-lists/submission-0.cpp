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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        while(true)
        {
            ListNode*min_node=NULL;
            int min_i=-1;
            for(int i=0;i<lists.size();i++)
            {
                if(lists[i])
                {
                        if(!min_node || min_node->val>lists[i]->val)
                        {
                            min_node=lists[i];
                            min_i=i;

                        }
                    
                }

            }
            if(min_node==NULL) break;
            temp->next=min_node;
            lists[min_i]=lists[min_i]->next;
            temp=temp->next;
            
        }
        return dummy->next;
        
    }
};
