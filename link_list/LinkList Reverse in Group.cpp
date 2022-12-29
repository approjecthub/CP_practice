//https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

/*
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
class Solution
{
    public:
    struct node *solve (struct node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        struct node * nodex = solve(head->next);
        struct node * nextNode = head->next;
        head->next = nextNode->next;
        nextNode->next = head;
        return nodex;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node * prev = NULL;
        struct node * newHead =NULL;
        struct node * curr = head;
        struct node * currHead = head;
        int cnt = 0;
        while(curr!=NULL){
            cnt++;
            if(cnt==k){
                
                struct node * currNext = curr->next;
                curr->next = NULL;
                newHead = solve(currHead);
                if(currHead == head){
                     head = curr;
                }
                else{
                    prev->next = newHead;
                }
                prev = currHead;
                currHead->next = currNext;
                currHead = currNext;
                
                curr = currNext;
                cnt = 0;
                
            }
            else{
                curr = curr->next;
            }
            
        }
        
        if(currHead !=NULL){
            
            newHead = solve(currHead);
            if(currHead == head){
                 head = newHead;
            }
            else{
                prev->next = newHead;
            }
            currHead->next = NULL;
        }
        return head;
    }
};
