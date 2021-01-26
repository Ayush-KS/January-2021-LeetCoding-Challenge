// Check If All 1's Are at Least Length K Places Away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        long long int last1 = INT_MIN;
        for(long long int i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                if((i - last1) <= k) {
                    return false;
                }
                last1 = i;
            }
        }
        return true;
    }
};