class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int cnt = 0;

        for(int i=0;i<nums.size();i++){
            if(cnt==0)  candidate=nums[i];

            if(nums[i]==candidate)  cnt+=1;
            else    cnt-=1;
        }

        return candidate;
    }
};