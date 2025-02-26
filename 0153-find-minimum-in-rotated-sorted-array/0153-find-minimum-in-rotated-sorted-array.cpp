class Solution {
public:
    int findMin(vector<int>& nums) {
        int target = nums[0];
        int left=0, right=nums.size()-1, mid, result=0;

        while(left<=right){
            mid=(left+right)/2;

            if(nums[mid]<target){
                result=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        return nums[result];
    }
};