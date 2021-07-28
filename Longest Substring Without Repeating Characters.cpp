//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
       
        if (n<=1){
            return n;
        }
        
        
        int i=0,j=0, maxc = 1;
        unordered_map<char, int> umap;
        
        while(i<n){
            if(umap.find(s[i]) == umap.end() || umap[s[i]] < j){
               
                umap[s[i]] = i;              
                
            }
            else{
                
                j = umap[s[i]]+1 ;
                umap[s[i]] = i;
            }
            
            i++;
            maxc = max(i-j, maxc);
            
        }
        
        return maxc;
    }
};
