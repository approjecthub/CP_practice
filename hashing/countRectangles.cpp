// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/23418998#questions/15546558

#include <bits/stdc++.h>

using namespace std;
int coutRectangle(vector<vector<int>> &points){
    int n = points.size(), ans=0;
    unordered_set<string> uset;
    for(int i=0; i<n; i++){
        string p = to_string(points[i][0]) + to_string(points[i][1]);
        // cout<<p<<endl;
        uset.insert(p);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                string p1 = to_string(x1)+to_string(y1);
                string p2 = to_string(x2)+to_string(y2);
                string p3 = to_string(x1)+to_string(y2);
                string p4 = to_string(x2)+to_string(y1);
                if(p1!=p3 && p1!=p4 && p1!=p2
                && uset.find(p3)!=uset.end() && uset.find(p4)!=uset.end()){
                cout<<p1<<","<<p2<<","<<p3<<","<<p4<<endl;
                    ans++;
                }
            }
        }
    }
    
    return ans/4;
}
int main()
{
    // vector<vector<int>> points = {{0,0},{0,1},{1,1},{1,0},{2,1},{2,0},{3,1},{3,0}};
    // vector<vector<int>> points = {{4,1}, {4,0}, {0,0}, {0,1},{1,1},{1,0},{2,0},{2,1}};
    vector<vector<int>> points = {{ 0, 0 },  { 1, 0 }, { 1, 1 }, { 0, 1 }, { 2, 0 }, { 2, 1 }, { 11, 23 }};
    cout<<coutRectangle(points)<<endl;
    return 0;
}
