class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        // pick one using index k:
        // use basic two pointer algorithm for a subarray except nums[0]~nums[k]
        for(int k=0;k<nums.size();){
            int i=k+1, j=nums.size()-1;

            // basic two pointer algorithm for a subarray: nums[k+1]~nums[nums.size()-1]
            while(i<j){
                // case 1: subsum is less than 0; i++ until i points a different value
                if(nums[i]+nums[j]+nums[k]<0){
                    while(true){
                        i+=1;
                        if(i>=nums.size() || nums[i-1]!=nums[i])  break;
                    }
                }
                // case 2: subsum is 0; i++ until i points a different value && push the solution to result
                else if(nums[i]+nums[j]+nums[k]==0){
                    result.push_back({nums[k], nums[i], nums[j]});
                    
                    while(true){
                        i+=1;
                        if(i>=nums.size() || nums[i-1]!=nums[i])  break;
                    }
                }
                // case 3: subsum is greater than 0; j-- until j points a different value
                else if(nums[i]+nums[j]+nums[k]>0){
                    
                    while(true){
                        j-=1;
                        if(j<0 || nums[j+1]!=nums[j])  break;
                    }
                }
            }

            // k++ until k points a different value
            while(true){
                k+=1;
                if(k>=nums.size()||nums[k-1]!=nums[k])  break;
            }
        }


        return result;
    }
};
