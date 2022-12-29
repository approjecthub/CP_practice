// https://leetcode.com/problems/flip-equivalent-binary-trees/

//####################### implementation 1 #####################################
class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        else if (root1 == NULL || root2 == NULL)
        {
            return false;
        }

        if ((root1->left == NULL && root2->left == NULL) ||
            (root1->left && root2->left && root1->left->val == root2->left->val))
        {
            return (root1->val == root2->val) &&
                   flipEquiv(root1->left, root2->left) &&
                   flipEquiv(root1->right, root2->right);
        }
        else
        {
            return (root1->val == root2->val) &&
                   flipEquiv(root1->left, root2->right) &&
                   flipEquiv(root1->right, root2->left);
        }
    }
};
//####################### implementation 2 #####################################
bool flipEquiv(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    { // only one of the node  is null
        return false;
    }
    /* flip is not happening at every nodes, so
    if flip happens,
        we will compare left subtree of one tree with right subtree of another & vice versa
    else
        we will compare left or right subtree of one tree with left or right subtree of another respectively

    */
    return root1->val == root2->val && ((flipEquiv(root1->left, root2->right) && flipEquiv(root2->left, root1->right)) || (flipEquiv(root1->left, root2->left) && flipEquiv(root2->right, root1->right)));
}
