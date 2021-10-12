//https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

pair<int, int> solve(Node *root){
        pair<int,int> p;
        if(root==NULL){
            p.first = 0;
            p.second = 0;
            return p;
        }
        pair<int, int> left = solve(root->left);//first=> included, second=>excluded
        pair<int, int> right = solve(root->right);
        int inc = root->data + left.second + right.second;
        int exc = max(left.first, left.second) + max(right.first, right.second);
        
        p.first = inc;
        p.second = exc;
        return p;
    }
    int getMaxSum(Node *root) 
    {
        if(root==NULL){
            return 0;
        }
        else{
            pair<int, int>p = solve(root);
            return max(p.first, p.second);
        }
        
    }
