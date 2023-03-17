class Node{
   
    Node *links[26];
    bool flag = false;
    public:
    bool containsKey(char c){
        return (links[ c- 'a'] != nullptr);
    }
    void createLink(char c){
        Node* node = new Node();
        links[c-'a'] = node;     
    }
    Node * getLink(char c){
        return links[c-'a'];
    }
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag = true;
    }
    
    
};
class Trie {
   
    Node *root= new Node();;
public:

    /** Initialize your data structure here. */


    void insert(string word) {
        Node *temp = root;
        for(int i = 0;i<word.size();i++){
            if(!(temp->containsKey(word[i]))){
                temp->createLink(word[i]);
            }            
             temp = temp->getLink(word[i]);
        }
               temp->setEnd();
    }

    bool search(string word) {
        Node *temp = root;
        for(int i = 0;i< word.size();i++){
            if(!temp->containsKey(word[i])) return false;
            temp = temp->getLink(word[i]);
        }
        return temp->isEnd();
    }

    bool startsWith(string word) {
        Node *temp = root;
        for(int i = 0;i< word.size();i++){
            if(!temp->containsKey(word[i])) return false;
            temp = temp->getLink(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */