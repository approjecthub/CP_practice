//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5209728

#include<vector>
#include<algorithm>
using namespace std;
bool compSort(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int countActivites(vector<pair<int,int> > intervals){
    sort(intervals.begin(), intervals.end(), compSort);
    int ans = 0, n = intervals.size(), i = 1;
    if (intervals.size() == 0)
        return 0;
    int end = intervals[0].second;
    while (i < n)
    {
        if (end > intervals[i].first)
        {
            ans++;
        }
        else
        {
            end = intervals[i].second;
        }
        i++;
    }
    return n-ans;
    
}