#include <bits/stdc++.h>
using namespace std;

// note that input form is DAG.
using edge = tuple<int, int>; 

class TopSort {

public:
    vector<edge> raw;
    unordered_map<int, vector<int>> data;
    unordered_map<int, int> deg;
    set<int> node; 
    vector<int> res;

    TopSort(vector<edge> _raw): raw(_raw) {
        prepare();
        sort(); 
    }

    ~TopSort() = default; 

    void prepare() {
        // generate graph. 
        for (auto& [s, e]: raw) {
            data[s].push_back(e);
            deg[e]++;
            node.insert(s);
            node.insert(e);
        }
    }

    void sort() {
        // sorting.
        queue<int> q; 

        // init. 
        for (auto &elem : node) {
            if (deg[elem] == 0) {
                q.push(elem);
                res.push_back(elem); 
            }
        }

        // iteration.  
        while (!q.empty()) {
            // invariant: the current node's indegree is zero. 
            auto cur = q.front();
            q.pop(); 

            for (auto &nxt: data[cur]) {
                deg[nxt]--; 
                if (deg[nxt] == 0) {
                    q.push(nxt);
                    res.push_back(nxt); 
                }
            }
        }
    }

    void show() {
        // print. 
    }
};

int main() {
    vector<edge> raw = {
        {1, 2}, 
        {2, 3}
    };

    TopSort temp = TopSort(raw);
    temp.show();
    return 0;
}