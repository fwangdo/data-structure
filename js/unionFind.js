class UnionFind {

    // TODO: we need to implement rank optimization and coordinate compression. 
    constructor (N) {
        this.N = N;  
        this.data = [null]; 
        for (let i = 1; i <= N; i ++ ) {
            this.data[i] = i; 
        }
        this.sample = [[1, 3], [3, 4], [5,8], [8,7]]; 
    }; 

    normalFind(idx) {
        if (this.data[idx] < 0 ){
            return idx; 
        } else {
            return this.find(this.find(this.data[idx])); 
        }
    }

    compFind(idx) {
        if (this.data[idx] < 0) {
            return idx; 
        } else {
            this.data[idx] = this.compFind(this.data[idx]) 
            return this.data[idx]; 
        }
    }

    union() {
        
    }
}