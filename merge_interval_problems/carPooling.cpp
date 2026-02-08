// https://leetcode.com/problems/car-pooling/description/
// Topics: Interval, Prefix Sum, Sorting

class Solution {

    public:
        bool solve(vector<vector<int>>& trips, int capacity) {
            int n = trips.size(), maxSize = 1001;
            vector<int> cost(maxSize, 0);
    
            for (int i = 0; i < n; i++) {
                cost[trips[i][1]] += trips[i][0];
                if (trips[i][2] < maxSize)
                    cost[trips[i][2]] -= trips[i][0];
            }
    
            int currCost = 0;
            for (int i = 0; i < maxSize; i++) {
                currCost += cost[i];
                if (currCost > capacity)
                    return false;
            }
    
            return true;
        }
    
        bool solve2(vector<vector<int>>& trips, int capacity) {
            int n = trips.size();
    
            // Sort trips based on the 2nd element (start location)
            sort(trips.begin(), trips.end(),
                 [](const vector<int>& a, const vector<int>& b) {
                     return a[1] < b[1];
                 });
            int currCost = trips[0][0], end = trips[0][2];
            if (currCost > capacity)
                return false;
            // Priority queue to fetch the minimum value of the first item in the
            // pair (end location) pair format: (end, noOfPassengers) Syntax
            // explanation:
    
            // For max value (of first element), replace greater<> with less<> (or
            // just omit the comparator for default max-heap)
            /*
            Syntax breakdown:
            - pair<int, int> - The element type stored in the queue
            - vector<pair<int, int>> - The underlying container (default is vector,
            but must be specified when using custom comparator)
            - greater<pair<int, int>> - The comparator that makes it a min-heap
            (smallest element has highest priority)
    
            -> Why greater<> creates a min-heap:
            By default, priority_queue uses less<> which creates a max-heap (largest
            on top) Using greater<> reverses this, so the smallest element comes
            first For pairs, comparison is done first by the first element, then by
            the second if tied
            */
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            // If max-heap is needed (to fetch the max value), use:
            // priority_queue<pair<int, int>> pq;
    
            pq.push({end, trips[0][0]});
    
            for (int i = 1; i < n; i++) {
                if (trips[i][1] >= end) {
                    while (pq.size() > 0) {
                        pq.pop();
                    }
                    currCost = trips[i][0];
                    end = trips[i][2];
                    pq.push({end, currCost});
                } else if (trips[i][1] < end) {
                    // this point of time we do not know if one of the past trip has
                    // already ended or not so before adding the current trip i.e.
                    // "currCost += trips[i][0];", we need to check if any of the
                    // past trips has already ended or not - one way of doing is to
                    // iterate over all past trips or we can use a priority queue to
                    // keep track of the end time of the past trips
                    while (pq.size() > 0 && pq.top().first < trips[i][1]) {
                        currCost -= pq.top().second;
                        pq.pop();
                    }
                    currCost += trips[i][0];
                    end = max(end, trips[i][2]);
                    pq.push({end, currCost});
                }
    
                if (currCost > capacity)
                    return false;
            }
            return true;
        }
    
        bool carPooling(vector<vector<int>>& trips, int capacity) {
            return solve(trips, capacity);
        }
    };