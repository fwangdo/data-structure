class UnionFind {
    constructor(N) {
        this.N = N;  
        this.data = [null]; 
        // 초기값: -1 (루트이면서 rank=1을 의미)
        for (let i = 1; i <= N; i++) {
            this.data[i] = -1; 
        }
    }

    normalFind(idx) {
        if (this.data[idx] < 0) {
            return idx; 
        } else {
            return this.normalFind(this.data[idx]); // 수정: 한 번만 재귀 호출
        }
    }

    compFind(idx) {
        if (this.data[idx] < 0) {
            return idx; 
        } else {
            this.data[idx] = this.compFind(this.data[idx]); // 경로 압축
            return this.data[idx]; 
        }
    }

    normalUnion(idx1, idx2) {
        const root1 = this.normalFind(idx1); 
        const root2 = this.normalFind(idx2); 

        if (root1 === root2) return false; // 이미 같은 집합

        this.data[root2] = root1; // root2를 root1에 합침
        return true;
    }

    rankUnion(idx1, idx2) {
        const root1 = this.compFind(idx1); 
        const root2 = this.compFind(idx2); 
        
        if (root1 === root2) return false; // 이미 같은 집합 (수정된 조건)
        
        const r1Value = this.data[root1]; // 음수값 (rank)
        const r2Value = this.data[root2]; // 음수값 (rank)
        // rank 비교: 더 음수인 쪽이 rank가 높음
        // 예: -5 < -3 이면 rank 5 > rank 3
        if (r1Value < r2Value) {
            // root1의 rank가 더 높으므로 root1이 새로운 root
            this.data[root2] = root1; 
        } else if (r1Value > r2Value) {
            // root2의 rank가 더 높으므로 root2가 새로운 root
            this.data[root1] = root2; 
        } else {
            // rank가 같으면 root1을 root로 하고 rank 증가
            this.data[root1]--; // rank 증가 (더 음수로)
            this.data[root2] = root1; 
        }

        return true; 
    }
}