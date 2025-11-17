#include <bits/stdc++.h>
using namespace std;

class Trie {

public:
    const int ROOT = 1;
    int unused = 2;
    int MX;
    vector<bool> chk;
    vector<vector<int>> nxt; 

    Trie(int _MX): MX(_MX) {
        chk.assign(MX, false);

        nxt.assign(MX, vector<int>{});
        for (int i = 0; i < MX; i++) {
            nxt[i].push_back(-1); 
        }
    }

    ~Trie() = default;
    
    int c2i(char c) {
        return c - 'a'; 
    }

    void insert(string &s) {
        int cur = ROOT; 
        for (auto c : s) {
            if(nxt[cur][c2i(c)] == -1) {
                nxt[cur][c2i(c)] = unused++; 
            }
            cur = nxt[cur][c2i(c)]; 
        }
        chk[cur] = true; 
    }

    void erase(string &s) {
        int cur = ROOT; 
        for (auto c: s) {
            if (nxt[cur][c2i(c)] == -1) {
                return; 
            }
            cur = nxt[cur][c2i(c)]; 
        }
        chk[cur] = false; 
    }

    bool find(string &s) {
        int cur = ROOT; 
        for (auto c : s) {
            if (nxt[cur][c2i(c)] == -1) {
                return false; 
            }
            cur = nxt[cur][c2i(c)]; 
        }
        return chk[cur]; 
    }
};