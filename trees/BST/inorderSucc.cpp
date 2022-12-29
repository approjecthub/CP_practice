// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/#

class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void solve(Node *root, Node *x, int &minDiff, Node *&ans)
    {
        if (!root)
            return;
        if (root != x && (root->data > x->data) && (minDiff > (root->data - x->data)))
        {
            minDiff = root->data - x->data;
            ans = root;
            solve(root->left, x, minDiff, ans);
        }
        else
        {
            solve(root->right, x, minDiff, ans);
        }
    }
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        Node *ans = NULL;
        int minDiff = INT_MAX;
        solve(root, x, minDiff, ans);
        return ans;
    }
};

/*
if we found the current root to be greater than the target, then
1.the root (if no left sub tree exsist) or
2.smallest node of it's left subtree will be answer(if left subtree exsist)
since it's a BST

so we do not need to track minDiff
*/

// implementation 2

Node *inOrderSuccessor(Node *root, Node *x)
{

    if (!root)
        return NULL;
    if (root != x && (root->data > x->data))
    {
        Node *lans = inOrderSuccessor(root->left, x);
        if (lans)
            return lans;
        else
            return root;
    }
    else
    {
        return inOrderSuccessor(root->right, x);
    }
}