class Solution {
public:
    bool visited[256]={false};

    int lengthOfLongestSubstring(string s) {

        if(s=="")   return 0;

        int i=0, j=0, result=0;
        visited[(int)s[i]]=true;
        for(i=0;i<s.size();i++){

            if(i>0){
                visited[(int)s[i-1]]=false;
            }
            
            while(j<s.size()-1 && !visited[(int)s[j+1]]){
                j+=1;
                visited[(int)s[j]]=true;
            }

            result=max(result, j-i+1);
        }

        return result;
    }
};