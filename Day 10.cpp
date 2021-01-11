// Create Sorted Array through Instructions

#define MOD		1000000007
#define ll		long long int
    const int maxn = 1e5 + 10;
class Solution {
public:
    
    int bit[maxn];
    
    void update(int in, int val) {
        while(in < maxn) {
            bit[in] += val;
            in += (in & (-in));
        }
    }
    
    int sum(int in) {
        int ans = 0;
        while(in) {
            ans += bit[in];
            in -= (in & (-in));
        }
        
        return ans;
    }
    
    int createSortedArray(vector<int>& arr) {
        ll ans = 0;
        int n = arr.size();
        memset(bit, 0, sizeof(bit));
        unordered_map<int, int> mp;
        
        
        for(int i = 0; i < n; i++) {
            ll small = sum(arr[i] - 1);
            ll large = (i) - (small + mp[arr[i]]);
            (ans += min(small, large)) %= MOD;
            update(arr[i], 1);
            mp[arr[i]]++;
        }
        return ans;
    }
};