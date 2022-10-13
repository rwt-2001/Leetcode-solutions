class Node{
    Node *links[26];
    bool end = false;
    
    
    public:

    bool hasLink(int index){
        return links[index] != NULL;
    }
    
    void createLink(int index){
        links[index] = new Node();
    }
    
    Node* getLink(int index){
        return links[index];
    }
    
    void setEnd(){
        end  = true;
    }
    
    bool isEnd(){
        return end;
    }
    
};

class Solution {
    vector<string> ans;
    unordered_map<string,int> mp; 
    Node* root = new Node();
public:
    void insertWord(string &word){
        Node *temp = root;
        
        for(int i = 0;i<word.size();i++){
            int index = word[i] - 'a';
            if(!temp->hasLink(index)){
                temp->createLink(index);
            }
            temp = temp->getLink(index);
        }
        
        
        
        temp->setEnd();
    }
    
    
    void dfs(vector<vector<char>>& board, int i, int j , Node * node, string curWord){
        if(i < 0 || j < 0 || i==board.size() || j==board[0].size() || board[i][j] == '0' || !node->hasLink(board[i][j] - 'a')) return;
        curWord += board[i][j];
        // cout<<curWord<<endl;
        int index = board[i][j] - 'a';
        if(node->getLink(index)->isEnd() && !mp[curWord]) {
            mp[curWord] = 1;
            ans.push_back(curWord);
            
        }
        
        board[i][j] = '0';
        
        dfs(board, i  + 1, j, node->getLink(index), curWord);
        dfs(board, i, j+1, node->getLink(index), curWord);
        dfs(board, i-1, j, node->getLink(index), curWord);
        dfs(board, i, j-1, node->getLink(index), curWord);
        board[i][j] =curWord[curWord.size() - 1] ;
        
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        
        for(int i = 0;i<words.size();i++) insertWord(words[i]);
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                dfs(board, i,j,root,"");
                if(mp.size()==words.size()) return ans;
            }
                
        }
        return ans;
    }
};