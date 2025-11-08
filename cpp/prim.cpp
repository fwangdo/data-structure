#include <bits/stdc++.h>
using namespace std; 

// type. 
using edge = tuple<int, int, int>; // weight, start, end.
using nxtEdge = tuple<int, int>; // weight, to. 

class Prim {

public:
    // basic
    vector<edge> raw; // { {1, 2}, {2, 3} .. }
    unordered_map<int, vector<tuple<int, int>>> graph;
    int N = 0; // nodes. 

    // constructor 
    Prim(vector<edge> _raw): raw(_raw) {
        prepare(); 
    }

    ~Prim() = default; 

    void prepare() {
        set<int> chk; 

        for (auto &elem : raw) {
            auto [weight, start, end] = elem;
            graph[start].push_back({end, weight});
            chk.insert(start); 
            chk.insert(end); 
        }
        N = chk.size(); 
    }

    int solve() {
        // assume connected graph. 
        int res = 0; 
        unordered_set<int> vis;
        priority_queue<
            edge,
            vector<edge>,
            greater<edge>> pq;

        auto [weight, start, end] = raw[0];
        pq.push(std::make_tuple(0, -1, start));

        for (int i = 0; i < N; i++) {
            auto [weight, past, cur] = pq.top();
            pq.pop();

            res += weight;
            vis.insert(cur); 

            for (auto &[new_weight, nxt]: graph[cur]) {
                if (vis.find(nxt) == vis.end()) 
                    pq.push({new_weight, cur, nxt}); 
            }
        }

        return res; 
    }
};