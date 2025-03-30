class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n);

        int i=0, j=0, k=0;

        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                temp[k]=nums1[i];
                i+=1;
                k+=1;
            }else if(nums1[i]==nums2[j]){
                temp[k]=nums1[i];
                i+=1;
                k+=1;

                temp[k]=nums2[j];
                j+=1;
                k+=1;
            }else if(nums1[i]>nums2[j]){
                temp[k]=nums2[j];
                j+=1;
                k+=1;
            }
        }

        while(i<m){
            temp[k]=nums1[i];
            i+=1;
            k+=1;
        }

        while(j<n){
            temp[k]=nums2[j];
            j+=1;
            k+=1;
        }

        for(int p=0;p<m+n;p++)  nums1[p]=temp[p];
    }
};