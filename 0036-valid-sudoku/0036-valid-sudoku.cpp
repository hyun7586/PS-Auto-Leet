bool squareCheck(int r, int c, vector<vector<char>> bd){
    bool isPresent[10]={false};
    
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(bd[i][j]!='.'){
                if(isPresent[(int)bd[i][j]-'0']==false){
                        isPresent[(int)bd[i][j]-'0']=true;
                }
                else{
                        return false;
                }
            }
        }
    }
    
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // every row check
        for(int i=0;i<9;i++){
            bool isPresent[10]={false};
            
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(isPresent[(int)board[i][j]-'0']==false)
                        isPresent[(int)board[i][j]-'0']=true;
                    else
                        return false;
                }
            }
        }
        
        // every column check
        for(int i=0;i<9;i++){
            bool isPresent2[10]={false};
            
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(isPresent2[(int)board[j][i]-'0']==false)
                        isPresent2[(int)board[j][i]-'0']=true;
                    else
                        return false;
                }
            }
        }
        
        // every square check
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(squareCheck(3*i, 3*j, board)==false) return false;
            
        
        return true;
        
    }
};