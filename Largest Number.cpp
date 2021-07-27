//https://leetcode.com/problems/largest-number/

class Solution {
    bool static compare(int n1, int n2){
       string s1 = to_string(n1);
        string s2 = to_string(n2);
        string res1 = s2+s1;
        string res2 = s1+s2;
        if(res2>res1)return true;
        else return false;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(), compare);
        string ans="";
        for(int i=0;i<nums.size();i++){
            ans += to_string(nums[i]);
        }
        
        //deleting starting 0's
        int i;
        for(i=0;i<ans.length();i++){
            if(ans.at(i)!='0'){
                break;
            }
        }
        if(i>0){
            ans.erase(0,i-1);
        }
        return ans;
    }
};
