// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/#

//TC: O(N), SC: O(N)
Node *lowestCommonAncestor(Node *root, int p, int q)
{
    if (!root)
        return NULL;
    if (root->data == p || root->data == q)
    {
        return root;
    }
    else
    {
        Node *lNode = lowestCommonAncestor(root->left, p, q);
        Node *rNode = lowestCommonAncestor(root->right, p, q);

        if (lNode && rNode && ((lNode->data == p && rNode->data == q) || (lNode->data == q && rNode->data == p)))
            return root;
        else if (lNode)
            return lNode;
        else if (rNode)
            return rNode;
        else
            return NULL;
    }
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *strt = lowestCommonAncestor(root, a, b);
    int lA, lB, count = 0;
    queue<pair<Node *, int>> que;
    que.push({strt, 0});

    while (que.size() > 0)
    {
        pair<Node *, int> topP = que.front();
        que.pop();

        Node *node = topP.first;
        int level = topP.second;

        if (node->data == a)
        {
            lA = level;
            count++;
        }

        if (node->data == b)
        {
            lB = level;
            count++;
        }

        if (count == 2)
        {
            break;
        }

        if (node->left)
        {
            que.push({node->left, level + 1});
        }
        if (node->right)
        {
            que.push({node->right, level + 1});
        }
    }

    return lA + lB;
}

// implementation 2 i.e without using additional level order traversal
//TC: O(N), SC: O(Height of the tree)
Node *lowestCommonAncestor(Node *root, int p, int q, int &dis, bool &isFoundBoth)
{
    if (!root)
        return NULL;
    else
    {
        Node *lNode = lowestCommonAncestor(root->left, p, q, dis, isFoundBoth);
        Node *rNode = lowestCommonAncestor(root->right, p, q, dis, isFoundBoth);

        if (lNode && rNode && ((lNode->data == p && rNode->data == q) || (lNode->data == q && rNode->data == p)))
        {
            dis += 2;
            isFoundBoth = true;
            return root;
        }

        else if (lNode)
        {
            if (!isFoundBoth && (lNode->data == p || lNode->data == q))
            {
                dis += 1;
            }
            if ((root->data == p && lNode->data == q) || (root->data == q && lNode->data == p))
            {
                isFoundBoth = true;
                return root;
            }
            return lNode;
        }

        else if (rNode)
        {
            if (!isFoundBoth && (rNode->data == p || rNode->data == q))
            {
                dis += 1;
            }
            if ((root->data == p && rNode->data == q) || (root->data == q && rNode->data == p))
            {
                isFoundBoth = true;
                return root;
            }
            return rNode;
        }
        else if (root->data == p || root->data == q)
        {
            return root;
        }
        else
            return NULL;
    }
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    int dis = 0;
    bool isFoundBoth = 0;
    if (a == b)
        return 0;
    lowestCommonAncestor(root, a, b, dis, isFoundBoth);
    return dis;
}