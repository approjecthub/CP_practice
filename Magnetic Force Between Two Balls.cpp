//https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution {
public:
    bool posibility(vector<int> position, int diff, int m){
        int strt = position[0];
        for(int i=1;i<position.size(); i++){
            if(position[i]-strt >= diff){
                m--;
                strt = position[i];
            }
        }
        if(m<=1){
            return true;
        }
        else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();      
        sort(position.begin(), position.end());
        int s=0, e=position[n-1]-position[0], mid,ans;
        while (s<=e){
            mid = s + (e-s)/2;
            
            if(posibility(position, mid, m)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid -1;
            }
            
        }
        
        return ans;
    }
};
