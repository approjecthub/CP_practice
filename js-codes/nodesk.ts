// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
//@ts-nocheck

/**
 * Definition for a binary tree node.
 */

import { Queue } from "@datastructures-js/queue";

class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function distanceK(
  root: TreeNode | null,
  target: TreeNode | null,
  k: number,
): number[] {
  if (!root || !target) return [];

  const queue = new Queue<TreeNode>();
  const adjacencyList = new Map<TreeNode, TreeNode[]>();
  queue.enqueue(root);

  // populating undirected graph from tree
  while (queue.size() > 0) {
    const node = queue.dequeue();
    if (!adjacencyList.has(node)) {
      adjacencyList.set(node, []);
    }

    if (node.left) {
      adjacencyList.get(node).push(node.left);
      if (!adjacencyList.has(node.left)) {
        adjacencyList.set(node.left, []);
      }
      adjacencyList.get(node.left).push(node);
      queue.enqueue(node.left);
    }
    if (node.right) {
      adjacencyList.get(node).push(node.right);
      if (!adjacencyList.has(node.right)) {
        adjacencyList.set(node.right, []);
      }
      adjacencyList.get(node.right).push(node);
      queue.enqueue(node.right);
    }
  }

  const queueForGT = new Queue<{ node: TreeNode; distance: number }>();
  queueForGT.enqueue({ node: target, distance: 0 });
  const visited = new Set<TreeNode>();
  visited.add(target);
  const result: number[] = [];

  while (queueForGT.size() > 0) {
    const { node, distance } = queueForGT.dequeue();
    if (distance === k) {
      result.push(node.val);
    } else {
      for (const neighbor of adjacencyList.get(node)) {
        if (!visited.has(neighbor)) {
          visited.add(neighbor);
          queueForGT.enqueue({ node: neighbor, distance: distance + 1 });
        }
      }
    }
  }

  return result;
}
