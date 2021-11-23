//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
    
public:
    unordered_map<int, int> mp;
    unordered_map<int, vector<pair<int,int>>> g;
    void dijkstra(int src,int V,int distanceThreshold){

		//Data Structures
		vector<int> dist(V,INT_MAX);
		set<pair<int,int> >  s;

		//1. Init 
		dist[src] = 0;
		s.insert({0,src});

		while(!s.empty()){

			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first; 
			s.erase(it); //Pop 

			//Iterate over the nbrs of node
			for(auto nbrPair : g[node]){

				int nbr = nbrPair.second;
				int currentEdge = nbrPair.first;

				if(distTillNow + currentEdge < dist[nbr]){
					//remove if nbr already exist in the set

					auto f = s.find({dist[nbr],nbr});
					if(f!=s.end()){
						s.erase(f);
					}
					//insert the updated value with the new dist
					dist[nbr] = distTillNow + currentEdge;
					s.insert({dist[nbr],nbr});

				}
			}
		}
        mp[src]=0;
        for(int i=0; i<V; i++){
            if(dist[i]<=distanceThreshold){
                mp[src]++;
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i=0; i<edges.size(); i++){
            g[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            g[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        
        for(int i=0;i<n;i++){
            dijkstra(i, n, distanceThreshold);
        }
        
        int wt = INT_MAX, idx=-1;
        for(int i=0;i<n;i++){
            if(wt>=mp[i]){
                wt = mp[i];
                idx = i;
            }
        }
        return idx;
    }
};
