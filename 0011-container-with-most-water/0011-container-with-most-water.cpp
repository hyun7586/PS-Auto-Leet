class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int i=0, j=height.size()-1;
        

        while(i<j){
            result=max(result, min(height[i], height[j])*(j-i));

            // exit conditions: 
            if(i+1==j)  break;

            if(height[i]>=height[j]){
                j--;
            }else{
                i++;
            }
        }

        return result;
    }
};