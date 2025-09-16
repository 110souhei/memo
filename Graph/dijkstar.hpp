template <typename T>

vector<T> dijkstra(Graph<T>& g,int n,int s,T ie = numeric_limits<T>::min(), T max_cost = numeric_limits<T>::max()){
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> q;
    vector<T> dist;
    dist.assign(n,max_cost);
    dist[s] = ie;
    q.push({dist[s],s});

    while(q.size()){
        auto [cost,idx] = q.top();
        q.pop();
        if(dist[idx] < cost) continue;
        for(auto& e : g.g[idx]){
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            q.push({dist[e.to],e.to});
        }
    }
    return dist;
}
