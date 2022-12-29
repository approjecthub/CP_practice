//https://www.geeksforgeeks.org/merge-sort-for-linked-list/
#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
void print(Node * ans){
    while(ans!=NULL){
       cout<<ans->data<<endl;
       ans =ans->next;
   }
}

    Node* merge(Node * h1, Node * h2){
        if(h1==NULL) return h2;
        else if(h2==NULL) return h1;
        
        Node * head = NULL;
        if(h1->data<= h2->data){
            head = h1;
            head->next = merge(h1->next, h2);
            
        }
        else{
            head = h2;
            h2->next = merge(h1, h2->next);
        }
        return head;
    }
    Node* findMid(Node* head){
        Node *p=head;
        Node *q=head;
        
        // cout<<"hi\n";
        while(p!=NULL && q!=NULL && q->next!=NULL){
    
            p = p->next;
            q = q->next->next;
        }
        
        return p;
    }
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        Node *h1=NULL;
        Node *h2=NULL;
        if(!head->next->next){
            if(head->data>head->next->data){
                int t = head->data;
                head->data = head->next->data;
                head->next->data = t;
            }
        }
        
        Node* mid = findMid(head);
        if(mid->next==NULL) {
            // cout<< "hi\n";
            return head;
        }
        
        h1 = mergeSort(mid->next);
        
        mid->next = NULL;
       
        h2 = mergeSort(head);
        // print(h1);
        // cout<<"------------M-----------\n";
        // print(h2);
        // cout<<"-----------END------------\n";
        
        return merge(h1,h2);
        //  return NULL;
        
    }


int main()
{
    struct Node* a = new Node(3);
    a->next = new Node(5);
    a->next->next = new Node(2);
    a->next->next->next = new Node(4);
    a->next->next->next->next = new Node(1);
   
   Node *ans = mergeSort(a);
   print(ans);
}
