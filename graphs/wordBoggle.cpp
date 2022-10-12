// https://practice.geeksforgeeks.org/problems/word-boggle4143/1
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool isTerminal = false;
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->children.find(word[i]) == node->children.end())
            {
                node->children[word[i]] = new Node();
            }
            node = node->children[word[i]];
        }
        node->isTerminal = true;
    }
};

bool isValidCell(int i, int j, vector<vector<char>> &board)
{
    int n = board.size(), m = board[0].size();
    return i >= 0 && i < n && j >= 0 && j < m && board[i][j] != '\0';
}
void DFS(int i, int j, vector<vector<char>> &board, Node *root, vector<string> &ans, string word)
{
    if (!root)
        return;
    if (root->children.find(board[i][j]) == root->children.end())
        return;

    vector<int> rowOffset = {0, 0, 1, -1, -1, -1, 1, 1};
    vector<int> colOffset = {1, -1, 0, 0, -1, 1, -1, 1};

    char temp = board[i][j];
    board[i][j] = '\0';
    if (root->children[temp]->isTerminal)
    {
        root->children[temp]->isTerminal = false;
        ans.push_back(word);
    }
    for (int l = 0; l < 8; l++)
    {
        int r = i + rowOffset[l];
        int c = j + colOffset[l];
        if (isValidCell(r, c, board))
        {
            DFS(r, c, board, root->children[temp], ans, word + board[r][c]);
        }
    }
    board[i][j] = temp;
}
vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
{
    // Code here
    Trie *trie = new Trie();

    for (auto word : dictionary)
    {
        trie->insert(word);
    }
    vector<string> ans;
    int n = board.size(), m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string s = "";
            s += board[i][j];
            DFS(i, j, board, trie->root, ans, s);
        }
    }

    return ans;
}