//https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    unordered_map<Node*, int> umap;
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        
        if(root==NULL){
            return 0;
        }
        if(umap.find(root)!=umap.end()){
            return umap[root];
        }
        if(root->left!=NULL && root->right!=NULL){
           
           umap[root]= max((root->data+getMaxSum(root->left->left)
        +getMaxSum(root->left->right)+ getMaxSum(root->right->left)
        +getMaxSum(root->right->right)),
        (getMaxSum(root->left) + getMaxSum(root->right)) );
            
        }
        else if(root->left!=NULL ){
            
            umap[root]= max((root->data+getMaxSum(root->left->left)
        +getMaxSum(root->left->right)),
        (getMaxSum(root->left) ) );
        }
        else if(root->right!=NULL){
            
            umap[root] = max((root->data+getMaxSum(root->right->left)
        +getMaxSum(root->right->right)),
        ( getMaxSum(root->right)) );
        }
        else{
            umap[root]= root->data;
        }
        return umap[root];
        
    }
};
