class Node{
   
    Node *links[26];
    bool flag = false;
    public:
    bool containsKey(char c){
        return (links[ c- 'a'] != nullptr);
    }
    bool containsKey(int c){
        return (links[ c] != nullptr);
    }
    void createLink(char c){
        Node* node = new Node();
        links[c-'a'] = node;     
    }
    Node * getLink(char c){
        return links[c-'a'];
    }
    Node * getLink(int c){
        return links[c];
    }
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag = true;
    }
    
    
};


class WordDictionary {
    Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *temp = root;
        for(int i = 0;i<word.size();i++){
        if(!(temp->containsKey(word[i]))){
                temp->createLink(word[i]);
            }            
             temp = temp->getLink(word[i]);
        }
        temp->setEnd();
    }
    bool search(string &word, int index, Node *curNode)
    {
        if(index == word.size() && curNode->isEnd()) return true;
        if(index == word.size() && !curNode->isEnd()) return false;
        
        bool canForm = false;
        if(word[index]=='.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(curNode->containsKey(i))
                {
                    canForm  = (canForm || search(word, index + 1, curNode->getLink(i)));
                }
                if(canForm) return true;
            }
            return false;
        }                        
        else if(curNode->containsKey(word[index]))
        {
            canForm = search(word, index + 1, curNode->getLink(word[index]));
        }
                                    
                
        return canForm;
        
    }
                        
    bool search(string word) {
        return search(word,0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */