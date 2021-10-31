//https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    string maskWord(string s){
        vector<int> mask(26,0);
        for(int i=0;i<s.length();i++){
            mask[s[i]-'a']++;
        }
        string ans = "";
        for(int i=0; i<26; i++){
            ans += 48+mask[i];
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<strs.size();i++){
            
            mp[maskWord(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
