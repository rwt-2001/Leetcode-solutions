//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        int tSize = s.size();
        vector<int> tar(26);
        vector<int> cur(26);
        for(auto &ch : s){
            tar[ch-'a']++;
        }
        
        Node *start = head;
        Node *end = head;
        int curSize = 0;
        vector<Node*>ans;
        
        while(end)
        {
            cur[end->data - 'a']++;
            curSize++;
            if(curSize > tSize){
                cur[start->data-'a']--;
                curSize--;
                start = start->next;
            }
            
            if(cur == tar)
            {
               ans.push_back(start);
               start = end->next;
               end->next = NULL;
               end = start;
               cur = vector<int>(26);
               curSize = 0;
            }
            else{
                end = end->next;
            }
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends