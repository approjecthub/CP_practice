//https://leetcode.com/problems/avoid-flood-in-the-city/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        
        set<int> dryDays;
        unordered_map<int, int> filledLake;
        
        for(int i = 0; i<n; i++){
            
            if(rains[i]==0){
                dryDays.insert(i);
                ans[i] = 1;
            }
            else{
                if(filledLake.find(rains[i])!= filledLake.end()){
                    int lastFilledDate = filledLake[rains[i]];
                    auto it = dryDays.lower_bound(lastFilledDate);
                    if(it == dryDays.end()){
                        return {};
                    }
                    else{
                        ans[*it] = rains[i];
                        dryDays.erase(it);
                    }
                }
            }
            
            filledLake[rains[i]] = i;
        }
        
        return ans;
    }
};