// Find the Most Competitive Subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(!(ans.empty()) && (ans.back() > nums[i]) && (n - i > k - ans.size()))
                ans.pop_back();
            if(ans.size() < k)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};