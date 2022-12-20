class Solution {
public:
    void dfs(vector<vector<int>> &rooms, vector<int> &visited, int n){
        if(!visited[n]){
            visited[n] = 1;
            for(auto &room : rooms[n]){
                dfs(rooms, visited, room);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        dfs(rooms, visited, 0);
        
        int sum = accumulate(visited.begin(), visited.end(), 0);
        
        return sum == n;
        
        
    }
};