// https://leetcode.com/problems/valid-parenthesis-string/
// Topics: Stack, String, Parentheses, Greedy

class Solution {
    public:
        bool solve(stack<char> stk, int pos, string s, char c){
            if(pos>=s.size()){
                return stk.empty()?true: false;
            }
            else if(c==')' && stk.size()>0 && stk.top()=='('){
                stk.pop();
            }
            else if(c=='('){
                stk.push(c);
            }
    
            for(int i=pos+1; i<s.size(); i++){
                if(s[i]== '('){
                    stk.push(s[i]);
                }
                else if(s[i]=='*'){
                    return solve(stk, i, s, '(') || 
                    solve(stk, i, s, ')') || 
                    solve(stk, i, s, '\0');
                }
                else{
                    if(stk.size()>0 && stk.top()=='('){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
    
            return stk.empty() ? true : false;
        }
    
        bool solve2(string s, int pos, int cnt){
            if(pos>=s.size()) return cnt==0;

            if(s[pos]=='('){
                return solve2(s, pos+1, cnt+1);
            }
            else if(s[pos]==')'){
                if(cnt==0) return false;
                return solve2(s, pos+1, cnt-1);
            }
            else if(s[pos]=='*'){
                return solve2(s, pos+1, cnt+1) || solve2(s, pos+1, cnt-1) || solve2(s, pos+1, cnt);
            }
            return false;
        }

        bool solveDP(string s, int pos, int cnt){
            int n = s.size();
            vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
            dp[n][0] = true;

            for(int pos=n-1; pos>=0; pos--){
                for(int cnt=0; cnt<=n; cnt++){
                    if(s[pos]=='('){
                        dp[pos][cnt] = cnt<n ? dp[pos+1][cnt+1] : false;
                    }
                    else if(s[pos]==')'){
                        if(cnt==0) dp[pos][cnt] = false;
                        else dp[pos][cnt] = dp[pos+1][cnt-1];
                    }
                    else if(s[pos]=='*'){
                        dp[pos][cnt] = (cnt<n ? dp[pos+1][cnt+1] : false) || (cnt>0 ? dp[pos+1][cnt-1] : false) || dp[pos+1][cnt];
                    }
                }
            }

            return dp[0][0];
        }
    
        bool checkValidString(string s) {
            // stack<char> stk;
    
            // return solve(stk, 0, s, s[0]);
            // return solve2(s, 0, 0);
            return solveDP(s, 0, 0);
        }
    };