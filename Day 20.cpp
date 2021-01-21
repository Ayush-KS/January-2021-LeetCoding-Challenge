// Valid Parentheses

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for(char c : str) {
            switch(c) {
                case ')': {
                    if(s.empty() || s.top() != '(')
                        return false;
                    s.pop();
                    break;
                }
                case '}': {
                    if(s.empty() || s.top() != '{')
                        return false;
                    s.pop();
                    break;
                }
                case ']': {
                    if(s.empty() || s.top() != '[')
                        return false;
                    s.pop();
                    break;
                }
                default: {
                    s.push(c);
                }
            }
        }
        return s.empty();
    }
};