class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomNote_chars[256]={0};
        int magazine_chars[256]={0};

        for(auto each : ransomNote)
            ransomNote_chars[(int)each]+=1;

        for(auto each : magazine)
            magazine_chars[(int)each]+=1;

        
        for(int i=0;i<256;i++){
            if(magazine_chars[i]<ransomNote_chars[i])   return false;
        }

        return true;
    }
};