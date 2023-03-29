class RangeModule {
private:
    vector<pair<int,int>> data;
public:
    vector<pair<int,int>> merge() {
        vector<pair<int,int>> ans;
        ans.push_back(data[0]);

        for(int i=1; i<data.size(); i++){
            int ansSize = ans.size();
            if(ans[ansSize-1].second> data[i].first){
                ans[ansSize-1].second = 
                max(ans[ansSize-1].second, data[i].second);
            }
            else{
                ans.push_back(data[i]);
            }
        }

        return ans;
    }

    int findIdxToInsert(pair<int,int> ele){
        int l = 0, r = data.size()-1, idx=-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(data[mid].first>= ele.first){
                idx = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return idx;
    }    

    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        pair<int,int> ele = {left, right};

        int idx = findIdxToInsert(ele);
        if(idx==-1){
            data.push_back(ele);
        }
        else{
            data.insert(data.begin()+idx, ele);
        }

        vector<pair<int, int>> temp = merge();
        swap(data, temp);
        // cout<<"After add: \n";
        // for(int i=0; i<data.size(); i++)
        // cout<<(data[i].first)<<","<<(data[i].second)<<endl;
    }
    
    bool queryRange(int left, int right) {
        // cout<<"left: "<<left<<", right: "<<right<<endl;
        // for(int i=0; i<data.size(); i++){
        //     cout<<(data[i].first)<<","<<(data[i].second)<<endl;
        // }
        
        for(int i=0; i<data.size(); i++){
            if(data[i].first<=left && data[i].second>=right){
                // cout<<"op1"<<endl;
                // cout<<"----------------------------------"<<endl;
                return true;
            }
            else if(data[i].first<=left && data[i].second>left){
                left = data[i].second;
            }
            // cout<<left<<","<<right<<endl;
        }

        // cout<<"op2"<<endl;
        // cout<<"----------------------------------"<<endl;
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<pair<int, int>> temp;

        for(int i=0; i<data.size(); i++){
            if(data[i].second<=left || data[i].first>=right){
                temp.push_back(data[i]);
            }
            else{
                if(data[i].first<left && 
                        data[i].second>right){
                    temp.push_back({data[i].first, left});
                    temp.push_back({right, data[i].second});
                }
                else if(data[i].second>left &&
                 data[i].first<left){
                    if(data[i].second<right){
                        temp.push_back({data[i].first, left});
                        left = data[i].second;
                    }
                }  
                else if(data[i].first<right &&
                 data[i].second>right) {
                    if(data[i].second>left){
                        temp.push_back({right, data[i].second});
                        right = data[i].second;
                    }                    
                }
                             
            }
        }
        swap(data, temp);
        // cout<<"After remove: \n";
        // for(int i=0; i<data.size(); i++)
        // cout<<(data[i].first)<<","<<(data[i].second)<<endl;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */