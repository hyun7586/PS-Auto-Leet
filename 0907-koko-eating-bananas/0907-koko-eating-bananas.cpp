class Solution {
public:
    bool isPossible(vector<int> piles, int k, int h){
        int cnt=0;

        for(auto each: piles){
            if(each%k!=0)   cnt+=each/k+1;
            else    cnt+=each/k;

            // prevent cnt overflow
            if(cnt>h)   return false;
        }

        return cnt<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=*max_element(piles.begin(), piles.end()), mid, result;

        while(left<=right){
            mid=(left+right)/2;

            if(isPossible(piles, mid, h)){
                right=mid-1;
                result=mid;
            }else{
                left=mid+1;
            }
        }
        return result;
    }
};