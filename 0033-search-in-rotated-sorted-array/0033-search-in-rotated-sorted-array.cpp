class Solution {
public:
    int binary_search(vector<int> nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;

            if (target < nums[mid]) {
                right = mid - 1;
            } else if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            }
        }

        return -1;
    }

    int findMinIndex(vector<int> nums) {
        int temp = nums[0];

        int left = 0, right = nums.size() - 1, mid, result = 0;

        while (left <= right) {
            mid = (left + right) / 2;

            if (temp > nums[mid]) {
                result = mid;
                right = mid - 1;
            } else if (temp <= nums[mid]) {
                left = mid + 1;
            }
        }

        return result;
    }

    int search(vector<int>& nums, int target) {
        int specialIndex = findMinIndex(nums);

        if (specialIndex == 0)
            return binary_search(nums, 0, nums.size() - 1, target);
        else {
            if (target >= nums[0]) {
                return binary_search(nums, 0, specialIndex - 1, target);
            } else {
                return binary_search(nums, specialIndex, nums.size() - 1, target);
            }
        }
    }
};