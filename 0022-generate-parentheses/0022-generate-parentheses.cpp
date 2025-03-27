class Solution {
public:
    vector<string> result;

    void func(string& str, int n, int current_open, int total_open){
        if(str.size()==2*n){
            result.push_back(str);
            return;
        }

        if(total_open<n){
            str.push_back('(');
            func(str, n, current_open+1, total_open+1);
            str.pop_back();
        }

        if(current_open>0){
            str.push_back(')');
            func(str, n, current_open-1, total_open);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp="";
        func(temp, n, 0, 0);
        return result;
    }
};