#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    char data;
    unordered_map<char, Node *> mp;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->mp.count(word[i]) == 0)
            {
                node->mp[word[i]] = new Node(word[i]);
            }
            node = node->mp[word[i]];
        }
        node->isTerminal = true;
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->mp.count(word[i]) != 0)
            {
                node = node->mp[word[i]];
            }
            else
            {
                return false;
            }
        }
        return node->isTerminal;
    }
};
int main()
{
    string words[] = {"this", "is", "a", "trie"};

    string queries[] = {"this", "b", "is"};
    Trie *trie = new Trie();
    for (string word : words)
    {
        trie->insert(word);
    }
    for (string q : queries)
    {
        cout << trie->search(q) << endl;
    }
    return 0;
}
