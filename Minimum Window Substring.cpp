//https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    // static string compareFreq(unordered_map<char,int> umapt, unordered_map<char,int> umaps){
    //     for(auto it: umapt){
    //         if (umaps.find(it.first) == umaps.end() || umaps[it.first]<it.second){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    string minWindow(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        
        if(ns<nt){
            return "";
        }
        if(ns==nt){
            string ans = s;
            sort(s.begin(),s.end());
            sort(t.begin(), t.end());
            if(s==t){
                return ans;
            }
            return "";
        }
        
        string ans= "";
        
        unordered_map<char,int> umapt ;
        
        for(int i=0; i<nt; i++){
            if(umapt.find(t[i]) == umapt.end()){
                umapt[t[i]] = 1;
            }
            else{
                umapt[t[i]]++;
            }
        }
        deque <int> dq;
        int cnt = 0,  len=INT_MAX;
        
        for(int i=0; i<ns; i++){
            
            if(umapt.find(s[i]) != umapt.end()){
               
                if(umapt[s[i]]>0){
                    cnt ++; 
                    umapt[s[i]]--;
                    dq.push_back(i);                    
                }                
                
            }
            
            if(cnt == nt){
                
                if(i-dq.front()<len){
                    len = i-dq.front();
                    ans = s.substr(dq.front(), i+1);
                }
                if(dq.size()>0){
                    
                 umapt[s[dq.front()]]++;
                    
                    cnt--;
                dq.pop_front();

                }
                else{
                    break;
                }
                
            }
                
            
        }
        return ans;
    }
};
