class AdjList {
    
    constructor() {
        this.data = new Map();  
    }

    insert(n1, n2) {
        if (!this.data.has(n1)) {
            this.data.set(n1, []); 
        }
        if (!this.data.has(n2)) {
            this.data.set(n2, []); 
        }

        this.data.get(n1).push(n2);
        this.data.get(n2).push(n1);
    }

    getEdgeFromNode(node) {
        if (!this.data.has(node)) return []; 
        return this.data.get(node); 
    }
}
