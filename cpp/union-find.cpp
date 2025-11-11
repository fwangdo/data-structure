#include <bits/stdc++.h>
using namespace std; 

class UnionFind {
public:
    int N;
    vector<int> data{-1}; 

    UnionFind(int _N): N(_N) {
        for (int i = 1; i <= N; i++) {
            data.push_back(-1); 
        }
    }

    ~UnionFind() = default; 

    int find(int idx) {
        if (data[idx] < 0) {
            return idx; 
        } else {
            return find(data[idx]); 
        }
    }

    int quick_find(int idx) {
        if (data[idx] < 0) {
            return idx; 
        } else {
            data[idx] = quick_find(data[idx]);
            return data[idx]; 
        }
    }

    bool uni(int idx1, int idx2) {
        // return true when it needs unification. if not, it will return false. 
        int r1 = find(idx1);
        int r2 = find(idx2); 

        if (r1 == r2) {
            return false; 
        }

        data[r2] = r1;
        return true; 
    }

    bool quick_union(int idx1, int idx2) {
        int r1 = quick_find(idx1);
        int r2 = quick_find(idx2);

        if (r1 == r2)
        {
            return false;
        }

        int r1_rank = data[r1];
        int r2_rank = data[r2]; 

        if (r1_rank < r2_rank) {
            data[r2] = r1; 
        }
        else if (r1_rank > r2_rank)
        {
            data[r1] = r2;
        }
        else
        {
            data[r1]--;
            data[r2] = r1;
        }

        return true; 
    }
};