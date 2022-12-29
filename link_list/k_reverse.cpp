// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        // Complete this method
        if (head == NULL || head->next == NULL || k == 1)
            return head;

        node *dummyHead = new node(-1);
        dummyHead->next = head;
        node *pre = dummyHead;
        node *start = pre->next;
        node *then = start->next;

        int ck = k - 1;
        while (then != NULL)
        {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
            ck--;

            if (ck == 0)
            {
                pre = start;
                if (pre->next != NULL && pre->next->next != NULL)
                {
                    start = pre->next;
                    then = pre->next->next;
                }
                else
                {
                    break;
                }
                ck = k - 1;
            }
        }

        return dummyHead->next;
    }
};

// Leetcode problem
// https://leetcode.com/problems/reverse-nodes-in-k-group/

ListNode *reverseKGroup(ListNode *head, int k)
{

    if (head == NULL || head->next == NULL || k == 1)
        return head;

    ListNode *dummyHead = new ListNode();
    dummyHead->next = head;
    ListNode *pre = dummyHead;
    ListNode *start = pre->next;
    ListNode *then = start->next;

    ListNode *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        n++;
    }

    int ck = k - 1, cn = 0;
    while (then != NULL)
    {
        start->next = then->next;
        then->next = pre->next;
        pre->next = then;
        then = start->next;
        ck--;
        cn++;
        if (ck == 0)
        {
            pre = start;
            if (pre->next != NULL && pre->next->next != NULL)
            {
                start = pre->next;
                then = pre->next->next;
            }
            else
            {
                break;
            }
            ck = k - 1;
            cn++;
            if (cn + k > n)
            {
                break;
            }
        }
    }
    return dummyHead->next;
}