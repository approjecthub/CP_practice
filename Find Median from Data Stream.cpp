//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
  priority_queue<int> maxheap;
  priority_queue<int, vector<int>, greater<int>> minheap;  
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n1 = maxheap.size();
        int n2 = minheap.size();
        if(n1==0){
            maxheap.push(num);
            return;
        }
        double med = findMedian();
        if(num>med){//minheap
            if(n2<=n1){
                minheap.push(num);
            }
            else{
                int x = minheap.top();
                minheap.pop();
                maxheap.push(x);
                minheap.push(num);
            }
        }
        else{//maxheap
            if(n1<=n2){
                maxheap.push(num);
            }
            else{
                int x = maxheap.top();
                maxheap.pop();
                minheap.push(x);
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        int n1 = maxheap.size();
        int n2 = minheap.size();

        double x =n1!=0? (double) maxheap.top(): 0;
        double y =n2!=0? (double) minheap.top(): 0;
        
        if(n1==n2){
            return (x+y)/2;
        }
        else if(n1<n2){
            return y;
        }
        else{
            return x;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
