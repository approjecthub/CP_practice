//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#

Node* LCA(Node *root, int n1, int n2)
{
   if(root==NULL){
       return NULL;
   }

   Node* left = LCA(root->left, n1,n2);
   Node* right = LCA(root->right, n1, n2);
   
   if((right != NULL && root->data==n1 && right->data==n2)
   ||(left!=NULL && root->data==n2 && left->data==n1)
   ||(left!=NULL && right != NULL &&left->data==n1 && right->data==n2)
   ||(left!=NULL && right != NULL && left->data==n2 && right->data==n1)
   ||root->data==n2 
   ||root->data==n1)
   {
       return root;
   }
   else if(left!=NULL )
   {
       return left;
   }
   else if(right != NULL )
   {
       return right;
   }
   else{
       return NULL;
   }
}
