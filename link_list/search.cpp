//
/*
Warm Up - Search!
 Complete the function which checks whether a given key is present in the Linked List or not! 

TC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next=NULL;
    
    Node(int data){
        this->data = data;
    }
};

void insertAtHead(Node * &head, int data){
    if(head==NULL){
        head = new Node(data);
    }
    else{
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

Node* insertInMiddle(Node* head, int data)
{
    //https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1/#
	if(head==NULL){
        head = new Node(data);
    }
    else if(head->next==NULL){
        head->next = new Node(data);
    }
    else{
        Node *forward = head->next;
        Node *mid = head;
        while(mid->next!=NULL && forward->next!=NULL){
            mid = mid->next;
            forward = forward->next->next;
            if(forward==NULL ) break;
        }
        
        
        Node *temp = new Node(data);
        temp->next = mid->next;
        mid->next = temp;
    }
    return head;
}

void displayLL(Node *head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}

bool isPresent(Node * head, int key){
    //Complete this function 
    
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}