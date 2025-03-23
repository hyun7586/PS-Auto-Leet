class Solution {
public:
    vector<vector<int>> result;

    void func(int level, vector<int> nums, vector<int> &selected){
        if(level==nums.size()){
            result.push_back(selected);
            return;
        }

        selected.push_back(nums[level]);
        func(level+1, nums, selected);

        selected.pop_back();
        func(level+1, nums, selected);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        func(0, nums, temp);

        return result;
    }
};