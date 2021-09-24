//https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

class Solution {
public:
    static string solve(string s, int a, int b, string ans, unordered_map<string, int> &umap){
        int n= s.size();
        string t1=s,t2;
        //calculate 1st operation
        for(int j=1;j<n;j+=2){
                t1[j] = (((t1[j]-48)+a)%10)+48;
            }
        //calculate 2nd operation
            t2 = s.substr(n-b,b)+s.substr(0,n-b);
        if(umap[t1] && umap[t2])return ans;
        if(umap[t1]){
            ans = min(ans,t2);
            umap[t2]= 1;
            
            ans = solve(t2,a,b,ans,umap);
        }
        else if(umap[t2]){
            ans = min(ans,t1);
            umap[t1]= 1;
            
            ans = solve(t1,a,b,ans,umap);
        }
        else{
            if(t1<t2) ans = min(ans, t1);
            else ans = min(ans, t2);
            umap[t1]= 1;
            umap[t2]= 1;
            ans = min(solve(t2,a,b,ans,umap), solve(t1,a,b,ans,umap));
        }
        return ans;
        
    }
    string findLexSmallestString(string s, int a, int b) {
        unordered_map<string, int> umap;
        umap[s] = 1;
   
        return solve(s,a,b,s, umap);
    }
};
