#pragma once
template<typename T = int>
struct Edge{
    int from,to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = -1, int idx = -1): from(from), to(to),cost(cost),idx(idx){}

    operator int() const {return to;} 
};


template <typename T = int>
struct Graph{
    vector<vector<Edge<T> > > g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {}

    void add_d_edge(int from, int to, T cost = 1){
        g[from].emplace_back(from,to,cost,es++); 
    }

    void add_edge(int from, int to, T cost = 1){
        g[from].emplace_back(from,to,cost,es);
        g[to].emplace_back(to,from,cost,es++);
    }
};
