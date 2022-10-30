class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        
        queue<pair<pair<int,int>, int>> q;
        int rowShift[] = {-1, 1, 0, 0};
        int colShift[] = {0, 0, 1, -1};
        
        vector<vector<int>> visited (grid.size(), vector<int> (grid[0].size(), -1));
        
        q.push({{0,0}, k});
        visited[0][0] = k;
        int steps = 0;
        while(!q.empty())
        {
            int n = q.size();
            
            while(n--){
                auto curVal = q.front();
                q.pop();

                int curi = curVal.first.first;
                int curj = curVal.first.second;
                int curObs = curVal.second;
                if(curi == grid.size() -1 &&  curj == grid[0].size()-1) return steps;

                for(int i = 0;i<4;i++){

                    if(curi + rowShift[i] <  0 || curj + colShift[i] <  0 || curi + rowShift[i] >= grid.size() || curj + colShift[i] >=  grid[0].size() ) continue;

                    int row = curi + rowShift[i];
                    int col = curj + colShift[i];

                    if(visited[row][col] != -1 && visited[row][col] >= curObs) continue;

                    if(grid[row][col] && curObs <= 0) continue;
                     

                    if(grid[row][col] == 1){
                        q.push({{row,col}, curObs-1});
                        visited[row][col] = curObs-1;
                    }else{
                        q.push({{row,col}, curObs});
                        visited[row][col] = curObs;
                    }

                }       
            }

            steps++;
            
        }
        
        return -1;
    }
};