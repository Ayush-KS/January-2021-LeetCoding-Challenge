// Minimize Deviation in Array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int imin =  INT_MAX;    
        for(int i : nums) {
            if(i & 1)
                i *= 2;
            imin = min(imin, i);
            pq.push(i);
        }
        
        int ans = INT_MAX;
        
        while(pq.top() % 2 == 0) {
            int curr = pq.top();
            pq.pop();
            ans = min(ans, curr - imin);
            if(curr % 2 == 0) {
                pq.push(curr / 2);
                imin = min(imin, curr/2);
            }
        }
        
        return min(ans, pq.top() - imin);
    }
};