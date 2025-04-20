class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        int cnt=1;

        sort(nums.begin(), nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1])  cnt=1;
            else    cnt+=1;

            if(cnt>n)  return nums[i];
        }

        return nums[0];
    }
};