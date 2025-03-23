class Solution {
public:
    bool visited[6]={false};
    vector<vector<int>> result;

    void func(int level, vector<int> nums, vector<int>& selected){
        if(level==nums.size()){
            vector<int> temp;

            for(auto each : selected)
                temp.push_back(nums[each]);

            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                selected.push_back(i);
                visited[i]=true;

                func(level+1, nums, selected);

                visited[selected.back()]=false;
                selected.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> selected;
        func(0, nums, selected);

        return result;
    }
};