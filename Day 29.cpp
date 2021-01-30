// Vertical Order Traversal of a Binary Tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int sz = q.size();
            unordered_map<int, vector<int>> temp;
            for(int i = 0; i < sz; i++) {
                pair<TreeNode*, int> curr = q.front();
                q.pop();
                temp[curr.second].push_back(curr.first -> val);
                if(curr.first -> left) {
                    q.push({curr.first -> left, curr.second - 1});
                }
                if(curr.first -> right) {
                    q.push({curr.first -> right, curr.second + 1});
                }
            }
            for(auto it : temp) {
                sort(it.second.begin(), it.second.end());
                for(int v : it.second) {
                    mp[it.first].push_back(v);
                }
            }
        }
        
        vector<vector<int>> op;
        for(auto it : mp) {
            op.push_back(it.second);
        }
        return op;
    }
};