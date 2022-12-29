// https://www.interviewbit.com/problems/largest-permutation/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, int B)
{
    int n = A.size();
    if (n == 0 || B == 0)
        return A;
    priority_queue<int> pq;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        pq.push(A[i]);
        umap[A[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int maxe = pq.top();
        int maxe_idx = umap[maxe];
        int curr = A[i];
        pq.pop();
        if (maxe != curr && B > 0)
        {
            int t = A[i];
            A[i] = A[maxe_idx];
            A[maxe_idx] = t;

            umap[curr] = maxe_idx;
            umap[maxe] = i;
            B--;
        }
    }

    return A;
}

//######################## sol 2#######################################
//########### TC: O(n), SC:O(n)

vector<int> solve(vector<int> &A, int B) {
    int n = A.size();
    if(n==0 || B==0) return A;

    vector<int> aux(n+1,-1); 
    for(int i=0; i<n; i++){
        aux[A[i]] = i;
    }

    for(int i=0; i<n; i++){
        int maxe = n-i;
        int maxe_idx = aux[maxe];
        int curr = A[i];

        if(maxe!=curr && B>0){
            int t = A[i];
            A[i] = A[maxe_idx];
            A[maxe_idx] = t;

            aux[curr] = maxe_idx;
            aux[maxe] = i;
            B--;
        }
    }

    return A;
}