// https://leetcode.com/problems/lru-cache/description/

class LLNode {
  key: number;
  value: number;
  prev: LLNode | null;
  next: LLNode | null;
  constructor(key: number, value: number) {
    this.key = key;
    this.value = value;
    this.prev = null;
    this.next = null;
  }
}

class DLList {
  head: LLNode | null;
  tail: LLNode | null;
  constructor() {
    this.head = new LLNode(-1, -1);
    this.tail = new LLNode(-1, -1);
    this.head.next = this.tail;
    this.tail.prev = this.head;
  }
  addNode(node: LLNode) {
    this.tail!.prev!.next! = node;
    node.prev = this.tail!.prev!
    node.next = this.tail
    this.tail!.prev! = node
  }
  moveNode(node: LLNode) {
    // remove node
    node.prev!.next! = node.next!
    node.next!.prev! = node.prev!;

    // move node to tail
    this.addNode(node)
  }
}

class LRUCache {
  dll: DLList;
  mapToNode: Map<number, LLNode>;
  capacity: number;
  constructor(capacity: number) {
    this.dll = new DLList();
    this.mapToNode = new Map<number, LLNode>();
    this.capacity = capacity;
  }

  get(key: number): number {
    const node = this.mapToNode.get(key)
    if (!node) return -1;
    this.dll.moveNode(node)
    return node.value!;
  }

  put(key: number, value: number): void {
    if(this.mapToNode.get(key)){
        const node = this.mapToNode.get(key)!
        node.value = value;
        this.dll.moveNode(node)
    }
    else{
        if(this.capacity === this.mapToNode.size){
            const firstNode = this.dll.head?.next!
            this.dll.moveNode(firstNode)
            this.mapToNode.delete(firstNode.key)
            firstNode.key = key
            firstNode.value = value
            this.mapToNode.set(key, firstNode)
        }
        else{
            const node = new LLNode(key, value);
            this.mapToNode.set(key, node)
            this.dll.addNode(node)
        }
    }
  }
}
