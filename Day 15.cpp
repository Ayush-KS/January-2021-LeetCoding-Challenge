// Minimum Operations to Reduce X to Zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int left = 0;
        int n = nums.size();
        int right = n;
        while(left < n) {
            sum += nums[left++];
        }
        if(sum < x) {
            return -1;
        }
        int ans = n + 1;
        while(left) {
            if(sum == x) {
                ans = min(ans, left + n - right - 1); 
            }
            if(sum >= x) {
                sum -= nums[--left];
            } else  {
                sum += nums[--right];
            }
        }
        if(sum == x) {
            ans = min(ans, left + n - right - 1); 
        }
        return sum == x ? ans : -1;
    }
};