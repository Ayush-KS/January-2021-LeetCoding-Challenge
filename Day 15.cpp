// Get Maximum in Generated Array

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) {
            return 0;
        }
        vector<int> arr(n + 10);
        arr[0] = 0;
        arr[1] = 1;
        int ans = 1;
        for(int i = 1; 2*i + 1 <= n; i++) {
            arr[2*i] = arr[i];
            arr[2*i + 1] = arr[i] + arr[i + 1];
            ans = max(ans, max(arr[2*i], arr[2*i + 1]));
        }
        
        return ans;
    }
};