#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> data { -1 }; // dummy index (1-based)
    MinHeap() = default;
    ~MinHeap() = default;

    int get_pidx(int idx) { return idx / 2; }
    pair<int,int> get_cidx(int idx) { return { idx * 2, idx * 2 + 1 }; }

    void push(int value) {
        data.push_back(value);
        int target_idx = data.size() - 1;
        // bubble-up
        while (target_idx > 1) {
            int pidx = get_pidx(target_idx);
            if (data[pidx] > data[target_idx]) {
                swap(data[pidx], data[target_idx]);
                target_idx = pidx;
            } else break;
        }
    }

    void pop() {
        if (data.size() <= 1) return;
        data[1] = data.back();
        data.pop_back();

        int target_idx = 1;
        // bubble-down
        while (true) {
            auto [c1, c2] = get_cidx(target_idx);
            if (c1 >= data.size()) break;

            int smallest = target_idx;
            if (c1 < data.size() && data[c1] < data[smallest]) smallest = c1;
            if (c2 < data.size() && data[c2] < data[smallest]) smallest = c2;
            if (smallest == target_idx) break;

            swap(data[target_idx], data[smallest]);
            target_idx = smallest;
        }
    }

    int top() {
        if (data.size() <= 1) throw runtime_error("heap is empty");
        return data[1];
    }

    bool empty() { return data.size() <= 1; }
};
