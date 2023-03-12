// https://leetcode.com/problems/range-module/

class RangeModule {
public:
    vector<vector<int>> data;
    static bool customSort(vector<int> &a, vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            int ansSize = ans.size();
            if(ans[ansSize-1][1]>= intervals[i][0]){
                ans[ansSize-1][1] = max(ans[ansSize-1][1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }    

    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        data.push_back({left, right});
        sort(data.begin(), data.end(), customSort);
        swap(data, merge(data));
    }
    
    bool queryRange(int left, int right) {
        
    }
    
    void removeRange(int left, int right) {
        
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */