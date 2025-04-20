class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prevNumber = nums[0];
        int countOfPrevNumbers=1;
        int trashCount=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==prevNumber){
                if(countOfPrevNumbers>=2){
                    // replace the number to INT_MAX
                    nums[i]=INT_MAX;
                    trashCount+=1;
                }else{
                    countOfPrevNumbers+=1;
                }
            } else{
                prevNumber=nums[i];
                countOfPrevNumbers=1;
            }
        }

        sort(nums.begin(), nums.end());

        return nums.size()-trashCount;
    }
};