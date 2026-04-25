// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

//@ts-nocheck

// below get random number approach is wrong, single pass to a link list doesn't gurantee random number.
/*
class LLNode {
    val: number;
    prev: LLNode | null;
    next: LLNode | null;
    constructor(val: number) {
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class DLinkedList {
    head: LLNode ;
    tail: LLNode ;
    constructor() {
        this.head =  new LLNode(-1);
        this.tail =  new LLNode(-1);
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }
    addNode(node: LLNode) {
        node.next = this.tail;
        node.prev= this.tail.prev;
        this.tail.prev.next = node;
        this.tail.prev = node;
    }
    removeNode(node: LLNode) {
        node.prev!.next = node.next!;
        node.next!.prev = node.prev!;


    }
}

class RandomizedSet {
    dataMap: Map<number, LLNode>;
    linkedList: DLinkedList;
    pointer: LLNode;
    constructor() {
        this.dataMap = new Map<number, LLNode>();
        this.linkedList = new DLinkedList();
        this.pointer = this.linkedList.head;
    }

    insert(val: number): boolean {
        if(this.dataMap.has(val)) return false;
        const node = new LLNode(val);
        this.dataMap.set(val, node);
        this.linkedList.addNode(node);
        return true;
    }

    remove(val: number): boolean {
        if(!this.dataMap.has(val)) return false;
        const node = this.dataMap.get(val)!;
        this.dataMap.delete(val);
        this.linkedList.removeNode(node);
        if(this.pointer === node) {
            this.pointer = this.pointer.next!;
        }
        return true;
    }

    getRandom(): number {
        let ans: number;
        if(this.pointer === this.linkedList.tail) {
            this.pointer = this.linkedList.head.next;
            
        }
        else if(this.pointer === this.linkedList.head){
            this.pointer = this.linkedList.head.next;
        }
         
        ans = this.pointer.val;
        this.pointer = this.pointer.next!;
        return ans;
    }
}
    */


class RandomizedSet {
    datas: number[];
    dataMap: Map<number, number>;
    constructor() {
        this.datas = [];
        this.dataMap = new Map<number, number>();
    }

    insert(val: number): boolean {
        if(this.dataMap.has(val)) return false;
        this.datas.push(val);
        this.dataMap.set(val, this.datas.length - 1);
        return true;
    }

    remove(val: number): boolean {
        if(!this.dataMap.has(val)) return false;
        const idx = this.dataMap.get(val)!;
        const lastIdx = this.datas.length - 1;

        this.datas[idx] = this.datas[lastIdx];
        this.dataMap.set(this.datas[idx], idx);
        this.datas.pop();
        this.dataMap.delete(val);
        return true;
    }

    getRandom(): number {
        const idx = Math.floor(Math.random() * this.datas.length);
        return this.datas[idx];
    }
}