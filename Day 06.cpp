// Kth Missing Positive Number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] - mid - 1 < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo + k;
    }
};