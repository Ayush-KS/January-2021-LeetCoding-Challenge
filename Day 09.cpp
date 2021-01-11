// Word Break

class Solution {
public:
    int ladderLength(string src, string tar, vector<string>& wordList) {
        unordered_map<string, bool> mp;
        for(string& str : wordList) {
            mp[str] = true;
        }
        
        int ans = 0;
        queue<string> q;
        q.push(src);
        mp[src] = false;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int s = 0; s < sz; s++) {
                string curr = q.front();
                q.pop();
                
                if(curr == tar)
                    return ans + 1;
                
                for(int i = 0; i < curr.size(); i++) {
                    char temp = curr[i];
                    for(int j = 0; j < 26; j++) {
                        curr[i] = j + 'a';
                        if(mp[curr]) {
                            mp[curr] = false;
                            q.push(curr);
                        }
                    }
                    curr[i] = temp;
                }
                
            }
            ans++;
        }
        
        return 0;
    }
};
