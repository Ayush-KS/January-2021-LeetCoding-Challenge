// Count Sorted Vowel Strings

class Solution {
public:
    int memo(vector<vector<int>>& dp, int n, int i) {
        if(n == 0)
            return 1;
        if(dp[n][i] != -1)
            return dp[n][i];
        int ans = 0;
        for(int j = i; j < 5; j++) {
            ans += memo(dp, n - 1, j);
        }
        dp[n][i] = ans;
        return ans;
    }
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        
        int ans = 0;
        for(int i = 0; i < 5; i++) {
            ans += memo(dp, n - 1, i);
        }
        return ans;
    }
};