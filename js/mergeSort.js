class MergeSort {
    
    constructor(data) {
        this.data = data;  
    }

    merge(st, en, mid) {
        const left = this.data.slice(st, mid+1);
        const right = this.data.slice(mid+1, en+1)
        let lidx = 0; 
        let ridx = 0; 
        let curIdx = st; 
        
        while (lidx < left.length || ridx < right.length) {
            // console.log(this.data, left, right, lidx, ridx)
            if (lidx === left.length) this.data[curIdx++] = right[ridx++]; 
            else if (ridx === right.length) this.data[curIdx++] = left[lidx++]; 
            else if (left[lidx] <= right[ridx]) this.data[curIdx++] = left[lidx++]; 
            else this.data[curIdx++] = right[ridx++];
        }
    }

    sort(st, en) {
        if (st == en) return; 
        let mid = Math.floor((st + en) / 2); 
        this.sort(st, mid); 
        this.sort(mid+1, en); 
        this.merge(st, en, mid); 
    } 

}

const mine = new MergeSort([5, 3, 1, 2])
mine.sort(0, mine.data.length - 1); 
console.log(mine.data); 