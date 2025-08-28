class AbsHeap {

    constructor() {
        this.data = [null]; 
    }

    getParentIdx(idx) {
        return Math.floor(idx / 2);  
    }

    getChildrenIdx(idx) {
        return [idx * 2, idx * 2 + 1]; 
    }

    top() {
        return this.data[1]; 
    }

    insert(elem) {
        const curIdx = this.data.length; 
        this.data[curIdx] = elem; 

        let targetIdx = curIdx; 
        // invaraint.  
        while (targetIdx > 1) {
            const pIdx = this.getParentIdx(targetIdx); 
            const pValue = this.data[pIdx]; 
            const cValue = this.data[targetIdx]; 

            if (Math.abs(pValue) > Math.abs(cValue)) {
                const temp = pValue;
                this.data[pIdx] = cValue; 
                this.data[targetIdx] = temp; 
                targetIdx = pIdx;  
            } else if (Math.abs(pValue) === Math.abs(cValue)) {
                if (cValue < pValue) {
                    const temp = pValue;
                    this.data[pIdx] = cValue; 
                    this.data[targetIdx] = temp; 
                    targetIdx = pIdx;  
                } else { 
                    break;
                } 
            } else {
                break; 
            } 
        }
    }

    delete() {
        if (this.data.length === 1) return 0; // heap empty
        if (this.data.length === 2) return this.data.pop(); 
        
        const top = this.top();
        // 루트에 마지막 원소 가져오기
        this.data[1] = this.data.pop(); 
        
        let targetIdx = 1;

        while (true) {
            const [cIdx1, cIdx2] = this.getChildrenIdx(targetIdx);
            const left = this.data[cIdx1];
            const right = this.data[cIdx2];
            let swapIdx = null;

            // 자식 존재 여부 확인
            if (cIdx1 >= this.data.length) break; // 왼쪽 자식 없음 → 종료

            if (cIdx2 >= this.data.length) { // 오른쪽 자식 없음 → 왼쪽만 비교
                if (Math.abs(left) < Math.abs(this.data[targetIdx]) || 
                (Math.abs(left) === Math.abs(this.data[targetIdx]) && left < this.data[targetIdx])) {
                    swapIdx = cIdx1;
                } else break;
            } else { // 두 자식 존재 → 절대값 기준 더 작은 쪽 선택
                let minChildIdx = (Math.abs(left) < Math.abs(right) || 
                    (Math.abs(left) === Math.abs(right) && left < right)) ? cIdx1 : cIdx2;

                if (Math.abs(this.data[minChildIdx]) < Math.abs(this.data[targetIdx]) ||
                (Math.abs(this.data[minChildIdx]) === Math.abs(this.data[targetIdx]) &&
                    this.data[minChildIdx] < this.data[targetIdx])) {
                    swapIdx = minChildIdx;
                } else break;
            }

            // swap
            const temp = this.data[targetIdx];
            this.data[targetIdx] = this.data[swapIdx];
            this.data[swapIdx] = temp;

            targetIdx = swapIdx; // 이동
        }

        return top;
    }

} 
