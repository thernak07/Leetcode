class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3) {
            return -1;
        }

        int maxi = nums[0];
        int mini = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != mini && nums[i] != maxi) {
                return nums[i];
            }
        }

        return -1;
    }
};