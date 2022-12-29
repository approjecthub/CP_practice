// implementation 1
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        if (root == p || root == q)
        {
            return root;
        }
        else
        {
            TreeNode *lNode = lowestCommonAncestor(root->left, p, q);
            TreeNode *rNode = lowestCommonAncestor(root->right, p, q);
            if ((lNode == p && rNode == q) || (lNode == q && rNode == p))
                return root;
            else if (lNode == p || lNode == q || lNode)
                return lNode;
            else if (rNode == q || rNode == p || rNode)
                return rNode;
            else
                return NULL;
        }
    }
};

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#
// implementation 2
//  Node* LCA(Node *root, int n1, int n2)
//  {
//     if(root==NULL){
//         return NULL;
//     }

//    Node* left = LCA(root->left, n1,n2);
//    Node* right = LCA(root->right, n1, n2);

//    if((right != NULL && root->data==n1 && right->data==n2)
//    ||(left!=NULL && root->data==n2 && left->data==n1)
//    ||(left!=NULL && right != NULL &&left->data==n1 && right->data==n2)
//    ||(left!=NULL && right != NULL && left->data==n2 && right->data==n1)
//    ||root->data==n2
//    ||root->data==n1)
//    {
//        return root;
//    }
//    else if(left!=NULL )
//    {
//        return left;
//    }
//    else if(right != NULL )
//    {
//        return right;
//    }
//    else{
//        return NULL;
//    }
// }

Node *LCA(Node *root, int n1, int n2)
{

    if (n1 > n2)
    {
        int t = n1;
        n1 = n2;
        n2 = t;
    }
    while (root != NULL)
    {
        if (root->data < n1)
        {
            root = root->right;
        }
        else if (root->data > n2)
        {
            root = root->left;
        }
        else
        {
            break;
        }
    }
    return root;
}
