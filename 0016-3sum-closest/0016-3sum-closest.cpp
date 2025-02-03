class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=nums[0]+nums[1]+nums[2];

        // sort
        sort(nums.begin(), nums.end());

        // pick one element
        for(int k=0;k<nums.size();k++){
            // two pointer algorithm for array left
            int i=k+1, j=nums.size()-1;
            int s=0;

            while(i<j){
                s=nums[k]+nums[i]+nums[j];
                if(abs(target-result)>abs(target-s))    result=s;

                if(i+1==j)  break;

                if(s>target){
                    // j--
                    j-=1;
                }else if(s<target){
                    // i++
                    i+=1;
                }else if(s==target){
                    return s;
                }
            }
        }

        return result;
    }
};