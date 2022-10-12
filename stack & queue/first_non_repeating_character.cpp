// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next = NULL;
    Node *prev = NULL;
    Node(int data)
    {
        this->data = data;
    }
};

void insertAtTail(Node *&head, Node *&tail, char data)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *temp = new Node(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void removeNode(Node *&head, Node *&tail, Node *node)
{
    // cout<<"here"<<endl;
    if (node->data == '~')
        return;
    if (node->prev == NULL && node->next == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else if (node->prev == NULL)
    {
        head = node->next;
        head->prev = NULL;
    }
    else if (node->next == NULL)
    {
        // cout<<"ok"<<endl;
        tail = node->prev;
        tail->next = NULL;
    }
    else
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    // free(node);
    node->data = '~';
}

void prinLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

string solve(string A)
{
    unordered_map<char, Node *> umap;
    Node *head = NULL;
    Node *tail = NULL;
    string B = "";

    for (auto it : A)
    {
        // cout<<it<<endl;
        if (umap.find(it) == umap.end())
        {
            // cout<<"ok"<<endl;
            insertAtTail(head, tail, it);
            umap.insert({it, tail});
            B += head->data;
        }
        else
        {
            Node *node = umap[it];
            // cout<<"node->data : "<<node->data<<endl;
            removeNode(head, tail, node);
            if (head == NULL)
            {
                B += "#";
            }
            else
            {
                B += head->data;
            }
        }
    }

    return B;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string A = "hspkzrqozquywqsnumncuclkrrwsormkfprzotxrcotbnteiizlvt";
    string B = solve(A);
    cout << "ans: " << B << endl;
    return 0;
}

// using queue
string solve(string A)
{
    unordered_map<char, int> umap;
    queue<char> que;
    string B = "";

    for (auto it : A)
    {
        // cout<<it<<endl;
        umap[it] += 1;
        if (umap[it] == 1)
        {
            // cout<<"ok"<<endl;
            que.push(it);
            char top;
            while (que.size() > 0)
            {
                top = que.front();
                if (umap[top] > 1)
                {
                    que.pop();
                }
                else
                {
                    break;
                }
            }
            B += top;
        }
        else
        {
            char top;
            while (que.size() > 0)
            {
                top = que.front();
                if (umap[top] > 1)
                {
                    que.pop();
                }
                else
                {
                    break;
                }
            }
            if (que.size() > 0)
            {
                B += top;
            }
            else
            {
                B += '#';
            }
        }
    }

    return B;
}