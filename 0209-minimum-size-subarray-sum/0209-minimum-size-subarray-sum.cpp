class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
        int j=0, s=0, result=nums.size()+1;
        for(int i=0;i<nums.size();i++){

            if(i>0) s-=nums[i-1];

            while(j<nums.size() && s<target){
                s+=nums[j];
                j+=1;
            }

            if(s>=target){
                result=min(result, j-i);
            }
        }

        if(result==nums.size()+1)   return 0;

        return result;
    }
};

//181 28 83
// 209 83
