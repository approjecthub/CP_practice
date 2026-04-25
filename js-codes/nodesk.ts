// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
//@ts-nocheck

/**
 * Definition for a binary tree node.
 */
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
    const disToNode = new Map<number, TreeNode[]>();
    const que: [number, TreeNode][] = [];
    let distanceToTarget: number;
  
    que.push([0, root]);
  
    if (!disToNode.has(0)) disToNode.set(0, []);
    disToNode.get(0).push(root);
  
    while (que.length > 0) {
      const [level, node] = que.shift();
  
      if (node.val === target.val) distanceToTarget = level;
  
      if (!disToNode.has(level + 1)) disToNode.set(level + 1, []);
  
      if (node.left) {
        que.push([level + 1, node.left]);
        disToNode.get(level + 1).push(node.left);
      }
      if (node.right) {
        que.push([level + 1, node.right]);
        disToNode.get(level + 1).push(node.right);
      }
    }
  
    const ans: number[] = [];
    if(disToNode.has(k-distanceToTarget)){
      // distance of nodes from root
      for(const node of disToNode.get(k-distanceToTarget)){
          if(node.val !== target.val) ans.push(node.val);
      }
      
    }
    if(disToNode.has(distanceToTarget-k)){
      ans.push(...disToNode.get(distanceToTarget-k).map(node => node.val));
    }
    if(disToNode.has(distanceToTarget+k)){
      ans.push(...disToNode.get(distanceToTarget+k).map(node => node.val));
    }
    return ans;
  }
