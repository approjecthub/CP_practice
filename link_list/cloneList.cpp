// https://leetcode.com/problems/copy-list-with-random-pointer/

// TC: O(N) & SC: O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        Node *temp = head;
        unordered_map<Node *, Node *> mp;
        mp[temp] = new Node(temp->val);

        while (temp)
        {
            Node *node = mp[temp];
            if (temp->next && mp.find(temp->next) == mp.end())
            {
                mp[temp->next] = new Node(temp->next->val);
                node->next = mp[temp->next];
            }
            else if (temp->next)
            {
                node->next = mp[temp->next];
            }

            if (temp->random && mp.find(temp->random) == mp.end())
            {
                mp[temp->random] = new Node(temp->random->val);
                node->random = mp[temp->random];
            }
            else if (temp->random)
            {
                node->random = mp[temp->random];
                node->random = mp[temp->random];
            }

            temp = temp->next;
        }

        return mp[head];
    }
};

// https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)