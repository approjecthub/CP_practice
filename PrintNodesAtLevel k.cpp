//https://www.geeksforgeeks.org/print-nodes-at-k-distance-from-root/

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// function should print the nodes at k distance from root
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> ans;
    if(k==0){
        ans.push_back(root->data);
        return ans;
    }
  queue<Node *> qu;
  qu.push(root);
  qu.push(NULL);
  int d=0;
  
  while(qu.size()>0){
      if(qu.front()==NULL){
          qu.push(NULL);
          qu.pop();
          d++;
      }
      else{
          Node * node = qu.front();
          if(d==k){
              ans.push_back(node->data);
          }
          qu.pop();
          if(node->left!=NULL){
              qu.push(node->left);
              
          }
          if(node->right!=NULL){
              qu.push(node->right);
              
          }
      }
      if(d>k){
          break;
      }
  }
  return ans;
  
}
