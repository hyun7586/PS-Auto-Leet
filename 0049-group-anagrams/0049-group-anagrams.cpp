class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // setting vectors
        vector<pair<string, string>> v;
        vector<vector<string>> result;
        for(auto each : strs)   v.push_back(make_pair(each, each));
        for(auto &each : v)  sort(each.second.begin(), each.second.end());

        // main logic
        while (!v.empty()) {
            vector<string> temp;

            pair<string, string> element = v[0];
            temp.push_back(element.first);

            for (int i = v.size() - 1; i > 0; i--) {
              if (element.second == v[i].second) {
                temp.push_back(v[i].first);
                v.erase(v.begin() + i);
              }
            }

            result.push_back(temp);
            v.erase(v.begin());
        }


        return result;
    }
};
