class Solution {
public:
    vector<vector<int>> result;

    void func(int level, vector<int> nums, vector<int>& selected){
        if(level==nums.size()){
            vector<int> temp;

            for(auto each : selected)
                temp.push_back(nums[each]);
            
            sort(temp.begin(), temp.end());
            
            result.push_back(temp);
            return;
        }

        selected.push_back(level);
        func(level+1, nums, selected);

        selected.pop_back();
        func(level+1, nums, selected);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> selected;
        func(0, nums, selected);
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }
};