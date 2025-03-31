class Solution {
public:
    int cnt=0;

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }

    int removeElement(vector<int>& nums, int val) {
        int i=0, j=nums.size()-1;

        while(i<j){
            while(i<nums.size() && nums[i]!=val) i+=1;
            while(j>=0 && nums[j]==val) j-=1;
            
            if(i>=j)    break;
            
            swap(nums, i, j);
        }

        for(int i=0;i<nums.size();i++)
            if(nums[i]!=val)    cnt+=1;
        

        
        return cnt;
    }
};