class Solution
{
    public:
        int nearestExit(vector<vector < char>> &maze, vector< int > &entrance)
        {
            queue<pair<int, int>> q;
            int row = maze.size() - 1;
            int col = maze[0].size() - 1;

            q.push({ entrance[0],
                entrance[1] });
            int steps = 0;
            vector<int> dir({ 0,
                1,
                0,
                -1,
                0 });
            while (!q.empty())
            {
                int n = q.size();
               	// cout<<n<<endl;
                for (int i = 0; i < n; i++)
                {

                    auto[curRow, curCol] = q.front();
                    q.pop();
                    if (curRow == row || curRow == 0 || curCol == col || curCol == 0)
                    {
                        if (!(curRow == entrance[0] && curCol == entrance[1])) return steps;
                    }

                    for (int j = 0; j < 4; j++)
                    {
                        int newRow = dir[j] + curRow;
                        int newCol = dir[j + 1] + curCol;

                        if ((newRow >= 0 && newRow <= row) && (newCol >= 0 && newCol <= col) && maze[newRow][newCol] != '+')
                        {
                            maze[newRow][newCol] = '+';
                            q.push({ newRow,
                                newCol });
                        }
                    }
                }
                steps++;
            }

            return -1;
        }
};