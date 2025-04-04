class Solution {
public:
    int directions[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size()));

        int row = matrix.size(), col = matrix[0].size(), cnt=0;
        int next_row, next_col, current_row=0, current_col=0, prev_direction=0;

        while(true){
            visited[current_row][current_col]=true;
            result.push_back(matrix[current_row][current_col]);
            cnt+=1;
            
            // exit conditions
            if(cnt==row*col)    break;

            // find the direction
            for(int i=prev_direction;;i=(i+1)%4){
                next_row=current_row+directions[i][0];
                next_col=current_col+directions[i][1];

                // bound check
                if(next_row<0 || next_row>=row || next_col<0 || next_col>=col)  continue;

                // if it can move to the next row/col
                if(!visited[next_row][next_col]){
                    prev_direction=i;
                    break;
                }
            }

            current_row=next_row;
            current_col=next_col;
        }

        return result;
    }
};