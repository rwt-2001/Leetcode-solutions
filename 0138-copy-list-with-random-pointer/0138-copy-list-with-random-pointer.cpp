/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        
        Node *nhead = new Node(0);
        Node *temphead = nhead;
        Node*temp = head;
        while(temp!=NULL)
        {
            
            nhead->next = new Node(temp->val);
            mp[temp] = nhead->next;
            nhead = nhead->next;
            temp = temp->next;
        }
        cout<<"here";
        nhead = temphead->next;
        temp = head;
        while(nhead && temp)
        {
            if(mp[temp->random])
            {
                nhead->random = mp[temp->random];
            }
            nhead = nhead->next;
            temp = temp->next;
        }
        return temphead->next;
    }
};