// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5225852#overview
//  https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

// TC: O(N)

bool isPresent(Node *root, int key)
{
    // Complete this method

    if (!root)
        return false;
    else if (root->key == key)
        return true;
    else
        return (isPresent(root->left, key) || isPresent(root->right, key));
}

// TC: O(logN)
bool search(struct Node *root, int key)
{
    if (!root)
        return false;
    else if (root->data == key)
        return true;
    else
    {
        if (root->data < key)
        {
            return search(root->right, key);
        }
        else
        {
            return search(root->left, key);
        }
    }
}