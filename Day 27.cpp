// Concatenation of Consecutive Binary Numbers

class Solution {
public:    
    const int mod = 1e9 + 7;
    
    int concatenatedBinary(int n) {
        string str = "";
        long mul = 1;
        long ans = 0;
        
        for(int i = n; i >= 1; i--) {
            int j = i;
            while(j) {
                if(j & 1) {
                    (ans += mul) %= mod;
                }
                (mul *= 2) %= mod;
                j >>= 1;
            }
        }
        
        return ans;
    }
};