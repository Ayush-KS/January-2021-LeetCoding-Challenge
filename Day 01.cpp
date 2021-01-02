// Check Array Formation Through Concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int cnt = 0;
        int n = arr.size();
        
        for(vector<int> v : pieces) {
            for(int i = 0; i < n; i++) {
                int j = 0;
                while(i < n && j < v.size() && arr[i] == v[j]) {
                    arr[i] = -1;
                    cnt++;
                    i++;
                    j++;
                }
            }
        }
        return cnt == n;
    }
};