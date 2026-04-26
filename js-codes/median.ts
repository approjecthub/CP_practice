// https://leetcode.com/problems/find-median-from-data-stream/description/

import { MaxHeap, MinHeap } from "@datastructures-js/heap";

class MedianFinder {
  maxHeap: MaxHeap<number>;
  minHeap: MinHeap<number>;
  constructor() {
    this.maxHeap = new MaxHeap();
    this.minHeap = new MinHeap();
  }

  addNum(num: number): void {
    if (this.maxHeap.size() === 0) {
      this.maxHeap.insert(num);
    } else if (this.minHeap.size() === 0 && num > this.maxHeap.top()!) {
      this.minHeap.insert(num);
    } else if (num <= this.maxHeap.top()!) {
      this.maxHeap.insert(num);
    } else {
      this.minHeap.insert(num);
    }

    if (this.maxHeap.size() < this.minHeap.size()) {
      const top = this.minHeap.pop()!;
      this.maxHeap.insert(top);
    } else if (this.maxHeap.size() - this.minHeap.size() > 1) {
      const top = this.maxHeap.pop()!;
      this.minHeap.insert(top);
    }
  }

  findMedian(): number {
    if (this.maxHeap.size() === this.minHeap.size()) {
      return (this.maxHeap.top()! + this.minHeap.top()!) / 2;
    } else {
      return this.maxHeap.top()!;
    }
  }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
