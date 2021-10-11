//https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *node){
        if(node==NULL ){
            return 0;
        }
        else if(node->left==NULL && node->right==NULL){
            node->data = 0;
        }
        else if(node->left!=NULL && node->right!=NULL){
          node->data = node->left->data+ node->right->data+
                    solve(node->left) + solve(node->right);
        }
        else if(node->left!=NULL ){
          node->data =  node->left->data+solve(node->left) ;
        }
        else if(node->right!=NULL){
          node->data =  node->right->data+ solve(node->right);
        }
        return node->data;
        
    }
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};
