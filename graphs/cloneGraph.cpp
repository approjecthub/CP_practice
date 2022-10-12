// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        unordered_map<int, Node *> umap;
        unordered_map<int, unordered_set<int>> neig;
        umap[node->val] = new Node(node->val);
        queue<Node *> que;
        que.push(node);

        while (que.size() > 0)
        {
            Node *temp = que.front();
            que.pop();
            Node *dc = umap[temp->val];

            for (auto it : temp->neighbors)
            {
                if (umap.find(it->val) == umap.end())
                {
                    umap[it->val] = new Node(it->val);
                    umap[it->val]->neighbors.push_back(dc);
                    dc->neighbors.push_back(umap[it->val]);

                    que.push(it);
                    neig[it->val].insert(dc->val);
                    neig[dc->val].insert(it->val);
                }
                else
                {
                    // cout<<()<<" , "<<(it->val)<<endl
                    if (neig[it->val].find(dc->val) == neig[it->val].end())
                    {
                        umap[it->val]->neighbors.push_back(dc);
                        neig[it->val].insert(dc->val);
                    }
                    if (neig[dc->val].find(it->val) == neig[it->val].end())
                    {
                        umap[dc->val]->neighbors.push_back(umap[it->val]);
                        neig[dc->val].insert(it->val);
                    }
                }
            }
        }

        return umap[node->val];
    }
};

//################# soln 2 ###############################
//#### cleaner, and less error prone sBFS solution
// https://leetcode.com/problems/clone-graph/discuss/1793212/C%2B%2Bor-Detailed-Explanation-w-DFS-and-BFS-or-Commented-code-with-extra-Test-Case
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        unordered_map<int, Node *> umap;
        umap[node->val] = new Node(node->val);
        queue<Node *> que;
        que.push(node);

        while (que.size() > 0)
        {
            Node *temp = que.front();
            que.pop();
            Node *dc = umap[temp->val];

            for (auto it : temp->neighbors)
            {
                if (umap.find(it->val) == umap.end())
                {
                    umap[it->val] = new Node(it->val);
                    que.push(it);
                }
                dc->neighbors.push_back(umap[it->val]);
            }
        }

        return umap[node->val];
    }
};