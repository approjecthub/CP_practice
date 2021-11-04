//given an array, find maximum xor possible using any 2 elements present in the array
#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        { //assuming that integer data to be 32 bit
            int bit = (1 << i) & num;
            if (bit)
            { //if bit is 1 we will insert the node at right & else at left
                if (node->right == NULL)
                {
                    node->right = new Node();
                }
                node = node->right;
            }
            else
            {
                if (node->left == NULL)
                {
                    node->left = new Node();
                }
                node = node->left;
            }
        }
    }

    int findMaxXOR(int num)
    {
        Node *node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        { 
            int bit = (1 << i) & num;
            if(bit){
                if(node->left!=NULL){
                    ans += (1 << i);
                    node = node->left;
                }
                else{
                    node = node->right;
                }
            }
            else{
                if(node->right!=NULL){
                    ans += (1 << i);
                    node = node->right;
                }
                else{
                    node = node->left;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Trie * trie = new Trie();
    int input[] = {25,10,2,8,5,3,18,13};
	int n = sizeof(input)/sizeof(int);
    int ans = 0;
    for(int i=0; i<n;i++){
        trie->insert(input[i]);
        ans = max(ans, trie->findMaxXOR(input[i]));
    }
    cout<<ans<<endl;
    return 0;
}