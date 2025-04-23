class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        // nums: sorted
        // while traversing nums if there is a disconnection between elements
        // push the range

        if(nums.size()==0)    return result;

        int start_value=nums[0];
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1 || nums[i]+1!=nums[i+1]){
                // disconnection
                if(start_value==nums[i])
                    result.push_back(to_string(start_value));
                else
                    result.push_back(to_string(start_value)+"->"+to_string(nums[i]));
                
                if(i<nums.size()-1)
                    start_value=nums[i+1];
            }
        }

        return result;
    }
};