template<typename T>
vector<T> bellman_ford(Graph<T>& edges, int n,int s, T MAX_T = numeric_limits<T>::max(), T MIN_T = numeric_limits<T>::min()){
    vector<T> dist(n,MAX_T);
    dist[s] = 0;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n; j++){
            for(auto& e : edges.g[j]){
                 if(dist[e.from] == MAX_T) continue;
                 dist[e.to] = min(dist[e.to],dist[e.from] + e.cost);
            }
        }
    }
    vector<bool> negative(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(auto& e : edges.g[j]){
                if(dist[e.from] == MAX_T)continue;
                if(dist[e.from] + e.cost < dist[e.to]){
                    dist[e.to] = dist[e.from] + e.cost;
                    negative[e.to] = true;
                }
                if(negative[e.from]){
                    negative[e.to] = true;
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(negative[i]) dist[i] = MIN_T;
    }
    return dist;
}