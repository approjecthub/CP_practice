// https://practice.geeksforgeeks.org/contest/interview-series-58/problems#

vector<Node *> findAnagrams(struct Node *head, string s)
{
    // code here
    unordered_map<char, int> umap;
    int n = s.size(), k = n;
    for (int i = 0; i < n; i++)
    {
        umap[s[i]]++;
    }

    Node *temp = head;
    Node *prev = new Node(-1);
    vector<Node *> ans;

    while (temp)
    {
        // cout<<temp->data<<endl;
        if (umap.find(temp->data) != umap.end() && umap[temp->data] > 0)
        {
            if (k == n)
            {
                // cout<<"if: "<<prev->data<<" , "<<temp->data <<endl;
                prev->next = temp;
            }
            umap[temp->data]--;
            k--;
        }
        else
        {
            if (k < n)
            {
                // cout<<"else: "<<prev->next->data<<endl;
                Node *prevTemp = prev->next;
                if (umap.find(temp->data) != umap.end() && umap[temp->data] == 0)
                {

                    while (prevTemp->data != temp->data)
                    {
                        k++;
                        umap[prevTemp->data]++;
                        prevTemp = prevTemp->next;
                    }
                    prevTemp = prevTemp->next;
                    prev->next = prevTemp;
                }
                else
                {
                    while (k < n)
                    {
                        umap[prevTemp->data]++;
                        prevTemp = prevTemp->next;
                        k++;
                        // if(umap.find(temp->data)!=umap.end()
                        // && umap.find(prevTemp->data)!=umap.end()){
                        //     break;
                        // }
                    }
                }
            }
        }
        temp = temp->next;
        if (k == 0)
        {
            // cout<<"in: "<<temp->data<<endl;
            Node *prevTemp = prev;
            ans.push_back(prevTemp->next);

            while (k < n)
            {
                // cout<<"i: "<<prevTemp->next->data<<" , "<<k<<endl;
                umap[prevTemp->next->data]++;
                prevTemp = prevTemp->next;
                k++;
            }

            // cout<<"o: "<<prevTemp->next->data<<" , "<<k<<endl;
            prevTemp->next = NULL;
        }

        // cout<<"#################################"<<endl;
        //     for(auto it: umap){
        //         cout<<it.first<<" : "<<it.second<<endl;
        //     }
        // cout<<"#################################"<<endl;
    }

    return ans;
}