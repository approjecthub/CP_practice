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

    void search(string word, unordered_map<string, bool> &mp, int st, int end)
    {
        Node *node = root;
        string current_str = "";
        for (int i = st; i < end; i++)
        {
            if (node->mp.count(word[i]) != 0)
            {
                current_str +=word[i];
                node = node->mp[word[i]];
            }
            else
            {
                break;
            }
        }
        if(node->isTerminal){
            mp[current_str]= true;
        }
    }
};

void documentSearch(string document, vector<string> words){
    unordered_map<string, bool> mp;
    Trie * trie = new Trie();
    for(string word: words){
        trie->insert(word);
    }
    int n = document.length();
    for(int i=0;i<n; i++){
        trie->search(document, mp, i, n);
    }
    for(auto w :words){
		if(mp[w]){
			cout<<w <<" : True" <<endl;
		}
		else{
			cout<<w <<" : False "<<endl;
		}
	}

	
}
int main(){
	
    string document  ="littl cute cat loves to code in c++, java & python";
    vector<string> words{"cute cat", "ttle", "cat","quick","big"};

    //find how many words are present inside document as substring
    /*
    Logic:
    1.Insert all words in the trie
    2.Check if substrings of document is present or not(now creating this substring is tricky 
    since we will be doing it in O(nw); where n=length of document, w=length of a word)
    */
    documentSearch(document,words);


	return 0;
}