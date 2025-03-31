class Solution {
public:
    bool isSubsequence(string s, string t) {
        // whether s is a subsequence of t
        int i=0, j=0;

        while(i<s.size()){   
            while(j<t.size() && s[i]!=t[j])   j+=1;

            if(j>=t.size()) break;

            if(s[i]==t[j]){
                i+=1;
                j+=1;
            }
        }
        
        if(i==s.size())
            return true;

        return false;
    }
};