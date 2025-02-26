class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size(), n=matrix.size();

        // searching for row
        // last: the maximum of the numbers which are less than target
        int left = 0, right=n-1, last=0, mid;

        while(left<=right){
            mid = (left+right)/2;

            if(matrix[mid][0]<target){
                last=mid;
                left=mid+1;
            }else if(matrix[mid][0]==target){
                return true;
            } else if(matrix[mid][0]>target){
                right=mid-1;
            }
        }

        // searching for col
        // return whether target is in the col
        left=0, right=m-1;

        while(left<=right){
            mid=(left+right)/2;

            if(matrix[last][mid]<target){
                left=mid+1;
            }else if(matrix[last][mid]==target){
                return true;
            }else if(matrix[last][mid]>target){
                right=mid-1;
            }
        }

        return false;
    }
};