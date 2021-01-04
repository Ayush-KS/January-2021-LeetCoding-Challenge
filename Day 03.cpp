// Beautiful Arrangement

class Solution {
public:
    int cnt(int n, vector<bool>& arr) {
        if(n == 0)
            return 1;
        int ans = 0;
        
        for(int i = 1; i < arr.size(); i++) {
            if((i % n == 0 || n % i == 0) && !arr[i]) {
                arr[i] = 1;
                ans += cnt(n - 1, arr);
                arr[i] = 0;
            }
        }
        
        return ans;
    }
    
    int countArrangement(int n) {
        vector<bool> arr(n + 1, 0);
        return cnt(n, arr);
    }
};