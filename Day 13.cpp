// Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& pp, int l) {
        sort(pp.begin(), pp.end());
        int si = 0;
        int ei = pp.size() - 1;
        int ans = 0;
        
        while(si <= ei) {
            if(pp[si] + pp[ei] <= l) {
                si++;
                ei--;
            } else {
                ei--;
            }
            ans++;
        }
        
        return ans;
    }
};