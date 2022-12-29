// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

long long minCost(long long arr[], long long n)
{
    // Your code here
    long long cost = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    while (pq.size() >= 2)
    {
        long long r1 = pq.top();
        pq.pop();
        long long r2 = pq.top();
        pq.pop();

        long long r3 = r1 + r2;
        cost += r3;

        pq.push(r3);
    }

    return cost;
}