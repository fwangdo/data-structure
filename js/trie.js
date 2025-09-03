// Trie 

class Trie {
    
    constructor(mx, letter) {
        this.root = 1; 
        this.unused = 2; 
        this.mx = mx // the maximum number of input. 
        this.chk = Array(mx).fill(false); 
        this.nxt = Array.from({ length: mx}, () => Array(letter).fill(-1)); 
    }

    convert(letter) {
        return letter.charCodeAt(0) - 'a'.charCodeAt(0);
    }

    insert(word) {
        // word is string. 
        let curIdx = this.root; 

        for (let i = 0; i < word.length; i++) {
            let curLetter = this.convert(word[i]); 
            let nxt = this.nxt[curIdx][curLetter]; 
            if (nxt === -1) {
                this.nxt[curIdx][curLetter] = this.unused++; 
            }
            curIdx = this.nxt[curIdx][curLetter]; 
        }

        this.chk[curIdx] = true; 
    }

    erase(word) {
        // success returns true, failure returns false. 
        let curIdx = this.root; 

        for (let i = 0; i < word.length; i++) {
            let curLetter = this.convert(word[i]); 
            let nxt = this.nxt[curIdx][curLetter]; 
            if (nxt === -1) {
                return false; 
            }
            curIdx = this.nxt[curIdx][curLetter]; 
        }

        if (this.chk[curIdx] === true) {
            this.chk[curIdx] = false; 
            return true; 
        } else {
            return false; 
        }
    }

    find(word) {
        // success returns true, failure returns false. 
        let curIdx = this.root; 

        for (let i = 0; i < word.length; i++) {
            let curLetter = this.convert(word[i]); 
            let nxt = this.nxt[curIdx][curLetter]; 
            if (nxt === -1) {
                return false; 
            }
            curIdx = this.nxt[curIdx][curLetter]; 
        }
        return this.chk[curIdx] === true; 
    }
}