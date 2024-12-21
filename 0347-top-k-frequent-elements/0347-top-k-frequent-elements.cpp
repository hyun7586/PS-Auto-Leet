bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second>b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> result;
        vector<pair<int, int>> temp;
       
        for(auto each : nums)   um[each]+=1;
        
        for(auto each : um) temp.push_back(make_pair(each.first, each.second));
        
        sort(temp.begin(), temp.end(), cmp);
        
        for(int i=0;i<k;i++)
            result.push_back(temp[i].first);
        
        return result;
    }
};