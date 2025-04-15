class Solution {
public:
    bool visited[300][300]={false};
    int directions[4][2]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int number_of_islands=0;

    void bfs(vector<vector<char>> grid, int row, int col, int m, int n){
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            auto each = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int next_row = each.first+directions[i][0];
                int next_col = each.second+directions[i][1];

                if(next_row<0 || next_row >=m || next_col <0 || next_col>=n)    continue;

                if(!visited[next_row][next_col] && grid[next_row][next_col]=='1'){
                    q.push({next_row, next_col});
                    visited[next_row][next_col]=true;
                }
            }
        }

        number_of_islands+=1;
    }

    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==false && grid[i][j]=='1'){
                    bfs(grid, i, j, grid.size(), grid[0].size());
                }
            }
        }

        return number_of_islands;
    }
};