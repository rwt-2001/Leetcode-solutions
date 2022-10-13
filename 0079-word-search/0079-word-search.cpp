class Solution {
public:
    bool isAvailable(string & word, vector<vector<char>> & board, int i, int j, int index , vector<vector<int>> &isVisited){
        if(index>=word.size()) return true;
        if(i<0 || i>=board.size() || j < 0 || j>=board[0].size()|| isVisited[i][j] == 1 || board[i][j]!=word[index]) return false;
        
        isVisited[i][j] = 1;
        
        bool isWordAvailable = false;
        
        isWordAvailable = isAvailable(word, board, i-1,j,index+1, isVisited) || isAvailable(word, board, i,j-1,index+1, isVisited) || isAvailable(word, board, i,j+1,index+1, isVisited) || isAvailable(word, board, i+1,j,index+1, isVisited);
        
        isVisited[i][j] = 0;
        
        return isWordAvailable;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> isVisited(board.size(), vector<int> (board[0].size(), 0));
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                
                if(isAvailable(word, board, i,j,0, isVisited)) return 1;
                
            }
        }
        return false;
    }
};