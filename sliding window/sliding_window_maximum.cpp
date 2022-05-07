// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5213108#overview

// https://www.youtube.com/watch?v=CZQGRp93K4k&t=628s

#include <bits/stdc++.h>

using namespace std;

void printDQ(deque<int> dq)
{
    cout << endl
         << "##########################" << endl;
    for (auto it : dq)
    {
        cout << it << " , ";
    }
    cout << endl
         << "##########################" << endl;
}

vector<int> maxInWindow(vector<int> arr, int k)
{
    vector<int> ans;
    deque<int> dq;

    int ck = 0, n = arr.size();
    for (int i = 0; i < k - 1; i++)
    {
        while (dq.size() > 0 && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k - 1; i < n; i++)
    {
        printDQ(dq);
        cout << i << " , arr[i] : " << arr[i] << " , arr[dq.back()] : " << arr[dq.back()] << endl;
        while (dq.size() > 0 && arr[dq.back()] < arr[i])
        {
            cout << "ok1" << endl;
            dq.pop_back();
        }
        if (dq.size() > 0 && dq.front() == i - k)
        {
            cout << "ok2" << endl;
            dq.pop_front();
        }
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }

    return ans;
}

int main()
{
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxInWindow(v, 3);
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}


//################# solution 2 #################################
//https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> q;
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i< nums.size();i++){
            q.push(nums[i]);
            if(dq.size()==0){
                dq.push_back(nums[i]);
            } 
            else{
                while(dq.size()>0 && dq.back()<nums[i]){
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
            
            if(q.size()==k){
                ans.push_back(dq.front());
                if(dq.front()==q.front()){
                    q.pop();
                    dq.pop_front();
                }
                else{
                    q.pop();
                }
            }
        }
        
        return ans;
    }
};