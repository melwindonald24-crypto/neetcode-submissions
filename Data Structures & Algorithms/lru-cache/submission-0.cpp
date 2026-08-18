
class Node{

  public:  
    pair<int,int> val;
    Node*prev;
    Node*next;
    Node(pair<int,int> val)
    {
        this->val=val;
        prev=next=NULL;
    }
};

class LRUCache {
public:

    int ocupied;
    int capacity;
    unordered_map<int,Node*>mpp;
    Node*head;

    LRUCache(int capacity) {
        this->capacity=capacity;
        ocupied=0;  
        head=NULL;
    }
    void deleteNode(Node*node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insertNode(Node*node)
    {
        node->next=head;
        node->prev=head->prev;
        head->prev->next=node;
        head->prev=node;
        head=node;
    }
    
    int get(int key) {

        if(mpp.find(key)!=mpp.end())
        {
            Node*recent=mpp[key];
            if(recent!=head)
            {
                deleteNode(recent);
                insertNode(recent);
            }
            return head->val.second;

        }
        else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {

        if(mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];

            node->val.second = value;

            if(node != head)
            {
                deleteNode(node);
                insertNode(node);
            }

            return;
        }

        if(head!=NULL)
        {
            if(ocupied==capacity)
            {
                ocupied--;
                mpp.erase(head->prev->val.first);
                deleteNode(head->prev);   
            }
            insertNode(new Node({key,value})); 
            
        }
        else{
            head=new Node({key,value});
            head->next=head->prev=head;
        }
        mpp[key]=head;
        ocupied++;
        
    }
};
