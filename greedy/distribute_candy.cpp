// https://www.interviewbit.com/problems/distribute-candy/
// TC: O(n^2) , SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &A)
{
    int ans = 0, n = A.size();
    vector<int> aux(n, 0);

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && A[i] > A[i - 1])
        {
            aux[i] = aux[i - 1] + 1;
        }
        else if (i > 0 && A[i] < A[i - 1])
        {
            aux[i] = 1;
            int j = i;
            while (j > 0 && A[j] < A[j - 1] && aux[j] == aux[j - 1])
            {
                aux[j - 1]++;
                j--;
            }
        }
        else
        {
            aux[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans += aux[i];
    }
    return ans;
}

// ######################### sol2 #############################
// TC: O(nlogn), SC: O(n)

class CompSort
{
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.first > p2.first;
    }
};

int totalCandy(vector<int> &A)
{
    int ans = 0, n = A.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompSort> pq;
    vector<int> aux(n, 0);

    for (int i = 0; i < n; i++)
    {
        pq.push({A[i], i});
    }

    while (pq.size() > 0)
    {
        pair<int, int> top = pq.top();
        int mine_idx = top.second;
        pq.pop();

        int candie = 1;
        // cout<<"idx: "<<mine_idx<<", A[idx]: "<<A[mine_idx];
        // if(mine_idx>0){
        //      cout<<", idx-1: "<<(mine_idx-1)<<", A[idx-1]: "<<A[mine_idx-1];
        // }
        // if(mine_idx<n-1){
        //     cout<<", idx+1: "<<(mine_idx+1)<<", A[idx+1]: "<<A[mine_idx+1];
        // }
        // cout<<endl;
        if (mine_idx > 0 && A[mine_idx - 1] < A[mine_idx])
        {
            // cout<<"if1"<<endl;
            candie = max(candie, aux[mine_idx - 1] + 1);
        }
        if (mine_idx < n - 1 && A[mine_idx + 1] < A[mine_idx])
        {
            // cout<<"if2"<<endl;
            candie = max(candie, aux[mine_idx + 1] + 1);
        }
        // cout<<A[mine_idx]<<" , "<<candie<<endl;
        aux[mine_idx] = candie;
    }

    for (int i = 0; i < n; i++)
    {
        // cout<<A[i]<<" : "<<aux[i]<<endl;
        ans += aux[i];
    }
    return ans;
}