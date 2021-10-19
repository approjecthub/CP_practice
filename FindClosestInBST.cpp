//https://www.geeksforgeeks.org/find-closest-element-binary-search-tree/

void solve(Node * root, int &ans, int k){
	    if(root==NULL){
	        return;
	    }
	    else if(root->data==k){
	        ans = 0;
	        return ;
	    }
	    else if(root->data>k){
	        ans = min(ans, abs(root->data-k));
	        solve(root->left, ans, k);
	    }
	    else{
	        ans = min(ans, abs(root->data-k));
	        solve(root->right, ans, k);
	    }
	}
    int minDiff(Node *root, int K)
    {
        //Your code here
        int ans = abs(root->data - K);
        solve(root, ans, K);
        return ans;
    }
