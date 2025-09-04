class MergeSort {
    
    constructor(data) {
        this.data = data;  
    }

    merge(st, en, mid) {
        const temp = {}; 
        let lidx = st; 
        let ridx = mid + 1; 
        
       for (let idx = st; idx <= en; idx++) {
            // console.log(this.data, left, right, lidx, ridx)
            if (lidx === mid + 1) temp[idx] = this.data[ridx++]; 
            else if (ridx === en + 1) temp[idx] = this.data[lidx++]; 
            else if (this.data[lidx] <= this.data[ridx]) temp[idx] = this.data[lidx++]; 
            else temp[idx] = this.data[ridx++];
        }

        for (const [idx, value] of Object.entries(temp)) {
            this.data[Number(idx)] = value; 
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