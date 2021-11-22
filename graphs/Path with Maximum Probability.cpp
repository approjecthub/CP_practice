//https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<double> dist(n, 0);
        set<pair<double, int>> s;
        unordered_map<int, vector<pair<double,int>>> g;
        
        for(int i=0; i<edges.size();i++){
            g[edges[i][0]].push_back({succProb[i],edges[i][1]});
            g[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        dist[start]=1;
        s.insert({1,start});
        while(!s.empty()){
            auto it = s.rbegin();
            int node = it->second;
            double distTillNow = it->first;
            // cout<<"poped: "<<(it->second)<<" : "<<(it->first)<<endl;
            s.erase(prev(s.end()));
            
            for(auto nbrPair : g[node]){
                
                int nbr = nbrPair.second;
                double edge = nbrPair.first;
                // cout<<nbr<<" , "<< dist[nbr]<<" , "<<edge<<" , "<<distTillNow<<endl;
                if(distTillNow*edge > dist[nbr]){
                    
                    auto f = s.find({dist[nbr], nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbr] = distTillNow*edge ;
                    // cout<<nbr<<" : "<<dist[nbr]<<endl;
                    s.insert({dist[nbr], nbr});
                }
                
            }
            
        }
        
        return dist[end];
    }
};
