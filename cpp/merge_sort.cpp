#include <bits/stdc++.h>
using namespace std;

class MergeSort {

public:
    vector<int> data; 
    MergeSort(vector<int> _data): data(_data) {};
    ~MergeSort() = default;

    void sort(int front, int back) {
        if (front == back)
            return;

        int mid = (front + back) / 2;
        sort(front, mid);
        sort(mid + 1, back);

        vector<int> temp{};
        int fidx = front;
        int bidx = mid + 1; 

        while (temp.size() <= (back - front + 1)) {
            int left = data[fidx];
            int right = data[bidx]; 

            if (fidx >= mid + 1) {
                temp.push_back(data[bidx++]); 
                continue;
            }
            if (bidx > back) {
                temp.push_back(data[fidx++]); 
                continue;
            }

            if (left <= right) {
                temp.push_back(data[fidx++]);
            } else {
                temp.push_back(data[bidx++]);
            }
        }

        int cur_idx = front; 
        for (auto& elem : temp) {
            data[cur_idx++] = elem; 
        }

        return;
    }

    void print() {
        for (auto& elem: data) {
            cout << elem << " "; 
        }
        cout << '\n'; 
    }
};

int main() {
    vector<int> data{1, 5, 11, 6, 7, 8, 15, 30, 55, 22, 26};
    MergeSort temp = MergeSort(data);
    temp.sort(0, temp.data.size() - 1);
    temp.print();
    return 0;
}