#include <bits/stdc++.h> 
using namespace std;

using edge = tuple<int, int, int>; // weight, start, end.
using minPq = priority_queue<edge, vector<edge>, greater<edge>>;

class Dijkstra {

public:
    vector<edge> raw;
    unordered_map<int, vector<tuple<int, int>>> graph; // weight, end.
    int init;
    unordered_map<int, int> dist; 

    Dijkstra(vector<edge> _raw): raw(_raw) {
        // TODO
        prepare(); 
    }

    ~Dijkstra() = default; 

    void prepare() {
        for (auto& [w, s, e] : raw) {
            graph[s].push_back({w, e});
            graph[e].push_back({w, s}); 
        }
        init = graph.begin()->first; 

        for (auto &[node, _] : graph)
            dist[node] = INT_MAX;
    }

    unordered_map<int, int> solve() {
        minPq pq;
        unordered_set<int> vis;
        dist[init] = 0;
        pq.push({0, -1, init});

        while (!pq.empty()) {
            auto [cur_dist, _, cur] = pq.top();
            pq.pop();

            if (vis.count(cur)) continue;
            vis.insert(cur);

            for (auto &[nxt, w] : graph[cur]) {
                if (dist[nxt] > cur_dist + w) {
                    dist[nxt] = cur_dist + w;
                    pq.push({dist[nxt], cur, nxt});
                }
            }
        }

        return dist;
    }
};