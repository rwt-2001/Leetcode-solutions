class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        unordered_map<int,int> nxt;
        int i = 2;
        int row = n - 1; 
        int col = 0;
        bool lr = true;
        while(row >= 0)
        {
            if(lr)
            {
                if(board[row][col] != -1)
                    nxt[i-1] = board[row][col];
                
                // cout<<i-1<<" "<<row<<" "<<col<<endl;
                col++;
            }else{
                 if(board[row][col] != -1)
                    nxt[i-1] = board[row][col];
                // cout<<i-1<<" "<<row<<" "<<col<<endl;
                col--;
            }
            
            if((i-1) % n == 0){
                if(lr) col--;
                else col++;
                lr = !lr;
                row--;
            }
            i++;
        }
        
        int moves = 0;
        
        queue<int> q;
        vector<int> visited(n*n + 1,0);
        q.push(1);
        while(q.size())
        {
            int qn = q.size();
            for(int i = 0;i<qn;i++)
            {
                int col = q.front();
       
                if(col == n*n) return moves;
                if(visited[col] == 0)
                {
                    visited[col] = 1;
                    for(int j = 1;j+col <= n*n &&  j<=6;j++)
                    {
                        int nextVal = col + j;
                        if(nxt[nextVal])
                        {
                            nextVal = nxt[nextVal];
                        }
                        if(visited[nextVal] == 0)
                            q.push(nextVal);
                    }
                }
                
                q.pop();
            }
            
                moves++;
        }
        
        
        
        return -1;
        
        
    }
};