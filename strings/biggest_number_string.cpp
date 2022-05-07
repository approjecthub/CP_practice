//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5212366#overview
#include<bits/stdc++.h>
using namespace std;

bool customComp(int n1, int n2){
    string str1 = to_string(n1) + to_string(n2);
    string str2 = to_string(n2) + to_string(n1);
    return str1 > str2;
}
string concatenate(vector<int> numbers){

    sort(numbers.begin(), numbers.end(), customComp);
    string ans = "";
    for(int i=0; i<numbers.size(); i++){
        ans += to_string(numbers[i]);
    }
    return ans;
}