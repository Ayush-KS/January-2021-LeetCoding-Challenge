// Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0, right = 0;
        int ans = 0;
        
        while(right < s.size()) {
            freq[s[right]]++;
            while(freq[s[right]] > 1) {
                freq[s[left++]]--;
            }
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};