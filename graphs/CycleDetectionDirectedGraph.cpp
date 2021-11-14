bool DFS(unordered_map<int, vector<int>> &g,unordered_map<int, bool> &visited, int src){
    visited[src] = true;
    bool ans = false;
    for(auto x: g[src]){
        if(visited[x]){
            return true;
        }
        else{
            ans = ans || DFS(g, visited, x);
            if(ans) return true;
        }
    }
    visited[src] = false;
    return ans;
}   
bool contains_cycle(int,vector <pair<int,int>> edges){
    //Complete this method
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> visited;
    for(auto p: edges){
        g[p.first].push_back(p.second);
        visited[p.first] = false;
    }
    return DFS(g, visited, edges[0].first);
}
