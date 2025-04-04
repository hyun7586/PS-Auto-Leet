class Solution {
public:

    int directions[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));
        int row = matrix.size();
        int col = matrix[0].size();
        int cnt=0;

        pair<int, int> current={0, 0};
        int prev_direction=0;
        int next_row, next_col;

        while(cnt<row*col){
            visited[current.first][current.second]=true;
            result.push_back(matrix[current.first][current.second]);
            cnt+=1;

            if(cnt==row*col)    break;

            for(int i=prev_direction;;i=(i+1)%4){
                next_row=current.first+directions[i][0];
                next_col=current.second+directions[i][1];

                if(next_row<0 || next_row>=row || next_col<0 || next_col>=col)  continue;

                if(!visited[next_row][next_col]){
                    prev_direction=i;
                    break;
                }
            }

            current.first=next_row;
            current.second=next_col;
        }

        return result;
    }
};