//https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> g;
        k--;
        for(auto x: times){
            g[x[0]-1].push_back({x[2], x[1]-1});
        }
        
        vector<int> dist(n, -1);
        
        int ans = 0;
        
        set<pair<int, int>>s;
        
        dist[k] = 0;
        s.insert({dist[k] , k});
        
        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);
            for(auto np: g[node]){
                int nbr = np.second;
                int edge = np.first;
                 if(distTillNow+ edge < dist[nbr] || dist[nbr]==-1){
                     auto f = s.find({dist[nbr], nbr});
                     if(f!=s.end()){
                         s.erase(f);
                     }
                     dist[nbr] = distTillNow+ edge;
                     s.insert({dist[nbr] , nbr});
                 }
            }
           
        }
        
        for(int i=0; i<n;i++){
            if(dist[i]==-1)return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;
        
    }
};
