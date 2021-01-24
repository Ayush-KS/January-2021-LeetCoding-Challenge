// Sort the Matrix Diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat.at(0).size();
        
        for(int i = 0; i < m; i++) {
            
            priority_queue<int, vector<int>, greater<int>> pq;
            int j = i;
            int k = 0;
            
            while(j != m && k != n) {
                pq.push(mat.at(j++).at(k++));    
            }
            
            j = i;
            k = 0;
            
            while(pq.size()) {
                mat.at(j++).at(k++) = pq.top();
                pq.pop();
            }
        }
        
        for(int i = 1; i < n; i++) {
            
            priority_queue<int, vector<int>, greater<int>> pq;
            int j = 0;
            int k = i;
            
            while(j != m && k != n) {
                pq.push(mat.at(j++).at(k++));
            }
            
            j = 0;
            k = i;
            
            while(pq.size()) {
                mat.at(j++).at(k++) = pq.top();
                pq.pop();
            }
        }
        
        return mat;
    }
};