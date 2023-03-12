// https://leetcode.com/problems/car-pooling/description/

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size(), maxSize=1001;
        vector<int> cost(maxSize,0);

        for(int i=0; i<n; i++){
            cost[trips[i][1]] += trips[i][0];
            if(trips[i][2]<maxSize) 
            cost[trips[i][2]] -= trips[i][0];
        }

        int currCost = 0;
        for(int i=0; i<maxSize; i++){
            currCost += cost[i];
            if(currCost> capacity) return false;
        }

        return true;
    }