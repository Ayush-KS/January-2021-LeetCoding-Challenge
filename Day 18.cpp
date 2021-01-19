// Max Number of K-Sum Pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        
        for(int i : nums) {
            if(mp[k - i]) {
                ans++;
                mp[k - i]--;
            } else {
                mp[i]++;
            }
        }
        
        return ans;
    }
};