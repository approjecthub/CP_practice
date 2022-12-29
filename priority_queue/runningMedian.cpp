// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
// Function to insert heap.
void insertHeap(int &x)
{
    if (maxHeap.size() > 0 && x > maxHeap.top())
    {
        // cout<<"min-->"<<x<<endl;
        minHeap.push(x);
    }
    else
    {
        // cout<<"max-->"<<x<<endl;
        maxHeap.push(x);
    }
    balanceHeaps();
}

// Function to balance heaps.
void balanceHeaps()
{
    // cout<<"balance-->"<<(minHeap.size())<<" , "<<(maxHeap.size())
    // <<","<<abs(minHeap.size() - maxHeap.size())<<endl;
    int minHeapSize = minHeap.size();
    int maxHeapSize = maxHeap.size();
    if (abs(minHeapSize - maxHeapSize) <= 1)
    {
        // cout<<"out"<<endl;
        return;
    }
    else
    {
        if (minHeapSize > maxHeapSize)
        {
            int x = minHeap.top();
            minHeap.pop();
            maxHeap.push(x);
        }
        else
        {
            int x = maxHeap.top();
            maxHeap.pop();
            minHeap.push(x);
        }
    }
}

// Function to return Median.
double getMedian()
{
    if (maxHeap.size() == minHeap.size())
    {

        return (double)(maxHeap.top() + minHeap.top()) / (double)2;
    }
    else if (maxHeap.size() > minHeap.size())
    {
        return (double)maxHeap.top();
    }
    else
    {
        return (double)minHeap.top();
    }
}