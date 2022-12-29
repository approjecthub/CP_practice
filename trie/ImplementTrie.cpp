// https://leetcode.com/problems/implement-trie-prefix-tree/

class Node
{
public:
    Node *children[26];
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
            int idx = word[i] - 'a';
            if (!node->children[idx])
            {
                node->children[idx] = new Node();
            }
            node = node->children[idx];
        }
        node->isTerminal = true;
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isTerminal;
    }

    bool startsWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1

// Function to insert string into TRIE.
void insert(struct TrieNode *root, string word)
{
    // code here
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        int idx = word[i] - 'a';
        if (!node->children[idx])
        {
            node->children[idx] = getNode();
        }
        node = node->children[idx];
    }
    node->isLeaf = true;
}

// Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string word)
{
    // code here
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        int idx = word[i] - 'a';
        if (!node->children[idx])
            return false;
        node = node->children[idx];
    }
    return node->isLeaf;
}