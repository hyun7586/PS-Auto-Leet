class Solution {
public:

    // i값에 대한 visited 여부: visited[i+100]에 저장
    bool visited[201]={false};

    int removeDuplicates(vector<int>& nums) {
        int j=0;
        
        for(int i=0;i<nums.size();i++){
            if(!visited[nums[i]+100]){
                visited[nums[i]+100]=true;
                j+=1;
                continue;
            }

            while(j<nums.size() && visited[nums[j]+100]) j+=1;

            if(j>=nums.size())  continue;

            nums[i]=nums[j];
            visited[nums[j]+100]=true;
            j+=1;
        }

        int result;
        for(result=1;result<nums.size();result++){
            if(nums[result-1]>=nums[result])
                break;
        }

        return result;
    }
};