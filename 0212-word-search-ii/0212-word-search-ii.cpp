class Node{
    Node * links[26];
    bool isEnd = false;
    
    public:
    
    bool contains(char c){
        return links[c-'a'] != NULL;
    }
    
    void createLink(char c){
        links[c-'a'] = new Node();
    }
    
    Node * getLink(char c){
        return links[c-'a'];
    }
    
    bool getEnd(){
        return isEnd;
    }
    
    void setEnd(){
        isEnd = true;
    }
    
};
class Solution {
    unordered_map<string, int> mp;
    Node * root = new Node();
    vector<string> ans;
    void insert(string &word){
        Node * temp = root;
        for(auto &c : word){
            
            if(!temp->contains(c)){
                temp->createLink(c);
            }
            
            temp = temp->getLink(c);
        }
        temp->setEnd();
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, string curWord, Node *curNode){
        
        
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] =='0'||!curNode->contains(board[i][j])) return;
        
        curNode = curNode->getLink(board[i][j]);
        curWord += board[i][j];
        if(curNode->getEnd() && mp[curWord]){
            mp[curWord]--;
            ans.push_back(curWord);
        }
        board[i][j] = '0';
        
        dfs(board, i+1, j, curWord, curNode);
        dfs(board, i-1, j, curWord, curNode);
        dfs(board, i, j+1, curWord, curNode);
        dfs(board, i, j-1, curWord, curNode);
        
        board[i][j] = curWord[curWord.size() - 1];
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &word : words){
            mp[word]++;
            insert(word);
        }
        for(int i = 0;i<board.size();i++)
            for(int j = 0;j<board[0].size();j++){
                dfs(board,i,j,"",root);
                if(ans.size() == words.size()) return ans;
            }
        return ans;
    }
};