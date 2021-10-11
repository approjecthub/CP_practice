//https://www.geeksforgeeks.org/diameter-of-a-binary-tree/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
    unordered_map<Node *, int> umap;
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        if(umap.find(root)==umap.end()){
           umap[root]= 1+max(height(root->left), height(root->right)); 
        }
        return umap[root];
    }
    int diameter(Node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        height(root);
        
        return max(1+height(root->left)+height(root->right) ,
        max(diameter(root->left), diameter(root->right)));
    }
};
