//https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        //Your code here
        if(!root) return INT_MAX;
        int ans = abs(root->data - K);
        if(root->data>K){
            return min(ans, minDiff(root->left, K));
        }
        else{
            return min(ans, minDiff(root->right, K));
        }
    }
};