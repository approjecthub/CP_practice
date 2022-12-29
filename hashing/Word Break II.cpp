//https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    void wordBreakUtil(string s,string temp, vector<string>& wordDict, vector<string>&ans, int i, int n){
        if(i==n){
            ans.push_back(temp);
        }
        
        for(int j = i; j<n; j++){
            string t = s.substr(i,j-i+1);
            auto it = find(wordDict.begin(), wordDict.end(), t);
            if(it!=wordDict.end()){
                if(temp == ""){
                    wordBreakUtil(s, temp+t, wordDict, ans, j+1, n);
                }
                else{
                    wordBreakUtil(s, temp+" "+t, wordDict, ans, j+1, n);
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        wordBreakUtil(s, "", wordDict, ans,0, s.size());
        return ans;
    }
};
