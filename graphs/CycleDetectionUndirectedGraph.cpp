bool contains_cycle(int,vector <pair<int,int>> edges){
    
    queue<pair<int,int>> q;
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> visited;
    for(auto p: edges){
        g[p.first].push_back(p.second);
        visited[p.first] = false;
    }
    
    q.push({edges[0].first, -1});
    visited[edges[0].first]= true;
    while(!q.empty()){
        auto p = q.front();
        //p.first => source node, p.second=> parent of the source
        q.pop();
        for(auto x: g[p.first]){
            if(visited[x] && x!=p.second){
                return true;
            }
            else if(!visited[x]){
                q.push({x, p.first});
            }
        }
    }
    return false;   
}
