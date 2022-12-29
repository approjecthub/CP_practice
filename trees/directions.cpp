// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, int p,
                                   int q, string &lmove, string &rmove)
    {
        if (!root)
            return NULL;

        else
        {
            TreeNode *lNode = lowestCommonAncestor(root->left, p, q, lmove, rmove);
            TreeNode *rNode = lowestCommonAncestor(root->right, p, q, lmove, rmove);
            if (lNode && rNode && lNode->val == p && rNode->val == q)
            {
                lmove = "U" + lmove;
                rmove = "R" + rmove;
                return root;
            }
            else if (lNode && rNode && lNode->val == q && rNode->val == p)
            {
                lmove = "U" + lmove;
                rmove = "L" + rmove;
                return root;
            }
            else if (lNode && lNode->val != p && lNode->val != q)
            {
                return lNode;
            }
            else if (rNode && rNode->val != p && rNode->val != q)
            {
                return rNode;
            }
            else if (lNode && lNode->val == p)
            {
                lmove = "U" + lmove;
                if (root->val == q)
                    return NULL;
                return lNode;
            }
            else if (lNode && lNode->val == q)
            {
                rmove = "L" + rmove;
                if (root->val == p)
                    return NULL;
                return lNode;
            }
            else if (rNode && rNode->val == p)
            {
                lmove = "U" + lmove;
                if (root->val == q)
                    return NULL;
                return rNode;
            }
            else if (rNode && rNode->val == q)
            {
                rmove = "R" + rmove;
                if (root->val == p)
                    return NULL;
                return rNode;
            }
            else if (root->val == p || root->val == q)
            {
                return root;
            }
            else
                return NULL;
        }
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string lmove = "", rmove = "";
        lowestCommonAncestor(root, startValue, destValue, lmove, rmove);
        return lmove + rmove;
    }
};

//################ implementation 2 #########################################
/*
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, int p,
                                   int q, string &lmove, string &rmove)
    {
        if (!root)
            return NULL;

        else
        {
            TreeNode *lNode = lowestCommonAncestor(root->left, p, q, lmove, rmove);
            TreeNode *rNode = lowestCommonAncestor(root->right, p, q, lmove, rmove);
            if (lNode && rNode)
            {
                lmove = "U" + lmove;
                if(lNode->val == q && rNode->val == p){
                    rmove = "L" + rmove;
                }
                else if(lNode->val == p && rNode->val == q){
                    rmove = "R" + rmove;
                }
                return root;
            }
            else if (lNode)
            {
                if(lNode->val == p){
                    lmove = "U" + lmove;
                    if (root->val == q)
                    return NULL;
                }
                else if(lNode->val == q){
                    rmove = "L" + rmove;
                    if (root->val == p)
                    return NULL;
                }
                return lNode;
            }
            else if (rNode)
            {
                if(rNode->val == p){
                    lmove = "U" + lmove;
                    if (root->val == q)
                    return NULL;
                }
                else if(rNode->val == q){
                    rmove = "R" + rmove;
                    if (root->val == p)
                    return NULL;
                }
                return rNode;
            }
            else if(root->val == p || root->val == q){
                return root;
            }
            else
                return NULL;
        }
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string lmove = "", rmove = "";
        lowestCommonAncestor(root, startValue, destValue, lmove, rmove);
        return lmove + rmove;
    }
};
*/


//################ implementation 3 #########################################
/*
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(!root){
            return "";
        }
        unordered_map<int, vector<pair<int, string>> > graph;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()>0){
            TreeNode* node = que.front();
            que.pop();
            if(node->left){
                graph[node->left->val].push_back({node->val, "U"});
                graph[node->val].push_back({node->left->val, "L"});
                que.push(node->left);
            }
            if(node->right){
                graph[node->right->val].push_back({node->val, "U"});
                graph[node->val].push_back({node->right->val, "R"});
                que.push(node->right);
            }
        }
        
        queue<pair<int, string>> que2;
        que2.push({startValue,""});
        unordered_set<int> uset;
        string ans = "";
        while(que2.size()>0){
            pair<int, string> p = que2.front();
            que2.pop();
            if(p.first == destValue){
                ans = p.second;
                break;
            }
            for(auto it: graph[p.first]){
                if(uset.find(it.first)==uset.end()){
                    uset.insert(it.first);
                    que2.push({it.first, p.second + it.second});
                }
            }
        }
        
        return ans;
    }
};
*/

//https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/discuss/1612105/3-Steps
/*
1. Build directions for both start and destination from the root.
Say we get "LLRRL" and "LRR".
2. Remove common prefix path.
We remove "L", and now start direction is "LRRL", and destination - "RR"
3. Replace all steps in the start direction to "U" and add destination direction.
The result is "UUUU" + "RR".

C++
Here, we build path in the reverse order to avoid creating new strings.

bool find(TreeNode* n, int val, string &path) {
    if (n->val == val)
        return true;
    if (n->left && find(n->left, val, path))
        path.push_back('L');
    else if (n->right && find(n->right, val, path))
        path.push_back('R');
    return !path.empty();
}
string getDirections(TreeNode* root, int startValue, int destValue) {
    string s_p, d_p;
    find(root, startValue, s_p);
    find(root, destValue, d_p);
    while (!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back()) {
        s_p.pop_back();
        d_p.pop_back();
    }
    return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
}
*/