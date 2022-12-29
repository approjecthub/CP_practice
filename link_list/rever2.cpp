// https://leetcode.com/problems/reverse-linked-list-ii/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || left == right)
    {
        return head;
    }
    stack<ListNode *> st;

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    int steps = 1;

    while (curr != NULL)
    {

        if (steps >= left && steps <= right)
        {
            st.push(curr);
        }
        else if (steps < left)
        {
            prev = curr;
        }
        else if (steps > right)
        {
            next = curr;
            break;
        }

        curr = curr->next;
        steps++;
    }
    cout << st.size() << endl;
    // if(prev==NULL) cout<<"prev-N"<<endl;
    // if(next==NULL) cout<<"next-N"<<endl;
    if (prev != NULL && st.size() > 0)
    {
        // cout<<"here"<<endl;
        prev->next = st.top();
    }
    else if (prev == NULL && st.size() > 0)
    {
        head = st.top();
    }

    while (st.size() > 0)
    {
        ListNode *top = st.top();
        st.pop();
        if (st.size() > 0)
        {
            top->next = st.top();
        }
        else
        {
            top->next = next;
        }
    }

    return head;
}

//############################## sol2 #################################
// https://leetcode.com/problems/reverse-linked-list-ii/discuss/30666/Simple-Java-solution-with-clear-explanation
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || left == right)
    {
        return head;
    }

    ListNode *dummyHead = new ListNode();
    dummyHead->next = head;

    ListNode *pre = dummyHead;
    for (int i = 1; i < left; i++)
    {
        pre = pre->next;
    }

    ListNode *start = pre->next;
    ListNode *then = start->next;
    for (int i = 1; i <= right - left; i++)
    {

        start->next = then->next;
        then->next = pre->next;
        pre->next = then;
        then = start->next;
    }

    return dummyHead->next;
}
