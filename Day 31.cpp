// Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0) {
            if(nums[i] < nums[i + 1])
                break;
            i--;
        }
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int in = i + 1;
        for(int j = i + 2; j < n; j++) {
            if(nums[j] > nums[i] && nums[j] <= nums[in]) {
                in = j;
            }
        }
        swap(nums[i], nums[in]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};